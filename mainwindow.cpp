#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <qtimer.h>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "image.h"

uint8_t dataBuffer[40];
bool dataFlag;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uiInit();

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(showSerialImg()));
    pTimer->start(50);

    isSerialOpened = false;
    isDispImg = false;
    imgFlag = false;
    dataFlag = false;
    isSave = false;
    isStream = false;
    isTimerOn = false;

    nowReadSize = 0;
    nowFlag = 0;

    fullBuffer = &fullBuffer0[0][0];

    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

    on_pushButtonRefresh_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::uiInit()
{
    ui->comboBoxBaudRate->setEditable(true);
    ui->comboBoxDataBits->setEditable(false);
    ui->comboBoxParity->setEditable(false);
    ui->comboBoxSerialName->setEditable(false);
    ui->comboBoxStopBits->setEditable(false);
    ui->comboBoxStreamCtrl->setEditable(false);

    ui->comboBoxBaudRate->addItems(BaudRates);
    ui->comboBoxDataBits->addItems(DataBits);
    ui->comboBoxParity->addItems(Paritys);
    ui->comboBoxStopBits->addItems(StopBits);
    ui->comboBoxStreamCtrl->addItems(StreamCtrls);

    ui->tabData->setDisabled(true);
    ui->tabImage->setDisabled(true);
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    ui->comboBoxSerialName->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBoxSerialName->addItem(info.portName());
    }
}

void MainWindow::serialPort_readyRead()
{
    if(ui->tabWidget->currentIndex()==1)
    {
        if(!isStream)
        {
            //从接收缓冲区中读取数据
            QByteArray buffer = serial.readAll();
            //从界面中读取以前收到的数据
            //QString recv = ui->textEdit->toPlainText();
            //recv += QString(buffer.toHex());
            QString recv= QString(buffer.toHex());
            //清空以前的显示
            //ui->textEdit->clear();
            //重新显示
            ui->textEdit->append(recv);
        }
        else
        {
            serialPort_readData();
        }
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        serialPort_readImage();
    }
}
void MainWindow::serialPort_readData()
{
    if(isSerialOpened==false)
    {
        SerialBuffer.clear();
        nowReadSize = 0;
        nowFlag = 0;
        dataFlag = false;
    }
    if(nowFlag==0&&dataFlag==false)
    {
        memset(&dataBuffer[0],0,40);
        QByteArray buffer = serial.readAll();
        if(buffer.length()>=2&&(uint8_t)buffer.data()[0]==(uint8_t)3&&(uint8_t)buffer.data()[1]==(uint8_t)~3)
        {
            nowFlag = 1;
            for(int i = 2;i<buffer.length();i++)
            {
                //if(i<buffer.length()-3&&buffer.data()[i]==0x59&&buffer.data()[i+1]==0x59)
                //SerialBuffer.append(buffer.data()[i]);
                if(i<=buffer.length()-2&&buffer.data()[i]==0x59&&buffer.data()[i+1]==0x59)
                {
                    //buffer = serial.readAll();
                    memcpy(&dataBuffer[0],SerialBuffer.data(),SerialBuffer.length());
                    SerialBuffer.clear();
                    nowFlag = 0;
                    dataFlag = true;
                    break;
                    //nowFlag = 2;
                }
                SerialBuffer.append(buffer.data()[i]);
            }
        }
    }
    else if(nowFlag==1)
    {
        QByteArray buffer = serial.readAll();
        for(int i = 0;i<buffer.length();i++)
        {
            //if(i<buffer.length()-3&&buffer.data()[i]==0x59&&buffer.data()[i+1]==0x59)
            //SerialBuffer.append(buffer.data()[i]);
            if(i<=buffer.length()-2&&buffer.data()[i]==0x59&&buffer.data()[i+1]==0x59)
            {
                //buffer = serial.readAll();
                memcpy(&dataBuffer[0],SerialBuffer.data(),40);
                SerialBuffer.clear();
                nowFlag = 0;
                dataFlag = true;
                break;
                //nowFlag = 2;
            }
            SerialBuffer.append(buffer.data()[i]);
        }

    }
}
void MainWindow::serialPort_readImage()
{
    if(isSerialOpened==false)
    {
        SerialBuffer.clear();
        nowReadSize = 0;
        nowFlag = 0;
        imgFlag = false;
    }
    if(nowFlag==0&&imgFlag==false)
    {
        QByteArray buffer = serial.readAll();
        if(buffer.length()>=2&&(uint8_t)buffer.data()[0]==(uint8_t)3&&(uint8_t)buffer.data()[1]==(uint8_t)~3)
        {
            /*SerialBuffer.append(&buffer.data()[2]);
            nowReadSize+=(buffer.length()-2);
            nowFlag = 1;*/
            nowFlag = 1;
            for(int i = 2;i<buffer.length();i++)
            {
                SerialBuffer.append(buffer.data()[i]);
                nowReadSize++;
                if(nowReadSize>=readBufferSize)
                {
                    buffer = serial.readAll();
                    memcpy(&fullBuffer0[0][0],SerialBuffer.data(),120*188);
                    SerialBuffer.clear();
                    nowFlag = 0;
                    nowReadSize = 0;
                    imgFlag = true;
                    break;
                    //nowFlag = 2;
                }
            }
            //nowFlag = 1;
        }
    }
    else if(nowFlag==1)
    {
        QByteArray buffer = serial.readAll();
        for(int i = 0;i<buffer.length();i++)
        {
            SerialBuffer.append(buffer.data()[i]);
            nowReadSize++;
            if(nowReadSize>=readBufferSize)
            {
                buffer = serial.readAll();
                memcpy(&fullBuffer0[0][0],SerialBuffer.data(),120*188);
                SerialBuffer.clear();
                nowFlag = 0;
                nowReadSize = 0;
                imgFlag = true;
                break;
                //nowFlag = 2;
            }
        }
    }
}

