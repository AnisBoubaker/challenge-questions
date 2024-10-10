/*
Module: utilitaires
Description: Fournit l'ensemble de fonction qui ne font partie d'aucun des autres modules.

Auteurs: Francis Gignac, Rachelle Sanscartier, Maxim St-Gelais, Abraham Suarez-Santizo

Date:2023-11-12
*/

#ifndef UTILITAIRES_H
#define UTILITAIRES_H

/*** CONSTANTES ***/
/* Taille maximale en lignes et colonnes d'une grille de labyrinthe. */
#define TAILLE_MAX_GRILLE 100

/*
   FONCTION: nb_aleatoire
   Cette fonction retourne une valeur aléatoire dans l'intervalle entier
   [min, max]. Chaque valeur possède la même probabilité d'être génére.

   PARAMÈTRES :
        - min : La plus petite valeur pouvant être générée (type : int).
        - max : La plus grande valeur pouvant être générée (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a préalablement été appelée.
 */
int nb_aleatoire(int min, int max);

/*
Fonction: dplc_haut

Description: Prend un tableau 1D de format 2 pour y instaurer des coordonnées
             modifié de manière ou le pion se déplace vers le HAUT dans le labyrinthe.

Arguments:
- coordo (tableau d'entiers): Tableau vide de taille 2 wui va contenir de
                              nouvelles coordonnées.
                              (ex: coordo[position horizontale][position verticale]).
- pos_lig (entier): Position VERTICALE d'un pion situé dans le labyrinthe.
- pos_col (entier): Position HORIZONTALE d'un pion situé dans le labyrinthe.

Retour: Aucun.

Paramètres modifiés: coordo.

Antécédents: aucun.
*/
void dplc_haut(int coordo[], int pos_lig, int pos_col);

/*
Fonction: dplc_bas

Description: Prend un tableau 1D de format 2 pour y instaurer des
             coordonnées modifié de manière ou le pion se
             déplace vers le BAS dans le labyrinthe.

Arguments:
- coordo (tableau d'entiers): Tableau vide de taille 2 qui va contenir de
                              nouvelles coordonnées.
                              (ex: coordo[position horizontale][position verticale]).
- pos_lig (entier): Position VERTICALE d'un pion situé dans le labyrinthe.
- pos_col (entier): Position HORIZONTALE d'un pion situé dans le labyrinthe.

Retour: Aucun.

Paramètres modifiés: coordo.

Antécédents: aucun.
*/
void dplc_bas(int coordo[], int pos_lig, int pos_col);


/*
Fonction: dplc_gauche

Description: Prend un tableau 1D de format 2 pour y instaurer des coordonnées modifié de
             manière ou le pion se déplace vers la GAUCHE dans le labyrinthe.

Arguments:
- coordo (tableau d'entiers): Tableau vide de taille 2 qui va contenir de
                              nouvelles coordonnées.
                              (ex: coordo[position horizontale][position verticale]).
- pos_lig (entier): Position VERTICALE d'un pion situé dans le labyrinthe.
- pos_col (entier): Position HORIZONTALE d'un pion situé dans le labyrinthe.

Retour: Aucun.

Paramètres modifiés: coordo.

Antécédents: aucun.
*/
void dplc_gauche(int coordo[], int pos_lig, int pos_col);


/*
Fonction: dplc_droite

Description: Prend un tableau 1D de format 2 pour y instaurer des coordonnées modifié de
             manière ou le pion se déplace vers la DROITE dans le labyrinthe.

Arguments:
- coordo (tableau d'entiers): Tableau vide de taille 2 qui va contenir de
                              nouvelles coordonnées.
                              (ex: coordo[position horizontale][position verticale]).
- pos_lig (entier): Position VERTICALE d'un pion situé dans le labyrinthe.
- pos_col (entier): Position HORIZONTALE d'un pion situé dans le labyrinthe.

Retour: Aucun.

Paramètres modifiés: coordo.

Antécédents: aucun.
*/
void dplc_droite(int coordo[], int pos_lig, int pos_col);

#endif
