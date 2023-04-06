#include "WidgetCarte.h"

WidgetCarte::WidgetCarte(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //toile = new QPainter(this);
    //toile->setRenderHint(QPainter::Antialiasing);
    //toile->setPen(Qt::NoPen);

    setMinimumSize(LARGEUR_CARTE* TAILLE_MINIMUM_TUILE, HAUTEUR_CARTE* TAILLE_MINIMUM_TUILE);

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

    q_carte.resize(HAUTEUR_CARTE);
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        q_carte[r].resize(LARGEUR_CARTE);
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            q_carte[r][c] = VIDE;
        }
    }
    pos_joueur.X = 0;
    pos_joueur.Y = 0;
    pos_adversaire.X = 0;
    pos_adversaire.Y = 0;

    //Connexions
    connect(threadMoteur, SIGNAL(jeuMAJ_Carte(QVector<QVector<int>>)), this, SLOT(MAJ_Carte(QVector<QVector<int>>)));
    connect(threadMoteur, SIGNAL(jeuMAJ_Joueur(Coordonnee)), this, SLOT(MAJ_Joueur(Coordonnee)));
    connect(threadMoteur, SIGNAL(jeuMAJ_Adversaire(Coordonnee)), this, SLOT(MAJ_Adversaire(Coordonnee)));
}

WidgetCarte::~WidgetCarte()
{}

void WidgetCarte::paintEvent(QPaintEvent* event)
{
    toile = new QPainter(this);
    toile->setRenderHint(QPainter::Antialiasing, false);
    toile->setRenderHint(QPainter::SmoothPixmapTransform, false);
    toile->setPen(Qt::NoPen);

    toile->setBrush(Qt::black);
    toile->drawRect(0, 0, width(), height());

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

    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            float x = espace_x + taille_tuile * c;
            float y = espace_y + taille_tuile * r;

            QPoint diamondPoints[] =
            {
                QPoint(x + taille_tuile / 2, y),
                QPoint(x + taille_tuile, y + taille_tuile / 2),
                QPoint(x + taille_tuile / 2, y + taille_tuile),
                QPoint(x, y + taille_tuile / 2)
            };

            switch (q_carte[r][c])
            {
            case VIDE:
                toile->setBrush(Qt::white);
                toile->drawRect(x, y, taille_tuile, taille_tuile);
                break;
            case MINI_JEU:
                toile->setBrush(Qt::white);
                toile->drawRect(x, y, taille_tuile, taille_tuile);

                toile->setBrush(Qt::blue);
                toile->drawRect(x, y, taille_tuile, taille_tuile);
                break;
            case JOUEUR:
                toile->setBrush(Qt::white);
                toile->drawRect(x, y, taille_tuile, taille_tuile);

                toile->setBrush(Qt::darkGreen);
                toile->drawEllipse(x, y, taille_tuile, taille_tuile);
                break;
            case ADVERSAIRE:
                toile->setBrush(Qt::white);
                toile->drawRect(x, y, taille_tuile, taille_tuile);

                toile->setBrush(Qt::red);
                toile->drawPolygon(diamondPoints, 4);
                break;
            case PLEIN:
                toile->setBrush(Qt::black);
                toile->drawRect(x, y, taille_tuile, taille_tuile);
                break;
            default:
                break;
            }
        }
    }

    //Émile
    QImage image("MicrosoftTeams-image.png");

    float hauteur_image = 0;
    float largeur_image = 0;
    float ratio_image = image.height() / (image.width()*1.0);
#define TAILLE_IMAGE 10;

    if (width() * HAUTEUR_CARTE > height() * LARGEUR_CARTE)
    {
        hauteur_image = ratio_image * float(height() / (HAUTEUR_CARTE * 1.0)) * TAILLE_IMAGE;
        largeur_image = float(height() / (HAUTEUR_CARTE * 1.0)) * TAILLE_IMAGE;
    }
    else
    {
        hauteur_image = ratio_image * float(width() / (LARGEUR_CARTE * 1.0)) * TAILLE_IMAGE;
        largeur_image = float(width() / (LARGEUR_CARTE * 1.0)) * TAILLE_IMAGE;
    }

    system("cls");
    std::cout << image.height() << std::endl << image.width() << std::endl;
    std::cout << ratio_image << std::endl;
    std::cout << hauteur_image << std::endl << largeur_image << std::endl;

    image = image.scaled(largeur_image, hauteur_image);



    espace_y = (height() - taille_tuile * HAUTEUR_CARTE) / 2;
    espace_x = (width() - taille_tuile * LARGEUR_CARTE) / 2;

    toile->drawImage(espace_x, espace_y, image);

    delete toile;
}

void WidgetCarte::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    update();
}

//Slots
void WidgetCarte::MAJ_Carte(QVector<QVector<int>> q_carte)
{
    this->q_carte = q_carte;
    update();
}
void WidgetCarte::MAJ_Adversaire(Coordonnee c)
{
    float x = espace_x + taille_tuile * c.X;
    float y = espace_y + taille_tuile * c.Y;

    QList<QPoint> diamondPoints =
    {
        QPoint(x + taille_tuile / 2, y),
        QPoint(x + taille_tuile, y + taille_tuile / 2),
        QPoint(x + taille_tuile / 2, y + taille_tuile),
        QPoint(x, y + taille_tuile / 2)
    };

    QPolygon losange(diamondPoints);

    //update(losange.boundingRect());
}
void WidgetCarte::MAJ_Joueur(Coordonnee c)
{

}