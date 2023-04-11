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
MoteurMenu::MoteurMenu(ES* threadArduino, ThreadMoteur* threadMoteur) : Moteur(threadArduino, threadMoteur) { initialiser(); }
MoteurMenu::~MoteurMenu()
{
    for (int i = 0; i < 3; i++)
    {
        delete moteurs[i];
    }
}

//Getteurs & setteurs
void MoteurMenu::setNomJoueur(std::string nom)
{
    nom_joueur = nom;
    std::cout << "Nom joueur envoyé : " << nom_joueur << std::endl;
}

//Méthodes
void MoteurMenu::initialiser()
{
    moteurs[0] = new MoteurJeu();
    moteurs[1] = new MoteurPointages(threadArduino);
    moteurs[2] = new MoteurTests(threadArduino);
}

void MoteurMenu::demarrer()
{
    std::unique_ptr<Evenement> evenement;
    int selection = 0;

    affichage(selection);
    while(true)
    {
        if(threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == BOUTON)
            {
                Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                Dieu lettreAppuyee = eBouton->getNom();

                if (lettreAppuyee == Dieu::JOYSTICK && selection < 2 && selection >= 0)
                {
                    if (selection == 0)
                    {
                        if (!MODE_CONSOLE)
                        {
                            emit threadMoteur->changementWidgetActif(selection + 1);

                            while (nom_joueur.empty())
                            {
                                threadMoteur->msleep(100);
                            }
                        }
                        else if (DEMANDER_NOM)
                        {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');

                            affichage(selection);

                            std::cout << "Nom du joueur : ";
                            getline(std::cin, nom_joueur);
                            std::cout << std::endl;
                        }

                        std::cout << "Nom joueur affiché : " << nom_joueur << std::endl;
                        
                        moteurs[selection] = new MoteurJeu(nom_joueur, threadArduino, threadMoteur);
                    }

                    if (MODE_CONSOLE)
                    {
                        system("cls");
                    }

                    moteurs[selection]->demarrer();

                    if (MODE_CONSOLE)
                    {
                        system("cls");
                    }

                    affichage(selection);
                }
                else if (lettreAppuyee == Dieu::JOYSTICK && selection == 2)
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
                    affichage(--selection);
                }
                else if (direction == Direction::BAS && selection < 2)
                {
                    affichage(++selection);
                }
            }
        }
    }
}

void MoteurMenu::affichage(int selection)
{
    if (MODE_CONSOLE)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "               Le Chemin de Croix               " << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        if (selection == 0)
        {
            std::cout << " ---> | Jouer" << std::endl;
            std::cout << "      | Pointages" << std::endl << std::endl;
            std::cout << "      | Quitter" << std::endl;
        }
        else if (selection == 1)
        {
            std::cout << "      | Jouer" << std::endl;
            std::cout << " ---> | Pointages" << std::endl << std::endl;
            std::cout << "      | Quitter" << std::endl;
        }
        else if (selection == 2)
        {
            std::cout << "      | Jouer" << std::endl;
            std::cout << "      | Pointages" << std::endl << std::endl;
            std::cout << " ---> | Quitter" << std::endl;
        }

        //Triches en cours
        std::cout << std::endl << std::endl;
        if (ENNEMI_INNOFFENSIF) std::cout << "ENNEMI_INNOFENSIF" << std::endl;
        if (MODE_CLAVIER) std::cout << "MODE_CLAVIER" << std::endl;
        if (VISION_NOCTURNE) std::cout << "VISION_NOCTURNE" << std::endl;
        if (MODE_MOZART) std::cout << "MODE_MOZART" << std::endl;
        if (MODE_FLASH_MC_QUEEN) std::cout << "MODE_FLASH_MC_QUEEN" << std::endl;
        if (MODE_TERRAIN_VAGUE) std::cout << "MODE_TERRAIN_VAGUE" << std::endl;
    }
    else
    {
        emit threadMoteur->menu_selection(selection);
    }
}