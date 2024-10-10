/*
Module: labyrinthe
Description: Fournit l'ensemble de fonction permettant de r�soudre un labyrinthe

Auteur: 


Date: 
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"


/*
Fonction: LAB_AFFICHER_GRILLE
Description: Affiche le labyrinthe dans la console.
Si une solution est fournie (pile_solution != NULL), on doit identifier, sur
la grille affichée, toutes les cases faisant partie de la solution (ex. par des X).
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonnées contenant la solution (partielle ou complète) du
Retour: Aucun.
Paramètre modifiés: Aucun.
 */
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) ;

/*
 * Fonction: lab_calculer_deplacements_possibles
 * Description: Vérifie la possibilité des déplacements à une position
 * paramètre:
 */


void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],    //fonction pour déterminer la ou les cases
                                                                            // adjacente a la position actuelle
                                          int hauteur_grille,
                                          int largeur_grille,
                                          int pos_ligne,
                                          int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,
                                          int deplacements[][2]) ;

int lab_choisir_deplacement(int deplacements_possible[][2], int nb_deplacement_possible) ; //choisie aléatoirement la
                                                                        // case adjacente que vas prendre l'algorythme

int lab_est_cases_adjacentes(int case1[2], int case2[2]) ;              //vérifie si la case est adjacente
                                                                        // a la position actuelle



int lab_est_une_sortie(int position[2],                                  //vérifie si la case actuel est une sortie
                       int grille[][TAILLE_MAX_GRILLE],
                       int largeur_grille,
                       int hauteur_grille);


int lab_resoudre_profondeur(                                        //algorythme de déplacement
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);




#endif