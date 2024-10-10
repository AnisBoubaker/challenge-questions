 
 
 

#include "utilitaire.h"


 

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand()/(RAND_MAX+0.001)*(max-min+1));
}


void afficher_grille_debug(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,
                           int pile_solution[][2], int debug)
{
     
    if (debug == 1)
    {
         
        for (int i = 0; i < (hauteur_grille+1); i++)
            for (int k = 0; k < largeur_grille; k++)
                printf("\b");

         
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
}