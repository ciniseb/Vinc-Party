/*====================================================================================================
Fichier: FenetreJeu.cpp
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
#include "FenetreJeu.h"
#include "Joystick.h"

//Constructeurs & destructeurs
FenetreJeu::FenetreJeu() {}
FenetreJeu::FenetreJeu(std::string nom_joueur, ES *thread) : Fenetre(thread)
{
    niveau.niveauSuivant();

    genererCarte();
    
    //TODO : Charger les mini-jeux.
    mini_jeux[0] = new FenetreJeuPiano(thread);
    //mini_jeux[1] = ...
    //mini_jeux[2] = ...

    joueur = Acteur{nom_joueur, Coordonnee{(LARGEUR_CARTE/2)-1, HAUTEUR_CARTE-1}};

    Coordonnee pos_adversaire{(LARGEUR_CARTE / 2), HAUTEUR_CARTE - 1};//TODO : générer une position aléatoire dans la map pour l'adversaire
    adversaire = Acteur{"BOB", pos_adversaire};
}
FenetreJeu::~FenetreJeu() {}

//Getteurs & setteurs
Niveau FenetreJeu::getNiveau()
{
    return niveau;
}
Tuile FenetreJeu::getTuile(Coordonnee coord)
{
    return carte[coord.Y][coord.X];
}
/*std::vector<Fenetre> FenetreJeu::getMiniJeux()
{
    return mini_jeux;
}*/
Acteur FenetreJeu::getJoueur()
{
    return joueur;
}
Acteur FenetreJeu::getAdversaire()
{
    return adversaire;
}
Chronometre FenetreJeu::getTemps()
{
    return temps;
}

void FenetreJeu::setNiveau(Niveau n)
{
    niveau = n;
}
void FenetreJeu::setTuile(Coordonnee coord, Tuile tuile)
{
    carte[coord.Y][coord.X] = tuile;
}
/*void FenetreJeu::setMiniJeux(std::vector<Fenetre> mjx)
{
    mini_jeux = mjx;
}*/
void FenetreJeu::setJoueur(Acteur j)
{
    joueur = j;
}
void FenetreJeu::setAdversaire(Acteur a)
{
    adversaire = a;
}
void FenetreJeu::setTemps(Chronometre t)
{
    temps = t;
}

//Méthodes
bool FenetreJeu::chargerGabaritCarte(int c_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE], int *nb_p_variables, int *nb_mj_variables)
{
    std::ifstream fichier;

    fichier.open("c_gabarit_" + std::to_string(HAUTEUR_CARTE) + "_" + std::to_string(LARGEUR_CARTE) + ".csv");

    if(fichier.is_open())
    {
        std::string ligne;

        for (int r = 0; getline(fichier, ligne) && r < HAUTEUR_CARTE; r++)
        {
            std::istringstream flux(ligne);
            std::string nombre;

            for (int c = 0; getline(flux, nombre, ';') && c < LARGEUR_CARTE; c++)
            {
                if (stoi(nombre) >= -2 && stoi(nombre) <= 2)
                {
                    c_gabarit[r][c] = stoi(nombre);
                    if(c_gabarit[r][c] == -2)
                    {
                        (*nb_p_variables)++;
                    }
                    else if (c_gabarit[r][c] == 2)
                    {
                        (*nb_mj_variables)++;
                    }
                }
                else
                {
                    fichier.close();
                    std::cout << "Mauvais fichier..." << std::endl;
                    return false;
                }
            }
        }

        fichier.close();
        return true;
    }
    std::cout << "Fichier introuvable..." << std::endl;
    return false;
}

