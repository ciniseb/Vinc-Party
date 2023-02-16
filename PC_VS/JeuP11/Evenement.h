#pragma once
#include <memory>

enum CodeEvenement
{
	BOUTON,
	JOYSTICK,
	ACCELEROMETRE
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
};

