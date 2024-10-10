/*
Module: labyrinthe_io

Description: Implémentation des fonctions du module labyrinthe_io

Auteurs: Anis Boubaker (professeur, fournissant une partie du code aux étudiants)
         Jafar Al-Khaiat
         Tayeb Amrouche
         Jose David Molina Penaloza
         William Zamudio-Turcotte

Date: 2023-11-12 (contributions de l'équipe d'étudiants)
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include "labyrinthe_io.h"
#include <stdio.h>
#include <stdlib.h>

/*******IMPLÉMENTATION DES FONCTIONS***********/
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
	FILE* fichier;
	char caractere_lu;
	int i = 0, //Compteurs d'indices dans le tableau
		j = 0;
	fichier = fopen(nom_fichier, "r");
	if (!fichier)
	{
		return 0;
	}

	*largeur_grille = -1;
	*hauteur_grille = -1;

	while ((caractere_lu = getc(fichier)) != EOF)
	{
		switch (caractere_lu)
		{
		case '*':
			grille[i][j] = 1;
			j++;
			break;
		case ' ':
			grille[i][j] = 0;
			j++;
			break;
		case 'E':
			grille[i][j] = 0;
			point_entree[0] = i;
			point_entree[1] = j;
			j++;
			break;
		case '\n':
			if (*largeur_grille != -1 && *largeur_grille != j) {
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le m�me nombre de colonnes.\n");
				return 0;
			}
			*largeur_grille = j;
			j = 0;
			i++;
			break;
		}
	}
	*hauteur_grille = i + 1;
	fclose(fichier);
	return 1;
}
