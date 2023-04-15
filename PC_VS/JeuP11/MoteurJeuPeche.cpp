/*====================================================================================================
Fichier: FenetreJeuPiano.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 05 f�vrier 2023
Description:
====================================================================================================*/
#include "FenetreJeuPeche.h"
#include "HasardMuons.h"



MoteurJeuPeche::MoteurJeuPeche(ES* threadArduino, ThreadMoteur* threadMoteur) : MoteurMiniJeu(threadArduino, threadMoteur) // Main du jeu
{
    initialiser();
}

MoteurJeuPeche::~MoteurJeuPeche()
{

}

void MoteurJeuPeche::initialiser()
{
    chrono = Chronometre();
    positionJoueur = 0;
    positionPoisson = 0;
    foisReussi = 0;
    activation = true;
    firstscan = true;
    pretPecher = false;
    Riviere1Etat = false;
    Riviere2Etat = false;
    comptePretPecher = 0;

    tempsInit = 0;
    tempsReussi = 0;
    totalReussi = 0;
    bit = 0;
    bitCount = 0;
    bitPrecedent = 0;
}

void MoteurJeuPeche::demarrer()
{
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;
    positionJoueur = 1;
    positionPoisson = 1;

    if (MODE_CONSOLE)
    {
        system("cls");
    }
    affichage(Menu);

    while (true)
    {
        if (!pretPecher)
        {
            if (foisReussi >= NB_HAMECONNAGE)
            {
                pretPecher = true;
            }
            else if (bitCount >= TEMPS_HAMECONNAGE)
            {
                threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));

                if (!MODE_CONSOLE)
                {
                    emit threadMoteur->jeuPecheMAJ_Baleine(14);
                    emit threadMoteur->changementWidgetActif(1);
                }

                return;
            }
        }

        if (pretPecher)
        {
            threadArduino->envoyerEvenement(std::make_unique<Vibration>());

            if (comptePretPecher > TEMPS_PECHE || reussite)
            {
                threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(0));

                if (!MODE_CONSOLE)
                {
                    emit threadMoteur->jeuPecheMAJ_Baleine(14);
                    emit threadMoteur->changementWidgetActif(1);
                }

                return;
            }
        }

        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            if (evenement->getCode() == BOUTON && demarrage)
            {
                chrono.demarrer();
                demarrage = false;
            }
            else if (evenement->getCode() == JOYSTICK && !demarrage)
            {
                if (MODE_CONSOLE)
                {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                }

                Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                Direction lettreAppuyee = eJoystick->getDirection();
                getJoueur(lettreAppuyee);
            }
            else if (evenement->getCode() == ACCELEROMETRE)
            {
                Accel* eAccel = static_cast<Accel*>(evenement.get());
                TypeMotion mouvement = eAccel->getType();
                if (mouvement == PECHE)
                {
                    reussite = true;
                }
            }
        }

        temps();
    }
}

