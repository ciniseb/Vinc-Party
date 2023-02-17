#pragma once
#include <memory>

enum CodeEvenement
{
	BOUTON,
	JOYSTICK,
	ACCELEROMETRE,
	BOUSSOLE,
	BARGRAPH,
	VIBRATION
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
};

