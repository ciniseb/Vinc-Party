/****************************************************************************
** Meta object code from reading C++ file 'WidgetCarte.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../WidgetCarte.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetCarte.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_WidgetCarte_t {
    uint offsetsAndSizes[12];
    char stringdata0[12];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[11];
    char stringdata5[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WidgetCarte_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_WidgetCarte_t qt_meta_stringdata_WidgetCarte = {
    {
        QT_MOC_LITERAL(0, 11),  // "WidgetCarte"
        QT_MOC_LITERAL(12, 9),  // "MAJ_Carte"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 17),  // "QList<QList<int>>"
        QT_MOC_LITERAL(41, 10),  // "MAJ_Acteur"
        QT_MOC_LITERAL(52, 6)   // "Acteur"
    },
    "WidgetCarte",
    "MAJ_Carte",
    "",
    "QList<QList<int>>",
    "MAJ_Acteur",
    "Acteur"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_WidgetCarte[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       4,    2,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject WidgetCarte::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidgetCarte.offsetsAndSizes,
    qt_meta_data_WidgetCarte,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_WidgetCarte_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WidgetCarte, std::true_type>,
        // method 'MAJ_Carte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QVector<int>>, std::false_type>,
        // method 'MAJ_Acteur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Acteur, std::false_type>
    >,
    nullptr
} };

void WidgetCarte::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetCarte *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MAJ_Carte((*reinterpret_cast< std::add_pointer_t<QList<QList<int>>>>(_a[1]))); break;
        case 1: _t->MAJ_Acteur((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Acteur>>(_a[2]))); break;
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

const QMetaObject *WidgetCarte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetCarte::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetCarte.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetCarte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