std::vector<bool> variablesAleatoires(int nb_total, int nb_variables)
{
    std::vector<bool> variables;
    variables.reserve(nb_total);

    for (int i = 0; i < nb_variables; i++)
    {
        variables.push_back(true);
    }
    for (int i = 0; i < (nb_total - nb_variables); i++)
    {
        variables.push_back(false);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(variables.begin(), variables.end(), g);

    return variables;
}
bool FenetreJeu::genererCarte()
{
    int c_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE];
    int nb_p_variables = 0;
    int nb_mj_variables = 0;
    chargerGabaritCarte(c_gabarit, &nb_p_variables, &nb_mj_variables);

    std::vector<bool> p_variables = variablesAleatoires(nb_p_variables, niveau.getNb_PleinsVariables());
    std::vector<bool> mj_variables = variablesAleatoires(nb_mj_variables, niveau.getNb_Mj_Dispo());

    int t_tuile;
    bool resultat;
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            switch (t_tuile = c_gabarit[r][c])
            {
            case -1:
                carte[r][c] = Tuile(PLEIN, "");//TODO chemin image
                break;
            case 0:
                carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                break;
            case -2:
                resultat = p_variables.back();
                if (resultat == true)
                {
                    carte[r][c] = Tuile(PLEIN, "");//TODO chemin image
                }
                else
                {
                    carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                }
                p_variables.pop_back();
                break;
            case 2:
                resultat = mj_variables.back();
                if (resultat == true)
                {
                    carte[r][c] = Tuile(MINI_JEU, "");//TODO chemin image
                }
                else
                {
                    carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                }
                mj_variables.pop_back();
                break;
            default:
                return false;
                break;
            }
        }
    }

    return true;
}

bool FenetreJeu::deplacementAdversaire()
{
    if (true/*distanceJoueurAdversaire > rayon de vibration*/)
    {
        //ANTOINE 2/3 et ENES 1/3
    }
    else
    {
        //ENES
    }
    
    double t_ecoule = temps.tempsEcoule_ms();
    if ((adversaire.t_dernier_deplacement + DT_DEPLACEMENT_JOUEUR)/niveau.getV_Adversaire() <= t_ecoule)
    {
        //adversaire.position.X = NouveauX; TODO nouveauY
        //adversaire.position.Y = NouveauY; TODO nouveauY
        adversaire.t_dernier_deplacement = t_ecoule;
        return true;
    }
    return false;
}
bool FenetreJeu::deplacementJoueur(Direction reponse)
{
    int NouveauX = joueur.position.X;
    int NouveauY = joueur.position.Y;

    switch (reponse)
    {
    case HAUT:
        NouveauY--;
        break;
    case BAS:
        NouveauY++;
        break;
    case DROITE:
        NouveauX++;
        break;
    case GAUCHE:
        NouveauX--;
        break;
    default:
        break;
    }
    double t_ecoule = temps.tempsEcoule_ms();
    if (((joueur.t_dernier_deplacement + DT_DEPLACEMENT_JOUEUR) <= t_ecoule) && carte[NouveauY][NouveauX].getRemplissage() != PLEIN && NouveauX < LARGEUR_CARTE && NouveauY < HAUTEUR_CARTE && NouveauX>0 && NouveauY>0)
    {
        joueur.position.X = NouveauX;
        joueur.position.Y = NouveauY;
        joueur.t_dernier_deplacement = t_ecoule;
        return true;
    }
    return false;
}

float FenetreJeu::distanceJoueur(Coordonnee coord)
{
    double a = abs(coord.X - joueur.position.X);
    double b = abs(coord.Y - joueur.position.Y);
    return sqrt((a*a) + (b*b));
}

