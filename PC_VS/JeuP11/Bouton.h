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
	bool pianoReussi;
public:
	Bouton(NomBouton nom, bool pianoReussi = false);
	Bouton(char data);
	~Bouton();
	NomBouton getNom();
	bool getPianoReussi();
};

