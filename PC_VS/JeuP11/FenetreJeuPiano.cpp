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
    
}
FenetreJeuPiano::~FenetreJeuPiano() {}

void FenetreJeuPiano::ouvrir()
{
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
    Sleep(5000);
    chrono.demarrer();
    Temps();
}

bool FenetreJeuPiano::Temps() // Fonction qui fait le refresh des fonctions
{
    //std::cout << "Temps" << std::endl;   
    system("cls");
    double bit;
    double bitCount = 0;
    
    while(chrono.tempsEcoule_s() < 60)
    {
        
        bit = bitCount - chrono.tempsEcoule_s();
        
        if (bit == 0 && bitCount < 40)
        {
            SetNote(bitCount);
            //std::cout << "Oue oue oue" << std::endl;
            AffichageEcran(Jeu);
            bitCount++;
        }
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
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    switch (mode)
    {
    case Menu:
        std::cout << "Appuyez sur A,S,D ou F pour commencer" << '\n';
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
        std::cout << "Appuyez sur A,S,D ou F au bon moment pour gagner" << '\n';
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