void MoteurJeuPeche::affichage(int selection)
{
    if (MODE_CONSOLE)
    {
        char ecran[14][20];
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        switch (selection)
        {
        case Menu:
            std::cout << "Appuyez sur A,S,D ou W pour commencer" << '\n';
            std::cout << "Ligne de peche   Barre de progression" << std::endl;
            break;
        case Jeu:
            if (!pretPecher)
            {
                std::cout << "Appuyez sur S pour descendre W pour monter" << '\n';
            }
            else
            {
                std::cout << "Appuyez sur H pour attraper le poisson        " << '\n';
            }
            std::cout << "Ligne de peche   Barre de progression" << std::endl;
            threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(foisReussi));
            break;
        default:
            break;
        }

        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (j == 1)
                {
                    if (selection == Jeu && (i == positionPoisson || i == positionPoisson + 1 || i == positionPoisson - 1))
                    {
                        if (i == positionJoueur)
                        {
                            ecran[i][j] = '*';
                        }
                        else
                        {
                            ecran[i][j] = '%';
                        }
                    }
                    else if (i == 0 || i == 13)
                    {
                        ecran[i][j] = '#';
                    }
                    else if (selection == Jeu && i == positionJoueur)
                    {
                        ecran[i][j] = '*';
                    }
                    else
                    {
                        ecran[i][j] = ' ';
                    }

                }
                else if (j == 18)
                {
                    if (foisReussi >= i)
                    {
                        for (int k = 0; k <= foisReussi; k++)
                        {
                            if (pretPecher == true)
                            {
                                for (int k = 0; k <= 8; k++)
                                {
                                    ecran[k + 1][j] = '=';
                                }
                            }
                            else
                            {
                                ecran[k + 1][j] = '=';
                            }
                        }
                    }
                    if (i == 0 || i == 10)
                    {
                        ecran[i][j] = '#';
                    }
                    else
                    {
                        ecran[i][j] = ' ';
                    }
                }
                else
                {
                    if (i == 0 || i == 13 || j == 0 || j == 2)
                    {
                        if (j >= 3 && j <= 17)
                        {
                            for (int k = 3; k < 17; k++)
                            {
                                ecran[i][k] = ' ';
                            }
                        }
                        if (j <= 3)
                        {
                            ecran[i][j] = '#';
                        }

                    }
                    else if (i == 0 || i == 10 || j == 17 || j == 19)
                    {
                        for (int k = 3; k < 17; k++)
                        {
                            ecran[i][k] = ' ';
                        }
                        if (j > 16)
                        {
                            for (int h = 0; h < 11; h++)
                            {
                                ecran[h][j] = '#';
                            }

                        }
                        for (int h = 11; h < 14; h++)
                        {
                            ecran[h][j] = ' ';
                        }

                    }
                    else
                    {
                        ecran[i][j] = ' ';
                    }
                }
            }
        }

        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                std::cout << ecran[i][j];
            }
            std::cout << '\n';
        }
    }
    else
    {
        switch (selection)
        {
        case Menu:
            if (bitCount > bitPrecedent && !Riviere1Etat)
            {
                emit threadMoteur->jeuPecheMAJ_Riviere(2);
                Riviere1Etat = true;
            }
            else if (bitCount > bitPrecedent && Riviere1Etat)
            {
                emit threadMoteur->jeuPecheMAJ_Riviere(1);
                Riviere1Etat = false;
            }
            emit threadMoteur->jeuPecheMAJ_Riviere(1);
            emit threadMoteur->jeuPecheMAJ_Baleine(3);
            emit threadMoteur->jeuPecheMAJ_Pecheur(1);
            emit threadMoteur->jeuPecheMAJ_ProgressBar(foisReussi);
            emit threadMoteur->jeuPecheMAJ_Instruction();
            break;
        case Jeu:
            if (pretPecher == false)
            {
                emit threadMoteur->jeuPecheMAJ_Baleine(positionPoisson);
            }
            else
            {
                emit threadMoteur->jeuPecheMAJ_Baleine(13);
            }

            threadArduino->envoyerEvenement(std::make_unique<QuadBargraph>(foisReussi));

            if (bitCount >= bitPrecedent && !Riviere1Etat && !Riviere2Etat)
            {
                emit threadMoteur->jeuPecheMAJ_Riviere(2);
                Riviere1Etat = true;
                Riviere2Etat = false;
            }
            else if (bitCount >= bitPrecedent && Riviere1Etat && !Riviere2Etat)
            {
                emit threadMoteur->jeuPecheMAJ_Riviere(1);
                Riviere1Etat = false;
                Riviere2Etat = true;
            }
            else if (bitCount >= bitPrecedent && !Riviere1Etat && Riviere2Etat)
            {
                emit threadMoteur->jeuPecheMAJ_Riviere(3);
                Riviere1Etat = false;
                Riviere2Etat = false;
            }

            emit threadMoteur->jeuPecheMAJ_Pecheur(positionJoueur);
            emit threadMoteur->jeuPecheMAJ_ProgressBar(foisReussi);
            emit threadMoteur->jeuPecheMAJ_Message();
            break;
        }
    }
}

