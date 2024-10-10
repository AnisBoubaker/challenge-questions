/*
Module: labyrinthe_io

Auteurs:Mba Nzudie,Aubin Sylva;Kramar,Timothy;Orantes Benitez, Elias et Jeudy,Melody

Date: 08 novembre 2023
*/

#include <string.h>
#include <stdio.h>

/***********COMMANDES PR�PROCESSEUR*************/
#include "labyrinthe_io.h"



/*******IMPLEMENTATION DES FONCTIONS***********/
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
int selection_menu(int grille_chargee) {
    int choix;
    int valideur = 0;
    if(grille_chargee==0){
        printf(" voici le menu principal:\n 1. Charger un labyrinthe\n 2. [Indisponible] Resoudre le labyrinthe\n 3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n 4. Quitter le programme\n");
    }
    else {
        printf(" voici le menu principal:\n 1. Charger un labyrinthe\n 2.  Resoudre le labyrinthe\n 3. Resoudre le labyrinthe pas-a-pas\n 4. Quitter le programme\n");
    }

    while(valideur==0) {
        printf("\nVeuillez faire un choix dans le menu principal:");
        scanf("%i",&choix);
     switch (choix) {

         case 1 :
                choix=1;
                valideur++;
                break;


         case 2 :
             choix=2;
             valideur++;
             break;

         case 3 :
             choix=3;
             valideur++;
             break;


         case 4 :
             choix=4;
             valideur++;
             break;

         default:
             valideur=0;
        }


    }
    return choix;
}
void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {

    printf("Veuillez entrer le nom du fichier contenant le labyrinthe : ");
    fflush(stdin);
    fgets(buf_nom_fichier, buf_taille, stdin);
    // Suppression du caractère de nouvelle ligne en fin de chaîne si présent
    size_t longeur = strlen(buf_nom_fichier) - 1;
    if (buf_nom_fichier[longeur] == '\n') {
        buf_nom_fichier[longeur] = '\0';
    }
}
