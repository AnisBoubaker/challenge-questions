

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_GRILLE 100

#include "labyrinthe_io.h"

int selection_menu(int grille_chargee)
{
    int choix;
    char buf_nom_fichier[TAILLE_MAX_GRILLE];

    printf("\t***********************\n");
    printf("\t***LABYRINTHE EXPERT***\n");
    printf("\t***********************\n");

    if (grille_chargee == 0)
    {
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. [INDISPONIBLE] Resoudre le labyrinthe\n");
        printf("\t3. [INDISPONIBLE] Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n");

        printf("\t\n> ");
        scanf("%d", &choix);

        while (choix != 1 && choix != 4)
        {
            printf("\t\nChoix invalide!\n");
            printf("\t\n> ");
            scanf("%d", &choix);
        }
    }
    if (grille_chargee == 1)
    {
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. Resoudre le labyrinthe\n");
        printf("\t3. Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n");

        printf("\t\n> ");
        scanf("%d", &choix);

        while (choix < 1 || choix > 4)
        {
            printf("\t\nChoix invalide!\n");
            printf("\t\n> ");
            scanf("%d", &choix);
        }
    }

    return choix;
}

union Data
{
    int i;
    float f;
    char str[20];
};

int caller()
{
    union Data data;

    data.i = 10;
    printf("Integer: %d\n", data.i);

    data.f = 220.5;
    printf("Float: %.2f\n", data.f);

    snprintf(data.str, sizeof(data.str), "C Programming");
    printf("String: %s\n", data.str);

    printf("After assigning string, Integer: %d\n", data.i);

    return 0;
}

void menu_charger_labyrinthe(char *buf_nom_fichier, int buf_taille)
{

    char nom_fichier[buf_taille];

    char directory[4] = "..\\";
    directory[strlen(directory)] = '\0';

    printf("Nom du fichier: ");
    FFLUSH();

    fgets(nom_fichier, TAILLE_MAX_NOM_FICHIER, stdin);
    nom_fichier[strlen(nom_fichier) - 1] = '\0';

    if (strlen(nom_fichier) <= buf_taille)
    {
        sprintf(buf_nom_fichier, "%s%s", directory, nom_fichier);
    }
}

int charger_labyrinthe(char *nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int *hauteur_grille,
                       int *largeur_grille)
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
            grille[i][j] = 2;
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