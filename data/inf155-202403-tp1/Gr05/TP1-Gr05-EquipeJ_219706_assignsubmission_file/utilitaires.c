/*
Module: utilitaires

Description: Implémentation des fonctions du module utilitaires

Auteurs: Jafar Al-Khaiat
         Tayeb Amrouche
         Jose David Molina Penaloza
         William Zamudio-Turcotte

Date: 2023-11-12
*/
#include "utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
 * Partie realisee par JDM. Ici, je vais creer une fonction qui donne des numeros au hazards afin de realiser la fonction choisir_deplacement.
 */

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX +0.001)*(max-min+1));
}