/****************************************************************************
** Meta object code from reading C++ file 'ChangeCameraPositionControls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scr/ChangeCameraPositionControls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChangeCameraPositionControls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraPositionControls_t {
    QByteArrayData data[11];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraPositionControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraPositionControls_t qt_meta_stringdata_CameraPositionControls = {
    {
QT_MOC_LITERAL(0, 0, 22), // "CameraPositionControls"
QT_MOC_LITERAL(1, 23, 20), // "changeCameraPosition"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 3), // "num"
QT_MOC_LITERAL(4, 49, 22), // "leftArrowButtonClicked"
QT_MOC_LITERAL(5, 72, 23), // "rightArrowButtonClicked"
QT_MOC_LITERAL(6, 96, 20), // "upArrowButtonClicked"
QT_MOC_LITERAL(7, 117, 22), // "downArrowButtonClicked"
QT_MOC_LITERAL(8, 140, 35), // "radioButtonPerspectiveCameraC..."
QT_MOC_LITERAL(9, 176, 5), // "state"
QT_MOC_LITERAL(10, 182, 26) // "radioButtonViewCubeClicked"

    },
    "CameraPositionControls\0changeCameraPosition\0"
    "\0num\0leftArrowButtonClicked\0"
    "rightArrowButtonClicked\0upArrowButtonClicked\0"
    "downArrowButtonClicked\0"
    "radioButtonPerspectiveCameraClicked\0"
    "state\0radioButtonViewCubeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraPositionControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void CameraPositionControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraPositionControls *_t = static_cast<CameraPositionControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCameraPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->leftArrowButtonClicked(); break;
        case 2: _t->rightArrowButtonClicked(); break;
        case 3: _t->upArrowButtonClicked(); break;
        case 4: _t->downArrowButtonClicked(); break;
        case 5: _t->radioButtonPerspectiveCameraClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->radioButtonViewCubeClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraPositionControls::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraPositionControls::changeCameraPosition)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CameraPositionControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraPositionControls.data,
      qt_meta_data_CameraPositionControls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraPositionControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraPositionControls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraPositionControls.stringdata0))
        return static_cast<void*>(const_cast< CameraPositionControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraPositionControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CameraPositionControls::changeCameraPosition(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
