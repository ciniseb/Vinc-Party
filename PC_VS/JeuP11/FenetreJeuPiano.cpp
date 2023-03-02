/*====================================================================================================
Fichier: FenetreJeuPiano.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 05 février 2023
Description: 
====================================================================================================*/
#include "FenetreJeuPiano.h"

//Constructeurs & destructeurs
FenetreJeuPiano::FenetreJeuPiano(ES *thread): FenetreMiniJeu(thread) // Main du jeu
{
    noteReussi = 0;
    chargerChanson(matrice);
}
FenetreJeuPiano::~FenetreJeuPiano() {}

bool FenetreJeuPiano::chargerChanson(bool matrice[40][4])
{
    std::ifstream fichier;

    fichier.open("chanson_1.csv");

    if (fichier.is_open())
    {
        std::string ligne;

        for (int r = 0; getline(fichier, ligne) && r < 40; r++)
        {
            std::istringstream flux(ligne);
            std::string nombre;
            for (int c = 0; getline(flux, nombre, ';') && c < 4; c++)
            {
                matrice[r][c] = stoi(nombre);
            }
        }
    }
    fichier.close();
    return true;
}

void FenetreJeuPiano::ouvrir()
{
    bool demarrage = true;
    std::unique_ptr<Evenement> evenement;

    //std::cout << "main" << std::endl;
    for (int i = 0; i < 22; i++)
    {
        noteA[i] = ' ';
        noteS[i] = ' ';
        noteD[i] = ' ';
        noteF[i] = ' ';
    }
    system("cls");
    AffichageEcran(Menu);
    
    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            if (evenement->getCode() == BOUTON)
            {
                if (demarrage)
                {
                    chrono.demarrer();
                    demarrage = false;
                }
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                Dieu lettreAppuyee = eBouton->getNom();
                if (VersBoutonPressee(lettreAppuyee) == true)
                {
                    noteReussi++;
                    std::cout << "'WOW!!" << std::endl;
                }
                else
                {
                    std::cout << "'ARK.." << std::endl;
                }
            }
        }
        Temps();

        if (chrono.tempsEcoule_s() > 41)
        {
            if (noteReussi >= 10)
            {
                reussite = true;
            }
            else
            {
                reussite = false;
            }
            return;
        }
    }
}

bool FenetreJeuPiano::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    //system("cls");

        bit = bitCount - chrono.tempsEcoule_s();
        
        if (bit == 0 && bitCount < 40)
        {
            SetNote(bitCount);
            //std::cout << "Oue oue oue" << std::endl;
            AffichageEcran(Jeu);
            bitCount++;
        }
    return true;
}

void FenetreJeuPiano::SetNote(int t)
{
    for (int j = 21; j > 0; j--)
    {
        noteA[j] = noteA[j - 1];
        noteS[j] = noteS[j - 1];
        noteD[j] = noteD[j - 1];
        noteF[j] = noteF[j - 1];
    }
    for (int i = 0; i < 4; i++)
    {
        if (matrice[t][i] == 0)
        {
            switch (i)
            {
            case 0:
                noteA[0] = ' ';
                break;
            case 1:
                noteS[0] = ' ';
                break;
            case 2:
                noteD[0] = ' ';
                break;
            case 3:
                noteF[0] = ' ';
                break;
            }
        }
        else
        {
            switch (i)
            {
            case 0:
                noteA[0] = 'Z';
                break;
            case 1:
                noteS[0] = 'X';
                break;
            case 2:
                noteD[0] = 'C';
                break;
            case 3:
                noteF[0] = 'V';
                break;
            }
        }
    }
}

void FenetreJeuPiano::AffichageEcran(int mode)
{
    //std::cout << "Affichage" << std::endl;
    char screen[25][50];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    switch (mode)
    {
    case Menu:
        std::cout << "Appuyez sur Z,X,C ou V pour commencer" << '\n';
        for (int i = 0; i < 24; i++)
        {
            //std::cout << i << '\n';
            for (int j = 0; j < 50; j++)
            {
               
                if (i == 0 || i == 23 || j == 0 || j == 49)
                {
                    
                    screen[i][j] = '#';
                }
                else
                {
                    screen[i][j] = ' ';
                }
            }
        }
        break;
    case Jeu:
        std::cout << "Appuyez sur Z,X,C ou V au bon moment pour gagner" << '\n';
        //std::cout << "Affichage Jeu" << std::endl;
        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (i == 0 || i == 23 || j == 0 || j == 49)
                {
                    screen[i][j] = '#';
                }
                else if (i == 20 && j != 0 && j != 49)
                {
                    screen[i][j] = '=';
                }
                else
                {
                    screen[i][j] = ' ';
                    if (j == 10)
                    {
                        screen[i][j] = GetNote(0, i-1);
                    }
                    if (j == 20)
                    {
                        screen[i][j] = GetNote(1, i-1);
                    }
                    if (j == 30)
                    {
                        screen[i][j] = GetNote(2, i-1);
                    }
                    if (j == 40)
                    {
                        screen[i][j] = GetNote(3, i-1);
                    }
                }
            }
        }
        break;
    }
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            std::cout << screen[i][j];
        }
        std::cout << '\n';
    }
    return;
}

char FenetreJeuPiano::GetNote(int note, int ligne)
{
    switch (note)
    {
    case 0:
       // std::cout << "valeur noteA ligne : "<< ligne << " = " << noteA[ligne] << '\n';
        return noteA[ligne];
        break;
    case 1:
        return noteS[ligne];
        break;
    case 2:
        return noteD[ligne];
        break;
    case 3:
        return noteF[ligne];
        break;
    }
    return ' ';
}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee(Dieu touche)
{
    char toucheEnChar = ' ';
    bool toucheReussi = 0;

    switch (touche)
    {
    case Dieu::D:
        toucheEnChar = 'Z';
            break;
    case Dieu::I:
        toucheEnChar = 'X';
        break;
    case Dieu::E:
        toucheEnChar = 'C';
        break;
    case Dieu::U:
        toucheEnChar = 'V';
        break;
    }
    switch (toucheEnChar)
    {
    case 'Z': //std::cout << "z marche" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            if (toucheEnChar == GetNote(i,20) || toucheEnChar == GetNote(i, 21))
            {
                //std::cout << "Pareille!" << std::endl;
                toucheReussi = 1;
            }
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'X': 
        //std::cout << "x marche" << std::endl;
        toucheReussi = 0;
        for (int i = 0; i < 4; i++)
        {
            if (toucheEnChar == GetNote(i, 20) || toucheEnChar == GetNote(i, 21))
            {
                //std::cout << "Pareille!" << std::endl;
                toucheReussi = 1;
            }
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'C': 
        //std::cout << "c marche" << std::endl;
        toucheReussi = 0;
        for (int i = 0; i < 4; i++)
        {
            if (toucheEnChar == GetNote(i, 20) || toucheEnChar == GetNote(i, 21))
            {
                //std::cout << "Pareille!" << std::endl;
                toucheReussi = 1;
            }
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'V': 
        //std::cout << "v marche" << std::endl;
         toucheReussi = 0;
        for (int i = 0; i < 4; i++)
        {
            if (toucheEnChar == GetNote(i, 20) || toucheEnChar == GetNote(i, 21))
            {
                //std::cout << "Pareille!" << std::endl;
                toucheReussi = 1;
            }
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    }
}