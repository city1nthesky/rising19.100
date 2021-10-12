/****************************************************************************
** Meta object code from reading C++ file 'upgradegroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UnixRav3/RavQt/Config/upgradegroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'upgradegroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UpgradeGroup_t {
    QByteArrayData data[15];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpgradeGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpgradeGroup_t qt_meta_stringdata_UpgradeGroup = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UpgradeGroup"
QT_MOC_LITERAL(1, 13, 16), // "SetSizeEditValid"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "OnLineEditTextChanged"
QT_MOC_LITERAL(4, 53, 4), // "text"
QT_MOC_LITERAL(5, 58, 10), // "PopAddMenu"
QT_MOC_LITERAL(6, 69, 19), // "TrigerAddSourceMenu"
QT_MOC_LITERAL(7, 89, 8), // "QAction*"
QT_MOC_LITERAL(8, 98, 7), // "pAction"
QT_MOC_LITERAL(9, 106, 20), // "OnClickedUpgradeMode"
QT_MOC_LITERAL(10, 127, 5), // "index"
QT_MOC_LITERAL(11, 133, 22), // "OnClickedDelayBootType"
QT_MOC_LITERAL(12, 156, 21), // "OnClickedForceUpgrade"
QT_MOC_LITERAL(13, 178, 18), // "OnClickedBandWidth"
QT_MOC_LITERAL(14, 197, 18) // "OnChangedProxyType"

    },
    "UpgradeGroup\0SetSizeEditValid\0\0"
    "OnLineEditTextChanged\0text\0PopAddMenu\0"
    "TrigerAddSourceMenu\0QAction*\0pAction\0"
    "OnClickedUpgradeMode\0index\0"
    "OnClickedDelayBootType\0OnClickedForceUpgrade\0"
    "OnClickedBandWidth\0OnChangedProxyType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpgradeGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,
      11,    1,   70,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    0,   74,    2, 0x0a /* Public */,
      14,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void UpgradeGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpgradeGroup *_t = static_cast<UpgradeGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetSizeEditValid(); break;
        case 1: _t->OnLineEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->PopAddMenu(); break;
        case 3: _t->TrigerAddSourceMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->OnClickedUpgradeMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnClickedDelayBootType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnClickedForceUpgrade(); break;
        case 7: _t->OnClickedBandWidth(); break;
        case 8: _t->OnChangedProxyType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject UpgradeGroup::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_UpgradeGroup.data,
      qt_meta_data_UpgradeGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpgradeGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpgradeGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpgradeGroup.stringdata0))
        return static_cast<void*>(const_cast< UpgradeGroup*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int UpgradeGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
