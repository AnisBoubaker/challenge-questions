/*
titre: utilitaires.c
Description: Implémentation des fonctions du module utilitaires.h
Auteurs:
Tommy Parent,
Maude Gallant-Mercier,
Camille Landry,
Saguira Neysa Charles
Date: 2023-11-07
*/

/***********COMMANDES PREPROCESSEUR*************/
#include "utilitaires.h"

/*******IMPLEMENTATION DES FONCTIONS***********/
int nb_aleatoire(int min,int max)
{
    return min + (int)(rand()/(RAND_MAX+0.001)*(max-min+1));
}

void demande_pour_continuer(void)
{
    system("pause");
    system ("cls");
}

