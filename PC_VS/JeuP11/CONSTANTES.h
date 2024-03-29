/*====================================================================================================
Fichier: CONSTANTES.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 02 février 2023
Description: Constantes utiles à la compréhension du programme
====================================================================================================*/
#pragma once

#define MODE_CONSOLE false
#define MODE_CLAVIER true

//Cheat codes
#define DEMANDER_NOM true
#define ENNEMI_INNOFFENSIF false
#define VISION_NOCTURNE false
#define MODE_MOZART false
#define MODE_FLASH_MC_QUEEN false
#define MODE_TERRAIN_VAGUE false

#define LARGEUR_CARTE 60
#define HAUTEUR_CARTE 30

#define VIDE 0
#define PLEIN -1
#define MINI_JEU 1
#define PLEIN_VARIABLE -2
#define MINI_JEU_VARIABLE 2
#define ADVERSAIRE -3
#define JOUEUR 3

#define NB_MINI_JEUX 3

//MoteurJeuPiano
#define Menu 0
#define Jeu 1
#define Score 2

//MoteurJeuPeche
#define NB_HAMECONNAGE 12
#define TEMPS_HAMECONNAGE 25
#define TEMPS_PECHE 8

#if MODE_FLASH_MC_QUEEN
    #define DT_DEPLACEMENT_JOUEUR 100 //Milisecondes
#else
    #define DT_DEPLACEMENT_JOUEUR 333 //Milisecondes
#endif // MODE_FLASH_MC_QUEEN

#define DT_DEPLACEMENT_ADVERSAIRE 500 //Milisecondes

#define RAYON_VISION 8
#define RAYON_VIBRATION 12

enum class Dieu
{
    D,
    I,
    E,
    U,
    JOYSTICK
};

enum class Etat
{
    Actif,
    Inactif,
    Pause
};

//affichage MoteurJeu
#define AFFICHAGE_COMPLET 0
#define AFFICHAGE_TEMPS 1
#define AFFICHAGE_ADVERSAIRE 2
#define AFFICHAGE_JOUEUR 3
#define AFFICHAGE_MINI_JEU 4

//WidgetCarte
#define TAILLE_MINIMUM_TUILE 16
#define PADDING 2

//WidgetRiviere
#define PADDING 2
