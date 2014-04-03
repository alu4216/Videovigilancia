/****************************************************************************
** Meta object code from reading C++ file 'viewerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visor-cliente/viewerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewerWindow_t {
    QByteArrayData data[18];
    char stringdata[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ViewerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ViewerWindow_t qt_meta_stringdata_ViewerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 16),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 24),
QT_MOC_LITERAL(4, 56, 30),
QT_MOC_LITERAL(5, 87, 29),
QT_MOC_LITERAL(6, 117, 11),
QT_MOC_LITERAL(7, 129, 4),
QT_MOC_LITERAL(8, 134, 24),
QT_MOC_LITERAL(9, 159, 4),
QT_MOC_LITERAL(10, 164, 27),
QT_MOC_LITERAL(11, 192, 21),
QT_MOC_LITERAL(12, 214, 27),
QT_MOC_LITERAL(13, 242, 31),
QT_MOC_LITERAL(14, 274, 12),
QT_MOC_LITERAL(15, 287, 7),
QT_MOC_LITERAL(16, 295, 35),
QT_MOC_LITERAL(17, 331, 36)
    },
    "ViewerWindow\0on_Salir_clicked\0\0"
    "on_actionSalir_triggered\0"
    "on_actionAbrirImagen_triggered\0"
    "on_actionAbrirVideo_triggered\0movie_frame\0"
    "rect\0on_checkBox_stateChanged\0arg1\0"
    "on_actionAcercaDe_triggered\0"
    "on_Push_Pausa_clicked\0on_actionCapturar_triggered\0"
    "on_actionPreferencias_triggered\0"
    "actualizar_s\0image_s\0"
    "on_actionAjustes_Conexion_triggered\0"
    "on_actionComenzar_a_enviar_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    0,   86,    2, 0x08,
       5,    0,   87,    2, 0x08,
       6,    1,   88,    2, 0x08,
       8,    1,   91,    2, 0x08,
      10,    0,   94,    2, 0x08,
      11,    0,   95,    2, 0x08,
      12,    0,   96,    2, 0x08,
      13,    0,   97,    2, 0x08,
      14,    1,   98,    2, 0x08,
      15,    1,  101,    2, 0x08,
      16,    0,  104,    2, 0x08,
      17,    0,  105,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewerWindow *_t = static_cast<ViewerWindow *>(_o);
        switch (_id) {
        case 0: _t->on_Salir_clicked(); break;
        case 1: _t->on_actionSalir_triggered(); break;
        case 2: _t->on_actionAbrirImagen_triggered(); break;
        case 3: _t->on_actionAbrirVideo_triggered(); break;
        case 4: _t->movie_frame((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_actionAcercaDe_triggered(); break;
        case 7: _t->on_Push_Pausa_clicked(); break;
        case 8: _t->on_actionCapturar_triggered(); break;
        case 9: _t->on_actionPreferencias_triggered(); break;
        case 10: _t->actualizar_s((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->image_s((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 12: _t->on_actionAjustes_Conexion_triggered(); break;
        case 13: _t->on_actionComenzar_a_enviar_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject ViewerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewerWindow.data,
      qt_meta_data_ViewerWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ViewerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewerWindow.stringdata))
        return static_cast<void*>(const_cast< ViewerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
