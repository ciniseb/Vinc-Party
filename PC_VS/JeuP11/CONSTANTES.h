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


//Cheat codes
#define ENNEMI_INNOFFENSIF true
#define VISION_NOCTURNE true
#define MODE_MOZART false
#define MODE_FLASH_MC_QUEEN true
#define MODE_TERRAIN_VAGUE true


#define MODE_CLAVIER true

#define LARGEUR_CARTE 60
#define HAUTEUR_CARTE 30

#define VIDE 0
#define PLEIN -1
#define MINI_JEU 1
#define PLEIN_VARIABLE -2
#define MINI_JEU_VARIABLE 2


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
#define NB_MINI_JEUX 1



#if MODE_FLASH_MC_QUEEN
    #define DT_DEPLACEMENT_JOUEUR 100 //Milisecondes
#else
    #define DT_DEPLACEMENT_JOUEUR 333 //Milisecondes
#endif // MODE_FLASH_MC_QUEEN




#define DT_DEPLACEMENT_ADVERSAIRE 500 //Milisecondes

#define RAYON_VISION 8
#define RAYON_VIBRATION 12







//ERREURS
//...