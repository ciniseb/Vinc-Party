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
#include <iostream>
#include <vector>
#include "CONSTANTES.h"
#include "Fenetre.h"
#include "Niveau.h"
#include "Tuile.h"
#include "Acteur.h"

class FenetreJeu : public Fenetre
{
private:
    //Attributs
    Niveau niveau;

    Tuile** carte;
    std::vector<Fenetre> mini_jeux;

    Acteur joueur;
    Acteur adversaire;

    double temps;

public:
    //Constructeurs & destructeurs
    FenetreJeu();
    FenetreJeu(std::string);
    ~FenetreJeu();

    //Getteurs & setteurs
    Niveau getNiveau();
    Tuile** getCarte();
    std::vector<Fenetre> getMiniJeux();
    Acteur getJoueur();
    Acteur getAdversaire();
    double getTemps();

    void setNiveau(Niveau);
    void setCarte(Tuile**);
    void setMiniJeux(std::vector<Fenetre>);
    void setJoueur(Acteur);
    void setAdversaire(Acteur);
    void setTemps(double);

    //M�thodes

};

