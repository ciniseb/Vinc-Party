/*====================================================================================================
Fichier: FenetrePointages.cpp
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
#include "FenetrePointages.h"

//Constructeurs & destructeurs
FenetrePointages::FenetrePointages()
{

}
FenetrePointages::~FenetrePointages() {}

//Getteurs & setteurs
std::vector<Pointage> FenetrePointages::getPointages()
{
    return pointages;
}

void FenetrePointages::setPointages(std::vector<Pointage> p)
{
    pointages = p;
}

//Méthodes
bool FenetrePointages::chargerPointages()
{
    /*std::ifstream fichier;

    fichier.open("pointages.txt");

    if (fichier.is_open())
    {
        std::string ligne;

        for (int r = 0; getline(fichier, ligne) && r < HAUTEUR_CARTE; r++)
        {
            std::istringstream flux(ligne);
            std::string nombre;

            for (int c = 0; getline(flux, nombre, ';') && c < LARGEUR_CARTE; c++)
            {
                if (stoi(nombre) >= -2 && stoi(nombre) <= 2)
                {
                    c_gabarit[r][c] = stoi(nombre);
                    if (c_gabarit[r][c] == -2)
                    {
                        (*nb_p_variables)++;
                    }
                    else if (c_gabarit[r][c] == 2)
                    {
                        (*nb_mj_variables)++;
                    }
                }
                else
                {
                    fichier.close();
                    std::cout << "Mauvais fichier..." << std::endl;
                    return false;
                }
            }
        }

        fichier.close();
        return true;
    }
    std::cout << "Fichier introuvable..." << std::endl;*/
    return false;
}
bool FenetrePointages::enregistrerPointages()
{
    return false;
}

void FenetrePointages::ouvrir()
{
    /*int reponse = -1;
    int selection = 0;

    affichage_DEBUG(selection);
    while (true)
    {
        if (threadArduino.evenementDisponible())
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
    }*/
}

void FenetrePointages::affichage_DEBUG(int selection)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    std::cout << "-----------------------------------------------" << std::endl;
    switch (selection)
    {
    case 0:
        std::cout << "  | Pointages : temps" << std::endl;
        break;
    case 1:
        std::cout << "  | Pointages : temps/niveau" << std::endl;
        break;
    case 2:
        std::cout << "  | Pointages : nombre de niveaux" << std::endl;
        break;
    case 3:
        std::cout << "  | Pointages : distance parcourue/minute" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "-----------------------------------------------" << std::endl;


    switch (selection)
    {
    case 0:
        
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    default:
        break;
    }
}