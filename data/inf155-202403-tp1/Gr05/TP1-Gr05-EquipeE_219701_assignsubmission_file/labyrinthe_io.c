/*
Module: labyrinthe_io.c

Auteur: Vito PELLEGRINELLI/ Mark AVRUTIN/ Romain LATREILLE/ Xavier MARTEL

Date: 16/10/2023
*/


/***********COMMANDES PREPROCESSEUR*************/

#include "labyrinthe_io.h"

/*******IMPLEMENTATION DES FONCTIONS***********/

int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int* hauteur_grille,
                       int* largeur_grille)
{
    FILE *fichier;
    char caractere_lu;
    int i = 0, //Compteurs d'indices dans le tableau
    j = 0;

    fichier = fopen(nom_fichier, "r");

    if (!fichier) {
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

    if (!grille_chargee)
    {
        // Affiche le menu pricipale avant le choix
        printf("         -------------------------------\n");
        printf("         ------- MENU PRINCIPALE -------\n");
        printf("         -------------------------------\n");

        printf("--------------------------------------------------------------------------------\n");
        printf("    1er etape:                   1 Choisiser un labyrinthe a resoudre.  \n");
        printf("    2e etape:     (Indisponible) 2 Resoudre le labyrinthe choisi.     \n");
        printf("       ou         (Indisponible) 3 Pour resoudre le labyrinthe pas a pas\n ");
        printf("    3e etape:                    4 Quitter\n");
        printf("--------------------------------------------------------------------------------\n");


        do
        {
            printf("Veuillez saisir un choix disponible :");
            scanf("%i", &choix);

            if (choix == 1 || choix == 4) // Verifie le choix de l'usager
            {
                return choix;
            }
            else
            {
                printf("Non disponible\n");
            }

        } while (choix > 1 && choix < 4);
    }

    if (grille_chargee)
    {
        // Affiche le menu pricipale apres le choix
        printf("         -------------------------------\n");
        printf("         ------- MENU PRINCIPALE -------\n");
        printf("         -------------------------------\n");

        printf("--------------------------------------------------------------------------------\n");
        printf("    1er etape:    1 Choisiser un labyrinthe a resoudre.  \n");
        printf("    2e etape:     2 Resoudre le labyrinthe choisi.     \n");
        printf("       ou         3 Pour resoudre le labyrinthe pas a pas\n ");
        printf("    3e etape:     4 Quitter\n");
        printf("--------------------------------------------------------------------------------\n");
        

        do
        {
            printf("Veuillez saisir un choix disponible :");
            scanf("%i", &choix);

            if (choix > 0 && choix < 5) // Verifie le choix de l'usager
            {
                return choix;
            }
            else
            {
                printf("Non disponible");
            }

        } while (choix < 1 || choix > 4);

    }
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {


    printf("Nom du fichier : ");
    char nom_fichier [buf_taille];

    //fgets(buf_nom_fichier, buf_taille, stdin);
    scanf("%s", nom_fichier);

    printf("Fichier lu : '%s'\n", nom_fichier);

    strncpy(buf_nom_fichier, nom_fichier, buf_taille);
    //nom_fichier[strlen(nom_fichier)] = '\0';
    buf_nom_fichier[buf_taille - 1] = '\0';



    //buf_nom_fichier [strlen(buf_nom_fichier) - 1] = '\0';



}
    //FONCTION TEST
    /*char buf_nom_fichier[100];

    printf("Nom du fichier : ");

    fgets(buf_nom_fichier, 50, stdin);

    buf_nom_fichier[strlen(buf_nom_fichier) - 1] = '\0';

    printf("%s", buf_nom_fichier);*/



