#include "CR_Vehicule.h"


CR_Vehicule::CR_Vehicule(int periode, int t_on, Vitesse vitesse) {
	this->periode = periode;
	this->t_on = t_on;


	switch (vitesse)
	{
	case Vitesse::RAPIDE: this->vitesse = 1;
		break;
	case Vitesse::LENTE: this->vitesse = 3;
		break;
	case Vitesse::NORMALE: this->vitesse = 2;
		break;
	default:
		break;
	}
}

CR_Vehicule::~CR_Vehicule(){}


bool CR_Vehicule::intersect(int x, int temps) {
	int X = x;
	int H = temps;

	int V = vitesse;



	//Formule du vehicule, genere une onde carre de periode et temps on voulu, la fait decaler quand le temps avance et indique si la position X est a ON ou a OFF
	//(Modificateur de vitesse * position en x + decalage du temps) modulo (periode * Modificateur de vitesse) < (Temps a On * Modificateur vitesse)
	return (((V * X * MS_PAR_CASE) + H) % (periode * V * MS_PAR_CASE)) < (t_on * V * MS_PAR_CASE);
}
