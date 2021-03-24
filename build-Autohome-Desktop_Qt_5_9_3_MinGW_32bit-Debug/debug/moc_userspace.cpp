/****************************************************************************
** Meta object code from reading C++ file 'userspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Auto_home/userspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Userspace_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Userspace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Userspace_t qt_meta_stringdata_Userspace = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Userspace"
QT_MOC_LITERAL(1, 10, 12), // "enter_option"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "time_view"
QT_MOC_LITERAL(4, 34, 10), // "send_email"
QT_MOC_LITERAL(5, 45, 11), // "temper_view"
QT_MOC_LITERAL(6, 57, 10), // "water_view"
QT_MOC_LITERAL(7, 68, 13), // "sunshine_view"
QT_MOC_LITERAL(8, 82, 12), // "connect_exam"
QT_MOC_LITERAL(9, 95, 11) // "recv_server"

    },
    "Userspace\0enter_option\0\0time_view\0"
    "send_email\0temper_view\0water_view\0"
    "sunshine_view\0connect_exam\0recv_server"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Userspace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Userspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Userspace *_t = static_cast<Userspace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enter_option(); break;
        case 1: _t->time_view(); break;
        case 2: _t->send_email(); break;
        case 3: _t->temper_view(); break;
        case 4: _t->water_view(); break;
        case 5: _t->sunshine_view(); break;
        case 6: _t->connect_exam(); break;
        case 7: _t->recv_server(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Userspace::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Userspace.data,
      qt_meta_data_Userspace,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Userspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Userspace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Userspace.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Userspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
