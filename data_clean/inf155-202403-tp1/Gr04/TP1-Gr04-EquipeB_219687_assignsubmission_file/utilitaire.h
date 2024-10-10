 
 
 

#ifndef FICHIERFOURNIS_UTILITAIRE_H
#define FICHIERFOURNIS_UTILITAIRE_H

#include <time.h>
#include <stdlib.h>
#include "labyrinthe.h"

#define TAILLE_MAX_GRILLE 100

int nb_aleatoire(int min, int max);

void afficher_grille_debug(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,
                           int pile_solution[][2], int debug);



#endif  


