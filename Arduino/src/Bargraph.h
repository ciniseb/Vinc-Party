#pragma once
#include "constantes.h"

class Bargraph
{
private:
	Dieu nomBargraph;
public:
	Bargraph(Dieu nomBargraph);
	Bargraph(char data);
	~Bargraph();
	Dieu getNomBargraph();
	char dataOut();

};


