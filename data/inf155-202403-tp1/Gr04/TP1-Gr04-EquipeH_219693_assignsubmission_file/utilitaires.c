/*
* Fichier : utilitaires.c
* Auteur : felix
* Date : 2023-10-31
*
* Description : Programme qui ...
*/


#include "utilitaires.h"

int valider_coords_dans_pile(int pile[][2],int taille, int x, int y)
{

    for (int i = 1; i <= taille; ++i)  //On regarde si une coordonee est dans une certaine pile
    {
        if(x == pile[i][0] && y == pile[i][1])
        {
            return 1;
        }

    }
    return 0;
}

int nb_aleatoire(int min, int max)  //Fonction pour genérer un nombre aléatoires
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}