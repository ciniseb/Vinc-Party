#include "WidgetCarte.h"

WidgetCarte::WidgetCarte(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

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
    connect(threadMoteur, SIGNAL(jeu_MAJ_Carte(QVector<QVector<int>>)), this, SLOT(MAJ_Carte(QVector<QVector<int>>)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_Coordonnee(int, Coordonnee, Coordonnee)), this, SLOT(MAJ_Coordonnee(int, Coordonnee, Coordonnee)));
}

WidgetCarte::~WidgetCarte()
{}

void WidgetCarte::paintEvent(QPaintEvent* event)
{
    QPainter toile(this);
    toile.setRenderHint(QPainter::Antialiasing, false);
    toile.setRenderHint(QPainter::SmoothPixmapTransform, false);
    toile.setPen(Qt::NoPen);

    toile.setBrush(Qt::black);
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
    pixmap_mj = pixmap_mj.scaled(taille_tuile - PADDING*2, taille_tuile - PADDING*2, Qt::KeepAspectRatio);

    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            float x = espace_x + taille_tuile * c;
            float y = espace_y + taille_tuile * r;

            QPoint diamondPoints[] =
            {
                QPoint(x + taille_tuile / 2, y + PADDING),
                QPoint(x + taille_tuile - PADDING, y + taille_tuile / 2),
                QPoint(x + taille_tuile / 2, y + taille_tuile - PADDING),
                QPoint(x + PADDING, y + taille_tuile / 2)
            };

            switch (q_carte[r][c])
            {
            case VIDE:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_tuile, taille_tuile);
                break;
            case MINI_JEU:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_tuile, taille_tuile);

                toile.drawImage(x + PADDING, y + PADDING, pixmap_mj);
                //toile.setBrush(Qt::green);
                //toile.drawRect(x + PADDING, y + PADDING, taille_tuile - PADDING * 2, taille_tuile - PADDING * 2);
                break;
            case JOUEUR:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_tuile, taille_tuile);

                toile.setBrush(Qt::blue);
                toile.drawEllipse(x + PADDING, y + PADDING, taille_tuile - PADDING * 2, taille_tuile - PADDING * 2);
                break;
            case ADVERSAIRE:
                toile.setBrush(Qt::white);
                //std::cout << x << ", " << y << std::endl;
                toile.drawRect(x, y, taille_tuile, taille_tuile);

                toile.setBrush(Qt::red);
                toile.drawPolygon(diamondPoints, 4);
                break;
            case PLEIN:
                toile.setBrush(Qt::black);
                toile.drawRect(x, y, taille_tuile, taille_tuile);
                break;
            default:
                break;
            }
        }
    }

    /*
    QImage image("MicrosoftTeams-image.png");

    float hauteur_image = 0;
    float largeur_image = 0;
    float ratio_image = image.height() / (image.width() * 1.0);

    if (width() * HAUTEUR_CARTE > height() * LARGEUR_CARTE)
    {
        hauteur_image = ratio_image * float(height() / (HAUTEUR_CARTE * 1.0)) * 1;
        largeur_image = float(height() / (HAUTEUR_CARTE * 1.0)) * 1;
    }
    else
    {
        hauteur_image = ratio_image * float(width() / (LARGEUR_CARTE * 1.0)) * 1;
        largeur_image = float(width() / (LARGEUR_CARTE * 1.0)) * 1;
    }

    image = image.scaled(largeur_image, hauteur_image);
    
    toile.drawImage(x, y, image);
    */
}

void WidgetCarte::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    repaint();
}

//Slots
void WidgetCarte::MAJ_Carte(QVector<QVector<int>> q_carte)
{
    this->q_carte = q_carte;
    repaint();
}
void WidgetCarte::MAJ_Coordonnee(int remplissage, Coordonnee xc, Coordonnee c)
{
    if (q_carte[xc.Y][xc.X] != MINI_JEU)
    {
        q_carte[xc.Y][xc.X] = VIDE;
        std::cout << "Case painte VIDE : (" << xc.X << ", " << xc.Y << ")" << std::endl;
    }
    else
    {
        std::cout << "MINI_JEU" << std::endl;
    }

    bool mj = false;
    if (q_carte[c.Y][c.X] == MINI_JEU)
    {
        mj = true;
    }

    switch (remplissage)
    {
    case JOUEUR:
        q_carte[c.Y][c.X] = JOUEUR;
        break;
    case ADVERSAIRE:
        q_carte[c.Y][c.X] = ADVERSAIRE;
        break;
    default:
        break;
    }

    repaint(espace_x + taille_tuile * xc.X, espace_y + taille_tuile * xc.Y, taille_tuile, taille_tuile);
    repaint(espace_x + taille_tuile * c.X, espace_y + taille_tuile * c.Y, taille_tuile, taille_tuile);

    if (mj)
    {
        q_carte[c.Y][c.X] = MINI_JEU;
    }
}