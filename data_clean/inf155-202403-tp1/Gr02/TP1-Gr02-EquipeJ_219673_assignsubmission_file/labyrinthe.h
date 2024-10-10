 

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

 
#define TAILLE_MAX_GRILLE 100  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"


 
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) ;

 


void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],     
                                                                             
                                          int hauteur_grille,
                                          int largeur_grille,
                                          int pos_ligne,
                                          int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,
                                          int deplacements[][2]) ;

int lab_choisir_deplacement(int deplacements_possible[][2], int nb_deplacement_possible) ;  
                                                                         

int lab_est_cases_adjacentes(int case1[2], int case2[2]) ;               
                                                                         



int lab_est_une_sortie(int position[2],                                   
                       int grille[][TAILLE_MAX_GRILLE],
                       int largeur_grille,
                       int hauteur_grille);


int lab_resoudre_profondeur(                                         
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);




#endif