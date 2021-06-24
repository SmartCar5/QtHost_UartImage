/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableView *tableViewReadOnly;
    QTableView *tableViewReadWrite;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(725, 529);
        tableViewReadOnly = new QTableView(Form);
        tableViewReadOnly->setObjectName(QString::fromUtf8("tableViewReadOnly"));
        tableViewReadOnly->setGeometry(QRect(30, 10, 291, 501));
        tableViewReadWrite = new QTableView(Form);
        tableViewReadWrite->setObjectName(QString::fromUtf8("tableViewReadWrite"));
        tableViewReadWrite->setGeometry(QRect(370, 10, 311, 501));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
