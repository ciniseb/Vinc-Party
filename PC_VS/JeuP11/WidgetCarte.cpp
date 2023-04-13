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

    /*joueur.position = {0, 0};
    joueur.ancienne_position = { 0, 0 };
    adversaire.position = { 0, 0 };
    adversaire.ancienne_position = { 0, 0 };*/

    //Connexions
    connect(threadMoteur, SIGNAL(jeu_MAJ_Carte(QVector<QVector<int>>)), this, SLOT(MAJ_Carte(QVector<QVector<int>>)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_Acteur(int, Acteur)), this, SLOT(MAJ_Acteur(int, Acteur)));
    connect(threadMoteur, SIGNAL(jeu_MAJ_Coordonnee(Coordonnee, Coordonnee)), this, SLOT(MAJ_Coordonnee(Coordonnee, Coordonnee)));
}

WidgetCarte::~WidgetCarte()
{}

void WidgetCarte::paintEvent(QPaintEvent* event)
{
    QPainter toile(this);
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
    pixmap_mj = pixmap_mj.scaled(taille_tuile - PADDING*2, taille_tuile - PADDING*2, Qt::KeepAspectRatio);

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
    }
}

void WidgetCarte::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    repaint();
}

//Méthodes
float WidgetCarte::distance(Coordonnee c1, Coordonnee c2)
{
    double a = abs(c2.X - c1.X);
    double b = abs(c2.Y - c1.Y);
    return sqrt((a * a) + (b * b));
}

//Slots
void WidgetCarte::MAJ_Carte(QVector<QVector<int>> q_carte)
{
    this->q_carte = q_carte;
    repaint();
}
void WidgetCarte::MAJ_Acteur(int type, Acteur acteur)
{
    switch (type)
    {
    case JOUEUR:
        joueur = acteur;
        //repaint(espace_x + taille_tuile * acteur.ancienne_position.X, espace_y + taille_tuile * acteur.ancienne_position.Y, taille_tuile, taille_tuile);
        break;
    case ADVERSAIRE:
        adversaire = acteur;
        //repaint(espace_x + taille_tuile * acteur.ancienne_position.X - taille_tuile, espace_y + taille_tuile * acteur.ancienne_position.Y - taille_tuile, taille_tuile * 3, taille_tuile * 3);
        break;
    default:
        break;
    }

    repaint();
    //repaint(espace_x + taille_tuile * acteur.ancienne_position.X, espace_y + taille_tuile * acteur.ancienne_position.Y, taille_tuile, taille_tuile);
    //repaint(espace_x + taille_tuile * acteur.position.X, espace_y + taille_tuile * acteur.position.Y, taille_tuile, taille_tuile);
}
/*void WidgetCarte::MAJ_Coordonnee(Coordonnee xc, Coordonnee c)
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
}*/