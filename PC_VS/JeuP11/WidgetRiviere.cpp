#include "WidgetRiviere.h"

WidgetRiviere::WidgetRiviere(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    riviere1 = new QPixmap ;
    riviere2 = new QPixmap;
    Pecheur = new QPixmap;
    BaleineDroite = new QPixmap;
    BaleineGauche = new QPixmap;

    riviere1->load("Riviere1.png");

    riviere = 1;
 
    /*float hauteur_image = 0;
    float largeur_image = 0;
    float ratio_image = riviere1->height() / (riviere1->width() * 1.0);

    //toile = new QPainter(this);
    //toile->setRenderHint(QPainter::Antialiasing);
    //toile->setPen(Qt::NoPen);

    /*setMinimumSize(LARGEUR_MINIMUM_RIVIERE, HAUTEUR_MINIMUM_RIVIERE);

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
    std::cout << riviere1->height() << std::endl << riviere1->width() << std::endl;
    std::cout << ratio_image << std::endl;
    std::cout << hauteur_image << std::endl << largeur_image << std::endl;

    int cropX = (riviere1->width() - largeur_image) / 2;
    int cropY = (riviere1->height() - hauteur_image) / 2;

    QPixmap riviereCopy = riviere1->copy(cropX, cropY, largeur_image, hauteur_image);

    QPixmap riviereScaled = riviereCopy.scaled(size());*/

    //Connexions
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_Riviere(int)), this, SLOT(MAJ_Riviere(int)));
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_Pecheur(int)), this, SLOT(MAJ_Pecheur(int)));
    connect(threadMoteur, SIGNAL(jeuPecheMAJ_Baleine(int)), this, SLOT(MAJ_Baleine(int)));
}

WidgetRiviere::~WidgetRiviere()
{}

void WidgetRiviere::paintEvent(QPaintEvent* event)
{

    /*QPainter painter(this);

    qreal targetAspectRatio = qreal(width()) / qreal(height());

    qreal sourceAspectRatio = qreal(riviere1.width()) / qreal(riviere1.height());

    int cropWidth;
    int cropHeight;

    if (targetAspectRatio > sourceAspectRatio)
    {
        cropWidth = riviere1.width();
        cropHeight = int(cropWidth / targetAspectRatio);
    }
    else
    {
        cropHeight = riviere1.height();
        cropWidth = int(cropHeight * targetAspectRatio);
    }

    int cropX = (riviere1.width() - cropWidth) / 2;
    int cropY = (riviere1.height() - cropHeight) / 2;

    QPixmap cropped_background = riviere1.copy(cropX, cropY, cropWidth, cropHeight);

    QPixmap scaled_backgroup = cropped_background.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    painter.drawPixmap(0, 0, scaled_backgroup);*/



         QPainter toile(this);
         toile.setRenderHint(QPainter::Antialiasing, false);
         toile.setRenderHint(QPainter::SmoothPixmapTransform, false);
         toile.setPen(Qt::NoPen);

         /*toile.setBrush(Qt::black);
         toile.drawRect(0, 0, width(), height());

        if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
         {
             taille_riviere = float(height() / (HAUTEUR_RIVIERE * 1.0));
         }
         else
         {
             taille_riviere = float(width() / (LARGEUR_RIVIERE * 1.0));
         }

         /*espace_y = (height() - taille_riviere * HAUTEUR_CARTE) / 2;
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
             float hauteur_riviere = 0;
             float largeur_riviere = 0;
             float ratio_riviere = riviere1->height() / (riviere1->width() * 1.0);
             //#define TAILLE_IMAGE 10;

             if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
             {
                 hauteur_riviere = ratio_riviere * float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
                 largeur_riviere = float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
             }
             else
             {
                 hauteur_riviere = ratio_riviere * float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
                 largeur_riviere = float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
             }

             system("cls");
             std::cout << riviere1->height() << std::endl << riviere1->width() << std::endl;
             std::cout << ratio_riviere << std::endl;
             std::cout << hauteur_riviere << std::endl << largeur_riviere << std::endl;



             espace_y = (height() - taille_riviere * HAUTEUR_RIVIERE) / 2;
             espace_x = (width() - taille_riviere * LARGEUR_RIVIERE) / 2;

             QPixmap riviereCopy = riviere1->copy(espace_x, espace_y, largeur_riviere, hauteur_riviere);

             QPixmap riviereScaled = riviereCopy.scaled(size());

             toile.drawPixmap(espace_x, espace_y, riviereScaled);

             toile.drawPixmap(0, 0, riviereScaled);

         }
         else
         {
             float hauteur_riviere = 0;
             float largeur_riviere = 0;
             float ratio_riviere = riviere1->height() / (riviere1->width() * 1.0);
             //#define TAILLE_IMAGE 10;

             if (width() * HAUTEUR_RIVIERE > height() * LARGEUR_RIVIERE)
             {
                 hauteur_riviere = ratio_riviere * float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
                 largeur_riviere = float(height() / (HAUTEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
             }
             else
             {
                 hauteur_riviere = ratio_riviere * float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
                 largeur_riviere = float(width() / (LARGEUR_RIVIERE * 1.0)) * TAILLE_RIVIERE;
             }

             system("cls");
             std::cout << riviere1->height() << std::endl << riviere1->width() << std::endl;
             std::cout << ratio_riviere << std::endl;
             std::cout << hauteur_riviere << std::endl << largeur_riviere << std::endl;



             espace_y = (height() - taille_riviere * HAUTEUR_RIVIERE) / 2;
             espace_x = (width() - taille_riviere * LARGEUR_RIVIERE) / 2;

             QPixmap riviereCopy = riviere1->copy(espace_x, espace_y, largeur_riviere, hauteur_riviere);

             QPixmap riviereScaled = riviereCopy.scaled(size());

             toile.drawPixmap(espace_x, espace_y, riviereScaled);

             toile.drawPixmap(0, 0, riviereScaled);
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

}
void WidgetRiviere::MAJ_Pecheur(int c)
{

}