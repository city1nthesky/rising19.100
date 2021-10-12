/****************************************************************************
** Meta object code from reading C++ file 'centerdiscoverygroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UnixRav3/RavQt/Config/centerdiscoverygroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centerdiscoverygroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CenterDiscoveryGroup_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CenterDiscoveryGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CenterDiscoveryGroup_t qt_meta_stringdata_CenterDiscoveryGroup = {
    {
QT_MOC_LITERAL(0, 0, 20), // "CenterDiscoveryGroup"
QT_MOC_LITERAL(1, 21, 21), // "OnLineEditTextChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "text"
QT_MOC_LITERAL(4, 49, 16) // "AddCenterClicked"

    },
    "CenterDiscoveryGroup\0OnLineEditTextChanged\0"
    "\0text\0AddCenterClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CenterDiscoveryGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void CenterDiscoveryGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CenterDiscoveryGroup *_t = static_cast<CenterDiscoveryGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnLineEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->AddCenterClicked(); break;
        default: ;
        }
    }
}

const QMetaObject CenterDiscoveryGroup::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_CenterDiscoveryGroup.data,
      qt_meta_data_CenterDiscoveryGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CenterDiscoveryGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CenterDiscoveryGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CenterDiscoveryGroup.stringdata0))
        return static_cast<void*>(const_cast< CenterDiscoveryGroup*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int CenterDiscoveryGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
