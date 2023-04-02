/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI du jeu
====================================================================================================*/
#include "WidgetJeu.h"

WidgetJeu::WidgetJeu(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //UI
    nom_joueur = new QLabel("Joueur : ");

    svg_distance = new QSvgWidget("losange.svg");
    svg_distance->setFixedSize(100, 100);
    distance = new QLabel("0");

    svg_temps = new QSvgWidget("losange.svg");
    temps = new QLabel("00:00:00");

    niveau = new QLabel("Niveau 0");

    mjx = new QLabel("0");
    svg_mjx = new QSvgWidget("losange.svg");

    layout_informations = new QHBoxLayout();
    layout_informations->addWidget(nom_joueur);
    layout_informations->addWidget(svg_distance);
    layout_informations->addWidget(distance);
    layout_informations->addWidget(svg_temps);
    layout_informations->addWidget(temps);
    layout_informations->addWidget(niveau);
    layout_informations->addWidget(mjx);
    layout_informations->addWidget(svg_mjx);


    //tuiles[HAUTEUR_CARTE][LARGEUR_CARTE];

    layout_principal = new QGridLayout();
    layout_principal->addLayout(layout_informations, 0, 0, 1, LARGEUR_CARTE, Qt::AlignCenter);

    setLayout(layout_principal);

    //Connexions
}

WidgetJeu::~WidgetJeu()
{}
