

#include "labyrinthe_io.h"
#include <stdlib.h>
#include <stdio.h>

int charger_labyrinthe(char *nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int *hauteur_grille, int *largeur_grille)
{
	FILE *fichier;
	char caractere_lu;
	int i = 0,
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
			if (*largeur_grille != -1 && *largeur_grille != j)
			{
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

void varia_log_message(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	vprintf(format, args);

	va_end(args);
}

int selection_menu(int grille_chargee)
{

	int choix;
	char name[TAILLE_MAX_NOM_FICHIER] = "[indisponible]";

	do
	{
		printf("***************************\n");
		printf("*****LABYRINTHE EXPERT*****\n");
		printf("***************************\n");

		if (grille_chargee == 0)
		{
			printf("1: Charger labyrinthe\n2: %s Resoudre labyrinthe\n3: %s Resoudre le labyrinthe Pas-A-Pas\n4: Quitter le programme\n",
				   name, name);
		}
		else
		{
			printf("1: Charger labyrinthe\n2: Resoudre labyrinthe\n3: Resoudre le labyrinthe Pas-A-Pas\n4: Quitter le programme\n");
		}
		printf("\n>");
		scanf("%d", &choix);
		do
		{

		} while (getchar() != '\n');

		if (choix != 1 && choix != 2 && choix != 3 && choix != 4)
		{
			printf("Choix est invalide!\n");
			system("pause");
		}
		else if (choix == 2 && grille_chargee == 0)
		{
			printf("Choix est invalide!\n");
			system("pause");
			choix = 0;
		}
		else if (choix == 3 && grille_chargee == 0)
		{
			printf("Choix est invalide!\n");
			system("pause");
			choix = 0;
		}
	} while (choix != 1 && choix != 2 && choix != 3 && choix != 4);
	return choix;
}

void menu_charger_labyrinthe(char *buf_nom_fichier, int buf_taille)
{
	printf("nom du fichier : ");
	scanf("%s", buf_nom_fichier);
}
