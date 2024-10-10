/*
 * Fichier: labyrinthe_io.h
 * Descriptions: Fichier header de labyrinthe_io.c permettant de déclarer les prototypes des fonctions
 */
#ifndef TP_LABYRINTHE_AAMIRVERSHA_LABYRINTHE_IO_H
#define TP_LABYRINTHE_AAMIRVERSHA_LABYRINTHE_IO_H

#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX_GRILLE 100


int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille);
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);
void lab_calculer_deplacements_possibles(
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

int lab_est_cases_adjacentes(int case1[2],
                             int case2[2]);

int lab_est_une_sortie(int position[2],
                       int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille,
                       int largeur_grille);


#endif //TP_LABYRINTHE_AAMIRVERSHA_LABYRINTHE_IO_H
