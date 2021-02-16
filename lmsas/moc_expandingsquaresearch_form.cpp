/****************************************************************************
** Meta object code from reading C++ file 'expandingsquaresearch_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Searches/expandingsquaresearch_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expandingsquaresearch_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExpandingSquareSearch_form_t {
    QByteArrayData data[10];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExpandingSquareSearch_form_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExpandingSquareSearch_form_t qt_meta_stringdata_ExpandingSquareSearch_form = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ExpandingSquareSearch_form"
QT_MOC_LITERAL(1, 27, 29), // "on_StartPointcheckBox_clicked"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 7), // "checked"
QT_MOC_LITERAL(4, 66, 27), // "on_ScoutPoscheckBox_clicked"
QT_MOC_LITERAL(5, 94, 15), // "getclickedPoint"
QT_MOC_LITERAL(6, 110, 26), // "on_tableWidget_cellClicked"
QT_MOC_LITERAL(7, 137, 3), // "row"
QT_MOC_LITERAL(8, 141, 6), // "column"
QT_MOC_LITERAL(9, 148, 26) // "on_AddUpdateButton_clicked"

    },
    "ExpandingSquareSearch_form\0"
    "on_StartPointcheckBox_clicked\0\0checked\0"
    "on_ScoutPoscheckBox_clicked\0getclickedPoint\0"
    "on_tableWidget_cellClicked\0row\0column\0"
    "on_AddUpdateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpandingSquareSearch_form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    2,   48,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void ExpandingSquareSearch_form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExpandingSquareSearch_form *_t = static_cast<ExpandingSquareSearch_form *>(_o);
        switch (_id) {
        case 0: _t->on_StartPointcheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_ScoutPoscheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->getclickedPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->on_tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_AddUpdateButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ExpandingSquareSearch_form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExpandingSquareSearch_form.data,
      qt_meta_data_ExpandingSquareSearch_form,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExpandingSquareSearch_form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpandingSquareSearch_form::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExpandingSquareSearch_form.stringdata))
        return static_cast<void*>(const_cast< ExpandingSquareSearch_form*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExpandingSquareSearch_form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
