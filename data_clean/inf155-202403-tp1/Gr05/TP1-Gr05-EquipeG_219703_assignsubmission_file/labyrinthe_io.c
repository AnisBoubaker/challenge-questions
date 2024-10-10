 

 
#define _CRT_SECURE_NO_WARNINGS
#include "labyrinthe_io.h"
#include <stdlib.h>
#include <stdio.h>

 
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
    FILE* fichier;
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

    int choix_utilisateur = 0;  

     
    printf("********************\n");
    printf("**   Labyrinthe   **\n");
    printf("********************\n");

     
    if (grille_chargee == 0)
    {
         
        printf("Veuillez choisir une des options suivantes:\n");
        printf("1) Charger un labyrinthe\n");
        printf("2) Resoudre un labyrinthe [INDISPONIBLE]\n");
        printf("3) Resoudre un labyrinthe pas-a-pas [INDISPONIBLE]\n");
        printf("4) Quitter le programme\n");
        printf("Votre choix: ");
        scanf("%d", &choix_utilisateur);

         
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

         
        if (choix_utilisateur == 4)
        {
            return 4;
        }

    }

     
    if (grille_chargee != 0)
    {
         
        printf("Veuillez choisir une des options suivantes:\n");
        printf("1) Charger un labyrinthe\n");
        printf("2) Resoudre un labyrinthe\n");
        printf("3) Resoudre un labyrinthe pas-a-pas\n");
        printf("4) Quitter le programme\n");
        printf("Votre choix: ");
        scanf("%d", &choix_utilisateur);

         
        if (choix_utilisateur == 1)
        {
            return 1;
        }

         
        if (choix_utilisateur == 2)
        {
            return 2;
        }

         
        if (choix_utilisateur == 3)
        {
            return 3;
        }

         
        if (choix_utilisateur == 4)
        {
            return 4;
        }
    }
}


void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
     
    fflush(stdin);
    printf("Veuillez saisir le nom du fichier: ");
    fgets(buf_nom_fichier,buf_taille, stdin);
    buf_nom_fichier[strlen(buf_nom_fichier)-1] = '\0';
}