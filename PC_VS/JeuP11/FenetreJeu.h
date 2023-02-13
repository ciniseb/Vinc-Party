/*====================================================================================================
Fichier: FenetreJeu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: C'est ici que le vrai jam se fait, celui aux multi-fruits.
====================================================================================================*/
#ifndef FENETREJEU_H
#define FENETREJEU_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include "CONSTANTES.h"
#include "Fenetre.h"
#include "Niveau.h"
#include "Tuile.h"
#include "Acteur.h"
#include "Chronometre.h"

class FenetreJeu : public Fenetre
{
private:
    //Attributs
    Niveau niveau;

    Tuile carte[HAUTEUR_CARTE][LARGEUR_CARTE];
    std::vector<Fenetre> mini_jeux;

    Acteur joueur;
    Acteur adversaire;

    Chronometre temps;

    //Méthodes

public:
    //Constructeurs & destructeurs
    FenetreJeu();
    FenetreJeu(std::string);
    ~FenetreJeu();

    //Getteurs & setteurs
    Niveau getNiveau();
    Tuile getTuile(Coordonnee);
    std::vector<Fenetre> getMiniJeux();
    Acteur getJoueur();
    Acteur getAdversaire();
    Chronometre getTemps();

    void setNiveau(Niveau);
    void setTuile(Coordonnee, Tuile);
    void setMiniJeux(std::vector<Fenetre>);
    void setJoueur(Acteur);
    void setAdversaire(Acteur);
    void setTemps(Chronometre);

    //Méthodes
    bool chargerGabaritCarte(int[HAUTEUR_CARTE][LARGEUR_CARTE], int*, int*);
    bool genererCarte();

    void affichage_DEBUG(std::ostream &);
};

#endif