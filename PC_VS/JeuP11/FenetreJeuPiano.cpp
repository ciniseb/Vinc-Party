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
#include "CONSTANTES.h"
#include "Joystick.h"
#include "Bouton.h"

//Constructeurs & destructeurs
FenetreJeuPiano::FenetreJeuPiano(ES *thread) : FenetreMiniJeu(thread)
{
    chanson[0] = Dieu::D;
    chanson[1] = Dieu::D;
    chanson[2] = Dieu::E;
    chanson[3] = Dieu::I;
    chanson[4] = Dieu::U;
    chanson[5] = Dieu::U;
    chanson[6] = Dieu::E;
    chanson[7] = Dieu::E;
    chanson[8] = Dieu::I;
    chanson[9] = Dieu::U;
    chanson[10] = Dieu::D;
    chanson[11] = Dieu::E;
    chanson[12] = Dieu::I;

}
FenetreJeuPiano::~FenetreJeuPiano() {}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee(Dieu touche)
{
    switch (touche)
    {
    case Dieu::D: std::cout << "z marche" << std::endl;
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
    case Dieu::I: std::cout << "x marche" << std::endl;
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
    case Dieu::E: std::cout << "c marche" << std::endl;
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
    case Dieu::U: std::cout << "v marche" << std::endl;
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
    std::unique_ptr<Evenement> evenement;

    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            Bouton* eBouton = static_cast<Bouton*>(evenement.get());
            Dieu lettreAppuyee = eBouton->getNom();
            VersBoutonPressee(lettreAppuyee);
        }
        
    }
}