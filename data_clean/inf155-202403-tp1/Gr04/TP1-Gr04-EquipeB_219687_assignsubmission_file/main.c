 


#include "labyrinthe.h"
#include "labyrinthe_io.h"


int main(void)
{
    int grille_chargee = 0;
    char buf_nom_fichier[TAILLE_MAX_NOM_FICHIER];
    int choix;

    int solution;

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int point_entree[2];
    int hauteur, largeur;
    int pile_solution[TAILLE_MAX_PILE][2];

    do
    {
        choix = selection_menu(grille_chargee);
        if (choix == 1)
        {
            menu_charger_labyrinthe(buf_nom_fichier, TAILLE_MAX_NOM_FICHIER);

            grille_chargee = charger_labyrinthe(buf_nom_fichier, grille, point_entree,
                               &hauteur, &largeur);
            if (grille_chargee == 0)
            {
                printf("\033[0;31m");
                printf("\nErreur - (Le chargement de la grille n'a pas ete effectue, pour eviter un malfonctionnement"
                       "il est conseille de quitter et de relancer le programme)\n\n");
                printf("\033[0m");
            }
        }
        else if (choix == 2)
        {
            lab_afficher_grille(grille, hauteur, largeur, pile_solution);
        }
        else if (choix == 3)
        {
            solution = lab_resoudre_profondeur(grille, hauteur, largeur,
                                    point_entree, pile_solution, 0);
            if (solution == 1)
                printf("Le labyrinthe a ete resolu!");
            else
                printf("Le labyrinthe n'a pas de solution.");
        }
        else if (choix == 4)
        {
            lab_resoudre_profondeur(grille, hauteur, largeur, point_entree, pile_solution, 1);
        }
    } while (choix != 5);

    return EXIT_SUCCESS;
}
