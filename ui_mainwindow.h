/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabSerial;
    QGroupBox *groupBoxNow;
    QLabel *labelSerialName;
    QComboBox *comboBoxSerialName;
    QLabel *labelBaudRate;
    QComboBox *comboBoxBaudRate;
    QLabel *labelDataBits;
    QComboBox *comboBoxDataBits;
    QLabel *labelParity;
    QComboBox *comboBoxParity;
    QLabel *labelStopBits;
    QComboBox *comboBoxStopBits;
    QLabel *labelStreamCtrl;
    QComboBox *comboBoxStreamCtrl;
    QProgressBar *progressBar;
    QPushButton *pushButtonReadDefault;
    QPushButton *pushButtonWriteDefault;
    QPushButton *pushButtonRefresh;
    QPushButton *pushButton_4;
    QGroupBox *groupBoxDefault;
    QWidget *tabData;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QGroupBox *groupBox_3;
    QTextEdit *textEditLaunch;
    QPushButton *pushButtonClrReceive;
    QPushButton *pushButton_3;
    QPushButton *pushButtonLaunch;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonTimer;
    QLCDNumber *lcdNumberTimer;
    QPushButton *pushButton;
    QWidget *tabImage;
    QGroupBox *groupBox_5;
    QLabel *label;
    QRadioButton *radioButtonIsFlep;
    QRadioButton *radioButtonIsImageMain;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonSaveImage;
    QPushButton *pushButtonFix;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 781, 551));
        tabSerial = new QWidget();
        tabSerial->setObjectName(QString::fromUtf8("tabSerial"));
        groupBoxNow = new QGroupBox(tabSerial);
        groupBoxNow->setObjectName(QString::fromUtf8("groupBoxNow"));
        groupBoxNow->setGeometry(QRect(10, 0, 331, 511));
        labelSerialName = new QLabel(groupBoxNow);
        labelSerialName->setObjectName(QString::fromUtf8("labelSerialName"));
        labelSerialName->setGeometry(QRect(10, 30, 72, 15));
        comboBoxSerialName = new QComboBox(groupBoxNow);
        comboBoxSerialName->setObjectName(QString::fromUtf8("comboBoxSerialName"));
        comboBoxSerialName->setGeometry(QRect(80, 30, 131, 22));
        labelBaudRate = new QLabel(groupBoxNow);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        labelBaudRate->setGeometry(QRect(10, 70, 72, 15));
        comboBoxBaudRate = new QComboBox(groupBoxNow);
        comboBoxBaudRate->setObjectName(QString::fromUtf8("comboBoxBaudRate"));
        comboBoxBaudRate->setGeometry(QRect(80, 70, 131, 22));
        labelDataBits = new QLabel(groupBoxNow);
        labelDataBits->setObjectName(QString::fromUtf8("labelDataBits"));
        labelDataBits->setGeometry(QRect(10, 110, 72, 15));
        comboBoxDataBits = new QComboBox(groupBoxNow);
        comboBoxDataBits->setObjectName(QString::fromUtf8("comboBoxDataBits"));
        comboBoxDataBits->setGeometry(QRect(80, 110, 131, 22));
        labelParity = new QLabel(groupBoxNow);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setGeometry(QRect(10, 150, 72, 15));
        comboBoxParity = new QComboBox(groupBoxNow);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        comboBoxParity->setGeometry(QRect(80, 150, 131, 22));
        labelStopBits = new QLabel(groupBoxNow);
        labelStopBits->setObjectName(QString::fromUtf8("labelStopBits"));
        labelStopBits->setGeometry(QRect(10, 190, 72, 15));
        comboBoxStopBits = new QComboBox(groupBoxNow);
        comboBoxStopBits->setObjectName(QString::fromUtf8("comboBoxStopBits"));
        comboBoxStopBits->setGeometry(QRect(80, 190, 131, 22));
        labelStreamCtrl = new QLabel(groupBoxNow);
        labelStreamCtrl->setObjectName(QString::fromUtf8("labelStreamCtrl"));
        labelStreamCtrl->setGeometry(QRect(10, 230, 72, 15));
        comboBoxStreamCtrl = new QComboBox(groupBoxNow);
        comboBoxStreamCtrl->setObjectName(QString::fromUtf8("comboBoxStreamCtrl"));
        comboBoxStreamCtrl->setGeometry(QRect(80, 230, 131, 22));
        progressBar = new QProgressBar(groupBoxNow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 480, 311, 23));
        progressBar->setValue(0);
        pushButtonReadDefault = new QPushButton(groupBoxNow);
        pushButtonReadDefault->setObjectName(QString::fromUtf8("pushButtonReadDefault"));
        pushButtonReadDefault->setGeometry(QRect(10, 270, 101, 28));
        pushButtonWriteDefault = new QPushButton(groupBoxNow);
        pushButtonWriteDefault->setObjectName(QString::fromUtf8("pushButtonWriteDefault"));
        pushButtonWriteDefault->setGeometry(QRect(160, 270, 101, 28));
        pushButtonRefresh = new QPushButton(groupBoxNow);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        pushButtonRefresh->setGeometry(QRect(10, 320, 101, 28));
        pushButton_4 = new QPushButton(groupBoxNow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(160, 320, 101, 28));
        groupBoxDefault = new QGroupBox(tabSerial);
        groupBoxDefault->setObjectName(QString::fromUtf8("groupBoxDefault"));
        groupBoxDefault->setGeometry(QRect(360, 0, 401, 511));
        tabWidget->addTab(tabSerial, QString());
        tabData = new QWidget();
        tabData->setObjectName(QString::fromUtf8("tabData"));
        groupBox = new QGroupBox(tabData);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 481, 521));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 461, 311));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 441, 281));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 340, 461, 111));
        textEditLaunch = new QTextEdit(groupBox_3);
        textEditLaunch->setObjectName(QString::fromUtf8("textEditLaunch"));
        textEditLaunch->setGeometry(QRect(10, 20, 441, 81));
        pushButtonClrReceive = new QPushButton(groupBox);
        pushButtonClrReceive->setObjectName(QString::fromUtf8("pushButtonClrReceive"));
        pushButtonClrReceive->setGeometry(QRect(20, 470, 93, 28));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(370, 470, 93, 28));
        pushButtonLaunch = new QPushButton(groupBox);
        pushButtonLaunch->setObjectName(QString::fromUtf8("pushButtonLaunch"));
        pushButtonLaunch->setGeometry(QRect(190, 470, 93, 28));
        groupBox_4 = new QGroupBox(tabData);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(490, 0, 281, 521));
        pushButtonTimer = new QPushButton(groupBox_4);
        pushButtonTimer->setObjectName(QString::fromUtf8("pushButtonTimer"));
        pushButtonTimer->setGeometry(QRect(10, 20, 93, 28));
        lcdNumberTimer = new QLCDNumber(groupBox_4);
        lcdNumberTimer->setObjectName(QString::fromUtf8("lcdNumberTimer"));
        lcdNumberTimer->setGeometry(QRect(150, 10, 101, 41));
        lcdNumberTimer->setSmallDecimalPoint(false);
        lcdNumberTimer->setDigitCount(5);
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 60, 93, 28));
        tabWidget->addTab(tabData, QString());
        tabImage = new QWidget();
        tabImage->setObjectName(QString::fromUtf8("tabImage"));
        groupBox_5 = new QGroupBox(tabImage);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 0, 771, 471));
        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 751, 441));
        label->setAutoFillBackground(false);
        radioButtonIsFlep = new QRadioButton(tabImage);
        radioButtonIsFlep->setObjectName(QString::fromUtf8("radioButtonIsFlep"));
        radioButtonIsFlep->setGeometry(QRect(10, 490, 115, 19));
        radioButtonIsImageMain = new QRadioButton(tabImage);
        radioButtonIsImageMain->setObjectName(QString::fromUtf8("radioButtonIsImageMain"));
        radioButtonIsImageMain->setGeometry(QRect(150, 490, 115, 19));
        pushButtonStop = new QPushButton(tabImage);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(670, 480, 93, 28));
        pushButtonSaveImage = new QPushButton(tabImage);
        pushButtonSaveImage->setObjectName(QString::fromUtf8("pushButtonSaveImage"));
        pushButtonSaveImage->setGeometry(QRect(280, 480, 93, 28));
        pushButtonFix = new QPushButton(tabImage);
        pushButtonFix->setObjectName(QString::fromUtf8("pushButtonFix"));
        pushButtonFix->setGeometry(QRect(390, 480, 93, 28));
        tabWidget->addTab(tabImage, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\212\344\275\215\346\234\272-V0.1.1", nullptr));
        groupBoxNow->setTitle(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\205\215\347\275\256", nullptr));
        labelSerialName->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        labelBaudRate->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        labelDataBits->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\346\225\260", nullptr));
        labelParity->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        labelStopBits->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        labelStreamCtrl->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\216\247", nullptr));
        pushButtonReadDefault->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\351\273\230\350\256\244\351\205\215\347\275\256", nullptr));
        pushButtonWriteDefault->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\351\273\230\350\256\244\351\205\215\347\275\256", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBoxDefault->setTitle(QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\351\205\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSerial), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\216\245\345\217\227", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\345\214\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        pushButtonClrReceive->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\345\217\227\345\214\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        pushButtonLaunch->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\351\242\204\347\225\231\345\212\237\350\203\275", nullptr));
        pushButtonTimer->setText(QCoreApplication::translate("MainWindow", "\345\217\221\350\275\246\350\256\241\346\227\266", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\250\241\345\274\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabData), QCoreApplication::translate("MainWindow", "\344\274\240\346\225\260\346\215\256", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        label->setText(QString());
        radioButtonIsFlep->setText(QCoreApplication::translate("MainWindow", "\347\277\273\350\275\254\345\233\276\345\203\217", nullptr));
        radioButtonIsImageMain->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButtonSaveImage->setText(QCoreApplication::translate("MainWindow", "\351\207\207\345\233\276", nullptr));
        pushButtonFix->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\346\230\276\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabImage), QCoreApplication::translate("MainWindow", "\344\274\240\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
