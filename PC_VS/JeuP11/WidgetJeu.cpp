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

    svg_distance = new QSvgWidget(QString("gutgh0bq1nllg31iowl.svg"));
    svg_distance->setFixedSize(40, 40);
    distance = new QLabel("0");

    svg_temps = new QSvgWidget(QString("gutgh0bq1nllg31iowl.svg"));
    svg_temps->setFixedSize(40, 40);
    temps = new QLabel("00:00:00");

    niveau = new QLabel("Niveau 0");

    mjx = new QLabel("0");
    svg_mjx = new QSvgWidget(QString("gutgh0bq1nllg31iowl.svg"));
    svg_mjx->setFixedSize(40, 40);

    widget_informations = new QWidget();
    widget_informations->setFixedHeight(50);
    layout_informations = new QHBoxLayout(widget_informations);
    layout_informations->addWidget(nom_joueur);
    layout_informations->addWidget(svg_distance);
    layout_informations->addWidget(distance);
    layout_informations->addWidget(svg_temps);
    layout_informations->addWidget(temps);
    layout_informations->addWidget(niveau);
    layout_informations->addWidget(mjx);
    layout_informations->addWidget(svg_mjx);

    widgetCarte = new WidgetCarte(threadMoteur);

    layout_principal = new QVBoxLayout();
    layout_principal->setContentsMargins(0, 0, 0, 0);
    layout_principal->setSpacing(0);
    layout_principal->addWidget(widget_informations);
    layout_principal->addWidget(widgetCarte);

    setLayout(layout_principal);

    //Connexions
}

WidgetJeu::~WidgetJeu()
{}
