/****************************************************************************
** Meta object code from reading C++ file 'savepicturewidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../savepicturewidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savepicturewidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_savePictureWidgets_t {
    QByteArrayData data[6];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_savePictureWidgets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_savePictureWidgets_t qt_meta_stringdata_savePictureWidgets = {
    {
QT_MOC_LITERAL(0, 0, 18), // "savePictureWidgets"
QT_MOC_LITERAL(1, 19, 16), // "sendDiagnoseInfo"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "Common::stDiagnoseRst"
QT_MOC_LITERAL(4, 59, 26), // "on_pushButton_save_clicked"
QT_MOC_LITERAL(5, 86, 28) // "on_pushButton_cancel_clicked"

    },
    "savePictureWidgets\0sendDiagnoseInfo\0"
    "\0Common::stDiagnoseRst\0"
    "on_pushButton_save_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_savePictureWidgets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void savePictureWidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        savePictureWidgets *_t = static_cast<savePictureWidgets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDiagnoseInfo((*reinterpret_cast< Common::stDiagnoseRst(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_save_clicked(); break;
        case 2: _t->on_pushButton_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (savePictureWidgets::*_t)(Common::stDiagnoseRst );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&savePictureWidgets::sendDiagnoseInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject savePictureWidgets::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_savePictureWidgets.data,
      qt_meta_data_savePictureWidgets,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *savePictureWidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *savePictureWidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_savePictureWidgets.stringdata0))
        return static_cast<void*>(const_cast< savePictureWidgets*>(this));
    return QWidget::qt_metacast(_clname);
}

int savePictureWidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void savePictureWidgets::sendDiagnoseInfo(Common::stDiagnoseRst _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
