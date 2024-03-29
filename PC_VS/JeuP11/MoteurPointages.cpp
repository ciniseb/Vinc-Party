/*====================================================================================================
Fichier: FenetrePointages.cpp
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
#include "MoteurPointages.h"


//Constructeurs & destructeurs
MoteurPointages::MoteurPointages(ES* threadArduino, ThreadMoteur* threadMoteur) : Moteur(threadArduino, threadMoteur) { initialiser(); }
MoteurPointages::~MoteurPointages() {}

//Getteurs & setteurs
std::vector<Pointage> MoteurPointages::getPointages()
{
    return pointages;
}

void MoteurPointages::setPointages(std::vector<Pointage> p)
{
    pointages = p;
}
void MoteurPointages::ajoutPointage(Pointage p)
{
    pointages.push_back(p);
}

//Méthodes
bool MoteurPointages::chargerPointages()
{
    pointages.clear();

    std::ifstream fichier;

    fichier.open("pointages.txt");

    if (fichier.is_open())
    {
        std::string ligne;

        std::string nom_joueur, n_atteint, temps, nb_tuiles_parcourues;

        while (getline(fichier, ligne))
        {
            std::istringstream flux(ligne);

            getline(flux, nom_joueur, ';');
            getline(flux, n_atteint, ';');
            getline(flux, temps, ';');
            getline(flux, nb_tuiles_parcourues);

            pointages.push_back(Pointage(nom_joueur, stoi(n_atteint), stod(temps), stoi(nb_tuiles_parcourues)));
        }

        fichier.close();
        return true;
    }
    std::cout << "Fichier introuvable..." << std::endl;
    return false;
}
bool MoteurPointages::enregistrerPointages()
{
    std::ofstream fichier;

    fichier.open("pointages.txt");

    if (fichier.is_open())
    {
        for (int r = 0; r < pointages.size(); r++)
        {
            fichier << pointages.at(r).getNomJoueur() << ";" << pointages.at(r).getN_Atteint() << ";" << pointages.at(r).getTemps() << ";" << pointages.at(r).getNb_tuiles_parcourues() << std::endl;
        }

        fichier.close();
        return true;
    }
    std::cout << "Fichier introuvable..." << std::endl;
    return false;
}

void MoteurPointages::initialiser()
{
    //TODO

}

void MoteurPointages::demarrer()
{
    const wchar_t* chanson_poi = L"alo.wav";
    bool played = PlaySound(chanson_poi, NULL, SND_ASYNC);

    chargerPointages();
    std::unique_ptr<Evenement> evenement;
    int selection = 0;

    affichage(selection);
    while (true)
    {
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == BOUTON)
            {
                if (!MODE_CONSOLE)
                {
                    Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                    Dieu lettreAppuyee = eBouton->getNom();

                    if (lettreAppuyee == Dieu::D)
                    {
                        if (MODE_CONSOLE)
                        {
                            system("cls");
                        }
                        else
                        {
                            bool played = PlaySound(NULL, NULL, SND_ASYNC);
                            emit threadMoteur->changementWidgetActif(0);
                        }
                        return;
                    }
                    else if (!MODE_CONSOLE && lettreAppuyee == Dieu::JOYSTICK)
                    {
                        emit threadMoteur->Pointage_Select();
                    }
                    else if (!MODE_CONSOLE && lettreAppuyee == Dieu::I)
                    {
                        emit threadMoteur->switchmode();
                    }
                }
                else
                {
                    Bouton* eBouton = static_cast<Bouton*>(evenement.get());
                    Dieu lettreAppuyee = eBouton->getNom();

                    if (lettreAppuyee == Dieu::JOYSTICK)
                    {
                        bool played = PlaySound(NULL, NULL, SND_ASYNC);
                        system("cls");
                    }

                }

            }
            else if(evenement->getCode() == JOYSTICK)
            {
                if (!MODE_CONSOLE)
                {
                    Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                    Direction direction = eJoystick->getDirection();

                    if (direction == Direction::HAUT /* && (selection > 0)*/)
                    {
                        selection--;
                        affichage(selection);
                        emit threadMoteur->Pointages_Up();
                    }
                    else if (direction == Direction::BAS /* && selection < 1*/)
                    {
                        selection++;
                        affichage(selection);
                        emit threadMoteur->Pointages_Down();
                    }
                    else if (direction == Direction::DROITE)
                    {
                        emit threadMoteur->Pointages_Right();
                    }
                    else if (direction == Direction::GAUCHE)
                    {
                        emit threadMoteur->Pointages_Left();
                    }
                }
                else
                {
                    Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                    Direction direction = eJoystick->getDirection();

                    if (direction == Direction::HAUT && (selection > 0))
                    {
                        selection--;
                        affichage(selection);
                    }
                    else if (direction == Direction::BAS  && selection < 1)
                    {
                        selection++;
                        affichage(selection);
                    }
                }

            }
        }
    }
}

