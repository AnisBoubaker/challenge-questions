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
        printf("le fichier n'a pas ete ouvert\n");  // j'ai rajouter ca a la fonction du prof.
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

    //verifier si une grille est charger
    if(grille_chargee)
    {
        //Creer le menu principal du programme
        printf("****** Menu Principal ******\n\n");
        printf("1. Charger le labyrithe\n");
        printf("2. Resoudre le labyrithe\n");
        printf("3. Resoudre le labyrithe etape par etape\n");
        printf("4. Quitter\n\n");

        //Demander a l'utilisateur son choix
        printf("Veuillez saisir votre choix:");
        scanf("%d", &choix);
        printf("\n");

        while(choix < 1 || choix > 4)
        {
            printf("Saisie invalide. Veuillez faire un different choix: ");
            scanf("%d", &choix);
            printf("\n");
        }
    }
    else
    {
        printf("Veuillez charger votre grille.\n");

        //Creer le menu principal du programme lorsqu'il n'y a pas de grille chargee
        printf("****** Menu Principal ******\n\n");
        printf("1. Charger le labyrithe\n");
        printf("2. [Indisponible] Resoudre le labyrithe\n");
        printf("3. [Indisponible] Resoudre le labyrithe etape par etape\n");
        printf("4. Quitter\n\n");

        //Demander a l'utilisateur son choix
        printf("Veuillez saisir votre choix:");
        scanf("%d", &choix);
        printf("\n");

        while(!(choix== 1 || choix == 4))
        {
            printf("Saisie invalide. Veuillez faire un different choix: ");
            scanf("%d", &choix);
            printf("\n");
        }
    }
    return choix;
}


void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    //stocker dans buf_nom_ficher le nom de la grille que l'utilisateur veut charger.
    printf("Veuillez saisir le nom de la grille que vous souhaitez charger: ");
    FFLUSH());
    fgets(buf_nom_fichier, buf_taille, stdin);

    //aller stocker la taille de buf_nom_fichier dans taille
    buf_taille = strlen(buf_nom_fichier);

    // permets d'enlever la saisie ''Enter'' a la fin de la chaine (saut de ligne)
    buf_nom_fichier[buf_taille - 1] = '\0';
}
