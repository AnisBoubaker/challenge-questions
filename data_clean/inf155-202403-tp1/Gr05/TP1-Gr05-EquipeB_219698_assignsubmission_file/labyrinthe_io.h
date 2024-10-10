 

#ifndef LABYRINTHE_IO_H
#define LABYRINTHE_IO_H


 
#include "labyrinthe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
#define TAILLE_MAX_NOM_FICHIER 100  

 
int charger_labyrinthe(
	char* nom_fichier,
	int grille[][TAILLE_MAX_GRILLE],
	int point_entree[2],
	int* hauteur_grille,
	int* largeur_grille);

 
int selection_menu(int grille_chargee) ;

 
void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);

#endif  