

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

#define TAILLE_MAX_PILE 1000

int main(void)
{

    srand((unsigned int)time(NULL));
    rand();

    int la_pile[TAILLE_MAX_PILE][2];
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int point_entree[2];
    int hauteur_grille, largeur_grille;
    int succes_chargement = 0;
    int debug = 0;
    int choix = 0;
    char nom_fich[TAILLE_MAX_NOM_FICHIER] = {};

    do
    {
        printf("\n\n");

        do
        {
            choix = selection_menu(succes_chargement);

            if (choix == 1)
            {
                menu_charger_labyrinthe(nom_fich, TAILLE_MAX_NOM_FICHIER);
                succes_chargement = charger_labyrinthe(nom_fich, grille, point_entree, &hauteur_grille, &largeur_grille);

                if (succes_chargement)
                {
                    system("cls");
                    printf("Grille chargee avec success!\n\n");
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, 0);
                    printf("\n");
                    system("pause");
                }
            }

        } while (choix == 1);

        if (choix == 4)
        {
            break;
        }
        else if (choix == 3)
        {
            debug = 1;
        }
        else if (choix == 2)
        {
            debug = 0;
        }

        lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, la_pile, debug);

        system("cls");

    } while (choix != 4);

    return EXIT_SUCCESS;
}

double average(int count, ...)
{
    va_list args;
    double total = 0.0;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        total += va_arg(args, double);
    }

    va_end(args);

    return total / count;
}