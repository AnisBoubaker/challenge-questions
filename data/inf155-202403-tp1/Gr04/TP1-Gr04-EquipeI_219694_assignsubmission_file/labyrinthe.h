/*
Module: labyrinthe
Description: Fournit l'ensemble de fonction permettant de résoudre un labyrinthe

Auteur: 


Date: 
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pile.h>
#ifndef LABYRINTHE_H
#define LABYRINTHE_H

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe

/*
 * fonction: LAB_AFFICHER_GRILLE
 * description: Affiche la grille du labyrinthe dans la console. La fonction doit parcourir la grille et afficher
 * des murs où la grille contient un 1, et un espace où il n'y en a pas. Pour afficher un mur, on utilise le caractère
 * ayant un code ASCII 219.
 * Si une solution est fournie (pile_solution != NULL), on doit identifier, sur la grille affichée, toutes les cases
 * faisant partie de la solution (ex. par des X).
 */
void lab_afficher_grille(int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE],int hauteur_grille, int largeur_grille,int pile_solution[][2]);


int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles);
int lab_est_cases_adjacentes(int case1[2], int case2[2]);

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille);




void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);
int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);


#endif