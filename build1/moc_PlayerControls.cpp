/****************************************************************************
** Meta object code from reading C++ file 'PlayerControls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scr/PlayerControls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerControls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlayerControls_t {
    QByteArrayData data[18];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerControls_t qt_meta_stringdata_PlayerControls = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PlayerControls"
QT_MOC_LITERAL(1, 15, 4), // "play"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "setPaused1"
QT_MOC_LITERAL(4, 32, 4), // "stop"
QT_MOC_LITERAL(5, 37, 5), // "begin"
QT_MOC_LITERAL(6, 43, 3), // "end"
QT_MOC_LITERAL(7, 47, 9), // "nextFrame"
QT_MOC_LITERAL(8, 57, 13), // "previousFrame"
QT_MOC_LITERAL(9, 71, 8), // "setState"
QT_MOC_LITERAL(10, 80, 18), // "QMovie::MovieState"
QT_MOC_LITERAL(11, 99, 5), // "state"
QT_MOC_LITERAL(12, 105, 11), // "playClicked"
QT_MOC_LITERAL(13, 117, 11), // "stopClicked"
QT_MOC_LITERAL(14, 129, 14), // "forwardClicked"
QT_MOC_LITERAL(15, 144, 15), // "backwardClicked"
QT_MOC_LITERAL(16, 160, 14), // "toBeginClicked"
QT_MOC_LITERAL(17, 175, 12) // "toEndClicked"

    },
    "PlayerControls\0play\0\0setPaused1\0stop\0"
    "begin\0end\0nextFrame\0previousFrame\0"
    "setState\0QMovie::MovieState\0state\0"
    "playClicked\0stopClicked\0forwardClicked\0"
    "backwardClicked\0toBeginClicked\0"
    "toEndClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       4,    0,   88,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    0,   90,    2, 0x06 /* Public */,
       7,    0,   91,    2, 0x06 /* Public */,
       8,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   93,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerControls *_t = static_cast<PlayerControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->setPaused1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->stop(); break;
        case 3: _t->begin(); break;
        case 4: _t->end(); break;
        case 5: _t->nextFrame(); break;
        case 6: _t->previousFrame(); break;
        case 7: _t->setState((*reinterpret_cast< QMovie::MovieState(*)>(_a[1]))); break;
        case 8: _t->playClicked(); break;
        case 9: _t->stopClicked(); break;
        case 10: _t->forwardClicked(); break;
        case 11: _t->backwardClicked(); break;
        case 12: _t->toBeginClicked(); break;
        case 13: _t->toEndClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::play)) {
                *result = 0;
            }
        }
        {
            typedef void (PlayerControls::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::setPaused1)) {
                *result = 1;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::stop)) {
                *result = 2;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::begin)) {
                *result = 3;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::end)) {
                *result = 4;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::nextFrame)) {
                *result = 5;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::previousFrame)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject PlayerControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerControls.data,
      qt_meta_data_PlayerControls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlayerControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerControls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerControls.stringdata0))
        return static_cast<void*>(const_cast< PlayerControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void PlayerControls::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void PlayerControls::setPaused1(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayerControls::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void PlayerControls::begin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void PlayerControls::end()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void PlayerControls::nextFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void PlayerControls::previousFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
