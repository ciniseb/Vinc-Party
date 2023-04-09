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
    uint offsetsAndSizes[34];
    char stringdata0[13];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[15];
    char stringdata5[10];
    char stringdata6[15];
    char stringdata7[12];
    char stringdata8[12];
    char stringdata9[13];
    char stringdata10[18];
    char stringdata11[11];
    char stringdata12[14];
    char stringdata13[15];
    char stringdata14[16];
    char stringdata15[16];
    char stringdata16[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ThreadMoteur_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ThreadMoteur_t qt_meta_stringdata_ThreadMoteur = {
    {
        QT_MOC_LITERAL(0, 12),  // "ThreadMoteur"
        QT_MOC_LITERAL(13, 21),  // "changementWidgetActif"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 5),  // "index"
        QT_MOC_LITERAL(42, 14),  // "menu_selection"
        QT_MOC_LITERAL(57, 9),  // "selection"
        QT_MOC_LITERAL(67, 14),  // "jeuMAJ_Complet"
        QT_MOC_LITERAL(82, 11),  // "std::string"
        QT_MOC_LITERAL(94, 11),  // "int[30][60]"
        QT_MOC_LITERAL(106, 12),  // "jeuMAJ_Temps"
        QT_MOC_LITERAL(119, 17),  // "jeuMAJ_Adversaire"
        QT_MOC_LITERAL(137, 10),  // "Coordonnee"
        QT_MOC_LITERAL(148, 13),  // "jeuMAJ_Joueur"
        QT_MOC_LITERAL(162, 14),  // "jeuMineur_menu"
        QT_MOC_LITERAL(177, 15),  // "jeuMineur_block"
        QT_MOC_LITERAL(193, 15),  // "jeuMineur_temps"
        QT_MOC_LITERAL(209, 15)   // "jeuMineur_timer"
    },
    "ThreadMoteur",
    "changementWidgetActif",
    "",
    "index",
    "menu_selection",
    "selection",
    "jeuMAJ_Complet",
    "std::string",
    "int[30][60]",
    "jeuMAJ_Temps",
    "jeuMAJ_Adversaire",
    "Coordonnee",
    "jeuMAJ_Joueur",
    "jeuMineur_menu",
    "jeuMineur_block",
    "jeuMineur_temps",
    "jeuMineur_timer"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ThreadMoteur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    6,   80,    2, 0x06,    5 /* Public */,
       9,    1,   93,    2, 0x06,   12 /* Public */,
      10,    1,   96,    2, 0x06,   14 /* Public */,
      12,    2,   99,    2, 0x06,   16 /* Public */,
      13,    0,  104,    2, 0x06,   19 /* Public */,
      14,    1,  105,    2, 0x06,   20 /* Public */,
      15,    1,  108,    2, 0x06,   22 /* Public */,
      16,    1,  111,    2, 0x06,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, 0x80000000 | 7, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

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
        // method 'changementWidgetActif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'menu_selection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuMAJ_Complet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuMAJ_Temps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'jeuMAJ_Adversaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        // method 'jeuMAJ_Joueur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuMineur_menu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jeuMineur_block'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'jeuMineur_temps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuMineur_timer'
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
        case 0: _t->changementWidgetActif((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->menu_selection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->jeuMAJ_Complet((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int[30][60]>>(_a[6]))); break;
        case 3: _t->jeuMAJ_Temps((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->jeuMAJ_Adversaire((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1]))); break;
        case 5: _t->jeuMAJ_Joueur((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->jeuMineur_menu(); break;
        case 7: _t->jeuMineur_block((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 8: _t->jeuMineur_temps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->jeuMineur_timer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::changementWidgetActif; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::menu_selection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(std::string , int , std::string , int , int , int [30][60]);
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Complet; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(std::string );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Temps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(Coordonnee );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Adversaire; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(Coordonnee , int );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Joueur; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::jeuMineur_menu; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(float );
            if (_t _q_method = &ThreadMoteur::jeuMineur_block; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuMineur_temps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuMineur_timer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ThreadMoteur::changementWidgetActif(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadMoteur::menu_selection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadMoteur::jeuMAJ_Complet(std::string _t1, int _t2, std::string _t3, int _t4, int _t5, int _t6[30][60])
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadMoteur::jeuMAJ_Temps(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadMoteur::jeuMAJ_Adversaire(Coordonnee _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ThreadMoteur::jeuMAJ_Joueur(Coordonnee _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ThreadMoteur::jeuMineur_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ThreadMoteur::jeuMineur_block(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ThreadMoteur::jeuMineur_temps(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ThreadMoteur::jeuMineur_timer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
