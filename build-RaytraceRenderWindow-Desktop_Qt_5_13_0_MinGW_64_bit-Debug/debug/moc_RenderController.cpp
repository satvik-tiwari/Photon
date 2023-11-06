/****************************************************************************
** Meta object code from reading C++ file 'RenderController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RaytraceRenderWindow/RenderController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderController_t {
    QByteArrayData data[23];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderController_t qt_meta_stringdata_RenderController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RenderController"
QT_MOC_LITERAL(1, 17, 21), // "objectRotationChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 17), // "xTranslateChanged"
QT_MOC_LITERAL(4, 58, 5), // "value"
QT_MOC_LITERAL(5, 64, 17), // "yTranslateChanged"
QT_MOC_LITERAL(6, 82, 17), // "zTranslateChanged"
QT_MOC_LITERAL(7, 100, 28), // "fresnelRenderingCheckChanged"
QT_MOC_LITERAL(8, 129, 5), // "state"
QT_MOC_LITERAL(9, 135, 24), // "phongShadingCheckChanged"
QT_MOC_LITERAL(10, 160, 25), // "interpolationCheckChanged"
QT_MOC_LITERAL(11, 186, 21), // "shadowBoxCheckChanged"
QT_MOC_LITERAL(12, 208, 20), // "reflectionBoxChanged"
QT_MOC_LITERAL(13, 229, 20), // "refractionBoxChanged"
QT_MOC_LITERAL(14, 250, 20), // "monteCarloBoxChanged"
QT_MOC_LITERAL(15, 271, 22), // "orthographicBoxChanged"
QT_MOC_LITERAL(16, 294, 15), // "BeginScaledDrag"
QT_MOC_LITERAL(17, 310, 11), // "whichButton"
QT_MOC_LITERAL(18, 322, 1), // "x"
QT_MOC_LITERAL(19, 324, 1), // "y"
QT_MOC_LITERAL(20, 326, 18), // "ContinueScaledDrag"
QT_MOC_LITERAL(21, 345, 13), // "EndScaledDrag"
QT_MOC_LITERAL(22, 359, 14) // "raytraceCalled"

    },
    "RenderController\0objectRotationChanged\0"
    "\0xTranslateChanged\0value\0yTranslateChanged\0"
    "zTranslateChanged\0fresnelRenderingCheckChanged\0"
    "state\0phongShadingCheckChanged\0"
    "interpolationCheckChanged\0"
    "shadowBoxCheckChanged\0reflectionBoxChanged\0"
    "refractionBoxChanged\0monteCarloBoxChanged\0"
    "orthographicBoxChanged\0BeginScaledDrag\0"
    "whichButton\0x\0y\0ContinueScaledDrag\0"
    "EndScaledDrag\0raytraceCalled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    1,   95,    2, 0x0a /* Public */,
       5,    1,   98,    2, 0x0a /* Public */,
       6,    1,  101,    2, 0x0a /* Public */,
       7,    1,  104,    2, 0x0a /* Public */,
       9,    1,  107,    2, 0x0a /* Public */,
      10,    1,  110,    2, 0x0a /* Public */,
      11,    1,  113,    2, 0x0a /* Public */,
      12,    1,  116,    2, 0x0a /* Public */,
      13,    1,  119,    2, 0x0a /* Public */,
      14,    1,  122,    2, 0x0a /* Public */,
      15,    1,  125,    2, 0x0a /* Public */,
      16,    3,  128,    2, 0x0a /* Public */,
      20,    2,  135,    2, 0x0a /* Public */,
      21,    2,  140,    2, 0x0a /* Public */,
      22,    0,  145,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float,   17,   18,   19,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   18,   19,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   18,   19,
    QMetaType::Void,

       0        // eod
};

void RenderController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->objectRotationChanged(); break;
        case 1: _t->xTranslateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->yTranslateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->zTranslateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->fresnelRenderingCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->phongShadingCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->interpolationCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->shadowBoxCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->reflectionBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->refractionBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->monteCarloBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->orthographicBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->BeginScaledDrag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 13: _t->ContinueScaledDrag((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 14: _t->EndScaledDrag((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 15: _t->raytraceCalled(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RenderController.data,
    qt_meta_data_RenderController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RenderController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
