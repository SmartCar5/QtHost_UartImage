#ifndef STREAMFORM_H
#define STREAMFORM_H

#include <QWidget>

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

private slots:
    void showData();
};

#endif // STREAMFORM_H
