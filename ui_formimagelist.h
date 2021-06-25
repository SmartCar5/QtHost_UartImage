/********************************************************************************
** Form generated from reading UI file 'formimagelist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMAGELIST_H
#define UI_FORMIMAGELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormImageList
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *FormImageList)
    {
        if (FormImageList->objectName().isEmpty())
            FormImageList->setObjectName(QString::fromUtf8("FormImageList"));
        FormImageList->resize(645, 563);
        tableWidget = new QTableWidget(FormImageList);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 621, 541));

        retranslateUi(FormImageList);

        QMetaObject::connectSlotsByName(FormImageList);
    } // setupUi

    void retranslateUi(QWidget *FormImageList)
    {
        FormImageList->setWindowTitle(QCoreApplication::translate("FormImageList", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormImageList: public Ui_FormImageList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMAGELIST_H
