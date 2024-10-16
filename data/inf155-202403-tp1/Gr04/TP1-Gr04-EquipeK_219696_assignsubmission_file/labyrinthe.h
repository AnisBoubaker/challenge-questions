/*
Module: labyrinthe

Description: Fournit l'ensemble de fonction permettant de r�soudre un labyrinthe

Auteur: Samy Mekkati, Daniel Atik, Jad Bizri


Date: 2023-11-12
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include "pile.h"
#include "utilitaires.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#define TAILLE_MAX_PILE 1000 //Taille maximale en ligne de la pile



void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);


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


int lab_est_une_sortie(
        const int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);


int lab_est_cases_adjacentes(int case1[2],
                             int case2[2]);


int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);



#endif