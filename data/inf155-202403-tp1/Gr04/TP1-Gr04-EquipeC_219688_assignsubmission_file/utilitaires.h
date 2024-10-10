/*
Module: utilitaires
Description: Module de fonctions utilitaires pour le programme du labyrinthe.

Auteur: Émile Yergeau

Date: 2023-11-06
*/

#ifndef INF155_TP1_UTILITAIRES_H
#define INF155_TP1_UTILITAIRES_H

//Dépendances du module
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthe.h"

//Constantes
#define MESSAGE_TITRE_LIGNE_1 "                *************************\n"
#define MESSAGE_TITRE_LIGNE_2 "                *** LABYRINTHE EXPERT ***\n"
#define MESSAGE_TITRE_LIGNE_3 "                *************************\n"

#define ESPACEMENT_OPTIONS "        %d. "
#define MESSAGE_OPTION_1 "Charger un labyrinthe\n", 1
#define MESSAGE_OPTION_2 "Resoudre le labyrinthe\n", 2
#define MESSAGE_OPTION_3 "Resoudre le labyrinthe pas-a-pas\n", 3
#define MESSAGE_OPTION_4 "Quitter le programme\n", 4
#define INDISPONIBLE "[Indisponible] "

#define MESSAGE_GRILLE_CHARGEE "        Grille chargee avec succes:\n\n"
#define MESSAGE_GRILLE_PAS_CHARGEE "Erreur lors du chargement de la grille.\n"

#define MESSAGE_AUCUNE_SOLUTIONS "Aucune solution trouvée :-(\n"

/*
Fonction: AFFICHER_OPTIONS
Description: affiche le titre et les options possibles

Paramètres:
    - grille_chargee (int): valeur booléenne, vrai si la grille a déjà été chargée, faux sinon.
Retour : aucun
*/
void afficher_options(int grille_chargee);

/*
Fonction: AFFICHER_CHARGEMENT_GRILLE
Description: affiche si l'on a réussi à charger la grille

Paramètres:
- grille_chargee (int): valeur booléenne, vrai si la grille a déjà été chargée, faux sinon.
- grille: tableau à deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonnées contenant la solution (partielle ou complète) du
                  labyrinthe.
Retour : aucun
*/
void afficher_chargement_grille(
        int grille_chargee,
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

/*
Fonction: AFFICHER_SOLUTION
Description: affiche la solution du labyrinthe.

Paramètres:
- solution_est_trouve (int): valeur booléenne, vrai si une solution à été trouvée, faux sinon.
- grille: tableau à deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonnées contenant la solution (partielle ou complète) du
                  labyrinthe.
Retour : aucun
*/
void afficher_solution(int solution_est_trouve, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);

#endif //INF155_TP1_UTILITAIRES_H
