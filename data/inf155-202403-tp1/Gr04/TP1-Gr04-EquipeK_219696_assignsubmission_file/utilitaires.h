/*
Module: labyrinthe

Description: Fournit l'ensemble de fonction permettant de resoudre certains problemes dans le code

Auteur: Samy Mekkati, Daniel Atik, Jad Bizri

Date: 2023-11-12
*/
#ifndef TP1_1_UTILITAIRES_H
#define TP1_1_UTILITAIRES_H

#include "labyrinthe.h"

#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#define TAILLE_MAX_PILE 1000 //Taille maximale en ligne de la pile

int nb_aleatoire(int min, int max);


void pas_a_pas(int debug, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);

void vider_pile(int pile[TAILLE_MAX_PILE][2]);


#endif //TP1_1_UTILITAIRES_H