void MainWindow::showSerialImg()
{
    if(imgFlag==true)
    {
        if(isSave==true)
        {
            static int num = 0;
            QImage img = QImage(&fullBuffer0[0][0],188,120,QImage::Format_Grayscale8);
            if(img.save(path+QString("\\%1.jpg").arg(num)))
            {
                num++;
            }
        }
        if(ui->radioButtonIsFlep->isChecked())
        {
            QImage img = QImage(&fullBuffer0[0][0],188,120,QImage::Format_Grayscale8);
            img = img.mirrored(true,true);
            QPixmap map = QPixmap::fromImage(img);
            ui->label->setPixmap(map.scaled(ui->label->size()));
        }
        else if(ui->radioButtonIsImageMain->isChecked())
        {
            image_main(0);
            QImage Image_Done = QImage(188,120,QImage::Format_BGR888);
            for(int i = 0; i<Image_Done.width(); i++){
                for(int j = 0; j<Image_Done.height(); j++){
                    /*-------------------------------------------------------IMG为处理过的图像的数组名-------------------------------------------------------*/
                    switch (IMG[j][i]) {
                    case 255: Image_Done.setPixel(i,j,qRgb(0xff,0xff,0xff));break;//white
                    case 0: Image_Done.setPixel(i,j,qRgb(0,0,0));break;
                    case 1: Image_Done.setPixel(i,j,qRgb(0xff,0xff,0xff));break;//white
                    case 2: Image_Done.setPixel(i,j,qRgb(0,0,0xff));break;//blue
                    case 3: Image_Done.setPixel(i,j,qRgb(0,0xff,0));break;//green
                    case 4: Image_Done.setPixel(i,j,qRgb(0xff,0,0));break;//red
                    case 5: Image_Done.setPixel(i,j,qRgb(0xa0,0xa0,0xa4));break;//gray
                    case 6: Image_Done.setPixel(i,j,qRgb(0xff,0,0xff));break;//magenta
                    }
                    Image_Done.setPixel(94,j,qRgb(0xAF,0XAF,0xAF));
                }
            }
            QPixmap map = QPixmap::fromImage(Image_Done);
            ui->label->setPixmap(map.scaled(ui->label->size()));
        }
        else
        {
            QImage img = QImage(&fullBuffer0[0][0],188,120,QImage::Format_Grayscale8);
            QPixmap map = QPixmap::fromImage(img);
            ui->label->setPixmap(map.scaled(ui->label->size()));
        }
        imgFlag = false;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(isSerialOpened == false)
    {
        QString portName = ui->comboBoxSerialName->currentText();
        qint32 baudRate = (ui->comboBoxBaudRate->currentText()).toInt();
        qint32 databits = (ui->comboBoxDataBits->currentText()).toInt();
        qint32 parity = ui->comboBoxParity->currentIndex();
        qint32 stopbit = ui->comboBoxStopBits->currentIndex();
        qint32 streamctrl = ui->comboBoxStreamCtrl->currentIndex();
        if(portName.isEmpty())
        {
           QMessageBox msg(this);
           msg.about(NULL,"INFO","ERROR INPUT (portName invalid)");
           //msg.exec();
        }
        if(baudRate<50||baudRate>11520000)
        {
            QMessageBox msg(this);
            msg.about(NULL,"INFO","ERROR INPUT (baudRate invalid)");
            //msg.exec();
        }
        //设置串口名
        serial.setPortName(portName);
        //设置波特率
        serial.setBaudRate(baudRate);
        //设置数据位数
        switch (databits)
        {
        case 5:
        {
            serial.setDataBits(QSerialPort::Data5);
            break;
        }
        case 6:
        {
            serial.setDataBits(QSerialPort::Data6);
            break;
        }
        case 7:
        {
            serial.setDataBits(QSerialPort::Data7);
            break;
        }
        case 8:
        {
            serial.setDataBits(QSerialPort::Data8);
            break;
        }
        default:
        {
            serial.setDataBits(QSerialPort::UnknownDataBits);
            break;
        }
        }
        //设置奇偶校验
        switch (parity)
        {
        case 0:
        {
            serial.setParity(QSerialPort::NoParity);
            break;
        }
        case 1:
        {
            serial.setParity(QSerialPort::EvenParity);
            break;
        }
        case 2:
        {
            serial.setParity(QSerialPort::OddParity);
            break;
        }
        case 3:
        {
            serial.setParity(QSerialPort::MarkParity);
            break;
        }
        case 4:
        {
            serial.setParity(QSerialPort::SpaceParity);
            break;
        }
        default:
        {
            serial.setParity(QSerialPort::UnknownParity);
            break;
        }
        }
        //设置停止位
        switch(stopbit)
        {
        case 0:
        {
            serial.setStopBits(QSerialPort::OneStop);
            break;
        }
        case 1:
        {
            serial.setStopBits(QSerialPort::OneAndHalfStop);
            break;
        }
        case 2:
        {
            serial.setStopBits(QSerialPort::TwoStop);
            break;
        }
        default:
        {
            serial.setStopBits(QSerialPort::UnknownStopBits);
            break;
        }
        }
        //设置流控制
        switch (streamctrl)
        {
        case 0:
        {
            serial.setFlowControl(QSerialPort::NoFlowControl);
            break;
        }
        case 1:
        {
            serial.setFlowControl(QSerialPort::HardwareControl);
            break;
        }
        case 2:
        {
            serial.setFlowControl(QSerialPort::SoftwareControl);
            break;
        }
        default:
        {
            serial.setFlowControl(QSerialPort::UnknownFlowControl);
            break;
        }
        }

        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox msg(this);
            msg.about(NULL,"INFO","error accured when opening port");
            //msg.exec();
            return;
        }
        ui->pushButton_4->setText("关闭");
        ui->pushButtonStop->setText("暂停");
        ui->tabData->setEnabled(true);
        ui->tabImage->setEnabled(true);
        isSerialOpened = true;
        SerialBuffer.clear();
        nowReadSize = 0;
        nowFlag = 0;
        imgFlag = false;
    }
    else
    {
        serial.close();
        ui->pushButton_4->setText("继续");
        ui->tabData->setEnabled(false);
        ui->pushButtonStop->setText("继续");
        isSerialOpened = false;
        SerialBuffer.clear();
        nowReadSize = 0;
        nowFlag = 0;
        imgFlag = false;
    }
}

