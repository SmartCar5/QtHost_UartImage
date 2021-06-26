#include "streamform.h"
#include "ui_streamform.h"
#include "mainwindow.h"
#include <qtimer.h>
#include <QString>
#include <QByteArray>

extern uint8_t dataBuffer[40];

streamForm::streamForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::streamForm)
{
    ui->setupUi(this);
    //data.setNum(40);
    QTimer* pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(showData()));
    pTimer->start(1000);
}

streamForm::~streamForm()
{
    delete ui;
}

void streamForm::showData()
{
    for(int i = 0;i<40;i++)
    {
        data.append(dataBuffer[i]);
    }
    ui->textEdit->append(QString(data.toHex()));
    data.clear();
}
