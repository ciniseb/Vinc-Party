/*====================================================================================================
Fichier: FenetreJeuPiano.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: FenetreJeuX est un nom temporaire pour expliquer la Classe de la fenêtre d'un mini-jeu
====================================================================================================*/
#include <iostream>
#include "MiniJeu.h"
#include "Fenetre.h"

class FenetreJeuPiano : public MiniJeu, public Fenetre
{
private:
    //Attributs
    int chanson[200];  
    int index=0;  
    

public:
    //Constructeurs & destructeurs
    FenetreJeuPiano();
    ~FenetreJeuPiano();

    //Getteurs & setteurs
    //defilement de la musique();
    bool VersBoutonPressee();
    void AffichageTouche();
    void AffichageEcran();
    void Bargraphe();

    //Méthodes
    
};
