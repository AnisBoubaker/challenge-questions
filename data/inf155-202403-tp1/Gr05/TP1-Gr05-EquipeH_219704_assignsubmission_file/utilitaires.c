/*
Module: labyrinthe_io
Description: Module de fonction d'entr�e/sortie en lien avec le programme du labyrinthe

Auteur: Ken Whittom ,Anthony Carhuallanqui Nerio, Franck Kamwa

Date: 2023-11-12
*/

#include "utilitaires.h"
#include <stdlib.h>




int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}