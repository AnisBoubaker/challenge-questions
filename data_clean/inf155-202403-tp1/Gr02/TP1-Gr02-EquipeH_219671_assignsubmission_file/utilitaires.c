 

 

#include <stdio.h>
#include <stdlib.h>
#include "utilitaires.h"



 

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