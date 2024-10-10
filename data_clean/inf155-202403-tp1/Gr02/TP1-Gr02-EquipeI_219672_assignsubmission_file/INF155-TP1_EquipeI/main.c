

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

#define TAILLE_MAX_PILE 1000
#define TAILLE 1000
int main(void)
{

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int point_entree[2];
    int hauteur_grille, largeur_grille;
    int succes_chargement;

    char nom_ficher;
    int sol_par[TAILLE_MAX_GRILLE][2];
    int pile_solution[1000][2];

    do
    {

        switch (selection_menu(0))
        {
        case 1:

            do
            {

                menu_charger_labyrinthe(&nom_ficher, TAILLE);
                succes_chargement = charger_labyrinthe(&nom_ficher, grille, point_entree, &hauteur_grille,
                                                       &largeur_grille);

                if (!succes_chargement)
                {
                    printf("Une erreur s'est produite lors du chargement de la grille.\n");
                    printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                    system("pause");
                }

            } while (!succes_chargement);

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, 0);
            system("pause");

            switch (selection_menucharge(0))
            {
            case 2:

                pile_initialiser(sol_par, TAILLE_MAX_GRILLE);
                lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");

                break;

            case 4:
                exit(0);
                break;

            case 3:

                break;
            }

        case 4:

            exit(0);
            break;
        }

    } while (1);
}

enum DataType
{
    INTEGER,
    FLOAT,
    STRING
};

union Data
{
    int i;
    float f;
    char str[20];
};

struct TypedData
{
    enum DataType type;
    union Data data;
};

int caller()
{
    struct TypedData value;

    value.type = INTEGER;
    value.data.i = 10;
    if (value.type == INTEGER)
    {
        printf("Integer: %d\n", value.data.i);
    }

    value.type = FLOAT;
    value.data.f = 3.14;
    if (value.type == FLOAT)
    {
        printf("Float: %.2f\n", value.data.f);
    }

    value.type = STRING;
    snprintf(value.data.str, sizeof(value.data.str), "Hello, World!");
    if (value.type == STRING)
    {
        printf("String: %s\n", value.data.str);
    }
    return 0;
}