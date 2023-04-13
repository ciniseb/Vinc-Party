/****************************************************************************
** Meta object code from reading C++ file 'ThreadMoteur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ThreadMoteur.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadMoteur.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ThreadMoteur_t {
    uint offsetsAndSizes[84];
    char stringdata0[13];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[15];
    char stringdata5[10];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[13];
    char stringdata9[15];
    char stringdata10[16];
    char stringdata11[16];
    char stringdata12[12];
    char stringdata13[11];
    char stringdata14[16];
    char stringdata15[15];
    char stringdata16[21];
    char stringdata17[19];
    char stringdata18[21];
    char stringdata19[14];
    char stringdata20[17];
    char stringdata21[17];
    char stringdata22[14];
    char stringdata23[18];
    char stringdata24[15];
    char stringdata25[7];
    char stringdata26[19];
    char stringdata27[11];
    char stringdata28[10];
    char stringdata29[13];
    char stringdata30[22];
    char stringdata31[20];
    char stringdata32[20];
    char stringdata33[20];
    char stringdata34[24];
    char stringdata35[20];
    char stringdata36[24];
    char stringdata37[15];
    char stringdata38[16];
    char stringdata39[16];
    char stringdata40[16];
    char stringdata41[10];
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
        QT_MOC_LITERAL(67, 15),  // "Pointages_Right"
        QT_MOC_LITERAL(83, 14),  // "Pointages_Left"
        QT_MOC_LITERAL(98, 12),  // "Pointages_Up"
        QT_MOC_LITERAL(111, 14),  // "Pointages_Down"
        QT_MOC_LITERAL(126, 15),  // "Pointage_Select"
        QT_MOC_LITERAL(142, 15),  // "Pointages_Names"
        QT_MOC_LITERAL(158, 11),  // "std::string"
        QT_MOC_LITERAL(170, 10),  // "playerName"
        QT_MOC_LITERAL(181, 15),  // "Pointages_Level"
        QT_MOC_LITERAL(197, 14),  // "Pointages_Time"
        QT_MOC_LITERAL(212, 20),  // "Pointages_TimePerLev"
        QT_MOC_LITERAL(233, 18),  // "Pointages_Distance"
        QT_MOC_LITERAL(252, 20),  // "jeu_MAJ_Informations"
        QT_MOC_LITERAL(273, 13),  // "jeu_MAJ_Temps"
        QT_MOC_LITERAL(287, 16),  // "jeu_MAJ_Distance"
        QT_MOC_LITERAL(304, 16),  // "jeu_MAJ_MiniJeux"
        QT_MOC_LITERAL(321, 13),  // "jeu_MAJ_Carte"
        QT_MOC_LITERAL(335, 17),  // "QList<QList<int>>"
        QT_MOC_LITERAL(353, 14),  // "jeu_MAJ_Acteur"
        QT_MOC_LITERAL(368, 6),  // "Acteur"
        QT_MOC_LITERAL(375, 18),  // "jeu_MAJ_Coordonnee"
        QT_MOC_LITERAL(394, 10),  // "Coordonnee"
        QT_MOC_LITERAL(405, 9),  // "AjoutNote"
        QT_MOC_LITERAL(415, 12),  // "Update_score"
        QT_MOC_LITERAL(428, 21),  // "Demarrage_WidgetPiano"
        QT_MOC_LITERAL(450, 19),  // "jeuPecheMAJ_Riviere"
        QT_MOC_LITERAL(470, 19),  // "jeuPecheMAJ_Pecheur"
        QT_MOC_LITERAL(490, 19),  // "jeuPecheMAJ_Baleine"
        QT_MOC_LITERAL(510, 23),  // "jeuPecheMAJ_ProgressBar"
        QT_MOC_LITERAL(534, 19),  // "jeuPecheMAJ_Message"
        QT_MOC_LITERAL(554, 23),  // "jeuPecheMAJ_Instruction"
        QT_MOC_LITERAL(578, 14),  // "jeuMineur_menu"
        QT_MOC_LITERAL(593, 15),  // "jeuMineur_block"
        QT_MOC_LITERAL(609, 15),  // "jeuMineur_temps"
        QT_MOC_LITERAL(625, 15),  // "jeuMineur_timer"
        QT_MOC_LITERAL(641, 9)   // "nomJoueur"
    },
    "ThreadMoteur",
    "changementWidgetActif",
    "",
    "index",
    "menu_selection",
    "selection",
    "Pointages_Right",
    "Pointages_Left",
    "Pointages_Up",
    "Pointages_Down",
    "Pointage_Select",
    "Pointages_Names",
    "std::string",
    "playerName",
    "Pointages_Level",
    "Pointages_Time",
    "Pointages_TimePerLev",
    "Pointages_Distance",
    "jeu_MAJ_Informations",
    "jeu_MAJ_Temps",
    "jeu_MAJ_Distance",
    "jeu_MAJ_MiniJeux",
    "jeu_MAJ_Carte",
    "QList<QList<int>>",
    "jeu_MAJ_Acteur",
    "Acteur",
    "jeu_MAJ_Coordonnee",
    "Coordonnee",
    "AjoutNote",
    "Update_score",
    "Demarrage_WidgetPiano",
    "jeuPecheMAJ_Riviere",
    "jeuPecheMAJ_Pecheur",
    "jeuPecheMAJ_Baleine",
    "jeuPecheMAJ_ProgressBar",
    "jeuPecheMAJ_Message",
    "jeuPecheMAJ_Instruction",
    "jeuMineur_menu",
    "jeuMineur_block",
    "jeuMineur_temps",
    "jeuMineur_timer",
    "nomJoueur"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ThreadMoteur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      32,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x06,    1 /* Public */,
       4,    1,  215,    2, 0x06,    3 /* Public */,
       6,    0,  218,    2, 0x06,    5 /* Public */,
       7,    0,  219,    2, 0x06,    6 /* Public */,
       8,    0,  220,    2, 0x06,    7 /* Public */,
       9,    0,  221,    2, 0x06,    8 /* Public */,
      10,    0,  222,    2, 0x06,    9 /* Public */,
      11,    1,  223,    2, 0x06,   10 /* Public */,
      14,    1,  226,    2, 0x06,   12 /* Public */,
      15,    1,  229,    2, 0x06,   14 /* Public */,
      16,    1,  232,    2, 0x06,   16 /* Public */,
      17,    1,  235,    2, 0x06,   18 /* Public */,
      18,    5,  238,    2, 0x06,   20 /* Public */,
      19,    1,  249,    2, 0x06,   26 /* Public */,
      20,    1,  252,    2, 0x06,   28 /* Public */,
      21,    1,  255,    2, 0x06,   30 /* Public */,
      22,    1,  258,    2, 0x06,   32 /* Public */,
      24,    2,  261,    2, 0x06,   34 /* Public */,
      26,    2,  266,    2, 0x06,   37 /* Public */,
      28,    1,  271,    2, 0x06,   40 /* Public */,
      29,    1,  274,    2, 0x06,   42 /* Public */,
      30,    0,  277,    2, 0x06,   44 /* Public */,
      31,    1,  278,    2, 0x06,   45 /* Public */,
      32,    1,  281,    2, 0x06,   47 /* Public */,
      33,    1,  284,    2, 0x06,   49 /* Public */,
      34,    1,  287,    2, 0x06,   51 /* Public */,
      35,    0,  290,    2, 0x06,   53 /* Public */,
      36,    0,  291,    2, 0x06,   54 /* Public */,
      37,    0,  292,    2, 0x06,   55 /* Public */,
      38,    1,  293,    2, 0x06,   56 /* Public */,
      39,    1,  296,    2, 0x06,   58 /* Public */,
      40,    1,  299,    2, 0x06,   60 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      41,    1,  302,    2, 0x0a,   62 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 25,    2,    2,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 27,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,    2,

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
        // method 'Pointages_Right'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pointages_Left'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pointages_Up'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pointages_Down'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pointage_Select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pointages_Names'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'Pointages_Level'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Pointages_Time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'Pointages_TimePerLev'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'Pointages_Distance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeu_MAJ_Informations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeu_MAJ_Temps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'jeu_MAJ_Distance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeu_MAJ_MiniJeux'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeu_MAJ_Carte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QVector<int>>, std::false_type>,
        // method 'jeu_MAJ_Acteur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Acteur, std::false_type>,
        // method 'jeu_MAJ_Coordonnee'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        QtPrivate::TypeAndForceComplete<Coordonnee, std::false_type>,
        // method 'AjoutNote'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Update_score'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Demarrage_WidgetPiano'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jeuPecheMAJ_Riviere'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuPecheMAJ_Pecheur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuPecheMAJ_Baleine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuPecheMAJ_ProgressBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'jeuPecheMAJ_Message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jeuPecheMAJ_Instruction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'nomJoueur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>
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
        case 2: _t->Pointages_Right(); break;
        case 3: _t->Pointages_Left(); break;
        case 4: _t->Pointages_Up(); break;
        case 5: _t->Pointages_Down(); break;
        case 6: _t->Pointage_Select(); break;
        case 7: _t->Pointages_Names((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 8: _t->Pointages_Level((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->Pointages_Time((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->Pointages_TimePerLev((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 11: _t->Pointages_Distance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->jeu_MAJ_Informations((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 13: _t->jeu_MAJ_Temps((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 14: _t->jeu_MAJ_Distance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->jeu_MAJ_MiniJeux((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->jeu_MAJ_Carte((*reinterpret_cast< std::add_pointer_t<QList<QList<int>>>>(_a[1]))); break;
        case 17: _t->jeu_MAJ_Acteur((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Acteur>>(_a[2]))); break;
        case 18: _t->jeu_MAJ_Coordonnee((*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Coordonnee>>(_a[2]))); break;
        case 19: _t->AjoutNote((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->Update_score((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->Demarrage_WidgetPiano(); break;
        case 22: _t->jeuPecheMAJ_Riviere((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->jeuPecheMAJ_Pecheur((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->jeuPecheMAJ_Baleine((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->jeuPecheMAJ_ProgressBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->jeuPecheMAJ_Message(); break;
        case 27: _t->jeuPecheMAJ_Instruction(); break;
        case 28: _t->jeuMineur_menu(); break;
        case 29: _t->jeuMineur_block((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 30: _t->jeuMineur_temps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->jeuMineur_timer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->nomJoueur((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
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
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Pointages_Right; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Pointages_Left; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Pointages_Up; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Pointages_Down; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Pointage_Select; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(const std::string & );
            if (_t _q_method = &ThreadMoteur::Pointages_Names; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::Pointages_Level; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(double );
            if (_t _q_method = &ThreadMoteur::Pointages_Time; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(double );
            if (_t _q_method = &ThreadMoteur::Pointages_TimePerLev; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::Pointages_Distance; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(std::string , int , std::string , int , int );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Informations; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(std::string );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Temps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Distance; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_MiniJeux; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(QVector<QVector<int>> );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Carte; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int , Acteur );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Acteur; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(Coordonnee , Coordonnee );
            if (_t _q_method = &ThreadMoteur::jeu_MAJ_Coordonnee; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::AjoutNote; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::Update_score; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::Demarrage_WidgetPiano; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_Riviere; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_Pecheur; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_Baleine; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_ProgressBar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_Message; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::jeuPecheMAJ_Instruction; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)();
            if (_t _q_method = &ThreadMoteur::jeuMineur_menu; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(float );
            if (_t _q_method = &ThreadMoteur::jeuMineur_block; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuMineur_temps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (ThreadMoteur::*)(int );
            if (_t _q_method = &ThreadMoteur::jeuMineur_timer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 31;
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
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
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
void ThreadMoteur::Pointages_Right()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ThreadMoteur::Pointages_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ThreadMoteur::Pointages_Up()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ThreadMoteur::Pointages_Down()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ThreadMoteur::Pointage_Select()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ThreadMoteur::Pointages_Names(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ThreadMoteur::Pointages_Level(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ThreadMoteur::Pointages_Time(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ThreadMoteur::Pointages_TimePerLev(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ThreadMoteur::Pointages_Distance(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ThreadMoteur::jeu_MAJ_Informations(std::string _t1, int _t2, std::string _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ThreadMoteur::jeu_MAJ_Temps(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ThreadMoteur::jeu_MAJ_Distance(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ThreadMoteur::jeu_MAJ_MiniJeux(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ThreadMoteur::jeu_MAJ_Carte(QVector<QVector<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void ThreadMoteur::jeu_MAJ_Acteur(int _t1, Acteur _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void ThreadMoteur::jeu_MAJ_Coordonnee(Coordonnee _t1, Coordonnee _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void ThreadMoteur::AjoutNote(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void ThreadMoteur::Update_score(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void ThreadMoteur::Demarrage_WidgetPiano()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void ThreadMoteur::jeuPecheMAJ_Riviere(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void ThreadMoteur::jeuPecheMAJ_Pecheur(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void ThreadMoteur::jeuPecheMAJ_Baleine(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void ThreadMoteur::jeuPecheMAJ_ProgressBar(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void ThreadMoteur::jeuPecheMAJ_Message()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void ThreadMoteur::jeuPecheMAJ_Instruction()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void ThreadMoteur::jeuMineur_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void ThreadMoteur::jeuMineur_block(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void ThreadMoteur::jeuMineur_temps(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void ThreadMoteur::jeuMineur_timer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
