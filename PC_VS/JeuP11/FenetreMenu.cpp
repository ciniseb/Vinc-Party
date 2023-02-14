/*====================================================================================================
Fichier: FenetreMenu.cpp
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
#include "FenetreMenu.h"
#define HAUT '1'
#define BAS '0'

//Constructeurs & destructeurs
FenetreMenu::FenetreMenu()
{
    //TODO threadArduino
    fenetres[0] = new FenetreJeu();
    fenetres[1] = new FenetrePointages();
    fenetres[2] = new FenetreTests();
    //f0 = new FenetreJeu();
}
FenetreMenu::~FenetreMenu()
{
    /*for (int i = 0; i < 3; i++)
    {
        delete fenetres[i];
    }*/
}

//Getteurs & setteurs


//Méthodes
void FenetreMenu::ouvrir()
{
    //threadArduino.exec();

    char reponse;
    int selection = 0;
    while(true)
    {
        affichage_DEBUG(selection);
        reponse = _getch();//TODO avec thread
        //std::cout << reponse << std::endl;
        if (reponse == VK_RETURN && 2 >= selection && selection >= 0)
        {
            fenetres[selection]->ouvrir();
            //f0->ouvrir();
        }
        else if (reponse == VK_RETURN && selection == 3)
        {
            return;
        }
        else
        {
            if(reponse == HAUT && (selection > 0 ))
            {
                selection--;
            }
            else if(reponse == BAS && selection < 3)
            {
                selection++;
            }
        }
    }
}

void FenetreMenu::affichage_DEBUG(int selection)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "               20-100 party!!!" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    if (selection == 0)
    {
        std::cout << " ---> | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << "      | Tests" << std::endl << std::endl;

        std::cout << "      | Quitter" << std::endl << std::endl;
    }
    else if (selection == 1)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << " ---> | Pointages" << std::endl;
        std::cout << "      | Tests" << std::endl << std::endl;

        std::cout << "      | Quitter" << std::endl << std::endl;
    }
    else if (selection == 2)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << " ---> | Tests" << std::endl << std::endl;

        std::cout << "      | Quitter" << std::endl << std::endl;
    }
    else if (selection == 3)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << "      | Tests" << std::endl << std::endl;

        std::cout << " ---> | Quitter" << std::endl << std::endl;
    }
    else
    {

    }
}