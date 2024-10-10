/*
Module: labyrinthe_io.c
Description: Module de fonction d'entrée/sortie en lien avec le programme du labyrinthe

Auteurs: Émile Yergeau
         Sabrina Poulin
         Xavier Brassard
Date: 2023-10-16
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
    int choix_selectionne = 0; // Valeur du choix valide saisi par l'usager

    afficher_options(grille_chargee);

    while (1)
    {
        printf("\n        > ");
        scanf("%d", &choix_selectionne);

        if (!grille_chargee && (choix_selectionne == 2 || choix_selectionne == 3) || choix_selectionne <= 0 || 4 < choix_selectionne)
        {
            printf("        Choix Invalide!\n");
        }
        else
        {
            break;
        }
    }
    return choix_selectionne;
}


void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    // On se débarrasse du '\n' de trop
    int c;
    while ( (c = getchar()) != EOF && c != '\n') { }

    // Saisie du nom du fichier
    printf("Nom du fichier: ");
    fgets(buf_nom_fichier, buf_taille, stdin);
    printf("%s", buf_nom_fichier);

    // Remplace '\n' par '\0'
    char caratere = 0;
    for ( int i = 0; i < buf_taille; i++)
    {
        caratere = buf_nom_fichier[i];
        if (caratere == '\n')
        {
            buf_nom_fichier[i] = '\0';
            break;
        }
    }
}