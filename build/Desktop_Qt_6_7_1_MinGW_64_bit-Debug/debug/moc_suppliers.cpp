/****************************************************************************
** Meta object code from reading C++ file 'suppliers.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../suppliers.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'suppliers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSuppliersENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSuppliersENDCLASS = QtMocHelpers::stringData(
    "Suppliers",
    "Supplier_vectorChanged",
    "",
    "getSupplierIndex",
    "num",
    "getSupplierMaxIndex",
    "setSupplierIndex",
    "setSupplierMaxIndex",
    "element",
    "supplier_clearVector",
    "setSupplier_vector",
    "newSupplier_vector",
    "Supplier_vector"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSuppliersENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   71, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   57,    2, 0x0a,    3 /* Public */,
       5,    0,   60,    2, 0x0a,    5 /* Public */,
       6,    1,   61,    2, 0x0a,    6 /* Public */,
       7,    1,   64,    2, 0x0a,    8 /* Public */,
       9,    0,   67,    2, 0x0a,   10 /* Public */,
      10,    1,   68,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   11,

 // properties: name, type, flags
      12, QMetaType::QStringList, 0x00015903, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Suppliers::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSuppliersENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSuppliersENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSuppliersENDCLASS_t,
        // property 'Supplier_vector'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Suppliers, std::true_type>,
        // method 'Supplier_vectorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getSupplierIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getSupplierMaxIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSupplierIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSupplierMaxIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'supplier_clearVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSupplier_vector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString>, std::false_type>
    >,
    nullptr
} };

void Suppliers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Suppliers *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Supplier_vectorChanged(); break;
        case 1: { int _r = _t->getSupplierIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getSupplierMaxIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setSupplierIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setSupplierMaxIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->supplier_clearVector(); break;
        case 6: _t->setSupplier_vector((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Suppliers::*)();
            if (_t _q_method = &Suppliers::Supplier_vectorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Suppliers *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->getSupplier_vector(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Suppliers *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSupplier_vector(*reinterpret_cast< QList<QString>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Suppliers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Suppliers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSuppliersENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Suppliers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Suppliers::Supplier_vectorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
