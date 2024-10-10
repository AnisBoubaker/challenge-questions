/*
Module: labyrinthe_io

Auteur: 

Date: 
*/


/***********COMMANDES PRÉPROCESSEUR*************/
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
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le même nombre de colonnes.\n");
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
   
int selection_menu(int grille_chargee) 
{   	
    int choix;
   
    printf("Bienvenue au labyrinthe!\n");
    printf("Menu principal\n"); 
    printf("1. Charger un labyrinthe\n");
    printf("2. Resoudre le labyrinthe\n");
    printf("3. Quitter\n");  

    printf("Veuillez saisir un choix: ");
    scanf("%i", &choix);
	
    if(!grille_chargee && choix == 2) 
    {
	printf("La résolution est indisponible tant que vous n'avez pas chargé un labyrinthe. Veuillez charger un labyrinthe.\n");
	    return 0; // Retourne faux si la grille n'a pas été chargée
    } 
	
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    printf("Veuillez saisir un nom de fichier correspondant au fichier contenant le labyrinthe a charger: ");
    fgets(buf_nom_fichier, buf_taille, stdin);
    buf_nom_fichier[strlen(buf_nom_fichier)-1] = '\0';
}
