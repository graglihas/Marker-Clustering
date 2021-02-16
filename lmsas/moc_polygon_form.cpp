/****************************************************************************
** Meta object code from reading C++ file 'polygon_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Polygon/polygon_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'polygon_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Polygon_Form_t {
    QByteArrayData data[7];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Polygon_Form_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Polygon_Form_t qt_meta_stringdata_Polygon_Form = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Polygon_Form"
QT_MOC_LITERAL(1, 13, 11), // "drawPolygon"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "digitizerFinished"
QT_MOC_LITERAL(4, 44, 33), // "CGDynamicGeometry::OperationS..."
QT_MOC_LITERAL(5, 78, 27), // "on_AddPolygonButton_clicked"
QT_MOC_LITERAL(6, 106, 25) // "on_SetStyleButton_clicked"

    },
    "Polygon_Form\0drawPolygon\0\0digitizerFinished\0"
    "CGDynamicGeometry::OperationState\0"
    "on_AddPolygonButton_clicked\0"
    "on_SetStyleButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Polygon_Form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       3,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Polygon_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Polygon_Form *_t = static_cast<Polygon_Form *>(_o);
        switch (_id) {
        case 0: _t->drawPolygon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->digitizerFinished((*reinterpret_cast< CGDynamicGeometry::OperationState(*)>(_a[1]))); break;
        case 2: _t->on_AddPolygonButton_clicked(); break;
        case 3: _t->on_SetStyleButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Polygon_Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Polygon_Form.data,
      qt_meta_data_Polygon_Form,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Polygon_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Polygon_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Polygon_Form.stringdata))
        return static_cast<void*>(const_cast< Polygon_Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Polygon_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
