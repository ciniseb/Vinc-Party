/*====================================================================================================
Fichier: FenetreJeuMineur.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
Description: Fenetre du jeu mineur 
====================================================================================================*/
#include "FenetreJeuMineur.h"

MoteurJeuMineur::MoteurJeuMineur(ES* threadArduino, ThreadMoteur* threadMoteur): MoteurMiniJeu(threadArduino, threadMoteur)
{
    initialiser();
}

MoteurJeuMineur::~MoteurJeuMineur() {}

void MoteurJeuMineur::demarrer()
{
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;
    
    system("cls");
    affichageEcran(Menu);


    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement(); // d�marre avec dieu
            if (evenement->getCode() == ACCELEROMETRE)
            {
                if (demarrage)
                {
                    chrono.demarrer();
                    demarrage = false;

                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                Accel* aaccel = static_cast<Accel*>(evenement.get());
                TypeMotion mouvement = aaccel->getType();
                variationAxe(mouvement);

                emit threadMoteur->jeuMineur_block(nbCoups/(nbVoulu*1.0)*100);
                // Animation(selon le pourcentage)

                affichageEcran(Jeu);
            }
        }

        Temps();

                if (nbCoups == nbVoulu)
                {
                    //Diamant...

                    reussite = true;
                    system("cls");
                    std::cout << "yeah gg" << std::endl;
                    //Sleep(2000);
                    demarrage = false;
                    threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));
                    nbCoups = 0;
                    return;
                }
                
        else if (chrono.tempsEcoule_s() > (tempsMax+1) && nbCoups != 5)
        {
            ///Animation de fail....

            reussite = false;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
            echouer = true;
            system("cls");
            std::cout << "booooooo :(                                                                 ";
            if (evenement->getCode() == BOUTON)
            {
                threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));
                nbCoups = 0;
                return;
            }
            nbCoups = 0;
            return;
        }
    }
}

void MoteurJeuMineur::affichageEcran(int mode)
{

    int height = ((nbVoulu * 2) + 1), width = ((nbVoulu * 2) + 1);
    char matrice[50][50];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    switch (mode)
    {
    case Menu:
        emit threadMoteur->jeuMineur_menu();
            std::cout << "Creusez pour commencer (h/b clavier), " << nbVoulu << " coups voulus en " << tempsMax << " secondes :o" << std::endl << std::endl; // donnez un coup pour commencer - avec accelerometre
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == nbVoulu && j == nbVoulu) {
                        matrice[i][j] = '*';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        break;
    case Jeu:
 

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
            std::cout << "Creusez jusqu'au diamant pour gagner!" << std::endl << std::endl;

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == nbVoulu && j == nbVoulu) {
                        matrice[i][j] = '*';
                    }
                    else if (i < (0 + nbCoups) || i >((nbVoulu * 2) - nbCoups) || j < (0 + nbCoups) || j >((nbVoulu * 2) - nbCoups)) {
                        matrice[i][j] = ' ';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        break;
    }

        // affichage matrice
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << matrice[i][j];
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << "nbCoups: " << nbCoups << "/" << nbVoulu << " coups" << std::endl;
        std::cout << std::endl << positionHaut << positionBas << std::endl;
   
}

int MoteurJeuMineur::getCoup() {
    return nbCoups;
}

void MoteurJeuMineur::setCoup(int x) {
    nbCoups = x;
}

void MoteurJeuMineur::variationAxe(TypeMotion variation) {
    if (variation == PECHE) {
        positionHaut = true;
        positionBas = false;
        threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(10));
    }
    if (variation == MINER && positionHaut==true){
        positionBas = true;
        positionHaut = false;
        std::cout << "descendu" << std::endl;
        nbCoups++;
        threadArduino->envoyerEvenement(std::make_unique<Vibration>());
        threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));
    }
}

bool MoteurJeuMineur::Temps() // Fonction qui fait le refresh des fonctions
{
 
    return true;
}

void MoteurJeuMineur::initialiser()
{
    chrono = Chronometre();

    nbCoups = 0; // compteur
    nbVoulu = 17; // changer pour augmenter la difficulte
    tempsMax = 10; // changer pour augmenter la difficulte

    bitCount = 0;
    positionHaut = false;
    positionBas = false;
    echouer = false;
}