bool MoteurJeuPeche::temps() // Fonction qui fait le refresh des fonctions
{
    bit = bitCount - chrono.tempsEcoule_s();

    if (bit <= 0)
    {
        if (bitCount >= bitPrecedent)
        {

            bitPrecedent = bitCount;
        }
        setPoisson();
        affichage(Jeu);
        verificationJoueurPoisson();
        bitCount++;
        if (pretPecher)
        {
            comptePretPecher++;
            std::cout << comptePretPecher << std::endl;

        }
    }
    return true;
}

void MoteurJeuPeche::setPoisson()
{
    int nombre = 0;
    if (pretPecher == true)
    {
        positionPoisson = 5;
    }
    else
    {
        if (firstscan == true)
        {
            if (MODE_CLAVIER)
            {
                srand(time(NULL));
                nombre = (rand() % 10) + 2;
            }
            else
            {
                nombre = (HasardMuons::valeurAleatoire() % 10) + 2;
            }
            positionPoisson = nombre;
            firstscan = false;
        }
        else
        {
            if (bitCount >= bitPrecedent)
            {
                if (positionPoisson <= 9 && positionPoisson >= 5)
                {
                    if (MODE_CLAVIER)
                    {
                        nombre = (rand() % 2) + 1;
                    }
                    else
                    {
                        nombre = (HasardMuons::valeurAleatoire() % 2) + 1;
                    }

                    switch (nombre)
                    {
                    case 1:
                        positionPoisson--;
                        break;
                    case 2:
                        positionPoisson++;
                        break;
                    }
                }

                else if (positionPoisson < 5 && positionPoisson > 2)
                {
                    if (MODE_CLAVIER)
                    {
                        nombre = (rand() % 4) + 1;
                    }
                    else
                    {
                        nombre = (HasardMuons::valeurAleatoire() % 4) + 1;
                    }

                    switch (nombre)
                    {
                    case 1:
                        positionPoisson--;
                        break;
                    case 2:
                        positionPoisson++;
                        break;
                    case 3:
                        positionPoisson++;
                        break;
                    case 4:
                        positionPoisson++;
                        break;
                    }
                }
                else if (positionPoisson > 8 && positionPoisson < 11)
                {
                    if (MODE_CLAVIER)
                    {
                        nombre = (rand() % 4) + 1;
                    }
                    else
                    {
                        nombre = (HasardMuons::valeurAleatoire() % 4) + 1;
                    }

                    switch (nombre)
                    {
                    case 1:
                        positionPoisson--;
                        break;
                    case 2:
                        positionPoisson--;
                        break;
                    case 3:
                        positionPoisson--;
                        break;
                    case 4:
                        positionPoisson++;
                        break;
                    }
                }
                else if (positionPoisson == 2)
                {
                    positionPoisson++;
                }
                else if (positionPoisson == 11)
                {
                    positionPoisson--;
                }


            }
        }
    }
}

void MoteurJeuPeche::getJoueur(Direction touche)
{
    if (pretPecher != true)
    {
        if (MODE_CONSOLE)
        {
            switch (touche)
            {
            case Direction::BAS:
                positionJoueur++;
                break;
            case Direction::HAUT:
                positionJoueur--;
                break;
            }
        }
        else
        {
            switch (touche)
            {
            case Direction::DROITE:
                positionJoueur++;
                break;
            case Direction::GAUCHE:
                positionJoueur--;
                break;
            }
        }

        if (positionJoueur < 1)
        {
            positionJoueur = 1;
        }
        if (positionJoueur > 12)
        {
            positionJoueur = 12;
        }
    }
    else
    {
        positionJoueur = 5;
    }

}

void MoteurJeuPeche::verificationJoueurPoisson()
{
    if (bitCount >= bitPrecedent)
    {
        if (positionJoueur <= positionPoisson + 1 && positionJoueur >= positionPoisson - 1)
        {
            foisReussi++;
        }
    }
}
