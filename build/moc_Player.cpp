/****************************************************************************
** Meta object code from reading C++ file 'Player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scr/Player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[18];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 12), // "beginClicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "endClicked"
QT_MOC_LITERAL(4, 32, 11), // "stopClicked"
QT_MOC_LITERAL(5, 44, 16), // "nextFrameClicked"
QT_MOC_LITERAL(6, 61, 20), // "previousFrameClicked"
QT_MOC_LITERAL(7, 82, 9), // "goToFrame"
QT_MOC_LITERAL(8, 92, 5), // "frame"
QT_MOC_LITERAL(9, 98, 17), // "updateFrameSlider"
QT_MOC_LITERAL(10, 116, 11), // "fitToWindow"
QT_MOC_LITERAL(11, 128, 5), // "state"
QT_MOC_LITERAL(12, 134, 17), // "changeCameraEvent"
QT_MOC_LITERAL(13, 152, 3), // "num"
QT_MOC_LITERAL(14, 156, 20), // "sequenceChangedEvent"
QT_MOC_LITERAL(15, 177, 14), // "sequenceNumber"
QT_MOC_LITERAL(16, 192, 23), // "chomboBoxVCChangedEvent"
QT_MOC_LITERAL(17, 216, 13) // "updateButtons"

    },
    "Player\0beginClicked\0\0endClicked\0"
    "stopClicked\0nextFrameClicked\0"
    "previousFrameClicked\0goToFrame\0frame\0"
    "updateFrameSlider\0fitToWindow\0state\0"
    "changeCameraEvent\0num\0sequenceChangedEvent\0"
    "sequenceNumber\0chomboBoxVCChangedEvent\0"
    "updateButtons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      14,    1,   89,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beginClicked(); break;
        case 1: _t->endClicked(); break;
        case 2: _t->stopClicked(); break;
        case 3: _t->nextFrameClicked(); break;
        case 4: _t->previousFrameClicked(); break;
        case 5: _t->goToFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateFrameSlider(); break;
        case 7: _t->fitToWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->changeCameraEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->sequenceChangedEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->chomboBoxVCChangedEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateButtons(); break;
        default: ;
        }
    }
}

const QMetaObject Player::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Player.data,
      qt_meta_data_Player,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(const_cast< Player*>(this));
    return QWidget::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
