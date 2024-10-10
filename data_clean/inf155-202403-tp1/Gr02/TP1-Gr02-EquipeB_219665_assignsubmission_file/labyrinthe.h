 

#ifndef LABYRINTHE_H
#define LABYRINTHE_H
#define TAILLE_MAX_GRILLE 100  
#include "Utilitaires.h"




 
void LAB_AFFICHER_GRILLE(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

 
void LAB_CALCULER_DEPLACEMENTS_POSSIBLES(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);


 
 
int LAB_EST_CASES_ADJACENTES(int case1[2], int case2[2]);





 
int LAB_CHOISIR_DEPLACEMENT(int deplacements_possibles[][2],int *nb_deplacements_possibles);

 
int LAB_EST_UNE_SORTIE(int position[2],int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille);

 
int LAB_RESOUDRE_PROFONDEUR(int grille[][TAILLE_MAX_GRILLE],
                            int hauteur_grille,
                            int largeur_grille,
                            int entree[2],
                            int pile_solution[][2],
                            int debug);


 


#endif