#include "WidgetRiviere.h"

WidgetRiviere::WidgetRiviere(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    QImage riviere1("Riviere1.png");
    QImage riviere2("Riviere2.png");
    QImage Pecheur("Pecheur.png");
    QImage BaleineDroite("Wailord_droite.png");
    QImage BaleineGauche("Wailord_gauche.png");

    riviere = 1;
 
    float hauteur_image = 0;
    float largeur_image = 0;
    float ratio_image = riviere1.height() / (riviere1.width() * 1.0);

    //toile = new QPainter(this);
    //toile->setRenderHint(QPainter::Antialiasing);
    //toile->setPen(Qt::NoPen);

    setMinimumSize(LARGEUR_MINIMUM_RIVIERE,HAUTEUR_MINIMUM_RIVIERE);

    if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
    {
        hauteur_image = ratio_image * float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        largeur_image = float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
    }
    else
    {
        hauteur_image = ratio_image * float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        largeur_image = float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
    }

    system("cls");
    std::cout << riviere1.height() << std::endl << riviere1.width() << std::endl;
    std::cout << ratio_image << std::endl;
    std::cout << hauteur_image << std::endl << largeur_image << std::endl;

    riviere1 = riviere1.scaled(largeur_image, hauteur_image);

    //Connexions
    connect(threadMoteur, SIGNAL(jeuMAJ_Riviere(int)), this, SLOT(MAJ_Riviere(int)));
    connect(threadMoteur, SIGNAL(jeuMAJ_Pecheur(int)), this, SLOT(MAJ_Pecheur(int)));
    connect(threadMoteur, SIGNAL(jeuMAJ_Baleine(int)), this, SLOT(MAJ_Baleine(int)));
}

WidgetRiviere::~WidgetRiviere()
{}

void WidgetRiviere::paintEvent(QPaintEvent* event)
{
    QImage riviere1("Riviere1.png");
    QImage riviere2("Riviere2.png");
    QImage Pecheur("Pecheur.png");
    QImage BaleineDroite("Wailord_droite.png");
    QImage BaleineGauche("Wailord_gauche.png");

    QPainter toile;
    toile.setRenderHint(QPainter::Antialiasing, false);
    toile.setRenderHint(QPainter::SmoothPixmapTransform, false);
    toile.setPen(Qt::NoPen);

    toile.setBrush(Qt::black);
    toile.drawRect(0, 0, width(), height());

   if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
    {
        taille_riviere = float(height() / (HAUTEUR_RIVIERE * 1.0));
    }
    else
    {
        taille_riviere = float(width() / (LARGEUR_RIVIERE * 1.0));
    }

    espace_y = (height() - taille_riviere * HAUTEUR_CARTE) / 2;
    espace_x = (width() - taille_riviere * LARGEUR_CARTE) / 2;

    /*for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            float x = espace_x + taille_riviere * c;
            float y = espace_y + taille_riviere * r;

            QPoint diamondPoints[] =
            {
                QPoint(x + taille_riviere / 2, y),
                QPoint(x + taille_riviere, y + taille_riviere / 2),
                QPoint(x + taille_riviere / 2, y + taille_riviere),
                QPoint(x, y + taille_riviere / 2)
            };

            switch (q_riviere[r][c])
            {
            case VIDE:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_riviere, taille_riviere);
                break;
            case MINI_JEU:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_riviere, taille_riviere);

                toile.setBrush(Qt::blue);
                toile.drawRect(x, y, taille_riviere, taille_riviere);
                break;
            case JOUEUR:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_riviere, taille_riviere);

                toile.setBrush(Qt::darkGreen);
                toile.drawEllipse(x, y, taille_riviere, taille_riviere);
                break;
            case ADVERSAIRE:
                toile.setBrush(Qt::white);
                toile.drawRect(x, y, taille_riviere, taille_riviere);

                toile.setBrush(Qt::red);
                toile.drawPolygon(diamondPoints, 4);
                break;
            case PLEIN:
                toile.setBrush(Qt::black);
                toile.drawRect(x, y, taille_riviere, taille_riviere);
                break;
            default:
                break;
            }
        }
    }*/

    //Émile

    if(riviere == 1)
    {
        float hauteur_image = 0;
        float largeur_image = 0;
        float ratio_image = riviere1.height() / (riviere1.width() * 1.0);
        //#define TAILLE_IMAGE 10;

        if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
        {
            hauteur_image = ratio_image * float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
            largeur_image = float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        }
        else
        {
            hauteur_image = ratio_image * float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
            largeur_image = float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        }

        system("cls");
        std::cout << riviere1.height() << std::endl << riviere1.width() << std::endl;
        std::cout << ratio_image << std::endl;
        std::cout << hauteur_image << std::endl << largeur_image << std::endl;

        riviere1 = riviere1.scaled(largeur_image, hauteur_image);



        espace_y = (height() - taille_riviere * HAUTEUR_CARTE) / 2;
        espace_x = (width() - taille_riviere * LARGEUR_CARTE) / 2;

        toile.drawImage(espace_x, espace_y, riviere1);
    }
    else
    {
        float hauteur_image = 0;
        float largeur_image = 0;
        float ratio_image = riviere2.height() / (riviere2.width() * 1.0);
        //#define TAILLE_IMAGE 10;

        if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
        {
            hauteur_image = ratio_image * float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
            largeur_image = float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        }
        else
        {
            hauteur_image = ratio_image * float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
            largeur_image = float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
        }

        system("cls");
        std::cout << riviere2.height() << std::endl << riviere2.width() << std::endl;
        std::cout << ratio_image << std::endl;
        std::cout << hauteur_image << std::endl << largeur_image << std::endl;

        riviere1 = riviere2.scaled(largeur_image, hauteur_image);



        espace_y = (height() - taille_riviere * HAUTEUR_CARTE) / 2;
        espace_x = (width() - taille_riviere * LARGEUR_CARTE) / 2;

        toile.drawImage(espace_x, espace_y, riviere1);
    }


}

void WidgetRiviere::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    update();
}

//Slots
void WidgetRiviere::MAJ_Riviere(int q_riviere)
{
    if (q_riviere == 1)
    {
        riviere = 1;
    }
    else if(q_riviere == 2)
    {
        riviere = 2;
    }
    update();
}
void WidgetRiviere::MAJ_Baleine(int c)
{
    float x = espace_x + taille_riviere * c;
    float y = espace_y + taille_riviere * c;

    QList<QPoint> diamondPoints =
    {
        QPoint(x + taille_riviere / 2, y),
        QPoint(x + taille_riviere, y + taille_riviere / 2),
        QPoint(x + taille_riviere / 2, y + taille_riviere),
        QPoint(x, y + taille_riviere / 2)
    };

    QPolygon losange(diamondPoints);

    //update(losange.boundingRect());
}
void WidgetRiviere::MAJ_Pecheur(int c)
{

}