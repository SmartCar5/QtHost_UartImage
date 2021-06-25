/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_pushButtonRefresh_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 20), // "serialPort_readyRead"
QT_MOC_LITERAL(4, 62, 20), // "serialPort_readImage"
QT_MOC_LITERAL(5, 83, 19), // "serialPort_readData"
QT_MOC_LITERAL(6, 103, 13), // "showSerialImg"
QT_MOC_LITERAL(7, 117, 13), // "timerCallBack"
QT_MOC_LITERAL(8, 131, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(9, 155, 31), // "on_pushButtonClrReceive_clicked"
QT_MOC_LITERAL(10, 187, 27), // "on_pushButtonLaunch_clicked"
QT_MOC_LITERAL(11, 215, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(12, 239, 30), // "on_pushButtonSaveImage_clicked"
QT_MOC_LITERAL(13, 270, 25), // "on_pushButtonStop_clicked"
QT_MOC_LITERAL(14, 296, 24), // "on_pushButtonFix_clicked"
QT_MOC_LITERAL(15, 321, 26), // "on_pushButtonTimer_clicked"
QT_MOC_LITERAL(16, 348, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0on_pushButtonRefresh_clicked\0"
    "\0serialPort_readyRead\0serialPort_readImage\0"
    "serialPort_readData\0showSerialImg\0"
    "timerCallBack\0on_pushButton_4_clicked\0"
    "on_pushButtonClrReceive_clicked\0"
    "on_pushButtonLaunch_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_pushButtonSaveImage_clicked\0"
    "on_pushButtonStop_clicked\0"
    "on_pushButtonFix_clicked\0"
    "on_pushButtonTimer_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonRefresh_clicked(); break;
        case 1: _t->serialPort_readyRead(); break;
        case 2: _t->serialPort_readImage(); break;
        case 3: _t->serialPort_readData(); break;
        case 4: _t->showSerialImg(); break;
        case 5: _t->timerCallBack(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButtonClrReceive_clicked(); break;
        case 8: _t->on_pushButtonLaunch_clicked(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButtonSaveImage_clicked(); break;
        case 11: _t->on_pushButtonStop_clicked(); break;
        case 12: _t->on_pushButtonFix_clicked(); break;
        case 13: _t->on_pushButtonTimer_clicked(); break;
        case 14: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
