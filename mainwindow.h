#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include "formimagelist.h"
#include "streamform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList serialPorts;
    QSerialPort serial;
    uint8_t fullBuffer0[120][188];
    QString path;
    QByteArray SerialBuffer;
    QByteArray SerialBuffer4Ctrl;
    //FormImageList form;

private slots:
    void on_pushButtonRefresh_clicked();
    void serialPort_readyRead();
    void serialPort_readImage();
    void serialPort_readData();
    void showSerialImg();
    void timerCallBack();

    void on_pushButton_4_clicked();//打开串口

    void on_pushButtonClrReceive_clicked();

    void on_pushButtonLaunch_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonSaveImage_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonFix_clicked();

    void on_pushButtonTimer_clicked();

    //void on_pushButton_clicked();

    void on_pushButtonStream_clicked();

private:
    Ui::MainWindow *ui;
    bool isSerialOpened;
    bool isDispImg;
    bool imgFlag;
    //bool dataFlag;
    bool isSave;
    bool isStream;
    bool isTimerOn;
    const QStringList BaudRates = {"115200","921600","1152000"};
    const QStringList DataBits = {"8","7","6","5"};
    const QStringList Paritys = {"NoParity","EvenParity","OddParity","SpaceParity","MarkParity"};
    const QStringList StopBits = {"OneStop","OneAndHalfStop","TwoStop"};
    const QStringList StreamCtrls = {"NoFlowControl","HardwareControl","SoftwareControl"};

    const int readBufferSize = 120*188;
    int nowReadSize;
    int nowFlag;


    long time_ms = 0;
private:
    void uiInit();
};
#endif // MAINWINDOW_H
