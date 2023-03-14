/*====================================================================================================
Fichier: PageMenu.cpp
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
#include "PageMenu.h"

#define DEMANDER_NOM false

//Constructeurs & destructeurs
PageMenu::PageMenu(ES* thread) : Page(thread)
{
    initialiser();
    ui.setupUi(this);

    //Connections

}
PageMenu::~PageMenu()
{
    for (int i = 0; i < 3; i++)
    {
        delete pages[i];
    }
}

//Getteurs & setteurs


//Méthodes
void PageMenu::initialiser()
{
    pages[0] = new PageTest(threadArduino/**/);
    pages[1] = new PageTest(threadArduino);
    pages[2] = new PageTest(threadArduino);
}

void PageMenu::ouvrir()
{
    std::unique_ptr<Evenement> evenement;
    int selection = 0;

    affichage_DEBUG(selection);
    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == BOUTON)
            {
                Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                Dieu lettreAppuyee = eBouton->getNom();

                if (lettreAppuyee == Dieu::D && selection < 3 && selection >= 0)
                {
                    if (selection == 0)
                    {
#if DEMANDER_NOM
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');

                        system("cls");
                        affichage_DEBUG(selection);

                        std::string nom_joueur;
                        std::cout << "Nom du joueur : ";
                        getline(std::cin, nom_joueur);
                        std::cout << std::endl;
#else
                        std::string nom_joueur = "PeuplierBlanc";

#endif // DEMANDER_NOM

                        pages[selection] = new PageTest(/*nom_joueur, */threadArduino);
                    }
                    pages[selection]->show();
                    system("cls");
                    affichage_DEBUG(selection);
                    if (selection == 0)
                    {

                    }
                }
                else if (lettreAppuyee == Dieu::D && selection == 3)
                {
                    exit(1);
                }
            }
            else if (evenement->getCode() == JOYSTICK)
            {
                Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                Direction direction = eJoystick->getDirection();

                if (direction == Direction::HAUT && (selection > 0))
                {
                    selection--;
                    affichage_DEBUG(selection);
                }
                else if (direction == Direction::BAS && selection < 3)
                {
                    selection++;
                    affichage_DEBUG(selection);
                }
            }
        }
    }
}

void PageMenu::affichage_DEBUG(int selection)
{
    //system("cls");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "               Le Chemin de Croix               " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    if (selection == 0)
    {
        std::cout << " ---> | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << "      | Crossy Road" << std::endl << std::endl;
        std::cout << "      | Quitter" << std::endl;
    }
    else if (selection == 1)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << " ---> | Pointages" << std::endl;
        std::cout << "      | Crossy Road" << std::endl << std::endl;
        std::cout << "      | Quitter" << std::endl;
    }
    else if (selection == 2)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << " ---> | Crossy Road" << std::endl << std::endl;
        std::cout << "      | Quitter" << std::endl;
    }
    else if (selection == 3)
    {
        std::cout << "      | Jouer" << std::endl;
        std::cout << "      | Pointages" << std::endl;
        std::cout << "      | Crossy Road" << std::endl << std::endl;
        std::cout << " ---> | Quitter" << std::endl;
    }
    else
    {

    }
}
