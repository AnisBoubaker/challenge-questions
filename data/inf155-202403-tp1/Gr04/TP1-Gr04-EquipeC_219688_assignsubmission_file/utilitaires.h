/*
Module: utilitaires
Description: Module de fonctions utilitaires pour le programme du labyrinthe.

Auteur: �mile Yergeau

Date: 2023-11-06
*/

#ifndef INF155_TP1_UTILITAIRES_H
#define INF155_TP1_UTILITAIRES_H

//D�pendances du module
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

#define MESSAGE_AUCUNE_SOLUTIONS "Aucune solution trouv�e :-(\n"

/*
Fonction: AFFICHER_OPTIONS
Description: affiche le titre et les options possibles

Param�tres:
    - grille_chargee (int): valeur bool�enne, vrai si la grille a d�j� �t� charg�e, faux sinon.
Retour : aucun
*/
void afficher_options(int grille_chargee);

/*
Fonction: AFFICHER_CHARGEMENT_GRILLE
Description: affiche si l'on a r�ussi � charger la grille

Param�tres:
- grille_chargee (int): valeur bool�enne, vrai si la grille a d�j� �t� charg�e, faux sinon.
- grille: tableau � deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonn�es contenant la solution (partielle ou compl�te) du
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

Param�tres:
- solution_est_trouve (int): valeur bool�enne, vrai si une solution � �t� trouv�e, faux sinon.
- grille: tableau � deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonn�es contenant la solution (partielle ou compl�te) du
                  labyrinthe.
Retour : aucun
*/
void afficher_solution(int solution_est_trouve, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);

#endif //INF155_TP1_UTILITAIRES_H
