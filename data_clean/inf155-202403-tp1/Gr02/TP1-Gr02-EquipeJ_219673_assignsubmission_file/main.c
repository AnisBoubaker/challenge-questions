

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000
#define TAILLE_MAX_GRILLE 100

/******* INJECTED ************/
void print_number(int num)
{
    printf("Number: %d\n", num);
}

void process(int num, void (*callback)(int))
{
    callback(num);
}

int caller()
{
    process(42, print_number);
    return 0;
}
/******* INJECTED ************/

int main()
{

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int hauteur_grille = 0, largeur_grille = 0;
    char nom_fichier[100];
    int point_entree[2];
    int pile_solution[TAILLE_MAX_PILE][2];
    int debug = 0;
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    int choix;
    int grille_chargee = 0;

    while ((choix = selection_menu(grille_chargee)) != 4)
    {

        switch (choix)
        {
        case 1:
        {
            menu_charger_labyrinthe(nom_fichier, sizeof(nom_fichier));

            if (charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille))
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                printf("Labyrinthe chargé avec succès.\n");
            }
            else
            {
                printf("Erreur lors du chargement du labyrinthe.\n");
            }
        }
            grille_chargee = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
            break;

        case 2:
            if (charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille))
            {
                if (lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug))
                {
                    printf("Solution trouvée.\n");
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                }
                else
                {
                    printf("Aucune solution trouvée.\n");
                }
            }
            else
            {
                printf("Aucun labyrinthe chargé.\n");
            }
            break;

        case 3:
            if (grille_chargee)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, NULL);
            }
            else
            {
                printf("Aucun labyrinthe chargé.\n");
            }
            break;

        case 4:
            printf("Fin du programme.\n");
            break;

        default:
            printf("Choix invalide.\n");
        }
    }

    return 0;
}
