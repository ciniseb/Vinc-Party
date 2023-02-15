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
    int reponse = -1;
    int selection = 0;

    affichage_DEBUG(selection);
    while(true)
    {
        if(threadArduino.evenementDisponible())
        {
            reponse = threadArduino.prochainEvenement().arg1;

            if (reponse == ENTER && 2 >= selection && selection >= 0)
            {
                if (selection == 0)
                {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');

                    system("cls");
                    affichage_DEBUG(selection);

                    std::string nom_joueur;
                    std::cout << "Nom du joueur : ";
                    getline(std::cin, nom_joueur);
                    std::cout << std::endl;
                    fenetres[selection] = new FenetreJeu(nom_joueur);
                }
                fenetres[selection]->ouvrir();
                system("cls");
                if (selection == 0)
                {
                    //TOTO getPointage et etc.
                }
            }
            else if (reponse == ENTER && selection == 3)
            {
                exit(1);
            }
            else
            {
                if (reponse == HAUT && (selection > 0))
                {
                    selection--;
                    affichage_DEBUG(selection);
                }
                else if (reponse == BAS && selection < 3)
                {
                    selection++;
                    affichage_DEBUG(selection);
                }
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