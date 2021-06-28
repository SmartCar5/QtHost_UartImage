#ifndef _IMAGE_H
#define _IMAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <stdint.h>

#define MISS 255
#define CAMERA_H  120                            //ͼƬ�߶�
#define CAMERA_W  188                            //ͼƬ���
#define FAR_LINE 1//ͼ�����ϱ߽�
#define NEAR_LINE 113//ͼ�����±߽�
#define LEFT_SIDE 0//ͼ������߽�
#define RIGHT_SIDE 187//ͼ�����ұ߽�
//#define ValidMaxLine 17//����ͷ������Զ���㶯̬��ֵʱ����ʼ��
#define ThreDownMax 140
#define MISS 255
#define white_num_MAX 15//ÿ��������������
#define CUT_LINE 33 //��ʼ������
#define THRE_AMOUNT ((120-CUT_LINE)*188)
#define up 0
#define down 1
#define _left 0
#define _right 1
#define _default 2

/////////////////////////////
#define black 0
#define white 1
#define image_blue  2
#define green 3
#define image_red   4
#define gray  5
#define purple 6
///////////////////////////

extern uint8_t IMG[CAMERA_H][CAMERA_W];//��ֵ����ͼ������
extern uint8_t image_Buffer_0[CAMERA_H][CAMERA_W];
extern uint8_t* fullBuffer;//ָ��Ҷ�ͼ���׵�ַ
extern int image_rampCanUp;
extern uint8_t image_transformX[120 * 188];
extern uint8_t image_transformY[120 * 188];
//extern uint8_t *fullBuffer;
typedef enum state_road {
    enterTriCross,//���������ʮ��
    enterTrident,//��������
    TridentStage2,//������׶�
    TridentStage3,
    quitTrident,
    rightTiltEnterCross,
    leftTiltEnterCross,
    enterCrossStage2,//����ʮ��
    specialQuitCross,
    quitCross,
    enterLeftRoundabout,
    leftRoundaboutStage2,
    leftRoundaboutStage3,
    leftRoundaboutStage4,
    leftRoundaboutStage5,//��������׶�
    leftRoundaboutStage6,
    leftRoundaboutStage7,
    leftRoundaboutStage8,
    leftRoundaboutStage9,
    enterRightRoundabout,
    rightRoundaboutStage2,
    rightRoundaboutStage3,
    rightRoundaboutStage4,
    rightRoundaboutStage5,//��������׶�
    rightRoundaboutStage6,
    rightRoundaboutStage7,
    rightRoundaboutStage8,
    rightRoundaboutStage9,
    stop,
    enterZebra,
    quitZebra,
    enterGarage,
    others,
    leftTiltEnterTrident,
    rightTiltEnterTrident,
    enterRamp,
    outRamp
}stateRoad;

typedef struct state_mgr {
    stateRoad curtState;
    stateRoad lastState;
}stateMgr_t;

typedef struct {
    uint8_t leftMissCount;//���Ե�����²���ʧ����
    uint8_t rightMissCount;//�ұ�Ե�����²���ʧ����
    uint8_t cuspLine;//���
    uint8_t leftBreakPoint;//���۵�
    uint8_t rightBreakPoint;//���۵�
    uint8_t crossFlag;
    uint8_t notTridentFlag;
    uint8_t tridentFlag;
}TiltEnterTriCross_t;


//void head_clear(void);
//ͼƬԤ����
void image_Preprocess(void);
//��̬��ֵ����
int image_GetOtsuThre(void);
void image_GetHistGram(uint16_t* ptrHistGram, uint8_t startLine, uint8_t endLine);
int image_Kittler(void);
int image_Iteration(void);
//ȥ����+��ֵ��
void image_RemoveDistortion(void);
void image_Binarization(void);
//����ͨ��
int find_f(int a);
void search_white_range();
void find_all_connect();
void find_road();
uint8_t find_continue(uint8_t i_start, uint8_t j_start);
void ordinary_two_line(void);
//�������������
void image_TellIfOutOfRoad(void);
void image_TellIfEnterZebra(void);
void image_TellIfQuitZebra(void);
void image_TellIfEnterLeftGarage(int16_t* ptrStateEnum);
void image_TellIfEnterRightGarage(int16_t* ptrStateEnum);
void image_SpecialPatching(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t* line);
//������ȡ
void image_FeatureExtract(void);
uint8_t image_LineIfStraight(uint8_t* ptrLine, uint8_t startLine, uint8_t endLine, float* ptrVaric);
uint8_t image_RootLineIfAbsStraight(uint8_t* ptrLine, uint8_t direct);
void image_InitEdgeLine(void);
void image_InitRoadLine(void);
void image_IfEdgeLineLose(uint8_t* ptrEnum);
int32_t image_FindJumpos(uint8_t* ptrEnum, uint8_t startLine, uint8_t endLine);
uint8_t image_FindTopAbsBlackNum(uint8_t iStart, uint8_t iEnd, uint8_t minWhiteWidth);
void image_TiltEnterTriCrossGetFeature(TiltEnterTriCross_t* ptrTiltMgr);
uint8_t image_LeastSquare(float* ptrK, float* ptrB, uint8_t iStart, uint8_t iEnd, uint8_t* ptrLine);
//Ԫ���ж�
uint8_t image_JudgeElement(void);
uint8_t image_TellIfNeedRemedy(void);
uint8_t image_TellRealWhiteNum(uint8_t row);
void image_TellIfEnterTricross(int16_t* ptrStateEnum);
void image_TellIfRightTiltEnterCross(int16_t* ptrStateEnum);
void image_TellIfLeftTiltEnterCross(int16_t* ptrStateEnum);
void image_TellIfEnterRamp(int16_t* ptrStateEnum);

