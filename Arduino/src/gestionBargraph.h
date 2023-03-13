#pragma once
#include "constantes.h"
#include "Bargraph.h"
#include "BargraphSeul.h"
#include "QuadBargraph.h"

class GestionBargraph
{
private:
    BargraphSeul bargraphsListe[4];
    int compteurMultiplex = 0;
    static const int barPin[];
    bool modeQuad = false;
    int valeurQuad = 0;
public:
    GestionBargraph(/* args */);
    ~GestionBargraph();
    void afficher();
    void commande(Bargraph bargraph);
    void commande(QuadBargraph quad_bargraph);
    void init();
    void calculer();
    bool intesection(Dieu lettre);
};