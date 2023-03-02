#pragma once
#include "Evenement.h"
#include "CONSTANTES.h"




class Bouton :
    public Evenement
{
private:
	Dieu nom;
	bool pianoReussi;
public:
	Bouton(Dieu nom, bool pianoReussi = false);
	Bouton(char data);
	~Bouton();
	Dieu getNom();
	bool getPianoReussi();
	std::string getDesciption();
};