void image_TellIfLateEnterTrident(int16_t* ptrStateEnum);
uint8_t image_TellIfEnterTridentStage2(int16_t* ptrStateEnum);
void image_TellIfEnterTrident(int16_t* ptrStateEnum);
uint8_t image_TellIfLeftTiltEnterTrident(int16_t* ptrStateEnum);
uint8_t image_TellIfRightTiltEnterTrident(int16_t* ptrStateEnum);
void image_TellIfMissJudgeTiltCross(int16_t* ptrStateEnum);
void image_TellIfLeftTiltQuitTrident(int16_t* ptrStateEnum);
void image_TellIfRightTiltQuitTrident(int16_t* ptrStateEnum);
void image_TellIfEnterTridentStage3(int16_t* ptrStateEnum);
void image_TellIfQuitTrident(int16_t* ptrStateEnum);
void image_TellIfEnterCross(int16_t* ptrStateEnum);
void image_TellIfEnterCrossWeak(int16_t* ptrStateEnum);
void image_TellIfSpecialQuitCross(int16_t* ptrStateEnum);
void image_TellIfQuitCross(int16_t* ptrStateEnum);
void image_TellIfTiltQuitCross(int16_t* ptrStateEnum);
void image_TellIfCrossComplete(int16_t* ptrStateEnum);
void image_TellIfSlightLeftTiltEnterCross(int16_t* ptrStateEnum);
void image_TellIfSlightRightTiltEnterCross(int16_t* ptrStateEnum);

void image_TellIfEnterRightRoundabout(int16_t* ptrStateEnum);
void image_TellIfTiltEnterRightRoundabout(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage2(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage3(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage4(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage5(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage6(int16_t* ptrStateEnum);//�Ƿ��Բ������
void image_TellIfRightRoundStage7(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage8(int16_t* ptrStateEnum);
void image_TellIfRightRoundStage9(int16_t* ptrStateEnum);
void image_TellIfQuitRightRound(int16_t* ptrStateEnum);//�Ƿ������
void image_TellIfMissJudgeRightRound(int16_t* ptrStateEnum);
void image_TellIfEnterLeftRoundabout(int16_t* ptrStateEnum);
void image_TellIfTiltEnterLeftRoundabout(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage2(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage3(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage4(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage5(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage6(int16_t* ptrStateEnum);//�Ƿ��Բ������
void image_TellIfLeftRoundStage7(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage8(int16_t* ptrStateEnum);
void image_TellIfLeftRoundStage9(int16_t* ptrStateEnum);
void image_TellIfQuitLeftRound(int16_t* ptrStateEnum);//�Ƿ������
void image_TellIfMissJudgeLeftRound(int16_t* ptrStateEnum);



//����
void image_EdgePatching(void);
void image_FindPatchPos(uint8_t direct, uint8_t* pos, uint8_t near = 100, uint8_t far = 60);
uint8_t image_GetWIndex(uint8_t direct, uint8_t pos);
uint8_t image_GetWhiteIndex(uint8_t direct, uint8_t pos);
float image_Line2Points(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t* line);
float image_LineRange(uint8_t x, uint8_t y, uint8_t range, uint8_t end, uint8_t* s_line, uint8_t* d_line, uint8_t direct);
void image_GetMidSgl(uint8_t* line, uint8_t direct, uint8_t farline, uint8_t nearline, uint8_t width);
void image_MidLineFilter(void);
void image_FindPatchPointEX(uint8_t direct, uint8_t d_line, uint8_t* point, uint8_t* line);
void image_MidLineCorrector(uint8_t threshold);
static double KalmanFilterKernal(const double ResrcData, double ProcessNiose_Q = 0.01, double MeasureNoise_R = 20);
void image_FindBreakPoint(uint8_t* line, uint8_t direct, uint8_t* ptrBreakPoint);
void KalmanFilter(void);
void image_MidLineFilterEx(void);
uint8_t image_CurveTranslation(uint8_t* ptrLine, uint8_t iStart, uint8_t iEnd, uint8_t direct, uint8_t roadWidth);
void image_PerfectCurvePatch(void);
float image_GetDistance(float x1, float x2, float y1, float y2);

void image_main(uint8_t adcJudge);
void get_mid_line(void);
void GetMidLine(void);

//���У��
void image_AdcCheck(void);

void my_memset(uint8_t* ptr, uint8_t num, uint8_t size);
void image_getDeviation(void);
#endif //
