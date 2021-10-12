/****************************************************************************
** Meta object code from reading C++ file 'screenwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UnixRav3/RavQt/Notifier/screenwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScreenWidget_t {
    QByteArrayData data[14];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreenWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreenWidget_t qt_meta_stringdata_ScreenWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScreenWidget"
QT_MOC_LITERAL(1, 13, 3), // "tip"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "ShowMessage"
QT_MOC_LITERAL(4, 30, 8), // "onPopEnd"
QT_MOC_LITERAL(5, 39, 8), // "selected"
QT_MOC_LITERAL(6, 48, 14), // "OpenMainScreen"
QT_MOC_LITERAL(7, 63, 12), // "OpenSettings"
QT_MOC_LITERAL(8, 76, 11), // "OpenLogView"
QT_MOC_LITERAL(9, 88, 6), // "Update"
QT_MOC_LITERAL(10, 95, 7), // "ExitAll"
QT_MOC_LITERAL(11, 103, 11), // "IconActived"
QT_MOC_LITERAL(12, 115, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(13, 149, 5) // "reson"

    },
    "ScreenWidget\0tip\0\0ShowMessage\0onPopEnd\0"
    "selected\0OpenMainScreen\0OpenSettings\0"
    "OpenLogView\0Update\0ExitAll\0IconActived\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reson"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreenWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void ScreenWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScreenWidget *_t = static_cast<ScreenWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tip(); break;
        case 1: _t->ShowMessage(); break;
        case 2: _t->onPopEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OpenMainScreen(); break;
        case 4: _t->OpenSettings(); break;
        case 5: _t->OpenLogView(); break;
        case 6: _t->Update(); break;
        case 7: _t->ExitAll(); break;
        case 8: _t->IconActived((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScreenWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScreenWidget::tip)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScreenWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScreenWidget.data,
      qt_meta_data_ScreenWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScreenWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenWidget.stringdata0))
        return static_cast<void*>(const_cast< ScreenWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScreenWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ScreenWidget::tip()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
