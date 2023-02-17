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
#include "FenetreJeuPiano.h"

//Constructeurs & destructeurs
FenetreJeuPiano::FenetreJeuPiano(ES *thread) : FenetreMiniJeu(thread)
{
    chanson[0] = TOUCHE_1;
    chanson[1] = TOUCHE_1;
    chanson[2] = TOUCHE_3;
    chanson[3] = TOUCHE_2;
    chanson[4] = TOUCHE_4;
    chanson[5] = TOUCHE_4;
    chanson[6] = TOUCHE_3;
    chanson[7] = TOUCHE_3;
    chanson[8] = TOUCHE_2;
    chanson[9] = TOUCHE_4;
    chanson[10] = TOUCHE_1;
    chanson[11] = TOUCHE_3;
    chanson[12] = TOUCHE_2;

}
FenetreJeuPiano::~FenetreJeuPiano() {}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee(int touche)
{
    switch (touche)
    {
    case TOUCHE_1: std::cout << "z marche" << std::endl;
        if (touche == chanson[index])
        { 
            std::cout << "Pareille!" << std::endl;
            index++;
            return 1;
        }
        else 
        {
            std::cout << "Mauvais!" << std::endl;
            index++;
            return 0;
        }
        break;
    case TOUCHE_2: std::cout << "x marche" << std::endl;
        if (touche == chanson[index])
        {
            std::cout << "Pareille!" << std::endl;
            index++;
            return 1;
        }
        else
        {
            std::cout << "Mauvais!" << std::endl;
            index++;
            return 0;
        }
        break;
    case TOUCHE_3: std::cout << "c marche" << std::endl;
        if (touche == chanson[index])
        {
            std::cout << "Pareille!" << std::endl;
            index++;
            return 1;
        }
        else
        {
            std::cout << "Mauvais!" << std::endl;
            index++;
            return 0;
        }
        break;
    case TOUCHE_4: std::cout << "v marche" << std::endl;
        if (touche == chanson[index])
        {
            std::cout << "Pareille!" << std::endl;
            index++;
            return 1;
        }
        else
        {
            std::cout << "Mauvais!" << std::endl;
            index++;
            return 0;
        }
        break;

    }
}

//Méthodes
void FenetreJeuPiano::ouvrir()
{
    std::cout << "FENETRE MINI JEU OUVERTE" << std::endl;
    int reponse = ARRET;

    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            reponse = threadArduino->prochainEvenement().arg1;
        }
        VersBoutonPressee(reponse);
        reponse = ARRET;
    }
}