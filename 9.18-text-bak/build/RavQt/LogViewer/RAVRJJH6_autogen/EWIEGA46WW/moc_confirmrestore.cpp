/****************************************************************************
** Meta object code from reading C++ file 'confirmrestore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UnixRav3/RavQt/LogViewer/confirmrestore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confirmrestore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfirmTitleWidget_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfirmTitleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfirmTitleWidget_t qt_meta_stringdata_ConfirmTitleWidget = {
    {
QT_MOC_LITERAL(0, 0, 18) // "ConfirmTitleWidget"

    },
    "ConfirmTitleWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfirmTitleWidget[] = {

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

void ConfirmTitleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ConfirmTitleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConfirmTitleWidget.data,
      qt_meta_data_ConfirmTitleWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfirmTitleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfirmTitleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmTitleWidget.stringdata0))
        return static_cast<void*>(const_cast< ConfirmTitleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConfirmTitleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ConfirmRestoreWidget_t {
    QByteArrayData data[4];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfirmRestoreWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfirmRestoreWidget_t qt_meta_stringdata_ConfirmRestoreWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ConfirmRestoreWidget"
QT_MOC_LITERAL(1, 21, 11), // "OnClickedOK"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17) // "OnClickedIgCancle"

    },
    "ConfirmRestoreWidget\0OnClickedOK\0\0"
    "OnClickedIgCancle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfirmRestoreWidget[] = {

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
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfirmRestoreWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfirmRestoreWidget *_t = static_cast<ConfirmRestoreWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnClickedOK(); break;
        case 1: _t->OnClickedIgCancle(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ConfirmRestoreWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfirmRestoreWidget.data,
      qt_meta_data_ConfirmRestoreWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfirmRestoreWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfirmRestoreWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmRestoreWidget.stringdata0))
        return static_cast<void*>(const_cast< ConfirmRestoreWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfirmRestoreWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
