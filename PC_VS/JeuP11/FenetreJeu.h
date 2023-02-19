/*====================================================================================================
Fichier: FenetreJeu.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
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
#include <cstdlib>
#include "ES.h"
#include "CONSTANTES.h"
#include "Fenetre.h"
#include "FenetreMiniJeu.h"
#include "Niveau.h"
#include "Tuile.h"
#include "Acteur.h"
#include "Chronometre.h"
#include "Pointage.h"
#include "FenetreJeuPiano.h"
#include "Joystick.h"

class FenetreJeu : public Fenetre
{
private:
    //Attributs
    Niveau niveau;

    Tuile carte[HAUTEUR_CARTE][LARGEUR_CARTE];
    FenetreMiniJeu *mini_jeux[NB_MINI_JEUX];

    Acteur joueur;
    Acteur adversaire;

    Chronometre temps;

    Pointage pointage;

    //M�thodes

public:
    //Constructeurs & destructeurs
    FenetreJeu();
    FenetreJeu(std::string, ES *);
    ~FenetreJeu();
    int COPIE_DE_CARTE[HAUTEUR_CARTE][LARGEUR_CARTE];


    //Getteurs & setteurs
    Niveau getNiveau();
    Tuile getTuile(Coordonnee);
    //std::vector<Fenetre> getMiniJeux();
    Acteur getJoueur();
    Acteur getAdversaire();
    Chronometre getTemps();
    Pointage getPointage();

    void setNiveau(Niveau);
    void setTuile(Coordonnee, Tuile);
    //void setMiniJeux(std::vector<Fenetre>);
    void setJoueur(Acteur);
    void setAdversaire(Acteur);
    void setTemps(Chronometre);

    //M�thodes
    bool chargerGabaritCarte(int[HAUTEUR_CARTE][LARGEUR_CARTE], int*, int*);
    bool genererCarte();

    bool deplacementJoueur(Direction, double *);
    float distanceJoueur(Coordonnee);

    void ouvrir();
    void jouer();

    void affichage_DEBUG(std::ostream &);
    bool Validation(bool Visite[][LARGEUR_CARTE], int AXE_x, int AXE_y);
    void AIMBOT_PART1();
    void AIMBOT_PART2();
    void RESETVERIFICATION(bool Visite[HAUTEUR_CARTE][LARGEUR_CARTE]);
    void DeplacementAdversaire();
};

#endif