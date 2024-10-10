/*
Module: labyrinthe
Description: Fournit l'ensemble des fonctions permettant de résoudre un labyrinthe.

Auteur: Alexis Roy-Tessier, Donald Vu, Mayas Kaced
Date:12 novembre 2023
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#include "Utilitaires.h"




/*
Fonction: LAB_AFFICHER_GRILLE
Description: Affiche la grille du labyrinthe dans la console. La fonction doit parcourir
la grille et afficher des murs où la grille contient un 1, et un espace où il n’y
en a pas. Pour afficher un mur, on utilise le caractère ayant pour code
ASCII 219.
Si une solution est fournie (pile_solution != NULL), on doit identifier, sur
la grille affichée, toutes les cases faisant partie de la solution (ex. par des X).
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
 de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonnées contenant la solution (partielle ou complète) du
 labyrinthe.
Retour: Aucun.
Paramètre modifiés: Aucun.
*/
void LAB_AFFICHER_GRILLE(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

/*
Fonction: LAB_CALCULER_DEPLACEMENTS_POSSIBLES
Description: Détermine la liste de déplacements possibles depuis une position
 donnée. Un déplacement vers une case X est possible depuis la position P
 si:
 - X n’est pas un mur
 - P et X sont deux cases adjacentes
 - X ne fait pas partie de la solution partielle en cours d'élaboration (pour ne
 pas revenir en arrière).
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
de la grille.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pos_ligne: la ligne de la grille sur laquelle nous sommes présentement positionnés.
- pos_colonne: la colonne de la grille sur laquele nous sommes présentement positionnés.
- solution_partielle: pile de coordonnées qui comprend les coordonnées de la solution en
 cours d'élaboration.
- nb_deplacements : adresse où stocker le nombre de déplacements possible trouvés.
- deplacements: tableau d'entiers (taille 4x2) qui contiendra le résultats: les coordonnées des
cases où un déplacement est possible depuis la position actuelle
(max 4 possibilités).
Retour : Aucun
 Paramètres modifiés : nb_deplacement, deplacements.
*/
void LAB_CALCULER_DEPLACEMENTS_POSSIBLES(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);


/*
Fonction: LAB_EST_CASES_ADJACENTES
Description: Renvoie Vrai si les deux cases case1 et case2 sont adjacentes, et faux sinon. Deux cases
sont adjacentes si elles sont collées l’une à l’autre dans la grille. Ex.: les
cases (5,3) et (5,4) sont adjacentes.
Paramètres:
- case1: (tableau de deux entiers) coordonnées de la première case.
- case2: (tableau de deux entiers) coordonnées de la seconde case.
Retour: (Entier) Valeur vraie si les deux cases sont adjacentes, faux sinon.
Paramètres modifiés: Aucun.
*/
//pas mettre dans deplacement
int LAB_EST_CASES_ADJACENTES(int case1[2], int case2[2]);





/*
Fonction: LAB_CHOISIR_DEPLACEMENT
Description: Choisit un déplacement parmi les déplacements possibles passés en paramètre.
Dans cette version, le choix du déplacement se fait de façon aléatoire parmi les
déplacement possibles. Cependant, si nous souhaitons faire évoluer notre programme
et choisir le prochain déplacement en utilisant une autre approche, il suffit de
changer cette fonction.
Paramètres:
- deplacements_possibles: tableau 2D contenant les coordonnées des déplacements possibles. Les
 données de ce tableau devraient être celles qui ont été obtenues par
 la fonction lab_calculer_deplacements_possibles.
- nb_deplacements_possibles: Nombre d'élélements dans le tableau deplacements_possibles.
Retour : (Entier) indice, dans le tableau deplacements_possibles qui a été choisi comme prochain
déplacement.
Paramètres modifiés : Aucun.
*/
int LAB_CHOISIR_DEPLACEMENT(int deplacements_possibles[][2],int *nb_deplacements_possibles);

/*
Fonction: LAB_EST_UNE_SORTIE
Description: Fonction qui renvoie Vrai si "position" est une sortie de la grille, sinon elle
renvoie Faux. "position" est une sortie si elle se trouve en périphérie de la grille et que ce n'est pas un mur.
Paramètres:
- position: (tableau de deux entiers) coordonnées de la case du labyrinthe que nous souhaitons
vérifier si c'est une sortie.
- grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe. - hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille. Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Paramètre modifiés: Aucun.
*/
int LAB_EST_UNE_SORTIE(int position[2],int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille);

/*
Fonction: LAB_RESOUDRE_PROFONDEUR
Description: Fonction principale du module qui a pour objectif de résoudre le labyrinthe
en utilisant l'algorithme de parcours en profondeur (décrit en détail à la page 11 de l’énoncé). La fonction construit
une solution du labyrinthe "grille" dans "pile_solution".
Cette fonction peut être exécutée en mode "debug", auquel cas, la fonction affiche à l'écran la grille avec une solution partielle à chaque fois qu'une case est ajoutée à la solution.
La fonction retourne une valeur vraie si une solution a été trouvée, ou une valeur fausse sinon.
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
de la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- entree : (tableau de 2 entiers) coordonnées du point d'entrée dans le labyrinthe
- pile_solution : (tableau 2D) pile de coordonnées. La pile doit avoir été initialisée
avant d'appeler cette fonction. Les coordonnées de la solution seront
empilées dans cette pile.
- debug : (entier) valeur booléenne. Si sa valeur est Vraie, la fonction affichera la grille
au fur et à mesure qu'on ajoute des cases à la solution.
Retour: (Entier) Valeur vraie si une solution a été trouvée, ou fausse sinon.
Paramètre modifiés: pile_solution.
*/
int LAB_RESOUDRE_PROFONDEUR(int grille[][TAILLE_MAX_GRILLE],
                            int hauteur_grille,
                            int largeur_grille,
                            int entree[2],
                            int pile_solution[][2],
                            int debug);


/*** CONSTANTES ***/


#endif