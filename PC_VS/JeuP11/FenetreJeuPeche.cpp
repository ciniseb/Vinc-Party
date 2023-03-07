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
        //VerificationJoueurPoisson();
    }
}

void FenetreJeuPeche::AffichageEcran(int mode)
{
    //std::cout << "Affichage" << std::endl;
    char screen[14][7];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    switch (mode)
    {
    case Menu:
        std::cout << "Appuyez sur Z,X,C ou V pour commencer" << '\n';
        for (int i = 0; i < 14; i++)
        {
            //std::cout << i << '\n';
            for (int j = 0; j < 7; j++)
            {

                if (i == 0 || i == 13 || j == 0 || j == 2 || j == 4 || j == 6)
                {
                    if (j == 3)
                    {
                        screen[i][j] = ' ';
                    }
                    else
                    {
                   screen[i][j] = '#';
                    }
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
        //std::cout << "Affichage Jeu" << std::endl;
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 7; j++)
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
                else if (j == 5)
                {
                    if (tempsReussi >= 10 && tempsReussi <= 20)
                    {
                        for (int k = 12; k > 5; k--)
                        {
                            screen[k][j] = '=';
                            if (i == 0 || i == 13)
                            {
                             screen[i][j] = '#';
                            }
                            else
                            {
                            screen[i][j] = ' ';
                            }
                        }

                    }
                    else if (tempsReussi >= 20)
                    {
                        for (int l = 12; l > 0 ; l--)
                        {
                            screen[l][j] = '=';
                            if (i == 0 || i == 13)
                            {
                            screen[i][j] = '#';
                            }
                            else
                            {
                            screen[i][j] = ' ';
                            }
                        }

                    }
                    else if (i == 0 || i == 13)
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
                    if (i == 0 || i == 13 || j == 0 || j == 2 || j == 4 || j == 6)
                    {
                        if (j == 3)
                        {
                            screen[i][j] = ' ';
                        }
                        else
                        {
                            screen[i][j] = '#';
                        }
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
        for (int j = 0; j < 7; j++)
        {
            std::cout << screen[i][j];
        }
        std::cout << '\n';
    }
    /*if (positionJoueur <= positionPoisson + 1 || positionJoueur >= positionPoisson - 1)
    {
        std::cout << positionPoisson << std::endl;
        std::cout << positionJoueur << std::endl;
        std::cout << tempsReussi << std::endl;
        std::cout << chrono.tempsEcoule_s() << std::endl;
        std::cout << "wow" << std::endl;
    }*/
}

bool FenetreJeuPeche::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    //system("cls");

    bit = bitCount - chrono.tempsEcoule_s();

    if (bit == 0 && bitCount < 60)
    {
        setPoisson();
        AffichageEcran(Jeu);
        VerificationJoueurPoisson();
        bitCount++;
    }
    return true;
}

void FenetreJeuPeche::setPoisson()
{
    if (bitCount == 0 || bitCount == 10 || bitCount == 20 || bitCount == 30 || bitCount == 40 || bitCount == 50)
    {
        positionPoisson = (rand() % 10) + 2;
    }
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
}

void FenetreJeuPeche::VerificationJoueurPoisson()
{

    if (positionJoueur <= positionPoisson + 1 && positionJoueur > positionPoisson - 1)
    {
        if (activation == true)
        {
        tempsInit = chrono.tempsEcoule_s();
        activation = false;
        }
    }
    else
    {
        if (activation == false || chrono.tempsEcoule_s() == 59)
        {
            tempsReussi += chrono.tempsEcoule_s() - tempsInit;
            activation = true;
        }
    }
}