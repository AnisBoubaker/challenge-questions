/*
titre: labyrinthe_io.c
Description: Implémentation des fonctions du module labyrinthe_io.h
Auteurs:
Tommy Parent,
Maude Gallant-Mercier,
Camille Landry,
Saguira Neysa Charles
Date: 2023-11-07
*/
/***********COMMANDES PR�PROCESSEUR*************/

#include "labyrinthe_io.h"
#include "utilitaires.h"

/*** CONSTANTES ***/

#define FFLUSH() do{} while (getchar()!='\n')

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

int selection_menu(int grille_chargee)
{
    int option;

    //si la grille n'a pas encore été charger, ne peut saisir que l'option 1 ou 4
    if(!grille_chargee)
    {
        printf("******************************************************************************\n"
               "\n"
               "                             MENU LABYRINTHE\n"
               "\n"
               "******************************************************************************\n");
        printf("1- Charger un labyrinthe\n"
                      "2- [INDISPONIBLE] Resoudre le labyrinthe\n"
                      "3- [INDISPONIBLE] Resoudre le labyrinthe pas-a-pas\n"
                      "4- Quitter le programme\n\n>");

        //l'utilisateur peut saisir une option seulement dans celle dipsponibles
        do
        {
            scanf("%i",&option);

            if(option==2 || option==3 || option<1 || option>4)
            {
                printf("Choix invalide !\n");
            }

        }while(option!=1 && option!=4);
    }

    //lorsque la grille à été charger, l'utilisateur peut saisir toutes les options dans le menu
    else if(grille_chargee)
    {
        printf("******************************************************************************\n"
               "\n"
               "                             MENU LABYRINTHE\n"
               "\n"
               "******************************************************************************\n");
        printf("1- Charger un labyrinthe\n"
                      "2- Resoudre le labyrinthe\n"
                      "3- Resoudre le labyrinthe pas-a-pas\n"
                      "4- Quitter le programme\n\n>");
        do
        {
            scanf("%i", &option);
            if(option<1 || option>4)
            {
                printf("Choix invalide !\n");
            }
        }while(option<1 || option>4);
    }

    return option;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    //demande à l'usager de saisir un nom de fichier
    printf("Nom du fichier:\n");

    FFLUSH();
    fgets(buf_nom_fichier,buf_taille,stdin);
    buf_nom_fichier[strlen((buf_nom_fichier))-1] = '\0';
}
