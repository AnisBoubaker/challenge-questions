/*
Module: labyrinthe.h
 
Description: Fournit l'ensemble de fonction permettant de rÃ©soudre un labyrinthe

Auteur: Vito PELLEGRINELLI/ Mark AVRUTIN/ Romain LATREILLE/ Xavier MARTEL


Date: 16/10/2023
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe

#include <stdio.h>
#include "utilitaires.h"
#include "pile.h"

/*******IMPLEMENTATION DES FONCTIONS***********/

/*
Fonction: LAB_AFFICHER_GRILLE

Description:

    Affiche la grille du labyrinthe dans la console. La fonction doit parcourir
    la grille et afficher des murs ou la grille contient un 1, et un espace ou il ny
    en a pas. Pour afficher un mur, on utilise le caractere ayant pour code ASCII 219.
    Si une solution est fournie (pile_solution != NULL), on doit identifier, sur
    la grille affichee, toutes les cases faisant partie de la solution (ex. par des X).


Parametres:

    - grille: tableau a deux dimensions d'entiers qui contient les informations
     de la structure du labyrinthe (1=mur, 0=couloir).
    - hauteur_grille : entier qui contient le nombre de lignes de la grille.
    - largeur_grille : entier qui contient le nombre de colonnes de la grille.
    - pile_solution : (tableau 2D) pile de coordonnees contenant la solution (partielle ou complete) du
     labyrinthe.

Retour: Aucun.
Parametre modifies: Aucun.
*/
void  lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);
/*
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);
*/
/*
Fonction: LAB_CALCULER_DEPLACEMENTS_POSSIBLES

Description:

    Determine la liste de deplacements possibles depuis une position
    donnee. Un deplacement vers une case X est possible depuis la position P si:

     - X n est pas un mur
     - P et X sont deux cases adjacentes
     - X ne fait pas partie de la solution partielle en cours d'elaboration (pour ne
     pas revenir en arriere).

Parametres:

    - grille: tableau a deux dimensions d'entiers qui contient les informations
    de la grille.
    - hauteur_grille : entier qui contient le nombre de lignes de la grille.
    - largeur_grille : entier qui contient le nombre de colonnes de la grille.
    - pos_ligne: la ligne de la grille sur laquelle nous sommes presentement positionnes.
    - pos_colonne: la colonne de la grille sur laquele nous sommes presentement positionnes.
    - solution_partielle: pile de coordonnees qui comprend les coordonnees de la solution en
     cours d'elaboration.
    - nb_deplacements : adresse ou stocker le nombre de deplacements possible trouves.
    - deplacements: tableau d'entiers (taille 4x2) qui contiendra le resultats: les coordonnees des
    cases ou un deplacement est possible depuis la position actuelle (max 4 possibilites).5

Retour : Aucun
Parametres modifies : nb_deplacement, deplacements.
*/

void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,int largeur_grille,
                                          int pos_ligne,int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,int deplacements[4][2]);
/*
Fonction: LAB_CHOISIR_DEPLACEMENT

Description:

    Choisit un deplacement parmi les deplacements possibles passes en parametre.
    Dans cette version, le choix du deplacement se fait de facon aleatoire parmi les
    deplacement possibles. Cependant, si nous souhaitons faire evoluer notre programme
    et choisir le prochain deplacement en utilisant une autre approche, il suffit de
    changer cette fonction.

Parametres:

    - deplacements_possibles: tableau 2D contenant les coordonnees des deplacements possibles. Les
     donnees de ce tableau devraient etre celles qui ont ete obtenues par
     la fonction lab_calculer_deplacements_possibles.
    - nb_deplacements_possibles: Nombre d'elements dans le tableau deplacements_possibles.

Retour : (Entier) indice, dans le tableau deplacements_possibles qui a ete choisi comme prochain
deplacement.
Parametres modifies : Aucun
*/

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles);

/*
Fonction: LAB_EST_CASES_ADJACENTES

Description:

    Renvoie Vrai si les deux cases case1 et case2 sont adjacentes, et faux sinon. Deux cases
    sont adjacentes si elles sont collees l une a lautre dans la grille. Ex.: les
    cases (5,3) et (5,4) sont adjacentes.

Parametres:

    - case1: (tableau de deux entiers) coordonnees de la premiere case.
    - case1: (tableau de deux entiers) coordonnees de la seconde case.

Retour: (Entier) Valeur vraie si les deux cases sont adjacentes, faux sinon.
Parametres modifies: Aucun.
*/

int lab_est_cases_adjacentes(int case1[2], int case2[2]);

/*
Fonction: LAB_EST_UNE_SORTIE

Description:

    Fonction qui renvoie Vrai si "position" est une sortie de la grille, sinon elle
    renvoie Faux. "position" est une sortie si elle se trouve en peripherie de la grille
    et que ce n'est pas un mur.

Parametres:

    - position: (tableau de deux entiers) coordonnees de la case du labyrinthe que nous souhaitons
    verifier si c'est une sortie.
    - grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe.
    - hauteur_grille : entier qui contient le nombre de lignes de la grille.
    - largeur_grille : entier qui contient le nombre de colonnes de la grille.

Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Parametre modifies: Aucun.
*/

int lab_est_une_sortie(int position[2],     int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille,  int largeur_grille);
/*
Fonction: LAB_RESOUDRE_PROFONDEUR

Description:

    Fonction principale du module qui a pour objectif de resoudre le labyrinthe
    en utilisant l'algorithme de parcours en profondeur (decrit en detail a la page 11
    de l enonce). La fonction construit
    une solution du labyrinthe "grille" dans "pile_solution".
    Cette fonction peut etre executee en mode "debug", auquel cas, la fonction
    affiche a l'ecran la grille avec une solution partielle a chaque fois qu'une
    case est ajoutee a la solution.
    La fonction retourne une valeur vraie si une solution a ete trouvee, ou une
    valeur fausse sinon.

Parametres:

    - grille: tableau a deux dimensions d'entiers qui contient les informations
     de la structure du labyrinthe.
    - hauteur_grille : entier qui contient le nombre de lignes de la grille.
    - largeur_grille : entier qui contient le nombre de colonnes de la grille.
    - entree : (tableau de 2 entiers) coordonnÃ©es du point d'entree dans le labyrinthe
    - pile_solution : (tableau 2D) pile de coordonnÃ©es. La pile doit avoir ete initialisee
     avant d'appeler cette fonction. Les coordonnÃ©es de la solution seront
     empilees dans cette pile.
    - debug : (entier) valeur booleenne. Si sa valeur est Vraie, la fonction affichera la grille
     au fur et a mesure qu'on ajoute des cases a la solution.

Retour: (Entier) Valeur vraie si une solution a Ã©tÃ© trouvee, ou fausse sinon.
Parametre modifiees: pile_solution.
*/

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                            int largeur_grille,             int entree[2],
                            int pile_solution[][2],         int debug);
#endif



















/*



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

int lab_est_cases_adjacentes(int case1[2], int case2[2]);

int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);


int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);*/