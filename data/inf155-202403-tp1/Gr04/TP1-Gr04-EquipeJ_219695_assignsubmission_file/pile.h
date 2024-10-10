/*
Module: pile
Description: Module offrant un ensemble de fonctions pour configurer et manipuler
			 une pile de coordonnées entières. La pile stockée dans un tableau à deux
			 dimensions (n lignes, 2 colonnes)
Auteur: Anis Boubaker
Date: 2017-02-13
*/


#ifndef PILE_H
#define PILE_H

/*
Fonction: pile_empiler
Description: Empile les coordonn�es new_ligne et new_colonne re�ues en
			 paramètre.
Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- new_ligne (entier): L'ordonnées à empiler
- new_colonne (entier): L'abscisse à empiler
Retour: Vrai si les coordonnés ont bien été empilées, faux sinon.
Paramètres modifiés: pile.
*/
int pile_empiler(int pile[][2], int new_ligne, int new_colonne);


/*
Fonction: pile_depiler
Description: Dépile les coordonnées du haut de la pile, et les stocke
			 dans les adresses fournies par les pointeurs ligne et colonne.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (pointeur d'entier): Adresse mémoire ou stocker l'ordonnées dépilée
- colonne (pointeur d'entier): Adresse mémoire ou stocker l'abscisse dépilée
Retour: Vrai si les coordonnés ont bien été dépilées, faux sinon.
Paramètres modifiés: pile, *ligne, *colonne.
*/
int pile_depiler(int pile[][2], int* ligne, int* colonne);


/*
Fonction: pile_est_vide
Description: Vérifie si la pile en paramètre est vide.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
Retour: Vrai si la pile est vide, faux sinon.
Param�tres modifiés: aucun.
*/
int pile_est_vide(int pile[][2]);

/*
Fonction: pile_contient
Description: Vérifie si la pile en paramètre contient les coordonnées (ligne, colonne).

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (entier): L'ordonnée
- colonne (entier): L'abscisse
Retour: Vrai si la pile contient les coordonnées (ligne, colonne), faux sinon.
Param�tres modifi�s: aucun.
*/
int pile_contient(int pile[][2], int ligne, int colonne);

/*
Fonction: pile_haut_pile
Description: Stocke dans les adresses fournies par les pointeurs ligne et colonne
			 les coordonnées en haut de la pile, sans les dépiler.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (pointeur d'entier): Adresse m�moire o� stocker l'ordonn�es d�pil�e
- colonne (pointeur d'entier): Adresse m�moire o� stocker l'abscisse d�pil�e
Retour: Aucun.
Param�tres modifi�s: *ligne, *colonne.
*/
void pile_haut_pile(int pile[][2], int* ligne, int* colonne);

/*
Fonction: pile_taille_pile
Description: Renvoie le nombre d'�l�ments dans la pile

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
Retour: Le nombre d'�l�ments contenus dans la pile.
Param�tres modifi�s: aucun.
*/
int pile_taille_pile(int pile[][2]);

/*
Fonction: pile_initialiser
Description: Initialise un tableau afin de servir comme structure de pile. La colonne 0
servira � stocker la taille du tableau ainsi que l'indice du haut de la pile.

Arguments:
- pile (tableau d'entiers): Tableau qui servira � stocker la structure de la pile.
- taille_max (entier): La taille du tableau (en m�moire).
Retour: Aucun.
Param�tres modifi�s: pile.
*/
void pile_initialiser(int pile[][2], int taile_max);

/*
Fonction: pile_copier
Description: Copie un tableau contenant une structure de pile dans un autre tableau.

Arguments:
- pile_originale (tableau d'entiers): Tableau contenant une structure de pile.
- pile_copie (tableau d'entiers): Tableau qui contiendra une copie de pile_originale.
Retour: Aucun.
Param�tres modifi�s: pile_copie.
Ant�c�dents: On suppose que le tableau pile_copie a une taille sup�rieure ou �gale au
			 tableau pile_originale.
*/
void pile_copier(int pile_originale[][2], int pile_copie[][2]);


#endif
