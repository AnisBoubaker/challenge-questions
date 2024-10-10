 

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

 
#define TAILLE_MAX_GRILLE 100  

 

 
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);
 
int lab_est_cases_adjacentes(
        const int case1[2],
        const int case2[2]);


 
void calcul_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);

 
int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles);

#endif