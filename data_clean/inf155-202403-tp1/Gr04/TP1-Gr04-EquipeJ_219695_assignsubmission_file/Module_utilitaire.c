 
 
 

#include "Module_utilitaire.h"


 
int nb_aleatoire(int min, int max)
{
return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}


void affiche_titre(void)
{
    printf("\t*************************\n");
    printf("\t*** LABYRINTHE EXPERT ***\n");
    printf("\t*************************\n");
}
