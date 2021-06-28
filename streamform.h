#ifndef STREAMFORM_H
#define STREAMFORM_H

#include <QWidget>
#include <QTimer>
//#include "qcustomplot.h"
#include <QRandomGenerator>
//using namespace cv;
using namespace std;
namespace Ui {
class streamForm;
}

class streamForm : public QWidget
{
    Q_OBJECT

public:
    explicit streamForm(QWidget *parent = nullptr);
    ~streamForm();

private:
    Ui::streamForm *ui;
    QByteArray data;
    QTimer dataTimer;
public:
    void setupRealtimeDataDemo(void *customPlot);
private slots:
    //void showFrame();
    void refreshData();
    void realtimeDataSlot();

private slots:
    void showData();
};

#endif // STREAMFORM_H
