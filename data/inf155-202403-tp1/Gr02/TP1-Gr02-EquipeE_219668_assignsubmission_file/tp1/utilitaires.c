/*
Titre: utilitaires.c
Description: Impl�mentation des fonctions du module utilitaire

Auteur: Equipe #
Date: 2023-11-12
*/

/***********COMMANDES PR�PROCESSEUR*************/
#include <stdlib.h>
#include "utilitaires.h"

/***********CONSTANTES DE COMPILATION*************/


/********* D�FINITION DES FONCTION **************/

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX +0.001)*(max-min +1));
}