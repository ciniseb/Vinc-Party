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
    QFont font;
    font.setPointSize(16);
    setFont(font);

    nom_joueur = new QLabel("Joueur : ");

    QPixmap pixmap_distance("distance.png");
    image_distance = new QLabel();
    image_distance->setPixmap(pixmap_distance.scaled(40, 40, Qt::KeepAspectRatio));
    distance = new QLabel("0");

    QPixmap pixmap_temps("temps.png");
    image_temps = new QLabel();
    image_temps->setPixmap(pixmap_temps.scaled(40, 40, Qt::KeepAspectRatio));
    temps = new QLabel("00:00:00");

    niveau = new QLabel("Niveau 0");

    mjx = new QLabel("0");
    QPixmap pixmap_mjx("clef2.png");
    image_mjx = new QLabel();
    image_mjx->setPixmap(pixmap_mjx.scaled(pixmap_mjx.width()*5, pixmap_mjx.height()*5, Qt::KeepAspectRatio));

    widget_informations = new QWidget();
    widget_informations->setFixedHeight(50);
    layout_informations = new QHBoxLayout(widget_informations);
    layout_informations->setContentsMargins(15, 0, 15, 0);
    layout_informations->setSpacing(15);
    layout_informations->addStretch(1);
    layout_informations->addWidget(nom_joueur);
    layout_informations->addStretch(1);
    layout_informations->addWidget(ligneVerticale());
    layout_informations->addWidget(image_distance);
    layout_informations->addWidget(distance);
    layout_informations->addWidget(ligneVerticale());
    layout_informations->addWidget(image_temps);
    layout_informations->addWidget(temps);
    layout_informations->addWidget(ligneVerticale());
    layout_informations->addWidget(niveau);
    layout_informations->addWidget(ligneVerticale());
    layout_informations->addWidget(mjx);
    layout_informations->addWidget(image_mjx);

    widgetCarte = new WidgetCarte(threadMoteur);

    layout_principal = new QVBoxLayout();
    layout_principal->setContentsMargins(0, 0, 0, 0);
    layout_principal->setSpacing(0);
    layout_principal->addWidget(widget_informations);
    layout_principal->addWidget(widgetCarte);

    setLayout(layout_principal);

    //Connexions
    connect(threadMoteur, SIGNAL(jeu_MAJ_Informations(std::string, int, std::string, int, int)), this, SLOT(MAJ_Informations(std::string, int, std::string, int, int)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_Temps(std::string)), this, SLOT(MAJ_Temps(std::string)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_Distance(int)), this, SLOT(MAJ_Distance(int)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_MiniJeux(int)), this, SLOT(MAJ_MiniJeux(int)));
}

WidgetJeu::~WidgetJeu()
{}

//Méthodes
QFrame* WidgetJeu::ligneVerticale()
{
    QFrame* ligne = new QFrame();
    ligne->setFrameShape(QFrame::VLine);
    ligne->setFrameShadow(QFrame::Plain);
    ligne->setLineWidth(3);

    QPalette palette = ligne->palette();
    palette.setColor(QPalette::WindowText, Qt::lightGray);
    ligne->setPalette(palette);

    return ligne;
}

//Slots
void WidgetJeu::MAJ_Informations(std::string nom, int d, std::string t, int n , int nb_mjx)
{
    nom_joueur->setText(QString::fromStdString("Joueur : " + nom));
    distance->setText(QString::number(d));
    temps->setText(QString::fromStdString(t));
    niveau->setText(QString::fromStdString("Niveau " + std::to_string(n)));
    mjx->setText(QString::number(nb_mjx));
}
void WidgetJeu::MAJ_Temps(std::string t)
{
    temps->setText(QString::fromStdString(t));
}
void WidgetJeu::MAJ_Distance(int d)
{
    distance->setText(QString::number(d));
}
void WidgetJeu::MAJ_MiniJeux(int nb_mjx)
{
    mjx->setText(QString::number(nb_mjx));
}