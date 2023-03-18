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

FenetreJeuMineur::FenetreJeuMineur(ES* thread): FenetreMiniJeu(thread) {initialiser();}
FenetreJeuMineur::~FenetreJeuMineur() {}

void FenetreJeuMineur::ouvrir()
{
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;
    //int nbCoupsReussis = 0;
    int nbVoulu = 5;
    
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
                std::cout << mouvement << std::endl;
                affichageEcran(Jeu);
            }
        }
        Temps();

            //std::cout << "the final "<<nbCoups;
            //if (chrono.tempsEcoule_s() < 10)
            
                //system("cls");
                //std::cout << "nbCOups final" << nbCoups;
                if (nbCoups == 5)
                {
                    reussite = true;
                    std::cout << "yeah gg" << std::endl;
                    //Sleep(1000);
                    demarrage = false;
                    return;

                }
                
        else if (chrono.tempsEcoule_s() > 11  && nbCoups != 5)
        {
            reussite = false;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
            echouer = true;
            std::cout << "booooooo 2                                                                ";
            if (evenement->getCode() == BOUTON)
            {
            return;
            }

        }
    }
}

void FenetreJeuMineur::affichageEcran(int mode) {
    int height = 11, width = 11;
    char matrice[11][11];

    //chrono.demarrer();
    //std::cout << "Temps ecoule: " << chrono << std::endl;
    //std::cout << "temps ecoule: "<<chrono.tempsEcoule_s()+1<<"s" << std::endl;

    switch (mode)
    {
    case Menu:
        std::cout << "Creusez pour commencer (h/b clavier), vous avez 10 secondes :o" << std::endl << std::endl; // donnez un coup pour commencer - avec accelerometre
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 5 && j == 5) {
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
        if (nbCoups == 0)
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        }
        if (nbCoups == 1)
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    else if (i == 0 || i == 10 || j == 0 || j == 10) {
                        matrice[i][j] = ' ';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        }
        if (nbCoups == 2)
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    else if (i <= 1 || i >= 9 || j <= 1 || j >= 9) {
                        matrice[i][j] = ' ';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        }
        if (nbCoups == 3)
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    else if (i <= 2 || i >= 8 || j <= 2 || j >= 8) {
                        matrice[i][j] = ' ';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        }
        if (nbCoups == 4)
        {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    else if (i <= 3 || i >= 7 || j <= 3 || j >= 7) {
                        matrice[i][j] = ' ';
                    }
                    else {
                        matrice[i][j] = '#';
                    }
                }
            }
        }
        if (nbCoups == 5)
        {
            system("cls");
            std::cout << "voici le diamant... avez-vous ete assez rapide?" << std::endl<<std::endl<<std::endl;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 5 && j == 5) {
                        matrice[i][j] = '*';
                    }
                    //if (i <= 4 || i >= 6 || j <= 4 || j >= 6) {
                      //  matrice[i][j] = ' ';
                    //}
                    else {
                        matrice[i][j] = ' ';
                    }
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

    std::cout << std::endl << "nbCoups: " << nbCoups << "/5" << std::endl;
    std::cout << std::endl << positionHaut << std::endl;
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
    }
    if (variation == MINER && positionHaut==true){
        positionBas = true;
        positionHaut = false;
        nbCoups++;
    }
}

bool FenetreJeuMineur::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    //system("cls");
    bit = bitCount - chrono.tempsEcoule_s();
    if (bit == 0 && bitCount < 10) {
        bitCount++;
    }


    return true;
}


void FenetreJeuMineur::initialiser()
{
    //TODO
    chrono = Chronometre();
    nbCoups = 0; // compteur
    bitCount = 0;
    positionHaut = false;
    positionBas = false;
    enso = true;
    echouer = false;
}


/*Chronometre FenetreJeuMineur::getTemps()
{
    return chrono;
}
*/

/*void FenetreJeuMineur::setTemps(Chronometre t)
{
    chrono = t;
}*/

// quoi faire:
// ajout chrono dans la barre de jeu
// retour accueil et reussite

// ajout composants
// accelerometre : dans fonction variation axe, detecte variation si coup assez fort
// bargraph : allume selon intensit� du coup
// a