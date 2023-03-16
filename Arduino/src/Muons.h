#pragma once
class Muons 
{
private:
    char valeur;

public:
    Muons(int valeur);
    Muons(char data);
    ~Muons();
    int getValeur();
    char dataOut();
};