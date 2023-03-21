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

//Constructeurs & destructeurs
MoteurJeu::MoteurJeu() {}
MoteurJeu::MoteurJeu(std::string nom_joueur, ES* threadArduino, ThreadMoteur* threadMoteur) : Moteur(threadArduino, threadMoteur)
{
    joueur.nom = nom_joueur;
    initialiser();
}
MoteurJeu::~MoteurJeu()
{
    for (int i = 0 ; i < NB_MINI_JEUX ; i++)
    {
        delete mini_jeux[i];
    }
}

//Getteurs & setteurs
Niveau MoteurJeu::getNiveau()
{
    return niveau;
}
Tuile MoteurJeu::getTuile(Coordonnee coord)
{
    return carte[coord.Y][coord.X];
}
Acteur MoteurJeu::getJoueur()
{
    return joueur;
}
Acteur MoteurJeu::getAdversaire()
{
    return adversaire;
}
Chronometre MoteurJeu::getTemps()
{
    return temps;
}

void MoteurJeu::setNiveau(Niveau n)
{
    niveau = n;
}
void MoteurJeu::setTuile(Coordonnee coord, Tuile tuile)
{
    carte[coord.Y][coord.X] = tuile;
}
void MoteurJeu::setJoueur(Acteur j)
{
    joueur = j;
}
void MoteurJeu::setAdversaire(Acteur a)
{
    adversaire = a;
}
void MoteurJeu::setTemps(Chronometre t)
{
    temps = t;
}

//Méthodes
bool MoteurJeu::chargerGabaritCarte(int c_gabarit[HAUTEUR_CARTE][LARGEUR_CARTE], int *nb_p_variables, int *nb_mj_variables)
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
bool MoteurJeu::genererCarte()
{
    std::vector<bool> p_variables = variablesAleatoires(nb_p_variables, niveau.getNb_PleinsVariables());
    std::vector<bool> mj_variables = variablesAleatoires(nb_mj_variables, niveau.getNb_Mj_Dispo());

    int t_tuile;
    bool resultat;
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            switch (t_tuile = carte_gabarit[r][c])
            {
            case -1:
                if (MODE_TERRAIN_VAGUE)
                {
                    carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                }
                else
                {
                    carte[r][c] = Tuile(PLEIN, "");//TODO chemin image
                }
                break;
            case 0:
                carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                break;
            case -2:
                if (MODE_TERRAIN_VAGUE)
                {
                    carte[r][c] = Tuile(VIDE, "");//TODO chemin image
                }
                else
                {
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
                }
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
Coordonnee MoteurJeu::genererPosAdversaire()
{
    int nb_pos_variables = 0;
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            if (carte[r][c].getRemplissage() == VIDE && distance(joueur.position, Coordonnee({ c, r })) > RAYON_VIBRATION && distance(joueur.position, Coordonnee({ c, r })) < HAUTEUR_CARTE && distance(joueur.position, Coordonnee({ c, r })) < LARGEUR_CARTE)
            {
                nb_pos_variables++;
            }
        }
    }

    std::vector<bool> pos_variables = variablesAleatoires(nb_pos_variables, 1);

    bool resultat;
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            if (carte[r][c].getRemplissage() == VIDE && distance(joueur.position, Coordonnee({ c, r })) > RAYON_VIBRATION && distance(joueur.position, Coordonnee({ c, r })) < HAUTEUR_CARTE && distance(joueur.position, Coordonnee({ c, r })) < LARGEUR_CARTE)
            {
                resultat = pos_variables.back();
                if (resultat == true)
                {
                    return Coordonnee({ c, r });
                }
                pos_variables.pop_back();
            }
        }
    }

    return Coordonnee();
}

void MoteurJeu::deplacementMiniJeu()
{
    std::vector<bool> mj_variables = variablesAleatoires(nb_mj_variables - niveau.getNB_Mj_Restants() + 1, 1);

    bool resultat;
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            if (carte_gabarit[r][c] == 2 && carte[r][c].getRemplissage() == VIDE)
            {
                resultat = mj_variables.back();
                if (resultat == true)
                {
                    carte[r][c] = Tuile(MINI_JEU, "");//TODO chemin image
                    return;
                }
                mj_variables.pop_back();
            }
        }
    }
}

bool MoteurJeu::verificationVide(Coordonnee coord)
{
    if (carte[coord.Y][coord.X].getRemplissage() != PLEIN && coord.X < LARGEUR_CARTE && coord.Y < HAUTEUR_CARTE && coord.X > 0 && coord.Y > 0)
        return true;
    else
        return false;
}

