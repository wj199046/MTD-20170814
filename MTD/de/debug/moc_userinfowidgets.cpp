/****************************************************************************
** Meta object code from reading C++ file 'userinfowidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userinfowidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfowidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userInfoWidgets_t {
    QByteArrayData data[15];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userInfoWidgets_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userInfoWidgets_t qt_meta_stringdata_userInfoWidgets = {
    {
QT_MOC_LITERAL(0, 0, 15), // "userInfoWidgets"
QT_MOC_LITERAL(1, 16, 19), // "SendUserInfoContent"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "strName"
QT_MOC_LITERAL(4, 45, 6), // "strAge"
QT_MOC_LITERAL(5, 52, 6), // "strSex"
QT_MOC_LITERAL(6, 59, 17), // "signalLogInUserId"
QT_MOC_LITERAL(7, 77, 5), // "strId"
QT_MOC_LITERAL(8, 83, 16), // "changeCurrentTab"
QT_MOC_LITERAL(9, 100, 9), // "PixLabel*"
QT_MOC_LITERAL(10, 110, 3), // "pix"
QT_MOC_LITERAL(11, 114, 32), // "on_pushButton_makeSure_2_clicked"
QT_MOC_LITERAL(12, 147, 30), // "on_pushButton_cancel_2_clicked"
QT_MOC_LITERAL(13, 178, 32), // "on_pushButton_makeSure_1_clicked"
QT_MOC_LITERAL(14, 211, 30) // "on_pushButton_cancel_1_clicked"

    },
    "userInfoWidgets\0SendUserInfoContent\0"
    "\0strName\0strAge\0strSex\0signalLogInUserId\0"
    "strId\0changeCurrentTab\0PixLabel*\0pix\0"
    "on_pushButton_makeSure_2_clicked\0"
    "on_pushButton_cancel_2_clicked\0"
    "on_pushButton_makeSure_1_clicked\0"
    "on_pushButton_cancel_1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userInfoWidgets[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   59,    2, 0x08 /* Private */,
      11,    0,   62,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,
      13,    0,   64,    2, 0x08 /* Private */,
      14,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void userInfoWidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userInfoWidgets *_t = static_cast<userInfoWidgets *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendUserInfoContent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->signalLogInUserId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changeCurrentTab((*reinterpret_cast< PixLabel*(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_makeSure_2_clicked(); break;
        case 4: _t->on_pushButton_cancel_2_clicked(); break;
        case 5: _t->on_pushButton_makeSure_1_clicked(); break;
        case 6: _t->on_pushButton_cancel_1_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PixLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (userInfoWidgets::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userInfoWidgets::SendUserInfoContent)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (userInfoWidgets::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userInfoWidgets::signalLogInUserId)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject userInfoWidgets::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_userInfoWidgets.data,
      qt_meta_data_userInfoWidgets,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *userInfoWidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userInfoWidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userInfoWidgets.stringdata0))
        return static_cast<void*>(const_cast< userInfoWidgets*>(this));
    return QWidget::qt_metacast(_clname);
}

int userInfoWidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void userInfoWidgets::SendUserInfoContent(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void userInfoWidgets::signalLogInUserId(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
