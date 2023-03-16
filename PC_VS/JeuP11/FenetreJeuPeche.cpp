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
            if (evenement->getCode() == BOUTON)
            {
                if (demarrage)
                {
                    chrono.demarrer();
                    demarrage = false;
                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                Dieu lettreAppuyee = eBouton->getNom();
                getJoueur(lettreAppuyee);
            }
        }
        Temps();
        if (foisReussi >= 15)
        {
            return;
        }
        else if (bitCount >= 60)
        {
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
        std::cout << "Appuyez sur Z,C pour descendre X,V pour monter" << '\n';
        std::cout << "Ligne de peche   Barre de progression" << std::endl;
        //std::cout << "Affichage Jeu" << std::endl;
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
                    if (foisReussi > i)
                    {
                        for (int k = 1; k < foisReussi; k++)
                        {
                            screen[k][j] = '=';
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

    if (bit == 0 && bitCount < 60)
    {
        if (bitCount >= bitPrecedent);
        {

            bitPrecedent = bitCount++;
        }
        setPoisson();
        AffichageEcran(Jeu);
        VerificationJoueurPoisson();
        bitCount++;
    }
    return true;
}

void FenetreJeuPeche::setPoisson()
{
    int nombre = 0;
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
    /*if (bitCount == 0 || bitCount == 10 || bitCount == 20 || bitCount == 30 || bitCount == 40 || bitCount == 50)
    {
        positionPoisson = (rand() % 10) + 2;
    }*/
}

void FenetreJeuPeche::getJoueur(Dieu touche)
{
     switch(touche)
    { 
    case Dieu::D:
        positionJoueur++;
    break;

    case Dieu::I:
        positionJoueur--;
    break;
    case Dieu::E:
        positionJoueur++;
        break;

    case Dieu::U:
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