bool MoteurJeu::verificationCoord(Coordonnee actuelle, Coordonnee ancienne)
{
    int Xactuelle = actuelle.X;
    int Yactuelle = actuelle.Y;
    int Xancienne = ancienne.X;
    int Yancienne = ancienne.Y;

    if (Xactuelle == Xancienne && Yactuelle == Yancienne)
        return true;
    else
        return false;
}

void MoteurJeu::deplacementAdversaireRandom()
{
    Coordonnee haut = { adversaire.position.X, adversaire.position.Y + 1 };
    Coordonnee droite = { adversaire.position.X + 1, adversaire.position.Y };
    Coordonnee bas = { adversaire.position.X, adversaire.position.Y - 1 };
    Coordonnee gauche = { adversaire.position.X - 1, adversaire.position.Y };
    Coordonnee anciennecoord = { adversaire.ancienneposition.X, adversaire.ancienneposition.Y };
    int nb_choix = 0;

    std::vector<Coordonnee> coords_possibles;

    if (verificationVide(haut) && !verificationCoord(haut, anciennecoord))
    {
        coords_possibles.push_back(haut);
        nb_choix++;
    }

    if (verificationVide(droite) && !verificationCoord(droite, anciennecoord))
    {
        coords_possibles.push_back(droite);
        nb_choix++;
    }

    if (verificationVide(bas) && !verificationCoord(bas, anciennecoord))
    {
        coords_possibles.push_back(bas);
        nb_choix++;
    }

    if (verificationVide(gauche) && !verificationCoord(gauche, anciennecoord))
    {
        coords_possibles.push_back(gauche);
        nb_choix++;
    }

    if (nb_choix == 0)
    {
        adversaire.position.X = adversaire.ancienneposition.X;
        adversaire.position.Y = adversaire.ancienneposition.Y;
    }
    else if (nb_choix == 1 || rand() % 4 + 1 <= 3)
    {
        Coordonnee NouvelleCoord = coords_possibles[rand() % nb_choix];

        adversaire.ancienneposition.X = adversaire.position.X;
        adversaire.ancienneposition.Y = adversaire.position.Y;

        adversaire.position.X = NouvelleCoord.X;
        adversaire.position.Y = NouvelleCoord.Y;
    }
    else
    {
        modeChasse();
    }
}

bool MoteurJeu::deplacementAdversaire()
{
    double t_ecoule = temps.tempsEcoule_ms();
    if ((adversaire.t_dernier_deplacement + DT_DEPLACEMENT_ADVERSAIRE)/niveau.getV_Adversaire() <= t_ecoule)
    {
        if (distance(adversaire.position, joueur.position) > RAYON_VIBRATION)
        {
            deplacementAdversaireRandom();
        }
        else
        {
            modeChasse();
        }

        adversaire.t_dernier_deplacement = t_ecoule;
        return true;
    }
    return false;
}

bool MoteurJeu::deplacementJoueur(Direction reponse)
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

float MoteurJeu::distance(Coordonnee c1, Coordonnee c2)
{
    double a = abs(c2.X - c1.X);
    double b = abs(c2.Y - c1.Y);
    return sqrt((a*a) + (b*b));
}

void MoteurJeu::initialiser()
{
    nb_p_variables = 0;
    nb_mj_variables = 0;

    niveau = Niveau();
    niveau.niveauSuivant();

    chargerGabaritCarte(carte_gabarit, &nb_p_variables, &nb_mj_variables);
    genererCarte();

    //TODO : Charger les mini-jeux.
    mini_jeux[0] = new MoteurJeuPiano(threadArduino);
    mini_jeux[1] = new MoteurJeuPiano(threadArduino);
    mini_jeux[2] = new MoteurJeuPiano(threadArduino);
    mini_jeux[3] = new MoteurJeuPiano(threadArduino);
    //mini_jeux[1] = ...
    //mini_jeux[2] = ...

    joueur = Acteur{ joueur.nom, Coordonnee{(LARGEUR_CARTE / 2) - 1, HAUTEUR_CARTE - 1} };

    //Coordonnee pos_adversaire{ 32, 8 };//TODO : générer une position aléatoire dans la map pour l'adversaire
    adversaire = Acteur{ "BOB", genererPosAdversaire()};
}

