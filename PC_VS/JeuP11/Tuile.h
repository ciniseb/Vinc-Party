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
    ~Tuile();

    //Getteurs & setteurs
    int getRemplissage();
    std::string getCheminImage();

    void setRemplissage(int);
    void setCheminImage(std::string);

    //Méthodes
    

};