void FenetreJeu::ouvrir()
{
    jouer();
}
void FenetreJeu::jouer()
{
    double dernier_t = 0;
    joueur.t_dernier_deplacement = temps.tempsEcoule_ms();
    adversaire.t_dernier_deplacement = temps.tempsEcoule_ms();
    std::unique_ptr<Evenement> evenement;
    int mj_actif = 0; //TODO : selection mini-jeu actif random sur nb mini jeux
    Direction directionActuelle = AUCUNE;

    genererCarte();
    temps.demarrer();

    system("cls");
    affichage_DEBUG(std::cout);
    while (true)
    {
        //Mise à jour du temps de jeu à l'écran
        if (temps.tempsAtteint_ms(dernier_t+1000))
        {
            affichage_DEBUG(std::cout);
            dernier_t += 1000;
        }

        //Tague du joueur par l'adversaire = fin de jeu
        if (adversaire.position.X == joueur.position.X && adversaire.position.Y == joueur.position.Y)
        {
            Pointage(joueur.nom, niveau.getNumero(), temps.tempsEcoule_m(), joueur.nb_tuiles_parcourues).enregistrerPointage();
            return;
        }

        //Déplacement de l'adversaire
        if (deplacementAdversaire())
        {
            affichage_DEBUG(std::cout);
        }

        //Mise à jour du déplacement du joueur
        if (directionActuelle != AUCUNE && deplacementJoueur(directionActuelle))
        {
            joueur.nb_tuiles_parcourues++;
            affichage_DEBUG(std::cout);
        }

        //Lecture des entrées
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == JOYSTICK)
            {
                Joystick *eJoystick = static_cast<Joystick*>(evenement.get());
                directionActuelle = eJoystick->getDirection();
            }
        }

        //Joueur sur une tuile de MINI_JEU
        if (carte[joueur.position.Y][joueur.position.X].getRemplissage() == MINI_JEU)
        {
            //mini_jeux[mj_actif]->ouvrir();
            if (mini_jeux[mj_actif]->reussi())
            {
                mj_actif = 0; //TODO
                niveau.miniJeuReussi(mj_actif); //TODO
                carte[joueur.position.Y][joueur.position.X].setRemplissage(VIDE);
                if (niveau.niveauFinit())
                {
                    if (niveau.niveauSuivant())
                    {
                        genererCarte();
                        joueur.position = Coordonnee{ (LARGEUR_CARTE / 2) - 1, HAUTEUR_CARTE - 1 };
                        adversaire.position = Coordonnee{ (LARGEUR_CARTE / 2), HAUTEUR_CARTE - 1 };//TODO : générer une position aléatoire dans la map pour l'adversaire
                    }
                    else
                    {
                        Pointage(joueur.nom, niveau.getNumero(), temps.tempsEcoule_m(), joueur.nb_tuiles_parcourues).enregistrerPointage();
                        return;
                    }
                }
                else
                {
                    //TODO : retirer mini jeu
                    affichage_DEBUG(std::cout);
                }
            }
            else
            {
                //TODO : bouger le mini jeu
                affichage_DEBUG(std::cout);
            }
        }
    }
}

void FenetreJeu::affichage_DEBUG(std::ostream &flux)
{
    int c_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE];
    int nb_p_variables = 0;
    int nb_mj_variables = 0;
    chargerGabaritCarte(c_gabarit, &nb_p_variables, &nb_mj_variables);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "  Joueur : " << joueur.nom << "  |  " << "Dsitance parcourue : " << joueur.nb_tuiles_parcourues << "  |  temps de jeu : " << temps << "  |  Niveau : " << niveau.getNumero() << "  |  " << niveau.getNB_Mj_Restants() << " (!!)" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
           // if (distanceJoueur({c, r}) > RAYON_VISION)
           // {
            //    flux << "  ";
           // }
            if (joueur.position.X == c && joueur.position.Y == r)
            {
                flux << "**";
            }
            else if (adversaire.position.X == c && adversaire.position.Y == r)
            {
                flux << "XX";
            }
            /*else if (carte[r][c].getRemplissage() == PLEIN && c_gabarit[r][c] == PLEIN_VARIABLE)
            {
                flux << "HH";
            }*/
            else if (carte[r][c].getRemplissage() == PLEIN)
            {
                flux << "##";
            }
            else if (carte[r][c].getRemplissage() == VIDE)
            {
                flux << "  ";
            }
            else if (carte[r][c].getRemplissage() == MINI_JEU)
            {
                flux << "!!";
            }
        }
        flux << std::endl;
    }
    flux << ++nb_affichages << std::endl;
}

bool FenetreJeu::Validation(bool Visite[HAUTEUR_CARTE][LARGEUR_CARTE], int AXE_x, int AXE_y)
{
    if (AXE_x < 0 || AXE_y < 0 || AXE_x >= HAUTEUR_CARTE || AXE_y >= LARGEUR_CARTE || carte[AXE_x][AXE_y].getRemplissage()!=PLEIN)
    {
        return false; 
    }
    if (Visite[AXE_x][AXE_y])
    {
        return false;
    }
    else
    return true;
}