void MoteurJeu::demarrer()
{
    temps.demarrer();
    affichage(AFFICHAGE_COMPLET);

    int mj_actif = niveau.choixMiniJeu();
    double dernier_t = 0;
    joueur.t_dernier_deplacement = temps.tempsEcoule_ms();
    adversaire.t_dernier_deplacement = temps.tempsEcoule_ms();

    std::unique_ptr<Evenement> evenement;
    Direction directionActuelle = AUCUNE;
    PointCardinal pointCardinalAncien = OFF;
    PointCardinal pointCardinalActuel = OFF;
    double tempsDerniereVibration = 0;

    while (true)
    {
        //Mise à jour du temps de jeu à l'écran
        if (temps.tempsAtteint_ms(dernier_t + 1000))
        {
            affichage(AFFICHAGE_TEMPS);
            dernier_t += 1000;
        }

        //Tague du joueur par l'adversaire = fin de jeu
        if (adversaire.position.X == joueur.position.X && adversaire.position.Y == joueur.position.Y && !ENNEMI_INNOFFENSIF)
        {
            Pointage(joueur.nom, niveau.getNumero(), temps.tempsEcoule_m(), joueur.nb_tuiles_parcourues).enregistrerPointage();
            return;
        }

        //Déplacement de l'adversaire
        if (deplacementAdversaire())
        {
            affichage(AFFICHAGE_ADVERSAIRE);
        }

        //Mise à jour du déplacement du joueur
        if (directionActuelle != AUCUNE && deplacementJoueur(directionActuelle))
        {
            joueur.nb_tuiles_parcourues++;
            affichage(AFFICHAGE_JOUEUR);

            //Determiner direction boussole;
            pointCardinalActuel = directionMiniJeuPlusProche(niveau.getNB_Mj_Restants());
            if (pointCardinalActuel != pointCardinalAncien)
            {
                threadArduino->envoyerEvenement(std::make_unique<Boussole>(pointCardinalActuel));
            }
            pointCardinalAncien = pointCardinalActuel;
        }

        //Lecture des entrées
        if (threadArduino->evenementDisponible())
        {
            evenement = threadArduino->prochainEvenement();

            if (evenement->getCode() == JOYSTICK)
            {
                Joystick* eJoystick = static_cast<Joystick*>(evenement.get());
                directionActuelle = eJoystick->getDirection();
            }
        }

        //Vibration
        if (temps.tempsAtteint_ms(tempsDerniereVibration + 2000) && distanceEntreTuiles(joueur.position.X, joueur.position.Y, adversaire.position.X, adversaire.position.Y) <= RAYON_VIBRATION)
        {
            tempsDerniereVibration = temps.tempsEcoule_ms();
            threadArduino->envoyerEvenement(std::make_unique<Vibration>());
        }

        //Joueur sur une tuile de MINI_JEU
        if (carte[joueur.position.Y][joueur.position.X].getRemplissage() == MINI_JEU)
        {
            threadArduino->envoyerEvenement(std::make_unique<Boussole>(OFF));
            pointCardinalAncien = OFF;
            directionActuelle = AUCUNE;

            if (!MODE_CONSOLE)
            {
                emit threadMoteur->changementWidgetActif(mj_actif + 3);
            }

            if (MODE_CONSOLE)
            {
                system("cls");
            }

            mini_jeux[mj_actif]->demarrer();

            if (mini_jeux[mj_actif]->reussi())
            {
                niveau.miniJeuReussi(mj_actif);
                if (niveau.niveauFinit())
                {
                    if (niveau.niveauSuivant())
                    {
                        genererCarte();
                        joueur.position = Coordonnee{ (LARGEUR_CARTE / 2) - 1, HAUTEUR_CARTE - 1 };
                        adversaire.position = genererPosAdversaire();
                    }
                    else
                    {
                        Pointage(joueur.nom, niveau.getNumero(), temps.tempsEcoule_m(), joueur.nb_tuiles_parcourues).enregistrerPointage();

                        if (!MODE_CONSOLE)
                        {
                            emit threadMoteur->changementWidgetActif(0);
                        }

                        return;
                    }
                }
            }
            else
            {
                deplacementMiniJeu();
            }

            mini_jeux[mj_actif]->initialiser();
            mj_actif = niveau.choixMiniJeu();
            carte[joueur.position.Y][joueur.position.X].setRemplissage(VIDE);

            if (MODE_CONSOLE)
            {
                system("cls");
            }

            affichage(AFFICHAGE_COMPLET);
        }
    }
}

