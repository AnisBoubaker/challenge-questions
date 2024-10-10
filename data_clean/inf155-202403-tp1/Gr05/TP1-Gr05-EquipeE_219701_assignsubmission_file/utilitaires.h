 

#ifndef UTILITAIRES_H
#define UTILITAIRES_H
#define TAILLE_MAX_GRILLE 100

#include <stdlib.h>
#include <time.h>


int nb_aleatoire(int min, int max);
void affiche_solution_grille(int grille[][TAILLE_MAX_GRILLE],
                             int hauteur_grille,
                             int largeur_grille,
                             int pile_solution[][2]);
void affiche_solution_grille_pas_a_pas(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);
#endif  