bool FenetreJeu::AIMBOT_PART1()
{
    std::queue<int> Xq;
    std::queue<int> Yq;
    int ADJx, ADJy, x, y;
    int Longueur = 5;
    int PossibiliteRestant = 1;
    int ProchainePossibilite = 0;
    int NS[] = { -1, 1, 0, 0 };
    int EO[] = { 0, 0, 1, -1 };
    int fin = false;
    bool Visite[HAUTEUR_CARTE][LARGEUR_CARTE];

    Xq.push(joueur.position.X);
    Yq.push(joueur.position.Y);
    Visite[joueur.position.X][joueur.position.Y] = true;
    std::cout << Xq.size() << std::endl;
    while (!fin)
    {
       // std::cout << Xq.size() << std::endl;

        x = Xq.front();
        y = Yq.front();
        Xq.pop();
        Yq.pop();
        if (x == adversaire.position.X && y == adversaire.position.Y)
        {
            fin = true;
            std::cout << "CEST SUPPOSER DETRE FINIS" <<std::endl <<std::endl;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int ADJx = x + NS[i];
            int ADJy = y + EO[i];
           // std::cout << ADJx << std::endl;
           // std::cout << ADJy << std::endl;


            if ( (ADJx>=0 || ADJy >= 0) && (ADJx <HAUTEUR_CARTE || ADJy < LARGEUR_CARTE) && (carte[ADJx][ADJy].getRemplissage() == VIDE) && (Visite[ADJx][ADJy] != true))
            {      
               // std::cout << " ADJx " << ADJx << std::endl;

                COPIE_DE_CARTE[ADJx][ADJy] = Longueur;
                Xq.push(ADJx);
                Yq.push(ADJy);
                Visite[ADJx][ADJy] = true;
                ProchainePossibilite++;

                for (int r = 0; r < HAUTEUR_CARTE; r++)
                {
                    for (int c = 0; c < LARGEUR_CARTE; c++)
                    {
                        std::cout << COPIE_DE_CARTE[r][c] <<" ";
                    }
                std::cout << std::endl;
                }
            }
        }
        std::cout << Xq.size() << std::endl;

        PossibiliteRestant--;
        if (PossibiliteRestant == 0)
        {
            PossibiliteRestant = ProchainePossibilite;
            ProchainePossibilite = 0; 
            Longueur++;
        }
    }    
 
}

void FenetreJeu::AIMBOT_PART2()
{
    int NS[] = { -1, 1, 0, 0 };
    int EO[] = { 0, 0, 1, -1 };
    int x = adversaire.position.X;
    int y = adversaire.position.Y;
    int Nx, Ny;
    int LowValue = 9999999;
    
    
    for (int i = 0; i < 4; i++)
    {
        Nx = x + NS[i];
        if (LowValue > COPIE_DE_CARTE[Nx][y] && (COPIE_DE_CARTE[Nx][y] != 0) && (carte[Nx][y].getRemplissage() != PLEIN))
        {
            LowValue = COPIE_DE_CARTE[Nx][y];
        }
        Ny = y + EO[i];
        if (LowValue > COPIE_DE_CARTE[x][Ny] && (COPIE_DE_CARTE[x][Ny] != 0) && (carte[Nx][y].getRemplissage() != PLEIN))
        {
            LowValue = COPIE_DE_CARTE[x][Ny];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        Nx = x + NS[i];
        if (LowValue == COPIE_DE_CARTE[Nx][y])
        {
            adversaire.position.X = Nx;
            adversaire.position.Y = y;
        }
        Ny = y + EO[i];
        if (LowValue == COPIE_DE_CARTE[x][Ny]) {
            adversaire.position.X = x;
            adversaire.position.Y = Ny;
        }
    }
}

void FenetreJeu::RESETVERIFICATION(bool Visite[HAUTEUR_CARTE][LARGEUR_CARTE])
{
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            Visite[r][c] = false;
        }
    }
}

void FenetreJeu::DeplacementAdversaire()
{
    int distance_entre_adv_jou = sqrt(((adversaire.position.X - joueur.position.X) ^ 2) + ((adversaire.position.Y - joueur.position.Y) ^ 2));
    AIMBOT_PART1();
}