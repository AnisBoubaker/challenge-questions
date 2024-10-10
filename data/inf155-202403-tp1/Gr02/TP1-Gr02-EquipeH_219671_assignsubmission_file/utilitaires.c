/*
titre: utilitaires.c
Description: implémentation fonction utilitaire.

Auteurs:     - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier


Date: 12 novembre 2023
*/

/***********COMMANDES PREPROCESSEUR*************/

#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"



/*******IMPLEMENTATION DES FONCTIONS***********/

int nb_aleatoire(int min,int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

void laby_expert()
{
    printf("*************************\n"
           "*** LABYRINTHE EXPERT ***\n"
           "*************************\n");
}