

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

int main()
{

    int sortie = 0;

    int choix_menu = -1;

    int grille_chargee = 0;

    int debug = 0;

    int est_resolu = 0;

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];

    int point_entree[2];

    int hauteur_grille, largeur_grille;

    int pile_solution[TAILLE_MAX_PILE][2];

    char nom_fichier[TAILLE_MAX_NOM_FICHIER];

    srand((unsigned int)time(NULL));

    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

    do
    {
        choix_menu = selection_menu(grille_chargee);

        switch (choix_menu)
        {

        case 1:
            menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
            grille_chargee = charger_labyrinthe(nom_fichier, grille, point_entree,
                                                &hauteur_grille, &largeur_grille);
            if (grille_chargee)
            {

                system("cls");

                printf("Grille chargee avec succes:\n");

                lab_afficher_grille(grille, hauteur_grille,
                                    largeur_grille, pile_solution);
                system("pause");
            }
            else
            {

                printf("Erreur lors du chargement de la grille.\n");
                system("pause");
            }

            system("cls");
            break;

        case 2:
            est_resolu = lab_resoudre_profondeur(grille, hauteur_grille,
                                                 largeur_grille, point_entree,
                                                 pile_solution, debug);
            if (!est_resolu)
                printf("La solution a ete trouvee :-)\n");
            else
                printf("Aucune solution trouvee :-(\n");
            break;
        case 3:
            debug = 1;
            est_resolu = lab_resoudre_profondeur(grille, hauteur_grille,
                                                 largeur_grille, point_entree,
                                                 pile_solution, debug);
            if (est_resolu)
                system("cls");
            break;
        case 4:
            sortie = 1;
        }
    } while (!sortie);
    return EXIT_SUCCESS;
}

int compare(void *a, void *b, size_t size)
{
    return memcmp(a, b, size);
}