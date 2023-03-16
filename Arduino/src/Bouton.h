#pragma once
#include "constantes.h"
class Bouton
{
private:
	Dieu nom;
	bool pianoReussi;
public:
	Bouton(Dieu nom, bool pianoReussi = false);
	~Bouton();
	Dieu getNom();
	bool getPianoReussi();
    char dataOut();
};