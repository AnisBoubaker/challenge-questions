 

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <stdio.h>
#include <stdlib.h>
#include "utilitaire.h"
#include "pile.h"

 
#define TAILLE_MAX_GRILLE 100  
#define TAILLE_MAX_PILE 100



 
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

 
void test_lab_afficher_grille(void);





 
void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);

int test_lab_deplacements_possibles(void);




 
int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles);

 
int test_lab_choisir_deplacement(void);



 
int lab_est_cases_adjacentes(int case1[2], int case2[2]);


 
 
int test_lab_est_cases_adjacentes(void);




 
int lab_est_une_sortie(
        const int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);


int test_lab_est_une_sortie(void);






 

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);





#endif