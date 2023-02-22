#pragma once
#include "constantes.h"
#include "Bargraph.h"
#include "BargraphSeul.h"

class GestionBargraph
{
private:
    BargraphSeul bargraphsListe[4];
    int compteurMultiplex = 0;
    static const int barPin[];
public:
    GestionBargraph(/* args */);
    ~GestionBargraph();
    void afficher();
    void commande(Bargraph bargraph);
    void init();
    void calculer();
};