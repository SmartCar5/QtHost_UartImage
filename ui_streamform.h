/********************************************************************************
** Form generated from reading UI file 'streamform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMFORM_H
#define UI_STREAMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_streamForm
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *streamForm)
    {
        if (streamForm->objectName().isEmpty())
            streamForm->setObjectName(QString::fromUtf8("streamForm"));
        streamForm->resize(400, 300);
        textEdit = new QTextEdit(streamForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(streamForm);

        QMetaObject::connectSlotsByName(streamForm);
    } // setupUi

    void retranslateUi(QWidget *streamForm)
    {
        streamForm->setWindowTitle(QCoreApplication::translate("streamForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class streamForm: public Ui_streamForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMFORM_H
