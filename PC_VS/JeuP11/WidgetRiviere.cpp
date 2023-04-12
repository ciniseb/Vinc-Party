#include "WidgetRiviere.h"

WidgetRiviere::WidgetRiviere(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    riviere1 = new QPixmap ;
    riviere2 = new QPixmap;
    riviere3 = new QPixmap;
    Pecheur = new QPixmap;
    BaleineDroite = new QPixmap;
    BaleineGauche = new QPixmap;
    Snorlax = new QPixmap;
    Snorlax2 = new QPixmap;
    baleineShake = false;
    pretPecher = false;

    riviere1->load("Riviere1.png");
    riviere2->load("Riviere2.png");
    riviere3->load("riviere3.png");
    Pecheur->load("Pecheur2.png"); 
    Snorlax->load("Snorlax4.png");
    Snorlax2->load("Snorlax5.png");
    BaleineDroite->load("MicrosoftTeams-image.png");
    BaleineGauche->load("Wailord_gauche.png");


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



         toile = new QPainter(this);
         toile->setRenderHint(QPainter::Antialiasing, false);
         toile->setRenderHint(QPainter::SmoothPixmapTransform, false);
         toile->setPen(Qt::NoPen);

         if (riviere == 1)
         {
             float hauteur_riviere = 0;
             float largeur_riviere = 0;
             float targetRatioRiviere = qreal(width()) / qreal(height());
             float ratio_riviere = riviere1->height() / (riviere1->width() * 1.0);
             //#define TAILLE_IMAGE 10;

             if (targetRatioRiviere > ratio_riviere)
             {
                 largeur_riviere = riviere1->width();
                 hauteur_riviere = float(largeur_riviere / targetRatioRiviere);
             }
             else
             {
                 hauteur_riviere = riviere1->height();
                 largeur_riviere = float(hauteur_riviere * targetRatioRiviere);
             }



             float espace_y_Riviere = (riviere1->height() - hauteur_riviere) / 2;
             float espace_x_Riviere = (riviere1->width() - largeur_riviere) / 2;

             QPixmap riviereCopy = riviere1->copy(espace_x_Riviere, espace_y_Riviere, largeur_riviere, hauteur_riviere);

             QPixmap riviereScaled = riviereCopy.scaled(size());

             toile->drawPixmap(espace_x_Riviere, espace_y_Riviere, riviereScaled);

             float hauteur_snorlax = 0;
             float largeur_snorlax = 0;
             float targetRatioSnorlax = qreal(width()) / qreal(height());
             float ratio_snorlax = (Snorlax->height()) / ((Snorlax->width() * 1.0));

             if (targetRatioSnorlax > ratio_snorlax)
             {
                 largeur_snorlax = Snorlax->width();
                 hauteur_snorlax = float(largeur_snorlax / targetRatioSnorlax);
             }
             else
             {
                 hauteur_snorlax = Snorlax->height();
                 largeur_snorlax = float(hauteur_snorlax * targetRatioSnorlax);
             }

             float espace_y_snorlax = (Snorlax->height() - hauteur_snorlax) / 2;
             float espace_x_snorlax = (Snorlax->width() - largeur_snorlax) / 2;

             QPixmap snorlaxCopy = Snorlax->copy(espace_x_snorlax, espace_y_snorlax, largeur_snorlax, hauteur_snorlax);

             QPixmap snorlaxScaled = snorlaxCopy.scaled(size() / 3);

             toile->drawPixmap(1000, 5, snorlaxScaled);
         }
         else if(riviere == 2)
         {
             float hauteur_riviere = 0;
             float largeur_riviere = 0;
             float targetRatioRiviere = qreal(width()) / qreal(height());
             float ratio_riviere = riviere2->height() / (riviere2->width() * 1.0);
             //#define TAILLE_IMAGE 10;

             if (targetRatioRiviere > ratio_riviere)
             {
                 largeur_riviere = riviere2->width();
                 hauteur_riviere = float(largeur_riviere / targetRatioRiviere);
             }
             else
             {
                 hauteur_riviere = riviere2->height();
                 largeur_riviere = float(hauteur_riviere * targetRatioRiviere);
             }



             float espace_y_Riviere = (riviere2->height() - hauteur_riviere) / 2;
             float espace_x_Riviere = (riviere2->width() - largeur_riviere) / 2;

             QPixmap riviereCopy = riviere2->copy(espace_x_Riviere, espace_y_Riviere, largeur_riviere, hauteur_riviere);

             QPixmap riviereScaled = riviereCopy.scaled(size());

             toile->drawPixmap(espace_x_Riviere, espace_y_Riviere, riviereScaled);

             float hauteur_snorlax2 = 0;
             float largeur_snorlax2 = 0;
             float targetRatioSnorlax2 = qreal(width()) / qreal(height());
             float ratio_snorlax2 = (Snorlax2->height()) / ((Snorlax2->width() * 1.0));

             if (targetRatioSnorlax2 > ratio_snorlax2)
             {
                 largeur_snorlax2 = Snorlax->width();
                 hauteur_snorlax2 = float(largeur_snorlax2 / targetRatioSnorlax2);
             }
             else
             {
                 hauteur_snorlax2 = Snorlax->height();
                 largeur_snorlax2 = float(hauteur_snorlax2 * targetRatioSnorlax2);
             }

             float espace_y_snorlax2 = (Snorlax2->height() - hauteur_snorlax2) / 2;
             float espace_x_snorlax2 = (Snorlax2->width() - largeur_snorlax2) / 2;

             QPixmap snorlax2Copy = Snorlax2->copy(espace_x_snorlax2, espace_y_snorlax2, largeur_snorlax2, hauteur_snorlax2);

             QPixmap snorlax2Scaled = snorlax2Copy.scaled(size() / 3);

             toile->drawPixmap(1000, 5, snorlax2Scaled);
         }
         else if (riviere == 3)
         {
             float hauteur_riviere = 0;
             float largeur_riviere = 0;
             float targetRatioRiviere = qreal(width()) / qreal(height());
             float ratio_riviere = riviere3->height() / (riviere3->width() * 1.0);
             //#define TAILLE_IMAGE 10;

             if (targetRatioRiviere > ratio_riviere)
             {
                 largeur_riviere = riviere3->width();
                 hauteur_riviere = float(largeur_riviere / targetRatioRiviere);
             }
             else
             {
                 hauteur_riviere = riviere3->height();
                 largeur_riviere = float(hauteur_riviere * targetRatioRiviere);
             }



             float espace_y_Riviere = (riviere3->height() - hauteur_riviere) / 2;
             float espace_x_Riviere = (riviere3->width() - largeur_riviere) / 2;

             QPixmap riviereCopy = riviere3->copy(espace_x_Riviere, espace_y_Riviere, largeur_riviere, hauteur_riviere);

             QPixmap riviereScaled = riviereCopy.scaled(size());

             toile->drawPixmap(espace_x_Riviere, espace_y_Riviere, riviereScaled);

             float hauteur_snorlax = 0;
             float largeur_snorlax = 0;
             float targetRatioSnorlax = qreal(width()) / qreal(height());
             float ratio_snorlax = (Snorlax->height()) / ((Snorlax->width() * 1.0));

             if (targetRatioSnorlax > ratio_snorlax)
             {
                 largeur_snorlax = Snorlax->width();
                 hauteur_snorlax = float(largeur_snorlax / targetRatioSnorlax);
             }
             else
             {
                 hauteur_snorlax = Snorlax->height();
                 largeur_snorlax = float(hauteur_snorlax * targetRatioSnorlax);
             }

             float espace_y_snorlax = (Snorlax->height() - hauteur_snorlax) / 2;
             float espace_x_snorlax = (Snorlax->width() - largeur_snorlax) / 2;

             QPixmap snorlaxCopy = Snorlax->copy(espace_x_snorlax, espace_y_snorlax, largeur_snorlax, hauteur_snorlax);

             QPixmap snorlaxScaled = snorlaxCopy.scaled(size() / 3);

             toile->drawPixmap(1000, 5, snorlaxScaled);
         }

             //pecheur

             float hauteur_pecheur = 0;
             float largeur_pecheur = 0;
             float targetRatioPecheur = qreal(width()) / qreal(height());
             float ratio_pecheur = (Pecheur->height()/7) / ((Pecheur->width() * 1.0)/7);

             if (targetRatioPecheur > ratio_pecheur)
             {
                 largeur_pecheur = Pecheur->width();
                 largeur_pecheur = float(largeur_pecheur/targetRatioPecheur);
             }
             else
             {
                 hauteur_pecheur = Pecheur->height();
                 largeur_pecheur = float(hauteur_pecheur * targetRatioPecheur);
             }

             float espace_y_Pecheur = (Pecheur->height() - hauteur_pecheur) / 2;
             float espace_x_Pecheur = (Pecheur->width() - largeur_pecheur) / 2;

             QPixmap pecheurCopy= Pecheur->copy(espace_x_Pecheur, espace_y_Pecheur, largeur_pecheur, hauteur_pecheur);

             QPixmap pecheurScaled = pecheurCopy.scaled(size()/7);

             toile->drawPixmap(espace_x_Pecheur+posPeche, espace_y_Pecheur-125, pecheurScaled);

             //baleine
             if (lastPos < posBal)
             {
                 if (pretPecher == false)
                 {
                     float hauteur_baleine = 0;
                     float largeur_baleine = 0;
                     float targetRatioBaleine = qreal(width()) / qreal(height());
                     float ratio_baleine = (BaleineDroite->height()) / ((BaleineDroite->width() * 1.0));

                     if (targetRatioBaleine > ratio_baleine)
                     {
                         largeur_baleine = BaleineDroite->width();
                         hauteur_baleine = float(largeur_baleine / targetRatioBaleine);
                     }
                     else
                     {
                         hauteur_baleine = BaleineDroite->height();
                         largeur_baleine = float(hauteur_baleine * targetRatioBaleine);
                     }

                     espace_y = (BaleineDroite->height() - hauteur_baleine) / 2;
                     espace_x = (BaleineDroite->width() - largeur_baleine) / 2;

                     QPixmap baleineCopy = BaleineDroite->copy(espace_x, espace_y, largeur_baleine, hauteur_baleine);

                     QPixmap baleineScaled = baleineCopy.scaled(size() / 5);

                     toile->drawPixmap(espace_x + posBal, espace_y + 210, baleineScaled);
                 }
                 else
                 {
                     float hauteur_baleine = 0;
                     float largeur_baleine = 0;
                     float targetRatioBaleine = qreal(width()) / qreal(height());
                     float ratio_baleine = (BaleineDroite->height()) / ((BaleineDroite->width() * 1.0));

                     if (targetRatioBaleine > ratio_baleine)
                     {
                         largeur_baleine = BaleineDroite->width();
                         hauteur_baleine = float(largeur_baleine / targetRatioBaleine);
                     }
                     else
                     {
                         hauteur_baleine = BaleineDroite->height();
                         largeur_baleine = float(hauteur_baleine * targetRatioBaleine);
                     }

                     espace_y = (BaleineDroite->height() - hauteur_baleine) / 2;
                     espace_x = (BaleineDroite->width() - largeur_baleine) / 2;

                     QPixmap baleineCopy = BaleineDroite->copy(espace_x, espace_y, largeur_baleine, hauteur_baleine);

                     QPixmap baleineScaled = baleineCopy.scaled(size() / 5);

                     if (baleineShake == false)
                     {
                         toile->drawPixmap(espace_x + posBal, espace_y + 190, baleineScaled);
                         baleineShake = true;
                         update();
                     }
                     else
                     {
                         toile->drawPixmap(espace_x + posBal, espace_y + 210, baleineScaled);
                         baleineShake = false;
                         update();
                     }
                 }
             }
             else
             {
                 if (pretPecher == false)
                 {
                     float hauteur_baleine = 0;
                     float largeur_baleine = 0;
                     float targetRatioBaleine = qreal(width()) / qreal(height());
                     float ratio_baleine = (BaleineGauche->height()) / ((BaleineGauche->width() * 1.0));

                     if (targetRatioBaleine > ratio_baleine)
                     {
                         largeur_baleine = BaleineGauche->width();
                         hauteur_baleine = float(largeur_baleine / targetRatioBaleine);
                     }
                     else
                     {
                         hauteur_baleine = BaleineGauche->height();
                         largeur_baleine = float(hauteur_baleine * targetRatioBaleine);
                     }

                     espace_y = (BaleineGauche->height() - hauteur_baleine) / 2;
                     espace_x = (BaleineGauche->width() - largeur_baleine) / 2;

                     QPixmap baleineCopy = BaleineGauche->copy(espace_x, espace_y, largeur_baleine, hauteur_baleine);

                     QPixmap baleineScaled = baleineCopy.scaled(size() / 5);

                     toile->drawPixmap(espace_x + posBal, espace_y + 210, baleineScaled);
                 }
                 else
                 {
                     float hauteur_baleine = 0;
                     float largeur_baleine = 0;
                     float targetRatioBaleine = qreal(width()) / qreal(height());
                     float ratio_baleine = (BaleineDroite->height()) / ((BaleineDroite->width() * 1.0));

                     if (targetRatioBaleine > ratio_baleine)
                     {
                         largeur_baleine = BaleineDroite->width();
                         hauteur_baleine = float(largeur_baleine / targetRatioBaleine);
                     }
                     else
                     {
                         hauteur_baleine = BaleineDroite->height();
                         largeur_baleine = float(hauteur_baleine * targetRatioBaleine);
                     }

                     espace_y = (BaleineDroite->height() - hauteur_baleine) / 2;
                     espace_x = (BaleineDroite->width() - largeur_baleine) / 2;

                     QPixmap baleineCopy = BaleineDroite->copy(espace_x, espace_y, largeur_baleine, hauteur_baleine);

                     QPixmap baleineScaled = baleineCopy.scaled(size() / 5);

                     if (baleineShake == false)
                     {
                         toile->drawPixmap(espace_x + posBal, espace_y + 190, baleineScaled);
                         baleineShake = true;
                         update();
                     }
                     else
                     {
                         toile->drawPixmap(espace_x + posBal, espace_y + 210, baleineScaled);
                         baleineShake = false;
                         update();
                     }
                 }
             }





         delete toile;
}

