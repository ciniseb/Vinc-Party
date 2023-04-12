/****************************************************************************
** Meta object code from reading C++ file 'WidgetJeuMineur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../WidgetJeuMineur.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetJeuMineur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_WidgetJeuMineur_t {
    uint offsetsAndSizes[18];
    char stringdata0[16];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[13];
    char stringdata5[12];
    char stringdata6[16];
    char stringdata7[6];
    char stringdata8[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WidgetJeuMineur_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_WidgetJeuMineur_t qt_meta_stringdata_WidgetJeuMineur = {
    {
        QT_MOC_LITERAL(0, 15),  // "WidgetJeuMineur"
        QT_MOC_LITERAL(16, 16),  // "blockRectChanged"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 5),  // "debut"
        QT_MOC_LITERAL(40, 12),  // "blockUpadate"
        QT_MOC_LITERAL(53, 11),  // "pourcentage"
        QT_MOC_LITERAL(65, 15),  // "updateCountdown"
        QT_MOC_LITERAL(81, 5),  // "timer"
        QT_MOC_LITERAL(87, 9)   // "blockRect"
    },
    "WidgetJeuMineur",
    "blockRectChanged",
    "",
    "debut",
    "blockUpadate",
    "pourcentage",
    "updateCountdown",
    "timer",
    "blockRect"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_WidgetJeuMineur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   53, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x0a,    3 /* Public */,
       4,    1,   46,    2, 0x0a,    4 /* Public */,
       6,    0,   49,    2, 0x0a,    6 /* Public */,
       7,    1,   50,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    2,

 // properties: name, type, flags
       8, QMetaType::QRect, 0x00015103, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject WidgetJeuMineur::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidgetJeuMineur.offsetsAndSizes,
    qt_meta_data_WidgetJeuMineur,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_WidgetJeuMineur_t,
        // property 'blockRect'
        QtPrivate::TypeAndForceComplete<QRect, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WidgetJeuMineur, std::true_type>,
        // method 'blockRectChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'debut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'blockUpadate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'updateCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timer'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void WidgetJeuMineur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetJeuMineur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->blockRectChanged(); break;
        case 1: _t->debut(); break;
        case 2: _t->blockUpadate((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->updateCountdown(); break;
        case 4: { int _r = _t->timer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetJeuMineur::*)();
            if (_t _q_method = &WidgetJeuMineur::blockRectChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WidgetJeuMineur *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QRect*>(_v) = _t->blockRect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WidgetJeuMineur *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlockRect(*reinterpret_cast< QRect*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *WidgetJeuMineur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetJeuMineur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetJeuMineur.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetJeuMineur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void WidgetJeuMineur::blockRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
