#pragma once
#include "Evenement.h"
#include <string>
class Muons :
    public Evenement
{
private:
    char valeur;

public:
    Muons(int valeur);
    Muons(char data);
    ~Muons();
    int getValeur();
    char dataOut();
    std::string getDesciption();
};

