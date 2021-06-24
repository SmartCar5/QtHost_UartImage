#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool initSerialPort();
    //bool openSerial(QString COM);
    bool closeSerial(QString COM);
    bool getSerialBuffer(void);
    QStringList serialPorts;
    QSerialPort serial;
    uint8_t fullBuffer0[120][188];
    QString path;
    QByteArray SerialBuffer;
    Form form;
private:
    Ui::MainWindow *ui;
    bool isSerialOpened;
    bool isDispImg;
    bool imgFlag;
private slots:
    void showSerialImg(void);
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void serialPort_readyRead();
    void serialPort_readyReadImg();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_checkBox_2_clicked();
};

#endif // MAINWINDOW_H
