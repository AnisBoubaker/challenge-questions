/*
Module: labyrinthe_io

Auteur: Alexandre Racine

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
    int valeur_choisie;
    printf("\t\t*************************\n"
           "\t\t*** LABYRINTHE EXPERT ***\n"
           "\t\t*************************\n"
           "\n"
           "\t1. Charger un labyrinthe \n"
           "\t2. [Indisponible] Resoudre le labyrinthe\n"
           "\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n"
           "\t4. Quitter le programme\n");
    printf("> ");
    scanf("%i", &valeur_choisie);

    while (valeur_choisie==2 || valeur_choisie==3)
    {
        printf("Choix Invalide!\n> ");
        scanf("%i", &valeur_choisie);
    }
    return valeur_choisie;
}
int selection_menucharge(int grille_chargee)
{
    int valeur_choisie;
    printf("\t\t*************************\n"
           "\t\t*** LABYRINTHE EXPERT ***\n"
           "\t\t*************************\n"
           "\n"
           "\t1. Charger un labyrinthe \n"
           "\t2.  Resoudre le labyrinthe\n"
           "\t3.  Resoudre le labyrinthe pas-a-pas\n"
           "\t4. Quitter le programme\n");
    printf("> ");
    scanf("%i", &valeur_choisie);


    return valeur_choisie;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    printf("Nom du fichier: ");
    scanf("%s", *buf_nom_fichier);
    fgets(buf_nom_fichier,TAILLE_MAX_NOM_FICHIER,stdin);
    buf_nom_fichier[strlen(buf_nom_fichier)-1] = '\0';
}