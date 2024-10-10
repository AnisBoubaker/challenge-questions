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
Description: Permet de valider si une coordonées a déja été utiliser dans la solution.
Paramètres:
    Pile: tableau 2D contenant la solution du labyrithne.
    Taille: (entier) Taille effective de la pile.
    x,y : (entier) Coordonées en X et en Y de la coordonées qu'on recherche.
Retour : (Entier) flag, Si 0 alors la coordonées n'st pas dans la pile et si 1 la coordonées est dans la pile.
Parametres modifies : Aucun.
*/
int valider_coords_dans_pile(int pile[][2],int taille, int x, int y);


/*
Fonction: VALIDER_COORDS_DANS_PILE
Description: Permet de valider si une coordonées a déja été utiliser dans la solution.
Paramètres:
    Pile: tableau 2D contenant la solution du labyrithne.
    Taille: (entier) Taille effective de la pile.
    x,y : (entier) Coordonées en X et en Y de la coordonées qu'on recherche.
Retour : (Entier) flag, Si 0 alors la coordonées n'st pas dans la pile et si 1 la coordonées est dans la pile.
ParamÃ¨tres modifiÃ©s : Aucun.
*/
int nb_aleatoire(int min, int max);

#endif //TP1_LABYRINTHE_UTILITAIRES_H
