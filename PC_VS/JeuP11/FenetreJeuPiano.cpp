/*====================================================================================================
Fichier: FenetreJeuX.cpp
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
FenetreJeuPiano::FenetreJeuPiano() // Main du jeu
{
    //std::cout << "main" << std::endl;
    system("cls");
    AffichageEcran(Menu);
    Sleep(5000);
    chrono.demarrer();
    Temps();
}
FenetreJeuPiano::~FenetreJeuPiano() {}

bool FenetreJeuPiano::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    system("cls");
    double bit;
    double bitCount = 0;
    while(chrono.tempsEcoule_s() < 40)
    {
        bit = bitCount - chrono.tempsEcoule_s();
        if (bit == 0)
        {
            SetNote(bitCount);
            AffichageEcran(Jeu);
            bitCount++;
        }
    }
    return true;
}

void FenetreJeuPiano::SetNote(int t)
{
    char valeur;
    if (t == 0)
    {
        for (int i = 0; i < 22; i++)
        {
            noteA[i] = ' ';
            noteS[i] = ' ';
            noteD[i] = ' ';
            noteF[i] = ' ';
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (i = 22; i > 0; i--)
        {
            noteA[i] = noteA[i - 1];
            noteS[i] = noteS[i - 1];
            noteD[i] = noteD[i - 1];
            noteF[i] = noteF[i - 1];
        }
        if (matrice[t][i] == 0)
        {
            switch (i)
            {
            case A:
                noteA[0] = ' ';
                break;
            case S:
                noteS[0] = ' ';
                break;
            case D:
                noteD[0] = ' ';
                break;
            case F:
                noteF[0] = ' ';
                break;
            }
        }
        else 
        {
            switch (i)
            {
            case A:
                noteA[0] = 'A';
                break;
            case S:
                noteS[0] = 'S';
                break;
            case D:
                noteD[0] = 'D';
                break;
            case F:
                noteF[0] = 'F';
                break;
            }
        }  
    }
}

void FenetreJeuPiano::AffichageEcran(int mode)
{
    //std::cout << "Affichage" << std::endl;
    char screen[25][50];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 1 });

    switch (mode)
    {
    case Menu:
        std::cout << "Appuyez sur A,S,D ou F pour commencer" << '\n';
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (i == 0 || i == 24 || j == 0 || j == 49)
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
        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (i == 0 || i == 23 || j == 0 || j == 49)
                {
                    screen[i][j] = '#';
                }
                else
                {
                    screen[i][j] = ' ';
                    if (j == 10 && i<22)
                    {
                        screen[i][j] = GetNote(A, i-1);
                    }
                    if (j == 20)
                    {
                        screen[i][j] = GetNote(S, i-1);
                    }
                    if (j == 30)
                    {
                        screen[i][j] = GetNote(D, i-1);
                    }
                    if (j == 40)
                    {
                        screen[i][j] = GetNote(F, i-1);
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
    case A:
       // std::cout << "valeur noteA ligne : "<< ligne << " = " << noteA[ligne] << '\n';
        return noteA[ligne];
        break;
    case S:
        return noteS[ligne];
        break;
    case D:
        return noteD[ligne];
        break;
    case F:
        return noteF[ligne];
        break;
    }
    return ' ';
}

