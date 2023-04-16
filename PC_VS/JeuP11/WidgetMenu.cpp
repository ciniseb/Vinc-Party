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
Description: UI du menu
====================================================================================================*/
#include "WidgetMenu.h"

WidgetMenu::WidgetMenu(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    espace_x = 0;
    espace_y = 0;

    //UI
    bouton_jouer = new QPushButton("Jouer");
    bouton_jouer->setCheckable(true);
    bouton_jouer->setFixedSize(500, 50);

    bouton_pointages = new QPushButton("Pointages");
    bouton_pointages->setCheckable(true);
    bouton_pointages->setFixedSize(500, 50);

    bouton_quitter = new QPushButton("Quitter");
    bouton_quitter->setCheckable(true);
    bouton_quitter->setFixedSize(500, 50);

    layout_boutons = new QVBoxLayout();
    layout_boutons->addWidget(bouton_jouer);
    layout_boutons->addWidget(bouton_pointages);
    layout_boutons->addSpacing(50);
    layout_boutons->addWidget(bouton_quitter);

    layout_principal = new QGridLayout();
    //layout_principal->addItem();
    layout_principal->addLayout(layout_boutons, 0, 0, 1, 1, Qt::AlignCenter);
    //horizontalSpacer = new QSpacerItem(200, 200, QSizePolicy::Fixed, QSizePolicy::Minimum);
    //layout_principal->addItem(horizontalSpacer, 0, 1, 1, 1);
    //verticalSpacer = new QSpacerItem(200, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);
    //layout_principal->addItem(verticalSpacer, 1, 0, 1, 1);

    setLayout(layout_principal);

    svg_fond = new QSvgRenderer(QString("le_chemin_de_croix.svg"));

    //Connexions
    connect(threadMoteur, SIGNAL(menu_selection(int)), this, SLOT(selection(int)));
}

WidgetMenu::~WidgetMenu()
{
    delete bouton_jouer;
    delete bouton_pointages;
    delete bouton_quitter;

    delete layout_boutons;
    delete layout_principal;

    delete threadMoteur;
}

void WidgetMenu::paintEvent(QPaintEvent* event)
{
    QPainter toile(this);
    toile.setRenderHint(QPainter::Antialiasing, false);
    toile.setRenderHint(QPainter::SmoothPixmapTransform, false);
    toile.setPen(Qt::NoPen);

    //Couleurs
    QBrush noir(QColor(0, 0, 0));

    toile.setBrush(noir);
    toile.drawRect(0, 0, width(), height());

    QImage image(QString("le_chemin_de_croix.svg"));
    image = image.scaled(QSize(width(), height()), Qt::KeepAspectRatio);

    espace_y = (height() - image.height()) / 2;
    espace_x = (width() - image.width()) / 2;

    toile.drawImage(espace_x, espace_y, image);
    QWidget::paintEvent(event);
    

    /*QPainter toile(this);
    toile.setRenderHint(QPainter::Antialiasing, false);
    toile.setRenderHint(QPainter::SmoothPixmapTransform, false);
    toile.setPen(Qt::NoPen);

    //Couleurs
    //QBrush brush(QColor("#"));
    QBrush brun(QColor(60, 45, 30));
    QBrush beige(QColor(100, 85, 70));
    QBrush rouge(QColor(255, 0, 0));
    QBrush bleu(QColor(0, 0, 255));
    QBrush noir(QColor(0, 0, 0));

    toile.setBrush(brun);
    toile.drawRect(0, 0, width(), height());

    if (width() * HAUTEUR_CARTE > height() * LARGEUR_CARTE)
    {
        taille_tuile = float(height() / (HAUTEUR_CARTE * 1.0));
    }
    else
    {
        taille_tuile = float(width() / (LARGEUR_CARTE * 1.0));
    }

    espace_y = (height() - taille_tuile * HAUTEUR_CARTE) / 2;
    espace_x = (width() - taille_tuile * LARGEUR_CARTE) / 2;

    QImage pixmap_mj("clef2.png");
    pixmap_mj = pixmap_mj.scaled(taille_tuile - PADDING * 2, taille_tuile - PADDING * 2, Qt::KeepAspectRatio);

    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            float x = espace_x + taille_tuile * c;
            float y = espace_y + taille_tuile * r;

            if (q_carte[r][c] == VIDE || q_carte[r][c] == MINI_JEU)
            {
                toile.setBrush(beige);
                toile.drawRect(x, y, taille_tuile, taille_tuile);

                if (r > 0 && q_carte[r - 1][c] == VIDE)
                {
                    toile.drawRect(x, y - taille_tuile / 2, taille_tuile, taille_tuile);
                }
                if (c > 0 && q_carte[r][c - 1] == VIDE)
                {
                    toile.drawRect(x - taille_tuile / 2, y, taille_tuile, taille_tuile);
                }
                if (r < HAUTEUR_CARTE - 1 && q_carte[r + 1][c] == VIDE)
                {
                    toile.drawRect(x, y + taille_tuile / 2, taille_tuile, taille_tuile);
                }
                if (c < LARGEUR_CARTE - 1 && q_carte[r][c + 1] == VIDE)
                {
                    toile.drawRect(x + taille_tuile / 2, y, taille_tuile, taille_tuile);
                }
            }

            if (q_carte[r][c] == MINI_JEU)
            {
                toile.drawImage(x + PADDING, y + PADDING, pixmap_mj);
            }
        }
    }

    toile.setBrush(noir);
    toile.drawEllipse(espace_x + taille_tuile * joueur.position.X + PADDING, espace_y + taille_tuile * joueur.position.Y + PADDING, taille_tuile - PADDING * 2, taille_tuile - PADDING * 2);

    if (distance(joueur.position, adversaire.position) <= RAYON_VISION || VISION_NOCTURNE)
    {
        QPoint diamondPoints[] =
        {
            QPoint(espace_x + taille_tuile * adversaire.position.X + taille_tuile / 2, espace_y + taille_tuile * adversaire.position.Y + PADDING),
            QPoint(espace_x + taille_tuile * adversaire.position.X + taille_tuile - PADDING, espace_y + taille_tuile * adversaire.position.Y + taille_tuile / 2),
            QPoint(espace_x + taille_tuile * adversaire.position.X + taille_tuile / 2, espace_y + taille_tuile * adversaire.position.Y + taille_tuile - PADDING),
            QPoint(espace_x + taille_tuile * adversaire.position.X + PADDING, espace_y + taille_tuile * adversaire.position.Y + taille_tuile / 2)
        };
        toile.setBrush(rouge);
        toile.drawPolygon(diamondPoints, 4);
    }*/
}

void WidgetMenu::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    repaint();
}

//Slots
void WidgetMenu::selection(int selection)
{
    switch (selection)
    {
    case 0:
        bouton_jouer->setChecked(true);
        bouton_pointages->setChecked(false);
        bouton_quitter->setChecked(false);
        break;
    case 1:
        bouton_jouer->setChecked(false);
        bouton_pointages->setChecked(true);
        bouton_quitter->setChecked(false);

        break;
    case 2:
        bouton_jouer->setChecked(false);
        bouton_pointages->setChecked(false);
        bouton_quitter->setChecked(true);
        break;
    default:
        break;
    }
}