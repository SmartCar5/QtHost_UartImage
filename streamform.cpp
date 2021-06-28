#include "streamform.h"
#include "ui_streamform.h"
#include "mainwindow.h"
#include <qtimer.h>
#include <QString>
#include <QByteArray>
//#include "qcustomplot.h"
#include <qcustomplot.h>
#include <QColor>
#include <QRgb>
#include <QPen>
#include <QMainWindow>
#include <qnamespace.h>
#include <QTimer>
#include <QRandomGenerator>
#include <QVector>
#include <QTime>
#include "opencv.hpp"

extern uint8_t dataBuffer[40];
extern bool dataFlag;

//void setupRealtimeDataDemo(QCustomPlot *customPlot);

streamForm::streamForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::streamForm)
{
    ui->setupUi(this);
    //data.setNum(40);
    setupRealtimeDataDemo(ui->customPlot);
    QTimer* pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(showData()));
    pTimer->start(50);
}

streamForm::~streamForm()
{
    delete ui;
}

void streamForm::showData()
{
    if(dataFlag==true)
    {
        for(int i = 0;i<40;i++)
        {
            data.append(dataBuffer[i]);
        }
        //ui->textEdit->append(QString(data.toHex()));
        data.clear();
        uint32_t temp = (dataBuffer[0]<<24)+(dataBuffer[1]<<16)+(dataBuffer[2]<<8)+dataBuffer[3];
        float data,data2;
        memcpy(&data,&dataBuffer[0],4);
        memcpy(&data2,&dataBuffer[4],4);
        printf("%d  %f\n",temp,data);
        double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
        ui->customPlot->graph(0)->addData(key, data);
        ui->customPlot->graph(0)->removeDataBefore(key-8);
        ui->customPlot->graph(0)->rescaleValueAxis();
        ui->customPlot->graph(1)->addData(key, data2);
        ui->customPlot->graph(1)->removeDataBefore(key-8);
        ui->customPlot->graph(1)->rescaleValueAxis();
        ui->customPlot->yAxis->setRange(2,-2);
        ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignCenter);
        ui->customPlot->replot();
        dataFlag = false;
    }
}

void streamForm::refreshData()
{
    /*static float i = 0;
    Data.push_back((0.025*sin(i/2)+0.05*sin(i)+0.1*sin(i*2)+0.2*sin(i*3)+0.4*sin(i*4)+0.8*sin(i*5)+0.8*sin(i*6)+
                   0.4*sin(i*7)+0.2*sin(i*8)+0.1*sin(i*9)+0.05*sin(i*10)+0.025*sin(i*11))/1.5);
    i+=0.1;*/
}

void streamForm::setupRealtimeDataDemo(void *p)
{
    QCustomPlot* customPlot = (QCustomPlot*)p;

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::GlobalColor::blue));
    customPlot->graph(0)->setName("temp");

    customPlot->addGraph(); // red line
    customPlot->graph(1)->setPen(QPen(Qt::GlobalColor::red));
    customPlot->graph(1)->setName("hui");
    //customPlot->graph(0)->setChannelFillGraph(customPlot->graph(1));

    QSharedPointer<QCPAxisTickerDateTime> dateTick(new QCPAxisTickerDateTime);
    dateTick->setDateTimeFormat("hh:mm:ss");
    ui->customPlot->xAxis->setTicker(dateTick);

    customPlot->legend->setVisible(true);


}

void streamForm::realtimeDataSlot()
{
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
    //使用随机数产生两条曲线
    double value0 = qrand() % 100;
    double value1 = qrand() % 80;
    //if (ui->checkBox_temp->isChecked())
        ui->customPlot->graph(0)->addData(key, value0);//添加数据1到曲线1
    //if (ui->checkBox_hui->isChecked())
        ui->customPlot->graph(1)->addData(key, value1);//添加数据2到曲线2
    //删除8秒之前的数据。这里的8要和下面设置横坐标宽度的8配合起来
    //才能起到想要的效果，可以调整这两个值，观察显示的效果。
    ui->customPlot->graph(0)->removeDataBefore(key-8);
    ui->customPlot->graph(1)->removeDataBefore(key-8);

      //自动设定graph(1)曲线y轴的范围，如果不设定，有可能看不到图像
    //也可以用ui->customPlot->yAxis->setRange(up,low)手动设定y轴范围
    ui->customPlot->yAxis->setRange(100,0);
    ui->customPlot->graph(0)->rescaleValueAxis();
    ui->customPlot->graph(1)->rescaleValueAxis(true);

    //这里的8，是指横坐标时间宽度为8秒，如果想要横坐标显示更多的时间
    //就把8调整为比较大到值，比如要显示60秒，那就改成60。
    //这时removeDataBefore(key-8)中的8也要改成60，否则曲线显示不完整。
    ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);//设定x轴的范围
    ui->customPlot->replot();
}
