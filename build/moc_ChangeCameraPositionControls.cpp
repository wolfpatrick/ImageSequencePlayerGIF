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
    QByteArrayData data[13];
    char stringdata0[264];
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
QT_MOC_LITERAL(4, 49, 18), // "chomboBoxVCChanged"
QT_MOC_LITERAL(5, 68, 22), // "leftArrowButtonClicked"
QT_MOC_LITERAL(6, 91, 23), // "rightArrowButtonClicked"
QT_MOC_LITERAL(7, 115, 20), // "upArrowButtonClicked"
QT_MOC_LITERAL(8, 136, 22), // "downArrowButtonClicked"
QT_MOC_LITERAL(9, 159, 35), // "radioButtonPerspectiveCameraC..."
QT_MOC_LITERAL(10, 195, 5), // "state"
QT_MOC_LITERAL(11, 201, 26), // "radioButtonViewCubeClicked"
QT_MOC_LITERAL(12, 228, 35) // "viewCubeCameraPositionsChange..."

    },
    "CameraPositionControls\0changeCameraPosition\0"
    "\0num\0chomboBoxVCChanged\0leftArrowButtonClicked\0"
    "rightArrowButtonClicked\0upArrowButtonClicked\0"
    "downArrowButtonClicked\0"
    "radioButtonPerspectiveCameraClicked\0"
    "state\0radioButtonViewCubeClicked\0"
    "viewCubeCameraPositionsChangedEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraPositionControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   65,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void CameraPositionControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraPositionControls *_t = static_cast<CameraPositionControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeCameraPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->chomboBoxVCChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->leftArrowButtonClicked(); break;
        case 3: _t->rightArrowButtonClicked(); break;
        case 4: _t->upArrowButtonClicked(); break;
        case 5: _t->downArrowButtonClicked(); break;
        case 6: _t->radioButtonPerspectiveCameraClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->radioButtonViewCubeClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->viewCubeCameraPositionsChangedEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        {
            typedef void (CameraPositionControls::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraPositionControls::chomboBoxVCChanged)) {
                *result = 1;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CameraPositionControls::changeCameraPosition(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraPositionControls::chomboBoxVCChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
