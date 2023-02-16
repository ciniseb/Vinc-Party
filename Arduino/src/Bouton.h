enum NomBouton
{
	D,
	I,
	E,
	U
};


class Bouton
{
private:
	NomBouton nom;
	bool pianoReussi;
public:
	Bouton(NomBouton nom, bool pianoReussi = false);
	~Bouton();
	NomBouton getNom();
	bool getPianoReussi();
    char dataOut();
};