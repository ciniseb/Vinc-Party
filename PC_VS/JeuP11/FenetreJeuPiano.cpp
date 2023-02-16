/*====================================================================================================
Fichier: FenetreJeuX.cpp
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
FenetreJeuPiano::FenetreJeuPiano(){
    chanson[0] = 'a';
    chanson[1] = 'a';
    chanson[2] = 'd';
    chanson[3] = 's';
    chanson[4] = 'f';
    chanson[5] = 'f';
    chanson[6] = 'd';
    chanson[7] = 'd';
    chanson[8] = 's';
    chanson[9] = 'f';
    chanson[10] = 'a';
    chanson[11] = 'd';
    chanson[12] = 's';

}
FenetreJeuPiano::~FenetreJeuPiano() {}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee(char c)
{
    switch (c)
    {
    case'a': std::cout << "a marche" << std::endl;
        if (c == chanson[index])
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
    case's': std::cout << "s marche" << std::endl;
        if (c == chanson[index])
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
    case'd': std::cout << "d marche" << std::endl;
        if (c == chanson[index])
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
    case'f': std::cout << "f marche" << std::endl;
        if (c == chanson[index])
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
    chanson[1] = 'a';
    chanson[2] = 'd';
    chanson[3] = 's';
    chanson[4] = 'f';
    chanson[5] = 'f';
    chanson[6] = 'd';
    chanson[7] = 'd';
    chanson[8] = 's';
    chanson[9] = 'f';
    chanson[10] = 'a';
    chanson[11] = 'd';
    chanson[12] = 's';

}