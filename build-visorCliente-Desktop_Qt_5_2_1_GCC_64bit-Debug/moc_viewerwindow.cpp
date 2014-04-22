/****************************************************************************
** Meta object code from reading C++ file 'viewerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../visor-cliente/viewerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewerWindow_t {
    QByteArrayData data[22];
    char stringdata[417];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ViewerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ViewerWindow_t qt_meta_stringdata_ViewerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 5),
QT_MOC_LITERAL(4, 36, 16),
QT_MOC_LITERAL(5, 53, 24),
QT_MOC_LITERAL(6, 78, 30),
QT_MOC_LITERAL(7, 109, 29),
QT_MOC_LITERAL(8, 139, 24),
QT_MOC_LITERAL(9, 164, 4),
QT_MOC_LITERAL(10, 169, 27),
QT_MOC_LITERAL(11, 197, 21),
QT_MOC_LITERAL(12, 219, 27),
QT_MOC_LITERAL(13, 247, 31),
QT_MOC_LITERAL(14, 279, 35),
QT_MOC_LITERAL(15, 315, 36),
QT_MOC_LITERAL(16, 352, 11),
QT_MOC_LITERAL(17, 364, 4),
QT_MOC_LITERAL(18, 369, 12),
QT_MOC_LITERAL(19, 382, 7),
QT_MOC_LITERAL(20, 390, 14),
QT_MOC_LITERAL(21, 405, 10)
    },
    "ViewerWindow\0Procesar_Imagen\0\0image\0"
    "on_Salir_clicked\0on_actionSalir_triggered\0"
    "on_actionAbrirImagen_triggered\0"
    "on_actionAbrirVideo_triggered\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_actionAcercaDe_triggered\0"
    "on_Push_Pausa_clicked\0on_actionCapturar_triggered\0"
    "on_actionPreferencias_triggered\0"
    "on_actionAjustes_Conexion_triggered\0"
    "on_actionComenzar_a_enviar_triggered\0"
    "movie_frame\0rect\0actualizar_s\0image_s\0"
    "QVector<QRect>\0rectangulo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x08,
       5,    0,   93,    2, 0x08,
       6,    0,   94,    2, 0x08,
       7,    0,   95,    2, 0x08,
       8,    1,   96,    2, 0x08,
      10,    0,   99,    2, 0x08,
      11,    0,  100,    2, 0x08,
      12,    0,  101,    2, 0x08,
      13,    0,  102,    2, 0x08,
      14,    0,  103,    2, 0x08,
      15,    0,  104,    2, 0x08,
      16,    1,  105,    2, 0x08,
      18,    1,  108,    2, 0x08,
      19,    2,  111,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,   17,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 20,    2,   21,

       0        // eod
};

void ViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewerWindow *_t = static_cast<ViewerWindow *>(_o);
        switch (_id) {
        case 0: _t->Procesar_Imagen((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->on_Salir_clicked(); break;
        case 2: _t->on_actionSalir_triggered(); break;
        case 3: _t->on_actionAbrirImagen_triggered(); break;
        case 4: _t->on_actionAbrirVideo_triggered(); break;
        case 5: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_actionAcercaDe_triggered(); break;
        case 7: _t->on_Push_Pausa_clicked(); break;
        case 8: _t->on_actionCapturar_triggered(); break;
        case 9: _t->on_actionPreferencias_triggered(); break;
        case 10: _t->on_actionAjustes_Conexion_triggered(); break;
        case 11: _t->on_actionComenzar_a_enviar_triggered(); break;
        case 12: _t->movie_frame((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 13: _t->actualizar_s((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->image_s((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QVector<QRect>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QRect> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewerWindow::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewerWindow::Procesar_Imagen)) {
                *result = 0;
            }
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ViewerWindow::Procesar_Imagen(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
