/****************************************************************************
** Meta object code from reading C++ file 'ThreadMoteur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ThreadMoteur.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadMoteur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
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
struct qt_meta_stringdata_ThreadMoteur_t {
    uint offsetsAndSizes[14];
    char stringdata0[13];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[18];
    char stringdata5[13];
    char stringdata6[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ThreadMoteur_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ThreadMoteur_t qt_meta_stringdata_ThreadMoteur = {
    {
        QT_MOC_LITERAL(0, 12),  // "ThreadMoteur"
        QT_MOC_LITERAL(13, 14),  // "menu_selection"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 9),  // "selection"
        QT_MOC_LITERAL(39, 17),  // "menu_confirmation"
        QT_MOC_LITERAL(57, 12),  // "updateNumero"
        QT_MOC_LITERAL(70, 6)   // "valeur"
    },
    "ThreadMoteur",
    "menu_selection",
    "",
    "selection",
    "menu_confirmation",
    "updateNumero",
    "valeur"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ThreadMoteur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       4,    0,   35,    2, 0x06,    3 /* Public */,
       5,    1,   36,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject ThreadMoteur::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_ThreadMoteur.offsetsAndSizes,
    qt_meta_data_ThreadMoteur,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ThreadMoteur_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ThreadMoteur, std::true_type>,
        // method 'menu_selection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'menu_confirmation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateNumero'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ThreadMoteur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadMoteur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->menu_selection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->menu_confirmation(); break;
        case 2: _t->updateNumero((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::menu_selection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::menu_confirmation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::updateNumero; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ThreadMoteur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadMoteur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadMoteur.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ThreadMoteur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ThreadMoteur::menu_selection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadMoteur::menu_confirmation()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ThreadMoteur::updateNumero(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
