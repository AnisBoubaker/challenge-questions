/*
Module: labyrinthe
Description: Fournit l'ensemble de fonction permettant de resoudre un labyrinthe
Auteur: Iman Assameur, Emily Wu, Cory Alejandra Herrera Gallego,Hoang Yen Pham
Date: 
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pile.h"
#include "utilitaires.h"

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#endif

/*
Fonction: LAB_AFFICHER_GRILLE
Auteur: Iman Assameur
Description: Affiche la grille du labyrinthe dans la console. La fonction doit parcourir
la grille et afficher des murs oï¿½ la grille contient un 1, et un espace ou il n y
en a pas. Pour afficher un mur, on utilise le caractere ayant pour code
ASCII 219.
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
Parametres modifies: Aucun.
*/
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

/*

 Fonction: LAB_CALCULER_DEPLACEMENTS_POSSIBLES
 Auteure: Emily Wu
 Description: determine la liste de deplacements possibles depuis une position donnee
 Arguments:
 - grille: tableau a deux dimensions d'entiers qui contient les informations
de la grille.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pos_ligne: la ligne de la grille sur laquelle nous sommes presentement positionnes.
- pos_colonne: la colonne de la grille sur laquelle nous sommes presentement positionnes.
- solution_partielle: pile de coordonnees qui comprend les coordonnees de la solution en
 cours d'elaboration.
- nb_deplacements : adresse ou stocker le nombre de deplacements possible trouves.
- deplacements: tableau d'entiers (taille 4x2) qui contiendra le resultats: les coordonnees des
cases ou un deplacement est possible depuis la position actuelle
modifies: nb_deplacements et deplacements
 retour: aucun
 */
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille,
                                         int largeur_grille,
                                         int pos_ligne,
                                         int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements,
                                         int deplacements[4][2]);

/*
Fonction: LAB_CHOISIR_DEPLACEMENT
Auteures: Emily Wu, Cory Gallego
Description: Choisit un deplacement parmi les deplacements possibles passes en parametre.
Dans cette version, le choix du dï¿½placement se fait de facon aleatoire parmi les
deplacement possibles. Cependant, si nous souhaitons faire evoluer notre programme
et choisir le prochain deplacement en utilisant une autre approche, il suffit de
changer cette fonction.
Arguments:
- deplacements_possibles: tableau 2D contenant les coordonnees des deplacements possibles. Les
 donnï¿½es de ce tableau devraient etre celles qui ont ete obtenues par
 la fonction lab_calculer_deplacements_possibles.
- nb_deplacements_possibles: Nombre d'elements dans le tableau deplacements_possibles.
Retour : (Entier) indice, dans le tableau deplacements_possibles qui a  choisi comme prochain
deplacement.
Parametres modifies : Aucun

*/
int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles);


/*
Fonction: LAB_EST_UNE_SORTIE
Auteur: Hoang Yen Pham
Description: Fonction qui renvoie Vrai si "position" est une sortie de la grille, sinon elle
renvoie Faux. "position" est une sortie si elle se trouve en peripherie de la grille
et que ce n'est pas un mur.
Parametres:
- position: (tableau de deux entiers) coordonnees de la case du labyrinthe que nous souhaitons
verifier si c'est une sortie.
- grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Parametre modifiees: Aucun.
*/
int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);


/*
Fonction: LAB_EST_CASES_ADJACENTES
Auteure: Cory Alejandra Herrera Gallego
Description: Renvoie Vrai si les deux cases case1 et case2 sont adjacentes, et faux sinon. Deux cases
sont adjacentes si elles sont collees l’une à l’autre dans la grille. Ex.: les
cases (5,3) et (5,4) sont adjacentes.
Parametres:
- case1: (tableau de deux entiers) coordonnees de la premiere case.
- case1: (tableau de deux entiers) coordonnees de la seconde case.
Retour: (Entier) Valeur vraie si les deux cases sont adjacentes, faux sinon.
Paramètres modifies: Aucun.
*/
int lab_est_cases_adjacentes(int case1[2], int case2[2]);


/*
Fonction: LAB_EST_UNE_SORTIE
Auteur: Cory Alejandra Herrera Gallego et Hoang Yen Pham

Description: Fonction qui renvoie Vrai si "position" est une sortie de la grille, sinon elle
renvoie Faux. "position" est une sortie si elle se trouve en périphérie de la grille
et que ce n'est pas un mur.
Paramètres:
- position: (tableau de deux entiers) coordonnées de la case du labyrinthe que nous souhaitons
vérifier si c'est une sortie.
- grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Paramètre modifiés: Aucun.
*/
int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);



/*Fonction: LAB_RESOUDRE_PROFONDEUR
Auteurs: Iman et Emily
Description: Fonction principale du module qui a pour objectif de résoudre le labyrinthe
en utilisant l'algorithme de parcours en profondeur (décrit en détail à la page 11
de l’énoncé). La fonction construit
une solution du labyrinthe "grille" dans "pile_solution".
Cette fonction peut être exécutée en mode "debug", auquel cas, la fonction
affiche à l'écran la grille avec une solution partielle à chaque fois qu'une
case est ajoutée à la solution.
La fonction retourne une valeur vraie si une solution a été trouvée, ou une
valeur fausse sinon.
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
 de la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- entree : (tableau de 2 entiers) coordonnées du point d'entrée dans le labyrinthe
- pile_solution : (tableau 2D) pile de coordonnées. La pile doit avoir été initialisée
 avant d'appeler cette fonction. Les coordonnées de la solution seront
 empilées dans cette pile.
- debug : (entier) valeur booléenne. Si sa valeur est Vraie, la fonction affichera la grille
 au fur et à mesure qu'on ajoute des cases à la solution.
Retour: (Entier) Valeur vraie si une solution a été trouvée, ou fausse sinon.
Paramètre modifiés: pile_solution.
*/

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);