void MoteurJeu::affichage(int selection)
{
    if (MODE_CONSOLE)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "  Joueur : " << joueur.nom << "  |  " << "Distance parcourue : " << joueur.nb_tuiles_parcourues << "  |  temps de jeu : " << temps << "  |  Niveau : " << niveau.getNumero() << "  |  " << niveau.getNB_Mj_Restants() << " (!!)" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (int r = 0; r < HAUTEUR_CARTE; r++)
        {
            for (int c = 0; c < LARGEUR_CARTE; c++)
            {
                if (distance(joueur.position, { c, r }) > RAYON_VISION && !VISION_NOCTURNE)
                {
                    std::cout << "  ";
                }
                else if (joueur.position.X == c && joueur.position.Y == r)
                {
                    std::cout << "**";
                }
                else if (adversaire.position.X == c && adversaire.position.Y == r)
                {
                    std::cout << "XX";
                }
                /*else if (carte[r][c].getRemplissage() == PLEIN && c_gabarit[r][c] == PLEIN_VARIABLE)
                {
                    std::cout << "HH";
                }*/
                else if (carte[r][c].getRemplissage() == PLEIN)
                {
                    std::cout << char(219) << char(219);

                }
                else if (carte[r][c].getRemplissage() == VIDE)
                {
                    std::cout << "  ";
                }
                else if (carte[r][c].getRemplissage() == MINI_JEU)
                {
                    std::cout << "!!";
                }
            }
            std::cout << std::endl;
        }
        std::cout << ++nb_affichages << std::endl;
        std::cout << adversaire.position.Y << ", " << adversaire.position.X;
    }
    else if(selection == AFFICHAGE_COMPLET)
    {
        int i_carte[HAUTEUR_CARTE][LARGEUR_CARTE];

        for (int r = 0; r < HAUTEUR_CARTE; r++)
        {
            for (int c = 0; c < LARGEUR_CARTE; c++)
            {
                if (distance(joueur.position, { c, r }) > RAYON_VISION && !VISION_NOCTURNE)
                {
                    i_carte[r][c] = VIDE;
                }
                else if (joueur.position.X == c && joueur.position.Y == r)
                {
                    i_carte[r][c] = JOUEUR;
                }
                else if (adversaire.position.X == c && adversaire.position.Y == r)
                {
                    i_carte[r][c] = ADVERSAIRE;
                }
                else if (carte[r][c].getRemplissage() == PLEIN)
                {
                    i_carte[r][c] = PLEIN;

                }
                else if (carte[r][c].getRemplissage() == VIDE)
                {
                    i_carte[r][c] = VIDE;
                }
                else if (carte[r][c].getRemplissage() == MINI_JEU)
                {
                    i_carte[r][c] = MINI_JEU;
                }
            }
            std::cout << std::endl;
        }

        std::stringstream t;
        t << temps;

        emit threadMoteur->jeuMAJ_Complet(joueur.nom,joueur.nb_tuiles_parcourues, t.str(), niveau.getNumero(), niveau.getNB_Mj_Restants(), i_carte);
    }
    else if (selection == AFFICHAGE_TEMPS)
    {
        std::stringstream t;
        t << temps;

        emit threadMoteur->jeuMAJ_Temps(t.str());
    }
    else if (selection == AFFICHAGE_ADVERSAIRE)
    {
        emit threadMoteur->jeuMAJ_Adversaire(adversaire.position);
    }
    else if (selection == AFFICHAGE_JOUEUR)
    {
        emit threadMoteur->jeuMAJ_Joueur(joueur.position, joueur.nb_tuiles_parcourues);
    }
}

bool MoteurJeu::modeChasse()
{
    int COPIE_DE_CARTE[HAUTEUR_CARTE][LARGEUR_CARTE];

    scanBFS(COPIE_DE_CARTE);
    modeSuiveurAdversaire(COPIE_DE_CARTE);
    return true;
}

