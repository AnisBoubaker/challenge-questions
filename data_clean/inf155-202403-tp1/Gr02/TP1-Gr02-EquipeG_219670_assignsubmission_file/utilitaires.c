 

 
#include "utilitaires.h"

 
int nb_aleatoire(int min,int max)
{
    return min + (int)(rand()/(RAND_MAX+0.001)*(max-min+1));
}

void demande_pour_continuer(void)
{
    system("pause");
    system ("cls");
}

