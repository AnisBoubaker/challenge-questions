

#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if (grille[i][j] == 1)
            {

                printf("%c", 219);
            }

            else if (pile_contient(pile_solution, i, j))
            {
                printf("X");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,
                                         int pos_ligne, int pos_colonne, int solution_partielle[][2],
                                         int *nb_deplacements, int deplacements[4][2])
{
    pile_initialiser(deplacements, 4);
    *nb_deplacements = 0;

    if ((pos_ligne - 1 >= 0) && (grille[pos_ligne - 1][pos_colonne] == 0) && (!pile_contient(solution_partielle, pos_ligne - 1, pos_colonne)))

    {
        deplacements[*nb_deplacements][0] = pos_ligne - 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }

    if ((pos_ligne + 1 < hauteur_grille) &&
        (grille[pos_ligne + 1][pos_colonne] == 0) &&
        (!pile_contient(solution_partielle, pos_ligne + 1, pos_colonne)))

    {
        deplacements[*nb_deplacements][0] = pos_ligne + 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }

    if ((pos_colonne - 1 >= 0) &&
        (grille[pos_ligne][pos_colonne - 1] == 0) &&
        (!pile_contient(solution_partielle, pos_ligne, pos_colonne - 1)))

    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne - 1;
        (*nb_deplacements)++;
    }

    if ((pos_colonne + 1 < largeur_grille) &&
        (grille[pos_ligne][pos_colonne + 1] == 0) &&
        (!pile_contient(solution_partielle, pos_ligne, pos_colonne + 1)))

    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne + 1;
        (*nb_deplacements)++;
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    int choix_aleatoire;
    int debug = 0;

    choix_aleatoire = nb_aleatoire(0, (nb_deplacements_possibles)-1);

    if (debug)
    {
        printf("Choix aleatoire : %i\n", choix_aleatoire);
    }

    return choix_aleatoire;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int debug = 0;

    if (((case1[0] == case2[0] || case1[0] + 1 == case2[0] || case1[0] - 1 == case2[0]) &&
         (case1[1] == case2[1] || case1[1] + 1 == case2[1] || case1[1] - 1 == case2[1])) &&
        ((case1[0] == case2[0] && case1[1] != case2[1]) || (case1[0] != case2[0] && case1[1] == case2[1])))
    {
        if (debug == 1)
        {
            printf("Les cases (%i,%i) et (%i,%i) sont adjacentes\n", case1[0], case1[1], case2[0], case2[1]);
        }
        return 1;
    }

    else
    {
        if (debug == 1)
        {
            printf("Les cases (%i,%i) et (%i,%i) ne sont pas adjacentes\n", case1[0], case1[1], case2[0], case2[1]);
        }
        return 0;
    }
}

int add(int a, int b)
{
    return a + b;
}

int caller()
{
    int (*func_ptr)(int, int) = add;

    int result = func_ptr(5, 10);

    return 0;
}

int lab_est_une_sortie(const int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{

    int val_pos_grille = grille[position[0]][position[1]];

    return ((position[0] == (hauteur_grille - 1) || (position[0] == 0) || ((position[1] == ((largeur_grille - 1))) || (position[1] == 0)))) && (val_pos_grille != 2)
               ? 1
               : 0;
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int pas_a_pas, int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2];
    int val_ligne, val_col;

    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);

    pile_empiler(pile_solution, entree[0], entree[1]);
    pile_haut_pile(pile_solution, &val_ligne, &val_col);
    if (debug)
    {
        printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
    }

    while (!pile_est_vide(pile_solution))
    {
        if (pas_a_pas != 0)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            systemPause();
        }

        int nb_deplacements;
        int deplacements[4][2];
        int nouvelle_position[2];

        int position_actuelle[2] = {pile_solution[pile_solution[0][1]][0], pile_solution[pile_solution[0][1]][1]};
        if (debug)
        {
            printf("Position actuelle : (%i,%i)\n", position_actuelle[0], position_actuelle[1]);
        }

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, position_actuelle[0], position_actuelle[1], pile_solution, &nb_deplacements, deplacements);

        if (debug)
        {
            printf("Deplacements possibles (%i):\n", nb_deplacements);
            for (int i = 0; i < nb_deplacements; i++)
            {
                printf("%i(%i,%i)\n", i, deplacements[i][0], deplacements[i][1]);
            }
        }

        if (nb_deplacements > 0)
        {
            int index_choisi = lab_choisir_deplacement(deplacements, nb_deplacements);

            nouvelle_position[0] = deplacements[index_choisi][0];
            nouvelle_position[1] = deplacements[index_choisi][1];

            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            for (int i = 0; i < nb_deplacements; i++)
            {
                if (i != index_choisi)
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements[i][0], deplacements[i][1]);
                }
            }

            if (debug)
            {
                pile_haut_pile(pile_solution, &val_ligne, &val_col);
                printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }

        else if ((nb_deplacements == 0) && (!pile_est_vide(pile_chemins_alternatifs)))
        {

            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0], &nouvelle_position[1]);
            if (debug)
            {
                printf("On cherche la case : (%i,%i)\n", nouvelle_position[0], nouvelle_position[1]);
            }

            while (!pile_est_vide(pile_solution) && !lab_est_cases_adjacentes(position_actuelle, nouvelle_position))
            {
                int dummy1, dummy2;
                pile_depiler(pile_solution, &dummy1, &dummy2);
                pile_haut_pile(pile_solution, &position_actuelle[0], &position_actuelle[1]);

                if (debug)
                {
                    pile_haut_pile(pile_solution, &val_ligne, &val_col);
                    printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                }
            }

            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            if (debug)
            {
                pile_haut_pile(pile_solution, &val_ligne, &val_col);
                printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }

        else if (pile_est_vide(pile_chemins_alternatifs))
        {
            return 0;
        }

        if (lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille))
        {
            return 1;
        }
    }

    return 0;
}