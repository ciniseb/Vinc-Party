#pragma once
#include "Evenement.h"
#include "CONSTANTES.h"



class Bargraph :
	public Evenement
{
private:
	Dieu nomBargraph;
public:
	Bargraph(Dieu nomBargraph);
	~Bargraph();
	Dieu getNomBargraph();
	char dataOut();

};


