#pragma once
enum TypeMotion
{
	PECHE,
	MINER,
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
