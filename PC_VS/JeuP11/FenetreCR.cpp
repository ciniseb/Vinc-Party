#include "FenetreCR.h"
/*====================================================================================================
Fichier: FenetreCR.cpp
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
#include "FenetreCR.h"
#include "CR_Vehicule.h"

//Constructeurs & destructeurs
MoteurCR::MoteurCR(ES* threadArduino, ThreadMoteur* threadMoteur) : MoteurMiniJeu(threadArduino, threadMoteur) { initialiser(); }
MoteurCR::~MoteurCR() {
    for (int i = 0; i < 6; i++)
    {
        delete vehicules[i];
    }
}

void MoteurCR::initialiser()
{
    //TODO
    vehicules[0] = new CR_Vehicule(10, 1, Vitesse::LENTE);
    vehicules[1] = new CR_Vehicule(20, 15, Vitesse::NORMALE);
    vehicules[2] = new CR_Vehicule(10, 5, Vitesse::LENTE);
    vehicules[3] = new CR_Vehicule(10, 3, Vitesse::RAPIDE);
    vehicules[4] = new CR_Vehicule(5, 1, Vitesse::LENTE);
    vehicules[5] = new CR_Vehicule(10, 1, Vitesse::LENTE);
}

void MoteurCR::demarrer()
{
    int dernierAffichage = 0;
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;
    posX = 30;
    posY = 12;

    system("cls");
    chrono.demarrer();

    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            if (evenement->getCode() == JOYSTICK)
            {
                
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                Joystick* eJoystick= static_cast<Joystick*>(evenement.get());
                Direction direction = eJoystick->getDirection();
                switch (direction)
                {
                case HAUT:if (posY > 0) posY--;
                    break;
                case BAS: if (posY < 12) posY++;
                    break;
                case GAUCHE: if (posX > 0) posX--;
                    break;
                case DROITE: if (posX < 59) posX++;
                    break;
                case AUCUNE:
                    break;
                default:
                    break;
                }
                
            }
            

        }

        if (posY <= 0) {
            reussite = true;
            return;
        }

        if (posY % 2) {
            if (posY < 12 && vehicules[posY / 2]->intersect(posX, chrono.tempsEcoule_ms())) {
                reussite = false;
                return;
            }
        }

        if (chrono.tempsAtteint_ms(dernierAffichage + 50)) {
            afficher();
            dernierAffichage = chrono.tempsEcoule_ms();
        }
        
    }
}




void MoteurCR::afficher()
{
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    std::cout << "                                                             " << std::endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (vehicules[i]->intersect(j,(int)chrono.tempsEcoule_ms())) {
                std::cout << "#";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl << "                                                             " << std::endl;
    }

    std::cout << (int)chrono.tempsEcoule_ms();
    

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)posX, (short)posY });
    std::cout << "X";

    return;
}