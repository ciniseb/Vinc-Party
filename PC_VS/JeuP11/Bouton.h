#pragma once
#include "Evenement.h"

enum NomBouton
{
	D,
	I,
	E,
	U
};


class Bouton :
    public Evenement
{
private:
	NomBouton nom;
public:
	Bouton(NomBouton nom);
	~Bouton();
	NomBouton getNom();
};

