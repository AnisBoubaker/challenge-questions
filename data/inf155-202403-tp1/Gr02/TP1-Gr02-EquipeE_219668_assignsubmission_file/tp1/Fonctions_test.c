/*
Titre: Fonctions_test
Description: Implementation des fonctions du module Fonctions_test

Auteur: Equipe E
Date: 2023-11-12
*/

/***********COMMANDES PR�PROCESSEUR*************/
#include "Fonctions_test.h"

void test_lab_afficher_grille(void)
{
    int grille1[][TAILLE_MAX_GRILLE] = {{1, 0, 0, 0, 1},
                                        {0, 1, 1, 1, 0},
                                        {0, 1, 1, 0, 0},
                                        {0, 1, 1, 1, 0}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", grille1[i][j]);
        }
    }
}