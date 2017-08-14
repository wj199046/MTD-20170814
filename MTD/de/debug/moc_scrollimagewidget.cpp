/****************************************************************************
** Meta object code from reading C++ file 'scrollimagewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../scrollimagewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrollimagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_scrollImageWidget_t {
    QByteArrayData data[3];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scrollImageWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scrollImageWidget_t qt_meta_stringdata_scrollImageWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "scrollImageWidget"
QT_MOC_LITERAL(1, 18, 20), // "signal_currentColumn"
QT_MOC_LITERAL(2, 39, 0) // ""

    },
    "scrollImageWidget\0signal_currentColumn\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scrollImageWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void scrollImageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        scrollImageWidget *_t = static_cast<scrollImageWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_currentColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (scrollImageWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scrollImageWidget::signal_currentColumn)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject scrollImageWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_scrollImageWidget.data,
      qt_meta_data_scrollImageWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *scrollImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scrollImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scrollImageWidget.stringdata0))
        return static_cast<void*>(const_cast< scrollImageWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int scrollImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void scrollImageWidget::signal_currentColumn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
