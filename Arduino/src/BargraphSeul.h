#pragma once

class BargraphSeul
{
private:
    char position =11;
    unsigned long tempsDebut = 0;
    bool actif = false;    
    static const int ledPin[];
public:
    BargraphSeul();
    ~BargraphSeul();
    void demarrer();
    void afficher();
    void calculer();
    void reset();
};

