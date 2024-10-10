 

#include "pile.h"
#include "labyrinthe.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef INF_155_EQUIPED_UTILITAIRES_H
#define INF_155_EQUIPED_UTILITAIRES_H

 

int deplacement_est_possible( int grille[][TAILLE_MAX_GRILLE],
                              int hauteur_grille,
                              int largeur_grille,
                              int pos_ligne,
                              int pos_colonne,
                              int solution_partielle[][2]);


 
void effacer_terminal(void);


 
void afficher_menu(int grille_chargee);

#endif
