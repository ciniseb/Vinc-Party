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

bool FenetreJeuPiano::chargerChanson(bool matrice[50001][4])
{
    std::ifstream fichier;

    fichier.open("chanson_1.csv");

    if (fichier.is_open())
    {
        std::string ligne;

        for (int r = 0; getline(fichier, ligne) && r < 50001; r++)
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
    bool start_music = false;
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
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 27 });
        //std::cout << bitCount << std::endl;
        if(bitCount == 3750 && start_music == false)
        {
            //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 28 });
            //std::cout << "Start" << std::endl;
            const wchar_t* chanson = L"StillDre.wav";
            bool played = PlaySound(chanson, NULL, SND_ASYNC);
            start_music = true;
        }
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 28 });
        //std::cout << "     ";
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();
            if (evenement->getCode() == BOUTON)
            {
                if (demarrage)
                {          
                    system("cls");
                    chrono.demarrer();
                    demarrage = false;
                }              
                else
                {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 26 });
                    Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                    Dieu lettreAppuyee = eBouton->getNom();
                    if (VersBoutonPressee(lettreAppuyee) == true)
                    {
                        noteReussi++;
                        char note = Dieu_en_char(lettreAppuyee);
                        switch (note)
                        {
                        case 'Z':
                            noteA[18] = ' ';
                            noteA[19] = ' ';
                            noteA[20] = ' ';
                            noteA[21] = ' ';
                            break;
                        case 'X':
                            noteS[18] = ' ';
                            noteS[19] = ' ';
                            noteS[20] = ' ';
                            noteS[21] = ' ';
                            break;
                        case 'C':
                            noteD[18] = ' ';
                            noteD[19] = ' ';
                            noteD[20] = ' ';
                            noteD[21] = ' ';
                            break;
                        case 'V':
                            noteF[18] = ' ';
                            noteF[19] = ' ';
                            noteF[20] = ' ';
                            noteF[21] = ' ';
                            break;
                        }
                        //std::cout << "'GG!!" << std::endl;
                    }
                    else if(noteReussi > 0)
                    {
                        noteReussi--;
                        //std::cout << "'ARK.." << std::endl;
                    }
                }  
            }
        }
        Temps();

        if (chrono.tempsEcoule_ms() > 41000)
        {
            if (noteReussi <= 10)
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

        bit = bitCount - chrono.tempsEcoule_ms();
        

        if (bit <= 0)
        {
            SetNote(bitCount/250);
            AffichageEcran(Jeu);
            bitCount = bitCount + 250;
            //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 31 });
            //std::cout << bitCount << std::endl;
        }
    return true;
}

void FenetreJeuPiano::SetNote(int t)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 30});
    std::cout << t << std::endl;
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
        std::cout << "Appuyez sur Z,X,C ou V au bon moment pour gagner" << std::endl
                  << "             Notes reussites : " << noteReussi << std::endl;
        //std::cout << "Affichage Jeu" << std::endl;
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
                    for (int e = 0; e < 4; e++)
                    {
                        if (i == 18 && j != 0 && j != 49)
                        {
                             screen[i][j] = '=';
                             if (GetNote(0, 17) != ' ')
                             {
                                 screen[i][10] = GetNote(0, 17);
                             }
                             if (GetNote(1, 17) != ' ')
                             {
                                 screen[i][20] = GetNote(1, 17);
                             }
                             if (GetNote(2, 17) != ' ')
                             {
                                 screen[i][30] = GetNote(2, 17);
                             }
                             if (GetNote(3, 17) != ' ')
                             {
                                 screen[i][40] = GetNote(3, 17);
                             }
                        }
                        else
                        {
                            
                            if (j == 10)
                            {
                                screen[i][j] = GetNote(0, i - 1);
                            }
                            if (j == 20)
                            {
                                screen[i][j] = GetNote(1, i - 1);
                            }
                            if (j == 30)
                            {
                                screen[i][j] = GetNote(2, i - 1);
                            }
                            if (j == 40)
                            {
                                screen[i][j] = GetNote(3, i - 1);
                            }
                        }
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

char FenetreJeuPiano::Dieu_en_char(Dieu dieu)
{
    char toucheEnChar = ' ';

    switch (dieu)
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
    return toucheEnChar;
}

//Getteurs & setteurs
bool FenetreJeuPiano::VersBoutonPressee(Dieu touche)
{
    char toucheEnChar = Dieu_en_char(touche);
    bool toucheReussi = 0;

    switch (toucheEnChar)
    {
    case 'Z': //std::cout << "z marche" << std::endl;
        if (toucheEnChar == GetNote(0,19) || toucheEnChar == GetNote(0, 20) || toucheEnChar == GetNote(0, 21) || toucheEnChar == GetNote(0, 22))
        {
            //std::cout << "Pareille!" << std::endl;
            toucheReussi = 1;
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'X': 
        //std::cout << "x marche" << std::endl;
        toucheReussi = 0;
        if (toucheEnChar == GetNote(1, 19) || toucheEnChar == GetNote(1, 20) || toucheEnChar == GetNote(1, 21) || toucheEnChar == GetNote(1, 22))
        {
            //std::cout << "Pareille!" << std::endl;
            toucheReussi = 1;
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'C': 
        //std::cout << "c marche" << std::endl;
        toucheReussi = 0;
        if (toucheEnChar == GetNote(2, 19) || toucheEnChar == GetNote(2, 20) || toucheEnChar == GetNote(2, 21) || toucheEnChar == GetNote(2, 22))
        {
            //std::cout << "Pareille!" << std::endl;
            toucheReussi = 1;
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'V': 
        //std::cout << "v marche" << std::endl;
         toucheReussi = 0;
         if (toucheEnChar == GetNote(3, 19) || toucheEnChar == GetNote(3, 20) || toucheEnChar == GetNote(3, 21) || toucheEnChar == GetNote(3, 22))
         {
             //std::cout << "Pareille!" << std::endl;
             toucheReussi = 1;
         }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    }
}