bool plusHautNiveau(const Pointage& p1, const Pointage& p2)
{
    return p1.getN_Atteint() > p2.getN_Atteint();
}
bool plusPetitTemps(const Pointage& p1, const Pointage& p2)
{
    if (p1.getN_Atteint() != p2.getN_Atteint())
    {
        return plusHautNiveau(p1, p2);
    }
    else
    {
        return p1.getTemps() < p2.getTemps();
    }
}
bool plusPetiteDistance(const Pointage& p1, const Pointage& p2)
{
    if (p1.getN_Atteint() != p2.getN_Atteint())
    {
        return plusHautNiveau(p1, p2);
    }
    else
    {
        return p1.getNb_tuiles_parcourues() < p2.getNb_tuiles_parcourues();
    }
}
void MoteurPointages::affichage(int selection)
{
    system("cls");
    if (MODE_CONSOLE)
    {
        std::cout << "-------------------------------------------------------------" << std::endl;
        switch (selection)
        {
        case 0:
            std::cout << "  | Pointages : temps total (m)" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Niveau atteint  |  Temps  |  Temps/niveau  |  Nom du joueur" << std::endl;
            break;
        case 1:
            std::cout << "  | Pointages : distance parcourue (tuiles)" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "Niveau atteint  |  Distance  |  Nom du joueur" << std::endl;
            break;
        default:
            break;
        }
        std::cout << "-------------------------------------------------------------" << std::endl;
    }

    std::streamsize precision = std::cout.precision();
    std::vector<Pointage> trie_pointages = pointages;
    switch (selection)
    {


    case 0:
        std::sort(trie_pointages.begin(), trie_pointages.end(), plusPetitTemps);
        for (int index = 0; index < trie_pointages.size(); index++)
        {
            if (MODE_CONSOLE)
            {
                if (index != 0 && trie_pointages.at(index - 1).getN_Atteint() > trie_pointages.at(index).getN_Atteint())
                {
                    std::cout << std::endl;
                }
            }

            if (!Qt)
            {
                for (int index = 0; index < trie_pointages.size(); index++)
                {
                    emit threadMoteur->Pointages_Level(trie_pointages.at(index).getN_Atteint());
                    emit threadMoteur->Pointages_Names(trie_pointages.at(index).getNomJoueur());
                    emit threadMoteur->Pointages_Time(trie_pointages.at(index).getTemps());
                    emit threadMoteur->Pointages_TimePerLev(trie_pointages.at(index).getMoy_t_n());
                    emit threadMoteur->Pointages_Distance(trie_pointages.at(index).getNb_tuiles_parcourues());
                    Qt = true;
                }
            }
            if (MODE_CONSOLE)
            {
                std::cout << trie_pointages.at(index).getN_Atteint();
                std::cout << "  |  ";
                if (trie_pointages.at(index).getTemps() < 10)
                {
                    std::cout << "00";
                }
                else if (trie_pointages.at(index).getTemps() <= 100)
                {
                    std::cout << "0";
                }
                std::cout << trie_pointages.at(index).getTemps();
                std::cout << "  |  ";
                if (trie_pointages.at(index).getMoy_t_n() < 10)
                {
                    std::cout << "0";
                }
                std::cout << std::setprecision(2) << std::fixed << trie_pointages.at(index).getMoy_t_n();
                std::cout << "  |  ";
                std::cout << trie_pointages.at(index).getNomJoueur();
                std::cout << std::setprecision(precision) << std::resetiosflags(std::ios::fixed) << std::endl;
            }
        }
        break;
    case 1:
        if (MODE_CONSOLE)
        {
            std::sort(trie_pointages.begin(), trie_pointages.end(), plusPetiteDistance);
            for (int index = 0; index < trie_pointages.size(); index++)
            {
                if (index != 0 && trie_pointages.at(index - 1).getN_Atteint() > trie_pointages.at(index).getN_Atteint())
                {
                    std::cout << std::endl;
                }

                std::cout << trie_pointages.at(index).getN_Atteint();
                std::cout << "  |  ";
                if (trie_pointages.at(index).getNb_tuiles_parcourues() <= 9)
                {
                    std::cout << "000";
                }
                else if (trie_pointages.at(index).getNb_tuiles_parcourues() <= 99)
                {
                    std::cout << "00";
                }
                else if (trie_pointages.at(index).getNb_tuiles_parcourues() <= 999)
                {
                    std::cout << "0";
                }
                std::cout << trie_pointages.at(index).getNb_tuiles_parcourues();
                std::cout << "  |  ";
                std::cout << trie_pointages.at(index).getNomJoueur() << std::endl;
            }
        }
        break;
    default:
        break;
    }
}
