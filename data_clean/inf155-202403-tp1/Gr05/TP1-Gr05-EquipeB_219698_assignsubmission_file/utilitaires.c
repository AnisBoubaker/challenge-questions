 
 
 
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "utilitaires.h"

 
 
 

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

 
void afficher_pile(int pile[][2])
{
    printf("Coordonnees dans la solution :");

    for(int i=1; i<pile[0][1]; i++) 
    {
        printf("(%i,%i)", pile[i][0], pile[i][1]); 
    }

    printf("\n");

}

 
void systemPause() 
{
    fflush(stdin); 
    printf("Appuyer sur ENTER pour continuer...\n");
    getchar(); 
}