#pragma once

#include <QThread>
#include "ES.h"
#include "Fenetre.h"

class Moteur;
class ThreadMoteur : public QThread
{
	Q_OBJECT

private:
	ES* threadArduino;
	Moteur* moteur;

public:
	ThreadMoteur(ES* threadArduino = nullptr, QObject *parent = nullptr);
	~ThreadMoteur();

	void run();
	bool stop = false;
signals:
	void updateNumero(int valeur);
};
