/*
Module: pile
Description: Module offrant un ensemble de fonctions pour configurer et manipuler
			 une pile de coordonnees entieres. La pile stockee dans un tableau a deux
			 dimensions (n lignes, 2 colonnes)

Auteur: Anis Boubaker
Date: 2017-02-13
*/


#ifndef PILE_H
#define PILE_H
#define TAILLE_MAX_PILE 1000 //La taille maximale des piles

/*
Fonction: pile_empiler
Description: Empile les coordonnees new_ligne et new_colonne recues en
			 parametre.
Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- new_ligne (entier): L'ordonnees a empiler
- new_colonne (entier): L'abscisse a empiler
Retour: Vrai si les coordonnes ont bien ete empilees, faux sinon.
Parametres modifies: pile.
*/
int pile_empiler(int pile[][2], int new_ligne, int new_colonne);


/*
Fonction: pile_depiler
Description: Depile les coordonnees du haut de la pile, et les stocke
			 dans les adresses fournies par les pointeurs ligne et colonne.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (pointeur d'entier): Adresse memoire ou stocker l'ordonnees depilee
- colonne (pointeur d'entier): Adresse memoire ou stocker l'abscisse depilee
Retour: Vrai si les coordonnes ont bien ete depilees, faux sinon.
Parametres modifies: pile, *ligne, *colonne.
*/
int pile_depiler(int pile[][2], int* ligne, int* colonne);


/*
Fonction: pile_est_vide
Description: Verifie si la pile en parametre est vide.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
Retour: Vrai si la pile est vide, faux sinon.
Parametres modifies: aucun.
*/
int pile_est_vide(int pile[][2]);

/*
Fonction: pile_contient
Description: Verifie si la pile en parametre contient les coordonnees (ligne, colonne).

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (entier): L'ordonnee
- colonne (entier): L'abscisse
Retour: Vrai si la pile contient les coordonnees (ligne, colonne), faux sinon.
Parametres modifies: aucun.
*/
int pile_contient(int pile[][2], int ligne, int colonne);

/*
Fonction: pile_haut_pile
Description: Stocke dans les adresses fournies par les pointeurs ligne et colonne
			 les coordonnees en haut de la pile, sans les depiler.

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
- ligne (pointeur d'entier): Adresse memoire ou stocker l'ordonnees haut pile
- colonne (pointeur d'entier): Adresse memoire ou stocker l'abscisse haut pile
Retour: 1 ou 0.
Parametres modifies: *ligne, *colonne.
*/
void pile_haut_pile(int pile[][2], int* ligne, int* colonne);

/*
Fonction: pile_taille_pile
Description: Renvoie le nombre d'elements dans la pile

Arguments:
- pile (tableau d'entiers): Tableau contenant la structure de pile
Retour: Le nombre d'elements contenus dans la pile.
Parametres modifies: aucun.
*/
int pile_taille_pile(int pile[][2]);

/*
Fonction: pile_initialiser
Description: Initialise un tableau afin de servir comme structure de pile. La colonne 0
servira a stocker la taille du tableau ainsi que l'indice du haut de la pile.

Arguments:
- pile (tableau d'entiers): Tableau qui servira à stocker la structure de la pile.
- taille_max (entier): La taille du tableau (en mémoire).
Retour: Aucun.
Paramatres modifies: pile.
*/
void pile_initialiser(int pile[][2], int taile_max);

/*
Fonction: pile_copier
Description: Copie un tableau contenant une structure de pile dans un autre tableau.

Arguments:
- pile_originale (tableau d'entiers): Tableau contenant une structure de pile.
- pile_copie (tableau d'entiers): Tableau qui contiendra une copie de pile_originale.
Retour: Aucun.
Parametres modifies: pile_copie.
Antecedents: On suppose que le tableau pile_copie a une taille superieure ou egale au
			 tableau pile_originale.
*/
void pile_copier(int pile_originale[][2], int pile_copie[][2]);


#endif
