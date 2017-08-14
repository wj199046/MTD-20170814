/****************************************************************************
** Meta object code from reading C++ file 'splitscreenlabelwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../splitscreenlabelwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splitscreenlabelwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SplitScreenLabelWidget_t {
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SplitScreenLabelWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SplitScreenLabelWidget_t qt_meta_stringdata_SplitScreenLabelWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SplitScreenLabelWidget"
QT_MOC_LITERAL(1, 23, 21), // "signalSendPrintScreen"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 12), // "captureimage"
QT_MOC_LITERAL(4, 59, 11), // "splitScreen"
QT_MOC_LITERAL(5, 71, 5), // "count"
QT_MOC_LITERAL(6, 77, 14), // "receivePicture"
QT_MOC_LITERAL(7, 92, 8), // "QPixmap&"
QT_MOC_LITERAL(8, 101, 6), // "pixmap"
QT_MOC_LITERAL(9, 108, 11), // "columnIndex"
QT_MOC_LITERAL(10, 120, 9), // "getColumn"
QT_MOC_LITERAL(11, 130, 5), // "index"
QT_MOC_LITERAL(12, 136, 19) // "slotCompleteCapture"

    },
    "SplitScreenLabelWidget\0signalSendPrintScreen\0"
    "\0captureimage\0splitScreen\0count\0"
    "receivePicture\0QPixmap&\0pixmap\0"
    "columnIndex\0getColumn\0index\0"
    "slotCompleteCapture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplitScreenLabelWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       6,    2,   45,    2, 0x08 /* Private */,
      10,    1,   50,    2, 0x08 /* Private */,
      12,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QPixmap,    3,

       0        // eod
};

void SplitScreenLabelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SplitScreenLabelWidget *_t = static_cast<SplitScreenLabelWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendPrintScreen((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->splitScreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->receivePicture((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->getColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotCompleteCapture((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SplitScreenLabelWidget::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SplitScreenLabelWidget::signalSendPrintScreen)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SplitScreenLabelWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SplitScreenLabelWidget.data,
      qt_meta_data_SplitScreenLabelWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SplitScreenLabelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplitScreenLabelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SplitScreenLabelWidget.stringdata0))
        return static_cast<void*>(const_cast< SplitScreenLabelWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SplitScreenLabelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SplitScreenLabelWidget::signalSendPrintScreen(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
