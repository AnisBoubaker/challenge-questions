//
// Created by Émile Madore on 2023-11-07.
//


#include "utilitaires.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}


void affiche_tab(int tab[][2], int nb_lignes){
    srand((unsigned int)time(NULL));
    rand();
    for (int i=0; i<nb_lignes; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("%i ", tab[i][j]);
        }
        printf("\n");
    }
}
