#pragma once
#include <memory>
#include <string>

enum CodeEvenement
{
	BOUTON,
	JOYSTICK,
	ACCELEROMETRE,
	BOUSSOLE,
	BARGRAPH,
	VIBRATION,
	QUAD_BARGRAPH,
	MUONS
};

class Evenement
{
private:
	CodeEvenement code;
public:
	Evenement(CodeEvenement code);
	~Evenement();
	CodeEvenement getCode();
	
	static std::unique_ptr<Evenement> decoder(char data);
	virtual char dataOut();
	virtual std::string getDesciption();
};