void WidgetRiviere::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    update();
}

//Slots
void WidgetRiviere::MAJ_Riviere(int q_riviere)
{
    if (q_riviere == 3)
    {
        riviere = 1;
    }
    else if(q_riviere == 2)
    {
        riviere = 2;
    }
    else if (q_riviere == 1)
    {
        riviere = 3;
    }
    update();
}
void WidgetRiviere::MAJ_Baleine(int c)
{
    lastPos = posBal;
    switch (c)
    {
    case 2:
        posBal = 0;
        break;
        
    case 3:
        posBal = 122;
        break;

    case 4:
        posBal = 244;
        break;

    case 5:
        posBal = 366;
        break;

    case 6:
        posBal = 488;
        break;

    case 7:
        posBal = 610;
        break;

    case 8:
        posBal = 732;
        break;

    case 9:
        posBal = 854;
        break;

    case 10:
        posBal = 976;
        break;

    case 11:
        posBal = 1098;
        break;
    }
    if (c == 13)
    {
        posBal = 366;
        pretPecher = true;
        baleineShake = true;
    }
    update();
}
void WidgetRiviere::MAJ_Pecheur(int c)
{
    switch (c)
    {

    case 1:
        posPeche = -199;
        break;

    case 2:
        posPeche =-86;
        break;

    case 3:
        posPeche = 27;
        break;

    case 4:
        posPeche = 140;
        break;

    case 5:
        posPeche = 253;
        break;

    case 6:
        posPeche = 366;
        break;

    case 7:
        posPeche = 479;
        break;

    case 8:
        posPeche = 592;
        break;

    case 9:
        posPeche = 705;
        break;

    case 10:
        posPeche = 818;
        break;

    case 11:
        posPeche = 931;
        break;

    case 12:
        posPeche = 1044;
        break;
    }
    update();
}