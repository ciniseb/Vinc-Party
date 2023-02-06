/*====================================================================================================
Fichier: FenetreJeu.cpp
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
#include "FenetreJeu.h"

//Constructeurs & destructeurs
FenetreJeu::FenetreJeu()
{
    niveau = Niveau();

    carte = new Tuile* [HAUTEUR_CARTE];
    for (int h = 0; h < HAUTEUR_CARTE; ++h)
    {
        carte[h] = new Tuile[LARGEUR_CARTE];
    }

    temps = 0;
}
FenetreJeu::FenetreJeu(std::string nom_joueur)
{
    niveau.niveauSuivant();

    carte = new Tuile* [HAUTEUR_CARTE];
    for (int h = 0; h < HAUTEUR_CARTE; ++h)
    {
        carte[h] = new Tuile[LARGEUR_CARTE];
    }
    //TODO : générer la carte à partir du fichier excel et du niveau avec un système d'attribution aléatoire
    //       pour la position des mini-jeux et des tuiles pleines variables.

    mini_jeux; //TODO : Charger les mini-jeux.

    joueur = Acteur{nom_joueur, Coordonnee{19, 19}};

    Coordonnee pos_adversaire{19, 20};//TODO : générer une position aléatoire dans la map pour l'adversaire
    adversaire = Acteur{"BOB", pos_adversaire};

    temps = 0;
}
FenetreJeu::~FenetreJeu()
{
    for(int h = 0; h < HAUTEUR_CARTE; ++h)
    {
        delete[] carte[h];  
    }

    delete[] carte;
}

//Getteurs & setteurs
Niveau FenetreJeu::getNiveau()
{
    return niveau;
}
Tuile** FenetreJeu::getCarte()
{
    return carte;
}
std::vector<Fenetre> FenetreJeu::getMiniJeux()
{
    return mini_jeux;
}
Acteur FenetreJeu::getJoueur()
{
    return joueur;
}
Acteur FenetreJeu::getAdversaire()
{
    return adversaire;
}
double FenetreJeu::getTemps()
{
    return temps;
}

void FenetreJeu::setNiveau(Niveau n)
{
    niveau = n;
}
void FenetreJeu::setCarte(Tuile** c)
{
    carte = c;
}
void FenetreJeu::setMiniJeux(std::vector<Fenetre> mjx)
{
    mini_jeux = mjx;
}
void FenetreJeu::setJoueur(Acteur j)
{
    joueur = j;
}
void FenetreJeu::setAdversaire(Acteur a)
{
    adversaire = a;
}
void FenetreJeu::setTemps(double t)
{
    temps = t;
}

//Méthodes
