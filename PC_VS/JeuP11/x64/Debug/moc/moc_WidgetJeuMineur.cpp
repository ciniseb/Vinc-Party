/****************************************************************************
** Meta object code from reading C++ file 'WidgetJeuMineur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
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
struct qt_meta_stringdata_WidgetJeuMineur_t {
    uint offsetsAndSizes[14];
    char stringdata0[16];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[5];
    char stringdata5[13];
    char stringdata6[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WidgetJeuMineur_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_WidgetJeuMineur_t qt_meta_stringdata_WidgetJeuMineur = {
    {
        QT_MOC_LITERAL(0, 15),  // "WidgetJeuMineur"
        QT_MOC_LITERAL(16, 5),  // "debut"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 5),  // "temps"
        QT_MOC_LITERAL(29, 4),  // "time"
        QT_MOC_LITERAL(34, 12),  // "blockUpadate"
        QT_MOC_LITERAL(47, 11)   // "pourcentage"
    },
    "WidgetJeuMineur",
    "debut",
    "",
    "temps",
    "time",
    "blockUpadate",
    "pourcentage"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_WidgetJeuMineur[] = {

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
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    1,   33,    2, 0x0a,    2 /* Public */,
       5,    1,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Float,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject WidgetJeuMineur::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WidgetJeuMineur.offsetsAndSizes,
    qt_meta_data_WidgetJeuMineur,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_WidgetJeuMineur_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WidgetJeuMineur, std::true_type>,
        // method 'debut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'temps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'blockUpadate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void WidgetJeuMineur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetJeuMineur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->debut(); break;
        case 1: _t->temps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->blockUpadate((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
