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
        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
        system("pause");
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
                system("pause");
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

int selection_menu(int grille_chargee) {

    int choix = 0; // Le choix que l'utilisateur va faire

    system("cls"); // Pour clear le terminale

    /* Imprime le "Labyrinthe expert" avec les etoils en couleur*/
    printf("\033[0;31m"); //Set the text to the color red
    printf("\t\t****\033[0m*****************\033[0;31m****\n\t\t*** "
           "\033[0;41mLABYRINTHE EXPERT"
           "\033[0;31m ***\n\t\t****\033[0m*****************\033[0;31m****\n");
    printf("\033[0m"); //Resets the text to default color

    // Charge les choix que l'utilisateur peux faire
    printf("\t1. Charger un labyrinthe\n");
    // Si le labrinthe n'a pas encore ete charger, avertie l'utilisateur qu'il ne peux pas faire le choix 2 ou 3 qui est de resourdre le labyrinthe
    if(grille_chargee == 0) {
        printf("\t2. [Indisponible] Resoudre le labyrinthe \n\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
    }
    else{
        printf("\t2. Resoudre le labyrinthe \n\t3. Resoudre le labyrinthe pas-a-pas\n");
    }
    printf("\t4. Quitter le programme\n");

    // Ici qu'on demande a l'usager de rentrer ca reponse
    do {
        printf("\t>");
        scanf("%d", &choix);
        // Si un labyrinthe n'a pas ete charger, si l'usager choisi 2 ou 3 le choix va etre rinitialiser a 0, car le choix est invalide
        if(grille_chargee == 0) {
            if(choix == 2 || choix == 3) {
                choix = 0;
            }
        }
        // Si le choix est mauvais on affiche que le choix est invalide
        if(choix != 1 && choix != 2 && choix != 3 && choix != 4) {
            printf("Choix Invalide!\n");
        }
    // Si le choix est invalides on laisse une nouvelles chance a l'utilisateur de rentrer un choix valide
    } while(choix != 1 && choix != 2 && choix != 3 && choix != 4);
    // Retourne le choix valide que l'utilisateur a fait
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {

    // Le nom de la grille que l'utilisateur va rentrer (grille1.txt ou grille2.txt ect..)
    char fin_grille[TAILLE_MAX_NOM_FICHIER];

    // Ici on initie la phrase avec ../ pour acceder au ficher
    strncpy(buf_nom_fichier, "../", TAILLE_MAX_NOM_FICHIER);

    //On demande le nom du ficher a l'usager
    printf("Nom du ficher :");
    // On stock sa reponse dans fin_grille
    scanf("%s", fin_grille);
    //On colle la partie buf_nom_ficher a fin_grille et on le stock dans buf_nom_fichier
    strncat(buf_nom_fichier, fin_grille, TAILLE_MAX_NOM_FICHIER);

}