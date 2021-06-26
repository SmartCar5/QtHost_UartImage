#include "formimagelist.h"
#include "ui_formimagelist.h"
#include <stdio.h>
#include <QList>
#include <tuple>
#include <QTimer>
#include "image.h"

extern float image_threUpFix;
extern float image_threDownFix;
extern stateMgr_t stateMgr;

ImageVarList<ImageVar<int>> intList;
ImageVarList<ImageVar<float>> floatList;

template<typename T>
ImageVar<T>::ImageVar(void)
{

}
template<typename T>
ImageVar<T>::ImageVar(T* pdata,QString sname,IOSTATUS sstat)
{
    ptr = pdata;
    data = *pdata;
    dataPtr = &data;
    name = sname;
    stat = sstat;
}
template<typename T>
void ImageVar<T>::changeData(T src)
{
    data = src;
    *ptr = src;
}
template<typename T1>
ImageVarList<T1>::ImageVarList()
{
    length = 0;
}
template<typename T1>
void ImageVarList<T1>::attach(T1 data)
{
    list.push_back(data);
    length++;
}
template<typename T1>
T1 ImageVarList<T1>::read(uint indx)
{
    return list[indx];
}
template<typename T1>
T1 ImageVarList<T1>::read(QString name)
{
    for(int i = 0;i<length;i++)
    {
        if(!strcmp(name,list.takeAt(i).name))
        {
            return list[i];
        }
    }
}
template<typename T1>
void ImageVarList<T1>::change(uint indx,T1 data)
{
    list.replace(indx,data);
}
template<typename T1>
void ImageVarList<T1>::change(QString name,T1 data)
{
    for(int i = 0;i<length;i++)
    {
        if(!strcmp(name,list.takeAt(i).name))
        {
            list.replace(i,data);
        }
    }
}

FormImageList::FormImageList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormImageList)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Value");
    ui->tableWidget->setColumnWidth(0,250);
    ui->tableWidget->setColumnWidth(1,250);

    listInit();

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(refreshVars()));
    pTimer->start(500);


}

FormImageList::~FormImageList()
{
    delete ui;
}

void FormImageList::listInit()
{
    //添加整形变量
    ImageVar<int> curStat((int*)&stateMgr.curtState,"curtState",READWRITE);
    ImageVar<int> lastStat((int*)&stateMgr.lastState,"lastState",READWRITE);
    //添加浮点型变量
    ImageVar<float> threUpFix(&image_threUpFix,"image_threUpFix",READWRITE);
    ImageVar<float> threDownFix(&image_threDownFix,"image_threDownFix",READWRITE);
    //整形变量链接
    intList.attach(curStat);
    intList.attach(lastStat);
    //浮点数变量链接
    floatList.attach(threUpFix);
    floatList.attach(threDownFix);

    ui->tableWidget->setRowCount(floatList.length+intList.length);//设置行数
    uint i = 0;
    for(i = 0;i<intList.length;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(intList.read(i).name));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString("%1").arg(intList.read(i).data)));
    }
    for(i=0;i<floatList.length;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i+intList.length,col++,new QTableWidgetItem(floatList.read(i).name));
        ui->tableWidget->setItem(i+intList.length,col++,new QTableWidgetItem(QString("%1").arg(floatList.read(i).data)));
    }
}
void FormImageList::refreshVars()
{
    uint i = 0;
    for(i = 0;i<intList.length;i++)
    {
        if(intList.read(i).stat==READONLY)
        {
            intList.read(i).changeData(*intList.read(i).ptr);
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString("%1").arg(intList.read(i).data)));
        }
        else
        {
            //intList.read(i).changeData(*intList.read(i).ptr);
            *(intList.read(i).dataPtr) = *intList.read(i).ptr;
            if((uint)ui->tableWidget->currentRow()!=i)
            {
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString("%1").arg(intList.read(i).data)));
            }
        }
    }
    for(i=0;i<floatList.length;i++)
    {
        if(floatList.read(i).stat==READONLY)
        {
            floatList.read(i).changeData(*floatList.read(i).ptr);
            ui->tableWidget->setItem(i+intList.length,1,new QTableWidgetItem(QString("%1").arg(floatList.read(i).data)));
        }
        else
        {
            //floatList.read(i).changeData(*floatList.read(i).ptr);
            *(floatList.read(i).dataPtr) = *floatList.read(i).ptr;
            if((uint)ui->tableWidget->currentRow()!=i+intList.length)
            {
                ui->tableWidget->setItem(i+intList.length,1,new QTableWidgetItem(QString("%1").arg(floatList.read(i).data)));
            }
        }
    }
}

void FormImageList::on_tableWidget_cellEntered(int row, int column)
{
    if(column==0)
    {
        return ;
    }
    if((uint)row>intList.length)
    {
        int temp = ui->tableWidget->item(row,column)->text().toInt();
        intList.read(row).changeData(temp);
    }
    else
    {
        int temp = ui->tableWidget->item(row,column)->text().toFloat();
        floatList.read(row-intList.length).changeData(temp);
    }
}

void FormImageList::on_tableWidget_itemEntered(QTableWidgetItem *item)
{
    if(item->column() == 0)
    {
        return;
    }
    if((uint)item->row()>intList.length)
    {
        int temp = item->text().toFloat();
        floatList.read(item->row()-intList.length).changeData(temp);
    }
    else
    {
        int temp = item->text().toInt();
        intList.read(item->row()).changeData(temp);
    }
}
