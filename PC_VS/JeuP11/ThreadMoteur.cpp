#include "ThreadMoteur.h"
#include "FenetreMenu.h"

ThreadMoteur::ThreadMoteur(ES* threadArduino, QObject *parent)
	: QThread(parent)
{
    this->threadArduino = threadArduino;
    this->moteur = new MoteurMenu(threadArduino, this);
}

ThreadMoteur::~ThreadMoteur()
{}

void ThreadMoteur::run()
{

    moteur->demarrer();
    /*std::unique_ptr<Evenement> evenement;
    bool actif = true;

    //ES threadArduino;
    //threadArduino.demarrer();

	int i = 0;
	while (true)
	{
		/*QMutex mutex;
		mutex.lock();
		if (stop)
		{
			break;
		}
		mutex.unlock();

        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == BOUTON)
            {
                Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                Dieu lettreAppuyee = eBouton->getNom();

                if (lettreAppuyee == Dieu::D && !stop)
                {
                    stop = true;
                }
                else if (lettreAppuyee == Dieu::D && stop)
                {
                    stop = false;
                }
            }
        }

        if (!stop)
        {
            msleep(100);
            emit updateNumero(i++);
        }
	}*/
}