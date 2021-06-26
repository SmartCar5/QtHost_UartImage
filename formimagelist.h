#ifndef FORMIMAGELIST_H
#define FORMIMAGELIST_H

#include <QWidget>
#include "image.h"
#include <QList>
#include <QTableWidgetItem>

namespace Ui {
class FormImageList;
class ImageVarList;
class ImageVar;
}
typedef enum iostatus
{
    READONLY,
    READWRITE
}IOSTATUS;
template<typename T>
class ImageVar{
public:
    ImageVar();
    ImageVar(T* data,QString name = "",IOSTATUS stat = READWRITE);
    void changeData(T src);
public:
    T data;
    T* dataPtr;
    T* ptr;
    QString name;
    IOSTATUS stat;
};

template<class T1>
class ImageVarList{
public:
    ImageVarList();
    //~ImageVarList();
public:
    QList<T1> list;
    uint length;
public:
    void attach(T1 data);
    T1 read(uint indx);
    T1 read(QString name);
    void change(uint indx,T1 data);
    void change(QString name,T1 data);
};

//template<typename T>
class FormImageList : public QWidget
{
    Q_OBJECT

public:
    explicit FormImageList(QWidget *parent = nullptr);
    ~FormImageList();
    void listInit();
private slots:
    void on_tableWidget_cellEntered(int row, int column);
    void refreshVars();

    void on_tableWidget_itemEntered(QTableWidgetItem *item);

private:
    Ui::FormImageList *ui;
};

#endif // FORMIMAGELIST_H
