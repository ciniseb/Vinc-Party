/****************************************************************************
** Meta object code from reading C++ file 'WidgetJeuMineurBlock.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../WidgetJeuMineurBlock.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetJeuMineurBlock.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_WidgetJeuMineurBlock_t {
    uint offsetsAndSizes[14];
    char stringdata0[21];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[15];
    char stringdata5[11];
    char stringdata6[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WidgetJeuMineurBlock_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_WidgetJeuMineurBlock_t qt_meta_stringdata_WidgetJeuMineurBlock = {
    {
        QT_MOC_LITERAL(0, 20),  // "WidgetJeuMineurBlock"
        QT_MOC_LITERAL(21, 9),  // "MAJ_Carte"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 17),  // "QList<QList<int>>"
        QT_MOC_LITERAL(50, 14),  // "MAJ_Adversaire"
        QT_MOC_LITERAL(65, 10),  // "Coordonnee"
        QT_MOC_LITERAL(76, 10)   // "MAJ_Joueur"
    },
    "WidgetJeuMineurBlock",
    "MAJ_Carte",
    "",
    "QList<QList<int>>",
    "MAJ_Adversaire",
    "Coordonnee",
    "MAJ_Joueur"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_WidgetJeuMineurBlock[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       4,    1,   35,    2, 0x0a,    3 /* Public */,
       6,    1,   38,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject WidgetJeuMineurBlock::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidgetJeuMineurBlock.offsetsAndSizes,
    qt_meta_data_WidgetJeuMineurBlock,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_WidgetJeuMineurBlock_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WidgetJeuMineurBlock, std::true_type>,
        // method 'MAJ_Carte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QVector<int>>, std::false_type>,
        // method 'MAJ_Adversaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        // method 'MAJ_Joueur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>
    >,
    nullptr
} };

void WidgetJeuMineurBlock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetJeuMineurBlock *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MAJ_Carte((*reinterpret_cast< std::add_pointer_t<QList<QList<int>>>>(_a[1]))); break;
        case 1: _t->MAJ_Adversaire((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1]))); break;
        case 2: _t->MAJ_Joueur((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
        }
    }
}

const QMetaObject *WidgetJeuMineurBlock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetJeuMineurBlock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetJeuMineurBlock.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetJeuMineurBlock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
