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

FenetreJeuMineur::FenetreJeuMineur(ES* thread): FenetreMiniJeu(thread)
{
    initialiser();
}

FenetreJeuMineur::~FenetreJeuMineur() {}

void FenetreJeuMineur::ouvrir()
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
                affichageEcran(Jeu);
            }
        }
        Temps();

                if (nbCoups == nbVoulu)
                {
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

void FenetreJeuMineur::affichageEcran(int mode) {
    int height = ((nbVoulu * 2) + 1), width = ((nbVoulu * 2) + 1);
    char matrice[50][50];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    switch (mode)
    {
    case Menu:
        std::cout << "Creusez pour commencer (h/b clavier), "<< nbVoulu << " coups voulus en " << tempsMax << " secondes :o" << std::endl << std::endl; // donnez un coup pour commencer - avec accelerometre
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
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        std::cout << "Creusez jusqu'au diamant pour gagner!" << std::endl << std::endl;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == nbVoulu && j == nbVoulu) {
                    matrice[i][j] = '*';
                }
                else if (i < (0 + nbCoups) || i >((nbVoulu*2) - nbCoups) || j < (0 + nbCoups) || j >((nbVoulu * 2) - nbCoups)) {
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

int FenetreJeuMineur::getCoup() {
    return nbCoups;
}

void FenetreJeuMineur::setCoup(int x) {
    nbCoups = x;
}

void FenetreJeuMineur::variationAxe(TypeMotion variation) {
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

bool FenetreJeuMineur::Temps() // Fonction qui fait le refresh des fonctions
{
    bit = bitCount - chrono.tempsEcoule_s();
    if (bit == 0 && bitCount < tempsMax) {
        bitCount++;
    }
    return true;
}

void FenetreJeuMineur::initialiser()
{
    //TODO
    chrono = Chronometre();
    nbCoups = 0;
}