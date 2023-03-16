#pragma once
#include "Evenement.h"
class QuadBargraph :
    public Evenement
{
private:
        int valeur;
public:
    QuadBargraph(int valeur);
    ~QuadBargraph();
    int getValeur();
    char dataOut();
};

