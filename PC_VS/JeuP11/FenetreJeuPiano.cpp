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

    if (MODE_MOZART) {
        reussite = true;
        return;
    }

    bool demarrage = true;
    bool start_music = false;
    std::unique_ptr<Evenement> evenement;

    //std::cout << "main" << std::endl;
    for (int i = 0; i < 22; i++)
    {
        noteD[i] = ' ';
        noteI[i] = ' ';
        noteE[i] = ' ';
        noteU[i] = ' ';
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
                        case 'D':
                            noteD[18] = ' ';
                            noteD[19] = ' ';
                            noteD[20] = ' ';
                            noteD[21] = ' ';
                            break;
                        case 'I':
                            noteI[18] = ' ';
                            noteI[19] = ' ';
                            noteI[20] = ' ';
                            noteI[21] = ' ';
                            break;
                        case 'E':
                            noteE[18] = ' ';
                            noteE[19] = ' ';
                            noteE[20] = ' ';
                            noteE[21] = ' ';
                            break;
                        case 'U':
                            noteU[18] = ' ';
                            noteU[19] = ' ';
                            noteU[20] = ' ';
                            noteU[21] = ' ';
                            break;
                        }
                        //std::cout << "'GG!!" << std::endl;
                    }
                    else if(noteReussi > 0)
                    {
                        
                    }
                }  
            }
        }
        Temps();

        if (chrono.tempsEcoule_ms() > 43000)
        {
            if (noteReussi >= 21)
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
        noteD[j] = noteD[j - 1];
        noteI[j] = noteI[j - 1];
        noteE[j] = noteE[j - 1];
        noteU[j] = noteU[j - 1];
    }
    for (int i = 0; i < 4; i++)
    {
        if (matrice[t][i] == 0)
        {
            switch (i)
            {
            case 0:
                noteD[0] = ' ';
                break;
            case 1:
                noteI[0] = ' ';
                break;
            case 2:
                noteE[0] = ' ';
                break;
            case 3:
                noteU[0] = ' ';
                break;
            }
        }
        else
        {
            switch (i)
            {
            case 0:
                noteD[0] = 'D';
                break;
            case 1:
                noteI[0] = 'I';
                break;
            case 2:
                noteE[0] = 'E';
                break;
            case 3:
                noteU[0] = 'U';
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
        std::cout << "Appuyez sur D,I,E ou U pour commencer" << '\n';
        for (int i = 0; i < 24; i++)
        {
            //std::cout << i << '\n';
            for (int j = 0; j < 50; j++)
            {
               
                if (i == 0 || i == 18 || j == 0 || j == 49)
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
        std::cout << "Appuyez sur D,I,E ou U quand la note s'affiche sur la manette" << std::endl
                  << "             Notes reussites : " << noteReussi << std::endl;
        //std::cout << "Affichage Jeu" << std::endl;
        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (i <18 && (i == 0 || i == 18  || j == 0 || j == 49))
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
                                 threadArduino->envoyerEvenement(std::make_unique<Bargraph>(Dieu::D));
                                 screen[i][10] = GetNote(0, 17);
                             }
                             if (GetNote(1, 17) != ' ')
                             {
                                 threadArduino->envoyerEvenement(std::make_unique<Bargraph>(Dieu::I));
                                 screen[i][20] = GetNote(1, 17);
                             }
                             if (GetNote(2, 17) != ' ')
                             {
                                 threadArduino->envoyerEvenement(std::make_unique<Bargraph>(Dieu::E));
                                 screen[i][30] = GetNote(2, 17);
                             }
                             if (GetNote(3, 17) != ' ')
                             {
                                 threadArduino->envoyerEvenement(std::make_unique<Bargraph>(Dieu::U));
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
    for (int i = 0; i < 19; i++)
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
        return noteD[ligne];
        break;
    case 1:
        return noteI[ligne];
        break;
    case 2:
        return noteE[ligne];
        break;
    case 3:
        return noteU[ligne];
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
        toucheEnChar = 'D';
        break;
    case Dieu::I:
        toucheEnChar = 'I';
        break;
    case Dieu::E:
        toucheEnChar = 'E';
        break;
    case Dieu::U:
        toucheEnChar = 'U';
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
    case 'D': //std::cout << "z marche" << std::endl;
        if (toucheEnChar == GetNote(0,19) || toucheEnChar == GetNote(0, 20) || toucheEnChar == GetNote(0, 21) || toucheEnChar == GetNote(0, 22))
        {
            //std::cout << "Pareille!" << std::endl;
            toucheReussi = 1;
        }
        //std::cout << "Mauvais!" << std::endl;
        return toucheReussi;
        break;
    case 'I': 
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
    case 'E': 
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
    case 'U': 
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