/*
Module: labyrinthe_io

Description : Fournit l'ensemble des fonctions du menu et gere les interactions de l'usager avec le programme.

Auteur: Samy Mekkati, Daniel Atik, Jad Bizri

Date: 2023-11-12

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
    int choix; //Stock la decision de l'utilisateur

    //Affichage du titre lors de l'ouverture du menu

    printf("\t\t*************************\n");
    printf("\t\t*** LABYRINTHE EXPERT ***\n");
    printf("\t\t*************************\n\n");
    printf("\t1. Charger un labyrinthe\n");

    //Si aucune grille n'a été chargé, les options 2 et 3 sont indisponibles,
    //puisqu'on ne peut rien résoudre.
    if (grille_chargee == 0)
    {
        printf("\t2. [Indisponible] Resoudre le labyrinthe\n"
               "\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n"
               "\t4. Quitter le programme\n");

        scanf("%i", &choix);

        //Dans la situation ou aucune grille n'est chargé et que l'usager essaye le choix 2 ou 3,
        //un message d'erreur s'affiche, puisque aucune grille ne peut être résolue.
        while(choix != 1 && choix != 4)
        {
            printf("Choix Invalide !\n");
            scanf("%i", &choix);
        }

        //Le choix 4 permet de quitter le menu.
        if (choix==4)
        {
            exit(0);
        }
    }

        //Dans le cas inverse, si une grille a été chargé, les options 2 et 3 sont disponibles,
        //puisqu'on peut résoudre un labyrinthe chargé.
    else
    {
        printf("\t2. Resoudre le labyrinthe\n"
               "\t3. Resoudre le labyrinthe pas-a-pas\n"
               "\t4. Quitter le programme\n");
        scanf("%i", &choix);

        //Le choix 4 permet de quitter le menu.
        if (choix==4)
        {
            exit(0);
        }
    }
    //Return la decision que l'utilisateur a fait
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{

    char prefixe_grille[buf_taille]; //String qui contient le prefixe "../"
    char nom_grille[buf_taille]; //String qui contient le nom de la grille. Exemple "grille1.txt"


    //Stockage du préfixe " ../ "
    strncpy(prefixe_grille, "../",buf_taille);

    //Saisi du nom de la grille par l'usager
    printf("\n Nom de fichier : ");
    scanf("%s", nom_grille);

    //Liaison du préfixe " ../ " au nom de grille saisit pas l'usager
    //afin d'éviter que l'usager ai besoin de saisir le préfixe lui-même
    strncat(prefixe_grille,nom_grille,buf_taille);
    strncpy(buf_nom_fichier,prefixe_grille,buf_taille);
}

