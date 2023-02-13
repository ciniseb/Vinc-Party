/*====================================================================================================
Fichier: Tuile.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 02 février 2023
Description: 
====================================================================================================*/
#ifndef TUILE_H
#define TUILE_H

#include <iostream>

class Tuile
{
private:
    //Attributs
    int remplissage;
    std::string chemin_image;
public:
    //Constructeurs & destructeurs
    Tuile();
    Tuile(int, std::string);
    ~Tuile();

    //Getteurs & setteurs
    int getRemplissage();
    std::string getCheminImage();

    void setRemplissage(int);
    void setCheminImage(std::string);

    //Méthodes
    

};

#endif