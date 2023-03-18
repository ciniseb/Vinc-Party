/*====================================================================================================
Fichier: FenetreJeuPiano.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description:
====================================================================================================*/
#include "FenetreJeuPeche.h"

FenetreJeuPeche::FenetreJeuPeche(ES* thread) : FenetreMiniJeu(thread) // Main du jeu
{

}

FenetreJeuPeche::~FenetreJeuPeche()
{

}

void FenetreJeuPeche::ouvrir()
{
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;
    positionJoueur = 1;
    positionPoisson = 1;
    system("cls");
    AffichageEcran(Menu);



    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            if (evenement->getCode() == JOYSTICK)
            {
                if (demarrage)
                {
                    chrono.demarrer();
                    demarrage = false;
                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                Direction lettreAppuyee = eJoystick->getDirection();
                getJoueur(lettreAppuyee);
            }
            if (evenement->getCode() == ACCELEROMETRE)
            {
                Accel* eAccel = static_cast<Accel*>(evenement.get());
                TypeMotion mouvement = eAccel->getType();
                if (pretPecher == true)
                {
                    if (mouvement == PECHE && comptePretPecher <= 10)
                    {
                        threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));
                        reussite = true;
                        return;
                    }
                }
            }
        }
        Temps();
        if (foisReussi >= 10)
        {
            pretPecher = true;
        }
        else if (bitCount >= 60)
        {
            threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));
            reussite = false;
            return;
        }
        //VerificationJoueurPoisson();
    }
}

void FenetreJeuPeche::AffichageEcran(int mode)
{
    //std::cout << "Affichage" << std::endl;
    char screen[14][20];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    switch (mode)
    {
    case Menu:
        std::cout << "Appuyez sur Z,X,C ou V pour commencer" << '\n';
        std::cout << "Ligne de peche   Barre de progression" << std::endl;
        for (int i = 0; i < 14; i++)
        {
            //std::cout << i << '\n';
            for (int j = 0; j < 20; j++)
            {

                if (i == 0 || i == 13)
                {
                    screen[i][j] = '#';
                }
                else
                {
                    screen[i][j] = ' ';
                }
                if (i == 0 || i == 13 || j == 0 || j == 2 || j == 17 || j == 19)
                {
                    if (j >= 3 && j <= 17)
                    {
                    for (int k = 3; k < 17; k++)
                    {
                        screen[i][k] = ' ';
                    }
                    }
                   screen[i][j] = '#';
                }
                else
                {
                    screen[i][j] = ' ';
                }
            }
        }
        break;
    case Jeu:
        if (pretPecher == false)
        {
        std::cout << "Appuyez sur Z,C pour descendre X,V pour monter" << '\n';
        }
        else
        {
        std::cout << "Appuyez sur B pour attraper le poisson        " << '\n';
        }

        std::cout << "Ligne de peche   Barre de progression" << std::endl;
        threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(foisReussi));
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if(j==1)
                {
                    if (i == positionPoisson || i == positionPoisson + 1 || i == positionPoisson -1)
                    {
                        if(i == positionJoueur)
                        {
                          screen[i][j] = '*';
                        }
                        else
                        {
                          screen[i][j] = '%';
                        }
                    }
                    else if (i == 0 || i == 13)
                    {
                        screen[i][j] = '#';
                    }
                    else if (i == positionJoueur)
                    {
                        screen[i][j] = '*';
                    }
                    else
                    {
                        screen[i][j] = ' ';
                    }

                }
                else if (j == 18)
                {
                    if (foisReussi >= i)
                    {
                        for(int k=0; k <= foisReussi; k++)
                        {
                            if (pretPecher == true)
                            {
                                for (int k = 0; k <= 7; k++)
                                {
                                screen[k+1][j] = '=';
                                }
                            }
                            else
                            {
                            screen[k+1][j] = '=';
                            }
                        }
                    }
                    if (i == 0 || i == 13)
                    {
                        screen[i][j] = '#';
                    }
                    else
                    {
                        screen[i][j] = ' ';
                    }
                }
                else
                {
                    if (i == 0 || i == 13 || j == 0 || j == 2 || j == 17 || j == 19)
                    {
                        if (j >= 3 && j <= 17)
                        {
                            for (int k = 3; k < 17; k++)
                            {
                                screen[i][k] = ' ';
                            }
                        }
                            screen[i][j] = '#';
                    }
                    else
                    {
                        screen[i][j] = ' ';
                    }
                }
            }
        }
        break;
    }
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << screen[i][j];
        }
        std::cout << '\n';
    }
}

bool FenetreJeuPeche::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    //system("cls");

    bit = bitCount - chrono.tempsEcoule_s();

    if (bit == 0 && bitCount < 30)
    {
        if (bitCount >= bitPrecedent);
        {

            bitPrecedent = bitCount;
        }
        setPoisson();
        AffichageEcran(Jeu);
        VerificationJoueurPoisson();
        bitCount++;
        if (pretPecher == true)
        {
            comptePretPecher++;
        }
    }
    return true;
}

void FenetreJeuPeche::setPoisson()
{
    int nombre = 0;
    if (pretPecher == true)
    {
        positionPoisson = 5;
    }
    else
    {
    if (firstscan == true)
    {
        nombre = (rand() % 10) + 2;
        positionPoisson = nombre;
        firstscan = false;
    }
    else
    {
        if (bitCount >= bitPrecedent)
        {
            if (positionPoisson <= 9 && positionPoisson >= 5)
            {
                nombre = (rand() % 2) + 1;
                switch (nombre)
                {
                case 1:
                    positionPoisson--;
                    break;
                case 2:
                    positionPoisson++;
                    break;
                }
            }

            else if (positionPoisson < 5 && positionPoisson > 2)
            {
                nombre = (rand() % 4) + 1;
                switch (nombre)
                {
                case 1:
                    positionPoisson--;
                    break;
                case 2:
                    positionPoisson++;
                    break;
                case 3:
                    positionPoisson++;
                    break;
                case 4:
                    positionPoisson++;
                    break;
                }
            }
            else if (positionPoisson > 8 && positionPoisson < 11)
            {
                nombre = (rand() % 4) + 1;
                switch (nombre)
                {
                case 1:
                    positionPoisson--;
                    break;
                case 2:
                    positionPoisson--;
                    break;
                case 3:
                    positionPoisson--;
                    break;
                case 4:
                    positionPoisson++;
                    break;
                }
            }
            else if (positionPoisson == 2)
            {
                positionPoisson++;
            }
            else if (positionPoisson == 11)
            {
                positionPoisson--;
            }


        }
    }
    }

    /*if (bitCount == 0 || bitCount == 10 || bitCount == 20 || bitCount == 30 || bitCount == 40 || bitCount == 50)
    {
        positionPoisson = (rand() % 10) + 2;
    }*/
}

void FenetreJeuPeche::getJoueur(Direction touche)
{
     switch(touche)
    { 
    case Direction::BAS:
        positionJoueur++;
    break;

    case Direction::HAUT:
        positionJoueur--;
    break;
    }      
     if (positionJoueur < 1)
     {
         positionJoueur = 1;
     }
     if (positionJoueur > 12)
     {
         positionJoueur = 12;
     }
}

void FenetreJeuPeche::VerificationJoueurPoisson()
{
    if (bitCount >= bitPrecedent);
    {
        if (positionJoueur <= positionPoisson + 1 && positionJoueur >= positionPoisson - 1)
        {
            foisReussi++;
        }
    }
}