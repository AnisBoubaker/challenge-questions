 


#include "utilitaires.h"

int valider_coords_dans_pile(int pile[][2],int taille, int x, int y)
{

    for (int i = 1; i <= taille; ++i)   
    {
        if(x == pile[i][0] && y == pile[i][1])
        {
            return 1;
        }

    }
    return 0;
}

int nb_aleatoire(int min, int max)   
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}