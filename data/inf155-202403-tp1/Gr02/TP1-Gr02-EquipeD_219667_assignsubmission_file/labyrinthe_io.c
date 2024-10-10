/*
Module: labyrinthe_io

Auteur: Ferdaws Aljane, Milena Busuioc, Rachid Hamza et William Lavoie

Date: 12 novembre 2023
*/


/***********COMMANDES PRÉPROCESSEUR*************/
#include "labyrinthe_io.h"
#include <string.h>
#include "utilitaires.h"

/*******IMPLEMENTATION DES FONCTIONS***********/
int charger_labyrinthe(char* nom_fichier,
                       int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2],
                       int* hauteur_grille,
                       int* largeur_grille)
{
	FILE* fichier;
	char caractere_lu;
	int i = 0, // Compteurs d'indices dans le tableau
		j = 0;

    // Ouvrir fichier en mode lecture (read)
	fichier = fopen(nom_fichier, "r");

    if(fichier == NULL)
    {
        perror("Error");
    }
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
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le meme nombre de colonnes.\n");
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
    afficher_menu(grille_chargee);

    if(!grille_chargee)
    {
        // Demande de saisie du choix à l'utilisateur
        printf(">");
        scanf("%d", &choix);

        // Vérification de la validité du choix
        while (choix != 1 &&  choix != 4 )
        {
            printf("\nChoix Invalide!\n\n>");
            scanf("%d", &choix);
        }
    }
    else
    {
        // Demande de saisie du choix à l'utilisateur
        printf(">");
        scanf("%d", &choix);

        // Vérification de la validité du choix
        while (choix < 1  ||  choix > 4)
        {
            printf("Choix Invalide!\n>");
            scanf("%d", &choix);
        }
    }

    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    // Demander à l'utilisateur d'entrer le nom du fichier
    printf("Nom du fichier:");

    // La lecture de l'entrée de l'utilisateur
    fflush(stdin);
    fgets(buf_nom_fichier, buf_taille, stdin);
    buf_nom_fichier[strlen(buf_nom_fichier)-1] = '\0';
}

