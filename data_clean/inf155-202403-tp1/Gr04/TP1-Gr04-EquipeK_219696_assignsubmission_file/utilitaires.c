 

#include "labyrinthe.h"


 

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

 

void pas_a_pas(int debug, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    if(debug == 1)
    {
        lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
        system("pause");
        system("cls");
    }
}


 

void vider_pile(int pile[TAILLE_MAX_PILE][2])
{
    int taille = pile[0][1];

    for (int i = 0; i < taille; ++i)
    {
        for(int j = 0; j < 2; j++)
        {
            pile[i][j] = 0;
        }
    }
}

