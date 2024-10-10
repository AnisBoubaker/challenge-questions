/*
Module: labyrinthe_io

Auteurs: Francis Gignac, Rachelle Sanscartier, Maxim St-Gelais, Abraham Suarez-Santizo

Date:2023-11-12
*/

/***********COMMANDES PR�PROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include "labyrinthe_io.h"
#include <stdlib.h>
#include <stdio.h>

/*******IMPLEMENTATION DES FONCTIONS***********/
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int* hauteur_grille, int* largeur_grille)
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

    //Initialisation des pointeurs
    *largeur_grille = -1;
    *hauteur_grille = -1;

    while ((caractere_lu = getc(fichier)) != EOF)
    {
        switch (caractere_lu)
        {
            //Positionnement des murs
            case '*':
                grille[i][j] = 1;
                j++;
                break;

            //Positionnement des couloirs
            case ' ':
                grille[i][j] = 0;
                j++;
                break;

            //Positionnement de l'entrée du labyrinthe
            case 'E':
                grille[i][j] = 0;
                point_entree[0] = i;//Numéro de ligne
                point_entree[1] = j;//Numéro de colonne
                j++;
                break;

            //Changement de ligne dans le tableau
            case '\n':
                if (*largeur_grille != -1 && *largeur_grille != j)
                {
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

    int choix_utilisateur = 0; /* Permet de choisir un choix dans le menu. */

    /* Permet f'afficher le titre du programme. */
    printf("********************\n");
    printf("**   Labyrinthe   **\n");
    printf("********************\n");

    /* Lorsque la grille n'est pas chargé dans le système. */
    if (grille_chargee == 0)
    {
        // Menu lorsqu'il n'y a pas de grille chargée.
        printf("Veuillez choisir une des options suivantes:\n");
        printf("1) Charger un labyrinthe\n");
        printf("2) Resoudre un labyrinthe [INDISPONIBLE]\n");
        printf("3) Resoudre un labyrinthe pas-a-pas [INDISPONIBLE]\n");
        printf("4) Quitter le programme\n");
        printf("Votre choix: ");
        scanf("%d", &choix_utilisateur);

        /* Boucle continue lorsque l'utilisateur choisis 2 et trois sans grille chargée. */
        while ((choix_utilisateur == 2) || (choix_utilisateur == 3))
        {
            printf("Ce choix est invalide, veuillez reesayer\n");
            printf("Votre choix: ");
            scanf("%d", &choix_utilisateur);
        }
        if (choix_utilisateur == 1)
        {
            return 1;
        }

        /* Si l'utilisateur veut quitter, ça met fin au programme. */
        if (choix_utilisateur == 4)
        {
            return 4;
        }

    }

    /* Lorsqu'une grille valide est chargée dans le système. */
    if (grille_chargee != 0)
    {
        /* Menu de choix lorsque une grille est chargé. */
        printf("Veuillez choisir une des options suivantes:\n");
        printf("1) Charger un labyrinthe\n");
        printf("2) Resoudre un labyrinthe\n");
        printf("3) Resoudre un labyrinthe pas-a-pas\n");
        printf("4) Quitter le programme\n");
        printf("Votre choix: ");
        scanf("%d", &choix_utilisateur);

        /* Si l'utilisateur veut charger une grille. */
        if (choix_utilisateur == 1)
        {
            return 1;
        }

        /* Si l'utilisateur veut résoudre un labyrinthe. */
        if (choix_utilisateur == 2)
        {
            return 2;
        }

        /* Si l'utilisateur veut résoudre un labyrinthe pas à pas. */
        if (choix_utilisateur == 3)
        {
            return 3;
        }

        /* Si l'utilisateur veut quitter le programme. */
        if (choix_utilisateur == 4)
        {
            return 4;
        }
    }
}


void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    /* On efface le tampon d'entrée (stdin). On demande le nom du fichier
       à l'utilisateur et on met le nom du fichier dans buf_nom_fichier.
    */
    fflush(stdin);
    printf("Veuillez saisir le nom du fichier: ");
    fgets(buf_nom_fichier,buf_taille, stdin);
    buf_nom_fichier[strlen(buf_nom_fichier)-1] = '\0';
}