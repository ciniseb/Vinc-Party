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
//CARTE et TUILE
#pragma once

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
    U
};
#define NB_MINI_JEUX 1

#define DT_DEPLACEMENT_JOUEUR 333 //Milisecondes
#define DT_DEPLACEMENT_ADVERSAIRE 450 //Milisecondes

#define RAYON_VISION 8
#define RAYON_VIBRATION 12

//ERREURS
//...