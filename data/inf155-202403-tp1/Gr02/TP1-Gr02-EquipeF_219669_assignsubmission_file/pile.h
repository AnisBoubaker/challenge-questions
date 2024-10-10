/*
Module: pile
Description: Module offrant un ensemble de fonctions pour configurer et manipuler
			 une pile de coordonn�es enti�res. La pile stock�e dans un tableau � deux
			 dimensions (n lignes, 2 colonnes)
Auteur: Anis Boubaker
Date: 2017-02-13
*/


#ifndef PILE_H
#define PILE_H

/*
Fonction: pile_empiler
Description: Empile les coordonn�es new_ligne et new_colonne re�ues en
			 param�tre.
Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- new_ligne (entier): L'ordonn�es � empiler
- new_colonne (entier): L'abscisse � empiler
Retour: Vrai si les coordonn�s ont bien �t� empil�es, faux sinon.
Param�tres modifi�s: pile.
*/
int pile_empiler(int pile[][2], int new_ligne, int new_colonne);


/*
Fonction: pile_depiler
Description: D�pile les coordonn�es du haut de la pile, et les stocke
			 dans les adresses fournies par les pointeurs ligne et colonne.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
-+ ligne (pointeur d'entier): Adresse m�moire o� stocker l'ordonn�es d�pil�e
- colonne (pointeur d'entier): Adresse m�moire o� stocker l'abscisse d�pil�e
Retour: Vrai si les coordonn�s ont bien �t� d�pil�es, faux sinon.
Param�tres modifi�s: pile, *ligne, *colonne.
*/
int pile_depiler(int pile[][2], int* ligne, int* colonne);


/*
Fonction: pile_est_vide
Description: V�rifie si la pile en param�tre est vide.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
Retour: Vrai si la pile est vide, faux sinon.
Param�tres modifi�s: aucun.
*/
int pile_est_vide(int pile[][2]);

/*
Fonction: pile_contient
Description: V�rifie si la pile en param�tre contient les coordonn�es (ligne, colonne).

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (entier): L'ordonn�e
- colonne (entier): L'abscisse
Retour: Vrai si la pile contient les coordonn�es (ligne, colonne), faux sinon.
Param�tres modifi�s: aucun.
*/
int pile_contient(int pile[][2], int ligne, int colonne);

/*
Fonction: pile_haut_pile
Description: Stocke dans les adresses fournies par les pointeurs ligne et colonne
			 les coordonn�es en haut de la pile, sans les d�piler.

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
