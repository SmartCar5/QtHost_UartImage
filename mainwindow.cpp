#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <qtimer.h>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "image.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(showSerialImg()));
    pTimer->start(50);

    isSerialOpened = false;
    isDispImg = false;
    imgFlag = false;

    fullBuffer = &fullBuffer0[0][0];

    on_pushButton_4_clicked();

    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);
    //QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyReadImg);

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->label_3->setVisible(false);
    ui->radioButton->setChecked(true);
    //qDebug("%lld",serial.bytesAvailable());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showSerialImg(void)
{
    if(imgFlag == true)
    {
        if(ui->checkBox->isChecked())
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
                }
            }
            QPixmap map = QPixmap::fromImage(Image_Done);
            ui->label_3->setPixmap(map.scaled(ui->label_3->size()));
            ui->textEdit_2->clear();
            ui->textEdit_2->append("curtState:"+QString("%1").arg(stateMgr.curtState)+"\n");
            //ui->textEdit_2->append("image_angle:"+QString("%1").arg(image_angle)+"\n");
        }
        else
        {
            QImage img = QImage(&fullBuffer0[0][0],188,120,QImage::Format_Grayscale8);
            QPixmap map = QPixmap::fromImage(img);
            ui->label_3->setPixmap(map.scaled(ui->label_3->size()));
        }
        if(ui->checkBox_2->isChecked())
        {
            static int num = 0;
            QImage img = QImage(&fullBuffer0[0][0],188,120,QImage::Format_Grayscale8);
            if(img.save(path+QString("%1.jpg").arg(num)))
            {
                num++;
            }
        }
        imgFlag = false;
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(isSerialOpened == false)
    {
        QString portName = ui->comboBox->currentText();
        qint32 baudRate = (ui->lineEditBPS->text()).toInt();
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
        serial.setDataBits(QSerialPort::Data8);
        //设置奇偶校验
        serial.setParity(QSerialPort::NoParity);
        //设置停止位
        serial.setStopBits(QSerialPort::OneStop);
        //设置流控制
        serial.setFlowControl(QSerialPort::NoFlowControl);
        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox msg(this);
            msg.about(NULL,"INFO","error accured when opening port");
            //msg.exec();
            return;
        }

        ui->pushButton->setText("关闭");
        isSerialOpened = true;
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->textEdit_2->setEnabled(true);
        form.show();
    }
    else
    {
        serial.close();
        ui->pushButton->setText("继续");
        isSerialOpened = false;
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->textEdit_2->setEnabled(false);
        form.hide();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->comboBox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox->addItem(info.portName());
    }
}

void MainWindow::serialPort_readyRead()
{
    if(!isDispImg)
    {
        //从接收缓冲区中读取数据
        QByteArray buffer = serial.readAll();
        //从界面中读取以前收到的数据
        QString recv = ui->textEdit->toPlainText();
        recv += QString(buffer.toHex());
        //清空以前的显示
        ui->textEdit->clear();
        //重新显示
        ui->textEdit->append(recv);
    }
    else
    {
        serialPort_readyReadImg();
    }
}

void MainWindow::serialPort_readyReadImg()
{
    int readBufferSize = 120*188;
    static int nowReadSize = 0;
    static int nowFlag = 0;
    if(nowFlag==0)
    {
        QByteArray buffer = serial.readAll();
        if((uint8_t)buffer.data()[0]==(uint8_t)3&&(uint8_t)buffer.data()[1]==(uint8_t)~3)
        {
            SerialBuffer.append(&buffer.data()[2]);
            nowReadSize+=(buffer.length()-2);
            nowFlag = 1;
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
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray data = ui->textEdit_2->toPlainText().toUtf8();
    serial.write(data);
    ui->textEdit_2->clear();
}

void MainWindow::on_radioButton_clicked()
{
    isDispImg = false;
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    if(isSerialOpened==true)
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}

void MainWindow::on_radioButton_2_clicked()
{
    isDispImg = true;
    ui->label_3->setVisible(true);
    ui->textEdit->setVisible(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    //ui->textEdit_2->setVisible(false);
}

void MainWindow::on_checkBox_2_clicked()
{
    path = QFileDialog::getExistingDirectory(this, "choose src Directory","D:\\CODE\\");
}