void MainWindow::on_pushButtonClrReceive_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButtonLaunch_clicked()
{
    QByteArray data = ui->textEditLaunch->toPlainText().toUtf8();
    serial.write(data);
    ui->textEditLaunch->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEditLaunch->clear();
}

void MainWindow::on_pushButtonSaveImage_clicked()
{
    if(isSave == true)
    {
        isSave = false;
    }
    else
    {
        path = QFileDialog::getExistingDirectory(this, "choose src Directory","D:\\CODE\\");
        isSave = true;
    }
}

void MainWindow::on_pushButtonStop_clicked()
{
    on_pushButton_4_clicked();
}

void MainWindow::on_pushButtonFix_clicked()
{
    static FormImageList form;
    form.show();
}

void MainWindow::on_pushButtonTimer_clicked()
{
    static uint click_times = 0;
    static QTimer* cTimer = new QTimer(this);
    click_times++;
    if(click_times==1)
    {
        connect(cTimer, SIGNAL(timeout()), this, SLOT(timerCallBack()));
        cTimer->start(50);
        ui->pushButtonTimer->setText("暂停");
        isTimerOn = true;
    }
    else if(click_times%3==1)
    {
        cTimer->start(50);
        ui->pushButtonTimer->setText("暂停");
        isTimerOn = true;
    }
    else if(click_times%3==2)
    {
        cTimer->stop();
        ui->pushButtonTimer->setText("停止");
        isTimerOn = false;
        time_ms = 0;
        //ui->lcdNumberTimer->display(0);
    }
    else if(click_times%3==0)
    {
        time_ms = 0;
        ui->pushButtonTimer->setText("发车计时");
        ui->lcdNumberTimer->display(0);
    }
}
void MainWindow::timerCallBack()
{
    if(isTimerOn)
    {
        time_ms++;
        ui->lcdNumberTimer->display(time_ms*50.0/1000.0);
    }
}

//void MainWindow::on_pushButton_clicked()
//{
//    isStream = !isStream;
//}

void MainWindow::on_pushButtonStream_clicked()
{
    isStream = !isStream;
    static streamForm S;
    S.show();
}
