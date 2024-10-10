/*
Module: utilitaires
Description: Module des fonctions utilitaires en lien avec le programme du labyrinthe

Auteurs: Paul Ayoub, Mohammad Hamadé, David Mushimiyimana et Vincenzo Jean Vincent Pirot

Date: 16 octobre 2023
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include "utilitaires.h"


/*******IMPLEMENTATION DES FONCTIONS***********/
int nb_aleatoire(int min, int max)
{
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}