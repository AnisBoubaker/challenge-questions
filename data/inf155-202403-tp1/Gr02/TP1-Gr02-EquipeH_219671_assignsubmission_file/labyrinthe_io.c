/*
titre: labyrinthe_io.c

Auteurs:    - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier

Date: 12 novembre 2023
*/


/***********COMMANDES PREPROCESSEUR*************/
#include "labyrinthe_io.h"
#include "labyrinthe.h"
#include "utilitaires.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FFLUSH() do{} while (getchar()!='\n')



/*******IMPLEMENTATION DES FONCTIONS***********/
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille)
{

	FILE* fichier;
	char caractere_lu;
	int i = 0, //Compteurs d'indices dans le tableau
		j = 0;
	fichier = fopen(nom_fichier, "r");
	if (!fichier) // le fichier est introuvable
	{
		return 0;
	}

	*largeur_grille = -1;
	*hauteur_grille = -1;

	while ((caractere_lu = getc(fichier)) != EOF)
	{
		switch (caractere_lu)
		{
		case '*': // cas où le caractère est un mur.
			grille[i][j] = 1;
			j++;
			break;
		case ' ': // cas où le caractèere est un passage vide.
			grille[i][j] = 0;
			j++;
			break;
		case 'E': // cas où le caractère est l'entrée.
			grille[i][j] = 0;
			point_entree[0] = i;
			point_entree[1] = j;
			j++;
			break;
		case '\n': // cas où le caractère est un saut de ligne
			if (*largeur_grille != -1 && *largeur_grille != j) {
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le meme nombre de colonnes.\n");
				return 0;
			}
			*largeur_grille = j; // la largeur de la grille prend la valeur du compteur de colonnes.
			j = 0; //réinitialisation du compteur de colonnes.
			i++;
			break;
		}
	}
	*hauteur_grille = i + 1; // l'hauteur de la grille prend une nouvelle valeur.
	fclose(fichier); // ferme le fichier.
	return 1;
}

int selection_menu(int grille_chargee)
{
    laby_expert();
    int saisie;

    if(!grille_chargee) // si la grillex.txt n'a pas encore été chargé, alors afficher ce menu d'options :
    {
        printf("     1. Charger un labyrinthe\n");
        printf("     2. [Indisponible] Resoudre le labyrinthe\n");
        printf("     3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        printf("     4. Quitter le programme\n");
        do
        {
            printf("> ");
            scanf(" %i", &saisie);
        } while (saisie != 1 && saisie != 4); // s'assure que la saisie soit entre 1 et 4.
    }
    else // si la grillex.txt a été chargé, alors afficher ce menu d'options :
    {
        printf("     1. Charger un labyrinthe\n");
        printf("     2. Resoudre le labyrinthe\n");
        printf("     3. Resoudre le labyrinthe pas-a-pas\n");
        printf("     4. Quitter le programme\n");
        printf("> ");
        scanf("  %i", &saisie);
    }
    return saisie; // la saisie entre 1 et 4 de l'usager sera retourné.
}


void menu_charger_labyrinthe(char* buf_nom_fichier,int buf_taille)
{

    printf("Saisir nom de fichier :");
    FFLUSH();
    fgets(buf_nom_fichier,buf_taille,stdin); // lit le nom du fichier. (remplace scanf).
    for(int i=0;i<strlen(buf_nom_fichier);i++)
    {
        if(buf_nom_fichier[i]=='\n')
        {
            buf_nom_fichier[i]='\0'; // remplace \n par \0 => fin de la chaine de caractères.
        }
    }
}

