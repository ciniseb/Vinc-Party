// JeuP11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 * Auteurs: Jean-Samuel Lauzon
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>

/*-------------------------- Librairies externes ----------------------------*/

#include"ES.h"
#include "Tests.h"


/*------------------------------ Constantes ---------------------------------*/








/*------------------------- Prototypes de fonctions -------------------------*/



/*---------------------------- Variables globales ---------------------------*/
//ES es;




/*----------------------------- Fonction "Main" -----------------------------*/
int main() {
    
    
    // Structure de donnees JSON pour envoie et reception
    
    /*while (true) {

    }*/

    //Tests. � commenter au besoin
    Tests tests;
    //tests.tests_chronometre();
    //tests.tests_fenetrejeu();
    //tests.tests_autre();
    tests.tests_FenetreJeuPiano();

    
    return 0;
}



/*---------------------------Definition de fonctions ------------------------*/

