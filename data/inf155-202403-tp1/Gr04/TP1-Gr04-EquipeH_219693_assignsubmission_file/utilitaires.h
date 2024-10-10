/*
* Fichier : utilitaires.h
* Auteur : felix
* Date : 2023-10-31
*
* Description : Programme qui ...
*/


#ifndef TP1_LABYRINTHE_UTILITAIRES_H
#define TP1_LABYRINTHE_UTILITAIRES_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
Fonction: VALIDER_COORDS_DANS_PILE
Description: Permet de valider si une coordon�es a d�ja �t� utiliser dans la solution.
Param�tres:
    Pile: tableau 2D contenant la solution du labyrithne.
    Taille: (entier) Taille effective de la pile.
    x,y : (entier) Coordon�es en X et en Y de la coordon�es qu'on recherche.
Retour : (Entier) flag, Si 0 alors la coordon�es n'st pas dans la pile et si 1 la coordon�es est dans la pile.
Parametres modifies : Aucun.
*/
int valider_coords_dans_pile(int pile[][2],int taille, int x, int y);


/*
Fonction: VALIDER_COORDS_DANS_PILE
Description: Permet de valider si une coordon�es a d�ja �t� utiliser dans la solution.
Param�tres:
    Pile: tableau 2D contenant la solution du labyrithne.
    Taille: (entier) Taille effective de la pile.
    x,y : (entier) Coordon�es en X et en Y de la coordon�es qu'on recherche.
Retour : (Entier) flag, Si 0 alors la coordon�es n'st pas dans la pile et si 1 la coordon�es est dans la pile.
Paramètres modifiés : Aucun.
*/
int nb_aleatoire(int min, int max);

#endif //TP1_LABYRINTHE_UTILITAIRES_H
