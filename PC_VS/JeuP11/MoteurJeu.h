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
#ifndef MOTEURJEU_H
#define MOTEURJEU_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <cmath>
#include <map>
#include "Vibration.h"
#include "ES.h"
#include "CONSTANTES.h"
#include "Moteur.h"
#include "MoteurMiniJeu.h"
#include "Niveau.h"
#include "Tuile.h"
#include "Acteur.h"
#include "Chronometre.h"
#include "Pointage.h"
#include "MoteurJeuPiano.h"
#include "MoteurJeuPeche.h"
#include "MoteurJeuMineur.h"
#include "Joystick.h"
#include "Boussole.h"

#include <QVector>

class MoteurJeu : public Moteur
{
private:
    //Attributs
    Niveau niveau;

    Tuile carte[HAUTEUR_CARTE][LARGEUR_CARTE];
    QVector<QVector<int>> q_carte;
    MoteurMiniJeu *mini_jeux[NB_MINI_JEUX];

    int carte_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE];
    int nb_p_variables;
    int nb_mj_variables;

    Acteur joueur;
    Acteur adversaire;

    Chronometre temps;

    double nb_affichages;

    //M�thodes
    double distanceEntreTuiles(int x1, int y1, int x2, int y2);
    PointCardinal directionMiniJeuPlusProche(int nbrJeux);

public:
    //Constructeurs & destructeurs
    MoteurJeu();
    MoteurJeu(std::string, ES* threadArduino = nullptr, ThreadMoteur* threadMoteur = nullptr);
    ~MoteurJeu();
    
    //Getteurs & setteurs
    Niveau getNiveau();
    Tuile getTuile(Coordonnee);
    Acteur getJoueur();
    Acteur getAdversaire();
    Chronometre getTemps();

    void setNiveau(Niveau);
    void setTuile(Coordonnee, Tuile);
    void setJoueur(Acteur);
    void setAdversaire(Acteur);
    void setTemps(Chronometre);

    //M�thodes
    bool chargerGabaritCarte(int[HAUTEUR_CARTE][LARGEUR_CARTE], int*, int*);
    bool genererCarte();
    Coordonnee genererPosAdversaire();

    void deplacementMiniJeu();

    bool modeChasse();
    bool scanBFS(int[HAUTEUR_CARTE][LARGEUR_CARTE]);
    void modeSuiveurAdversaire(int[HAUTEUR_CARTE][LARGEUR_CARTE]);
    bool verificationVide(Coordonnee);
    bool verificationCoord(Coordonnee, Coordonnee);
    void deplacementAdversaireRandom();
    bool deplacementAdversaire();
    bool deplacementJoueur(Direction);

    float distance(Coordonnee, Coordonnee);

    void initialiser();
    void demarrer();

    void affichage(int);
};

#endif
