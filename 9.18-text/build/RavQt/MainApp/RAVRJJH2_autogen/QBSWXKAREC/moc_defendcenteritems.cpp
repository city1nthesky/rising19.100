/****************************************************************************
** Meta object code from reading C++ file 'defendcenteritems.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UnixRav3/RavQt/MainApp/home/defendcenteritems.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'defendcenteritems.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DefendCenterItemRect_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefendCenterItemRect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefendCenterItemRect_t qt_meta_stringdata_DefendCenterItemRect = {
    {
QT_MOC_LITERAL(0, 0, 20) // "DefendCenterItemRect"

    },
    "DefendCenterItemRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefendCenterItemRect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DefendCenterItemRect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject DefendCenterItemRect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DefendCenterItemRect.data,
      qt_meta_data_DefendCenterItemRect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DefendCenterItemRect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefendCenterItemRect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DefendCenterItemRect.stringdata0))
        return static_cast<void*>(const_cast< DefendCenterItemRect*>(this));
    return QWidget::qt_metacast(_clname);
}

int DefendCenterItemRect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_DefendCenterItemButton_t {
    QByteArrayData data[3];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefendCenterItemButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefendCenterItemButton_t qt_meta_stringdata_DefendCenterItemButton = {
    {
QT_MOC_LITERAL(0, 0, 22), // "DefendCenterItemButton"
QT_MOC_LITERAL(1, 23, 7), // "clicked"
QT_MOC_LITERAL(2, 31, 0) // ""

    },
    "DefendCenterItemButton\0clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefendCenterItemButton[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void DefendCenterItemButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DefendCenterItemButton *_t = static_cast<DefendCenterItemButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DefendCenterItemButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DefendCenterItemButton::clicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DefendCenterItemButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_DefendCenterItemButton.data,
      qt_meta_data_DefendCenterItemButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DefendCenterItemButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefendCenterItemButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DefendCenterItemButton.stringdata0))
        return static_cast<void*>(const_cast< DefendCenterItemButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int DefendCenterItemButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void DefendCenterItemButton::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_DefendCenterItem_t {
    QByteArrayData data[4];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefendCenterItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefendCenterItem_t qt_meta_stringdata_DefendCenterItem = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DefendCenterItem"
QT_MOC_LITERAL(1, 17, 7), // "clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12) // "OnClickedBtn"

    },
    "DefendCenterItem\0clicked\0\0OnClickedBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefendCenterItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DefendCenterItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DefendCenterItem *_t = static_cast<DefendCenterItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->OnClickedBtn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DefendCenterItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DefendCenterItem::clicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DefendCenterItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DefendCenterItem.data,
      qt_meta_data_DefendCenterItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DefendCenterItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefendCenterItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DefendCenterItem.stringdata0))
        return static_cast<void*>(const_cast< DefendCenterItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int DefendCenterItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DefendCenterItem::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
