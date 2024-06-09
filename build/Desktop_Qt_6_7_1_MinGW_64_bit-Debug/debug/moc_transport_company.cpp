/****************************************************************************
** Meta object code from reading C++ file 'transport_company.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../transport_company.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transport_company.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTransport_companyENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTransport_companyENDCLASS = QtMocHelpers::stringData(
    "Transport_company",
    "Invoice_vectorChanged",
    "",
    "Order_vectorChanged",
    "getOrderIndex",
    "num",
    "getOrderMaxIndex",
    "getInvoiceIndex",
    "setOrderIndex",
    "setOrderMaxIndex",
    "element",
    "setInvoiceIndex",
    "order_clearVector",
    "invoice_clearVector",
    "setOrder_vector",
    "newOrder_vector",
    "setInvoice_vector",
    "newInvoice_vector",
    "Order_vector",
    "Invoice_vector"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTransport_companyENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       2,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    3 /* Public */,
       3,    0,   87,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   88,    2, 0x0a,    5 /* Public */,
       6,    0,   91,    2, 0x0a,    7 /* Public */,
       7,    1,   92,    2, 0x0a,    8 /* Public */,
       8,    1,   95,    2, 0x0a,   10 /* Public */,
       9,    1,   98,    2, 0x0a,   12 /* Public */,
      11,    1,  101,    2, 0x0a,   14 /* Public */,
      12,    0,  104,    2, 0x0a,   16 /* Public */,
      13,    0,  105,    2, 0x0a,   17 /* Public */,
      14,    1,  106,    2, 0x0a,   18 /* Public */,
      16,    1,  109,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   17,

 // properties: name, type, flags
      18, QMetaType::QStringList, 0x00015903, uint(1), 0,
      19, QMetaType::QStringList, 0x00015903, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Transport_company::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTransport_companyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTransport_companyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTransport_companyENDCLASS_t,
        // property 'Order_vector'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // property 'Invoice_vector'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Transport_company, std::true_type>,
        // method 'Invoice_vectorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Order_vectorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getOrderIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getOrderMaxIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getInvoiceIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setOrderIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setOrderMaxIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setInvoiceIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'order_clearVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'invoice_clearVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setOrder_vector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString> &, std::false_type>,
        // method 'setInvoice_vector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString> &, std::false_type>
    >,
    nullptr
} };

void Transport_company::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transport_company *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Invoice_vectorChanged(); break;
        case 1: _t->Order_vectorChanged(); break;
        case 2: { int _r = _t->getOrderIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getOrderMaxIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getInvoiceIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setOrderIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setOrderMaxIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setInvoiceIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->order_clearVector(); break;
        case 9: _t->invoice_clearVector(); break;
        case 10: _t->setOrder_vector((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 11: _t->setInvoice_vector((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Transport_company::*)();
            if (_t _q_method = &Transport_company::Invoice_vectorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Transport_company::*)();
            if (_t _q_method = &Transport_company::Order_vectorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Transport_company *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->getOrder_vector(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->getInvoice_vector(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Transport_company *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOrder_vector(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 1: _t->setInvoice_vector(*reinterpret_cast< QList<QString>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Transport_company::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transport_company::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTransport_companyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Transport_company::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Transport_company::Invoice_vectorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Transport_company::Order_vectorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
