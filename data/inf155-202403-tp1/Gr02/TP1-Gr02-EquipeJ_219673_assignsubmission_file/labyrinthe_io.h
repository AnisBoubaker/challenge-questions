/*
Module: labyrinthe_io
Description: Module de fonction d'entr�e/sortie en lien avec le programme du labyrinthe

Auteur:    

Date: 
*/

#ifndef LABYRINTHE_IO_H
#define LABYRINTHE_IO_H


//D�pendances du module
#include "labyrinthe.h"
#include <stdio.h>
#include <string.h>

//Constantes
#define TAILLE_MAX_NOM_FICHIER 100 //Taille maximale (en cracat�res) du nom de fichier

/*
Fonction: CHARGER_LABYRINTHE
Description: Charge un labyrinthe depuis le disque dur et le stocke dans "grille". Si une erreur
			 se produit (fichier introuvable, fichier non-conforme), la fonction retourne faux. Sinon
			 elle retourne vrai.
Param�tres:
- nom_fichier (chaine de caract�res): Le nom du fichier sur le disque � charger. �a doit �tre un fichier
										 texte comprenant uniquement des * (pour les murs), des espaces (pour
										 les couloirs et une lettre E pour repr�senter l'entr�e.
- grille: (tableau 2D d'entiers): Tableau qui contiendra la topologie de la grille. Chaque case aura soit la
								  valeur 0 (pour un couloir) soit 1 (pour un mur).
- point_entree: (tableau de deux cases) Tableau dans lequel seront stock�es les coordonn�es du point d'entr�e.
- hauteur_grille: (pointeur d'entier) Adresse dans laquelle sera stock�e la hauteur de la grille (nombre de lignes)
- largeur_grille: (pointeur d'entier) Adresse dans laquelle sera stock�e la largeur de la grille (nombre de colonnes)
Retour : (valeur bool�enne) Vrai si la grille s�est charg�e correctement, faux sinon.
Param�tres modifi�s : grille, point_entree, *hauteur_grille et *largeur_grille.
*/
int charger_labyrinthe(
	char* nom_fichier,
	int grille[][TAILLE_MAX_GRILLE],
	int point_entree[2],
	int* hauteur_grille,
	int* largeur_grille);

int selection_menu(int grille_chargee);

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);

#endif // !LABYRINTHE_IO_H