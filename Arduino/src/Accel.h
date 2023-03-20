#pragma once
enum TypeMotion
{
	MINER,
	RIEN
};


class Accel 
{
private:
	TypeMotion type;
public:
	Accel(TypeMotion type);
	Accel(char data);
	~Accel();
	TypeMotion getType();
    char dataOut();

};
