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

    double nb_affichages = 0;

    //M�thodes

public:
    //Constructeurs & destructeurs
    FenetreJeu();
    FenetreJeu(std::string, ES *);
    ~FenetreJeu();
    


    //Getteurs & setteurs
    Niveau getNiveau();
    Tuile getTuile(Coordonnee);
    //std::vector<Fenetre> getMiniJeux();
    Acteur getJoueur();
    Acteur getAdversaire();
    Chronometre getTemps();

    void setNiveau(Niveau);
    void setTuile(Coordonnee, Tuile);
    //void setMiniJeux(std::vector<Fenetre>);
    void setJoueur(Acteur);
    void setAdversaire(Acteur);
    void setTemps(Chronometre);

    //M�thodes
    bool chargerGabaritCarte(int[HAUTEUR_CARTE][LARGEUR_CARTE], int*, int*);
    bool genererCarte();

    bool verificationVide(Coordonnee);

    bool verificationCoord(Coordonnee, Coordonnee);

    void deplacementAdversaireRandom();

    bool deplacementAdversaire();
    bool deplacementJoueur(Direction);
    float distanceActeur(Acteur, Coordonnee);

    void ouvrir();
    void jouer();

    void affichage_DEBUG(std::ostream &);
    bool modeChasse();
    bool scanBFS(int[HAUTEUR_CARTE][LARGEUR_CARTE]);
    void modeSuiveurAdversaire(int[HAUTEUR_CARTE][LARGEUR_CARTE]);
};

#endif