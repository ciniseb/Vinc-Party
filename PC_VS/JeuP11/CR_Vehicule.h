#pragma once
#define MS_PAR_CASE 250

enum class Vitesse {
    RAPIDE,LENTE, NORMALE
};


class CR_Vehicule
{
private:
    int periode = 0;
    int t_on = 0;
    int vitesse = 0;
public:
    CR_Vehicule(int periode, int t_on, Vitesse vitesse);
    ~CR_Vehicule();
    bool intersect(int x, int temps);
};

