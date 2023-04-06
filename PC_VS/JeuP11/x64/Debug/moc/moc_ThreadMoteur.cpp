/****************************************************************************
** Meta object code from reading C++ file 'ThreadMoteur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ThreadMoteur.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadMoteur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
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
    uint offsetsAndSizes[30];
    char stringdata0[13];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[15];
    char stringdata5[10];
    char stringdata6[20];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[18];
    char stringdata10[13];
    char stringdata11[18];
    char stringdata12[11];
    char stringdata13[14];
    char stringdata14[16];
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
        QT_MOC_LITERAL(67, 19),  // "jeuMAJ_Informations"
        QT_MOC_LITERAL(87, 11),  // "std::string"
        QT_MOC_LITERAL(99, 12),  // "jeuMAJ_Carte"
        QT_MOC_LITERAL(112, 17),  // "QList<QList<int>>"
        QT_MOC_LITERAL(130, 12),  // "jeuMAJ_Temps"
        QT_MOC_LITERAL(143, 17),  // "jeuMAJ_Adversaire"
        QT_MOC_LITERAL(161, 10),  // "Coordonnee"
        QT_MOC_LITERAL(172, 13),  // "jeuMAJ_Joueur"
        QT_MOC_LITERAL(186, 15)   // "jeuMAJ_distance"
    },
    "ThreadMoteur",
    "changementWidgetActif",
    "",
    "index",
    "menu_selection",
    "selection",
    "jeuMAJ_Informations",
    "std::string",
    "jeuMAJ_Carte",
    "QList<QList<int>>",
    "jeuMAJ_Temps",
    "jeuMAJ_Adversaire",
    "Coordonnee",
    "jeuMAJ_Joueur",
    "jeuMAJ_distance"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ThreadMoteur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       6,    5,   68,    2, 0x06,    5 /* Public */,
       8,    1,   79,    2, 0x06,   11 /* Public */,
      10,    1,   82,    2, 0x06,   13 /* Public */,
      11,    1,   85,    2, 0x06,   15 /* Public */,
      13,    1,   88,    2, 0x06,   17 /* Public */,
      14,    1,   91,    2, 0x06,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
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
        // method 'jeuMAJ_Informations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuMAJ_Carte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QVector<int>>, std::false_type>,
        // method 'jeuMAJ_Temps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'jeuMAJ_Adversaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        // method 'jeuMAJ_Joueur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        // method 'jeuMAJ_distance'
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
        case 2: _t->jeuMAJ_Informations((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 3: _t->jeuMAJ_Carte((*reinterpret_cast< std::add_pointer_t<QList<QList<int>>>>(_a[1]))); break;
        case 4: _t->jeuMAJ_Temps((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->jeuMAJ_Adversaire((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1]))); break;
        case 6: _t->jeuMAJ_Joueur((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1]))); break;
        case 7: _t->jeuMAJ_distance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
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
            using _t = void (ThreadMoteur::*)(std::string , int , std::string , int , int );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Informations; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(QVector<QVector<int>> );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Carte; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(std::string );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Temps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(Coordonnee );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Adversaire; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(Coordonnee );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_Joueur; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuMAJ_distance; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
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
void ThreadMoteur::jeuMAJ_Informations(std::string _t1, int _t2, std::string _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadMoteur::jeuMAJ_Carte(QVector<QVector<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadMoteur::jeuMAJ_Temps(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ThreadMoteur::jeuMAJ_Adversaire(Coordonnee _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ThreadMoteur::jeuMAJ_Joueur(Coordonnee _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ThreadMoteur::jeuMAJ_distance(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
