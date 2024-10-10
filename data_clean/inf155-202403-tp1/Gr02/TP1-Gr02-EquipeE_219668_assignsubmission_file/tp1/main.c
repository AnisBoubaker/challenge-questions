

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define POOL_SIZE 1024

typedef struct
{
    unsigned char pool[POOL_SIZE];
    size_t offset;
} MemoryPool;

void init_pool(MemoryPool *pool)
{
    pool->offset = 0;
}

int main(void)
{

    srand(time(NULL));

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int point_entree[2];
    int hauteur_grille, largeur_grille;
    int choix;
    int grille_charger = 0;

    char nom_du_fichier[TAILLE_MAX_GRILLE];
    int taille_du_fichier;

    int succes_lab;
    int pile_solution[TAILLE_MAX_PILE][2];

    choix = selection_menu(grille_charger);
    if (choix == 4)
    {
        printf("Vous avez quitte\n");
        exit(EXIT_FAILURE);
    }
    if (choix == 1)
    {
        menu_charger_labyrinthe(nom_du_fichier, sizeof(nom_du_fichier));
    }

    grille_charger = charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

    printf("Press any key to continue...\n");
    getchar();

    choix = selection_menu(grille_charger);

    if (choix == 1)
    {
        while (choix == 1)
        {
            printf("Vous avez deja chargee une grille, veuillez choisir une differente option : ");
            scanf("%d", &choix);
        }
    }
    if (choix == 2)
    {
        if (lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0))
        {

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            printf("Press any key to continue...\n");
            getchar();
        }
        else
        {
            printf("le labyrinthe n'a pas ete resolu");
        }

        charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    }
    if (choix == 3)
    {
        if (lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0))
        {

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
        }
        else
        {
            printf("le labyrinthe n'a pas ete resolu");
        }

        charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    }
    if (choix == 4)
    {
        printf("Vous avez quitte\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