bool MoteurJeu::scanBFS(int COPIE_DE_CARTE[HAUTEUR_CARTE][LARGEUR_CARTE])
{
    std::queue<int> Xq;
    std::queue<int> Yq;
    int ADJx, ADJy, x, y;
    int Longueur = 5;
    int PossibiliteRestant = 1;
    int ProchainePossibilite = 0;
    int NS[] = { -1, 1, 0, 0 };
    int EO[] = { 0, 0, 1, -1 };
    bool Visite[HAUTEUR_CARTE][LARGEUR_CARTE];
    for (int r = 0; r < HAUTEUR_CARTE; r++)
    {
        for (int c = 0; c < LARGEUR_CARTE; c++)
        {
            COPIE_DE_CARTE[r][c] = 0;
            Visite[r][c] = false;
        }
    }

    Xq.push(joueur.position.X);
    Yq.push(joueur.position.Y);
    Visite[joueur.position.Y][joueur.position.X] = true;
    while (true /* && !Xq.empty() && !Yq.empty()*/)
    {


        //!!!!!!!!!!!!!!!!!!!!!!!!!!
        //AUCUNE IDEE FIX TEMPORAIRE
        if (Xq.size() == 0) {
            return false;
        }

        x = Xq.front();
        y = Yq.front();
        Xq.pop();
        Yq.pop();
        if (x == adversaire.position.X && y == adversaire.position.Y)
        {     
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            ADJy = y + NS[i];
            ADJx = x + EO[i];

            if (ADJy >= 0 && ADJx >= 0 && ADJy < HAUTEUR_CARTE && ADJx < LARGEUR_CARTE && carte[ADJy][ADJx].getRemplissage() != PLEIN && !Visite[ADJy][ADJx])
            {      
                COPIE_DE_CARTE[ADJy][ADJx] = Longueur;
                COPIE_DE_CARTE[joueur.position.Y][joueur.position.X] = 4;
                Xq.push(ADJx);
                Yq.push(ADJy);
                Visite[ADJy][ADJx] = true;

                ProchainePossibilite++;
            }
        }

        PossibiliteRestant--;
        if (PossibiliteRestant == 0)
        {
            PossibiliteRestant = ProchainePossibilite;
            ProchainePossibilite = 0; 
            Longueur++;
        }
    }    
}

void MoteurJeu::modeSuiveurAdversaire(int COPIE_DE_CARTE[HAUTEUR_CARTE][LARGEUR_CARTE])
{
    int NS[] = { -1, 1, 0, 0 };
    int EO[] = { 0, 0, 1, -1 };
    int x = adversaire.position.X;
    int y = adversaire.position.Y;
    int Nx, Ny;
    int LowValue = 9999999;
    
    
    for (int i = 0; i < 4; i++)
    {
        Nx = x + EO[i];
        if (LowValue > COPIE_DE_CARTE[y][Nx] && (COPIE_DE_CARTE[y][Nx] != 0) && (carte[y][Nx].getRemplissage() != PLEIN))
        {
            LowValue = COPIE_DE_CARTE[y][Nx];
        }
        Ny = y + NS[i];
        if (LowValue > COPIE_DE_CARTE[Ny][x] && (COPIE_DE_CARTE[Ny][x] != 0) && (carte[Ny][x].getRemplissage() != PLEIN))
        {
            LowValue = COPIE_DE_CARTE[Ny][x];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        Nx = x + EO[i];
        if (LowValue == COPIE_DE_CARTE[y][Nx])
        {
            adversaire.ancienneposition.X = adversaire.position.X;
            adversaire.ancienneposition.Y = adversaire.position.Y;

            adversaire.position.X = Nx;
            adversaire.position.Y = y;
        }
        Ny = y + NS[i];
        if (LowValue == COPIE_DE_CARTE[Ny][x])
        {
            adversaire.ancienneposition.X = adversaire.position.X;
            adversaire.ancienneposition.Y = adversaire.position.Y;

            adversaire.position.X = x;
            adversaire.position.Y = Ny;
        }
    }
}

double MoteurJeu::distanceEntreTuiles(int x1, int y1, int x2, int y2) {
    return sqrt((float)pow(x1-x2,2) + (float)pow(y1-y2,2));
}

PointCardinal MoteurJeu::directionMiniJeuPlusProche(int nbrJeux) {
    std::vector<Coordonnee> listePositionsJeux;
    float distanceMin = 10000.0;
    int index = 0;
    //Trouver les deux restants
    for (int i = 0; i < HAUTEUR_CARTE; i++)
    {
        for (int j = 0; j < LARGEUR_CARTE; j++)
        {
            if (carte[i][j].getRemplissage() == MINI_JEU) {
                listePositionsJeux.push_back({j,i});
            }
        }
    }

    for (int i = 0; i < nbrJeux; i++)
    {
        double distance = distanceEntreTuiles(joueur.position.X, joueur.position.Y, listePositionsJeux[i].X, listePositionsJeux[i].Y);
        if (distance < distanceMin) {
            distanceMin = distance;
            index = i;
        }
    }

    int distanceX = joueur.position.X - listePositionsJeux[index].X;
    int distanceY = joueur.position.Y - listePositionsJeux[index].Y;

    if (abs(distanceX) > abs(distanceY)) {
        if (distanceX >= 0) {
            return OUEST;
        }
        else {
            return EST;
        }
    }
    else {
        if (distanceY >= 0) {
            return NORD;
        }
        else {
            return SUD;
        }
    }
}