/****************************************************************************
** Meta object code from reading C++ file 'preferenciadialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visor-cliente/preferenciadialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferenciadialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PreferenciaDialog_t {
    QByteArrayData data[5];
    char stringdata[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PreferenciaDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PreferenciaDialog_t qt_meta_stringdata_PreferenciaDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 8),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 17),
QT_MOC_LITERAL(4, 46, 21)
    },
    "PreferenciaDialog\0s_camera\0\0"
    "on_pushOk_clicked\0on_pushCerrar_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreferenciaDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   32,    2, 0x08,
       4,    0,   33,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreferenciaDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PreferenciaDialog *_t = static_cast<PreferenciaDialog *>(_o);
        switch (_id) {
        case 0: _t->s_camera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushOk_clicked(); break;
        case 2: _t->on_pushCerrar_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PreferenciaDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PreferenciaDialog::s_camera)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PreferenciaDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PreferenciaDialog.data,
      qt_meta_data_PreferenciaDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *PreferenciaDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreferenciaDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PreferenciaDialog.stringdata))
        return static_cast<void*>(const_cast< PreferenciaDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PreferenciaDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PreferenciaDialog::s_camera(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
