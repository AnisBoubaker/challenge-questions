/*
Module: utilitaires
Description: Contient les fonctions supplémentaires

Auteurs: Mba Nzudie,Aubin Sylva;Kramar,Timothy;Orantes Benitez, Elias et Jeudy,Melody


Date:08 novembre 2023
*/
#include "utilitaires.h"
#include <stdlib.h>

#define RAND_MAX



int nb_aleatoire(int min, int max)
{
    return min + ((int)rand() / (RAND_MAX + 0.001) * (max - min + 1));//(A.Boubaker,communication personnelle,2023)
}
