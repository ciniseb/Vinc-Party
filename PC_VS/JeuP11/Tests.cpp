/*====================================================================================================
Fichier: Tests.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 12 février 2023
Description: 
====================================================================================================*/
#include "Tests.h"

//Constructeurs & destructeurs
Tests::Tests() {}
Tests::~Tests() {}

//Méthodes
void Tests::tests_chronometre()
{
    Chronometre chrono;

    std::cout << "  Résultat attendu : -1 secondes" << std::endl;

    std::cout << "temps (ms) : " << chrono.tempsEcoule_ms() << std::endl;
    std::cout << "temps (s) : " << chrono.tempsEcoule_s() << std::endl;
    std::cout << "temps (m) : " << chrono.tempsEcoule_m() << std::endl;

    chrono.demarrer();
    std::cout << "  Chronomètre démarré..." << std::endl;

    std::cout << "  Résultat attendu : 0 secondes" << std::endl;

    std::cout << "temps (ms) : " << chrono.tempsEcoule_ms() << std::endl;
    std::cout << "temps (s) : " << chrono.tempsEcoule_s() << std::endl;
    std::cout << "temps (m) : " << chrono.tempsEcoule_m() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "  Résultat attendu : 5 secondes" << std::endl;

    std::cout << "temps (ms) : " << chrono.tempsEcoule_ms() << std::endl;
    std::cout << "temps (s) : " << chrono.tempsEcoule_s() << std::endl;
    std::cout << "temps (m) : " << chrono.tempsEcoule_m() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(50));
    std::cout << "  Résultat attendu : 55 secondes" << std::endl;

    std::cout << "temps (ms) : " << chrono.tempsEcoule_ms() << std::endl;
    std::cout << "temps (s) : " << chrono.tempsEcoule_s() << std::endl;
    std::cout << "temps (m) : " << chrono.tempsEcoule_m() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "  Résultat attendu : 1 minute" << std::endl;

    std::cout << "temps (ms) : " << chrono.tempsEcoule_ms() << std::endl;
    std::cout << "temps (s) : " << chrono.tempsEcoule_s() << std::endl;
    std::cout << "temps (m) : " << chrono.tempsEcoule_m() << std::endl;

    std::cout << "  Est-ce que 55 secondes on été atteintes ? :" << chrono.tempsAtteint_ms(55000) << std::endl;
    std::cout << "  Est-ce que 65 secondes on été atteintes ? :" << chrono.tempsAtteint_ms(65000) << std::endl;
}

void Tests::tests_fenetrejeu()
{
    FenetreJeu partie("Ciniseb");

    /*int c_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE];
    int nb_p_variables = 0;
    int nb_mj_variables = 0;

    partie.chargerGabaritCarte(c_gabarit, &nb_p_variables, &nb_mj_variables);

    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            if (c_gabarit[r][c] >= 0)
            {
                std::cout << " ";
            }
            std::cout << c_gabarit[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << nb_p_variables << std::endl;
    std::cout << nb_mj_variables << std::endl;*/

    Niveau niveau;

    for (int i = 0 ; i < 6 ; i++)
    {
        niveau.niveauSuivant();
        partie.setNiveau(niveau);
        std::cout << niveau.getNumero() << std::endl;
        partie.genererCarte();
        partie.affichage_DEBUG(std::cout);
        std::cout << std::endl << std::endl;
    }
}


void assignerTableau(int t[3][3])
{
    t[0][0] = 6;
    t[0][1] = 6;
    t[0][2] = 6;
    t[1][0] = 6;
    t[1][1] = 6;
    t[1][2] = 6;
    t[2][0] = 6;
    t[2][1] = 6;
    t[2][2] = 6;
}
void Tests::tests_autre()
{
    int tab[3][3];
    assignerTableau(tab);

    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}