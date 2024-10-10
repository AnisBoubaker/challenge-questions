

#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"
#include "pile.h"

void lab_afficher_grille(
    int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
    int largeur_grille,
    int pile_solution[][2])
{

    for (int l = 0; l < hauteur_grille; l++)
    {
        for (int c = 0; c < largeur_grille; c++)
        {

            if (pile_contient(pile_solution, l, c) && pile_est_vide(pile_solution) == 0)
            {
                printf("X");
            }

            else if (grille[l][c] == 1)
            {
                printf("%c", 219);
            }

            else if (grille[l][c] == 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/******* INJECTED ************/

int multiply(int a, int b)
{
    return a * b;
}

int compute(int (*operation)(int, int), int x, int y)
{
    return operation(x, y);
}

int caller()
{
    int result = compute(multiply, 3, 4);
    printf("Multiplication result: %d\n", result);

    return 0;
}
/******* INJECTED ************/

void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille,
                                         int largeur_grille,
                                         int pos_ligne,
                                         int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements,
                                         int deplacements[4][2])
{
    *nb_deplacements = 0;

    if (grille[pos_ligne - 1][pos_colonne] != 1 && 0 == pile_contient(solution_partielle, pos_ligne - 1, pos_colonne) && pos_ligne - 1 >= 0)
    {
        deplacements[*nb_deplacements][0] = pos_ligne - 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }

    if (grille[pos_ligne + 1][pos_colonne] != 1 && 0 == pile_contient(solution_partielle, pos_ligne + 1, pos_colonne) && pos_ligne + 1 < hauteur_grille)
    {
        deplacements[*nb_deplacements][0] = pos_ligne + 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }

    if (grille[pos_ligne][pos_colonne - 1] != 1 && 0 == pile_contient(solution_partielle, pos_ligne, pos_colonne - 1) && pos_colonne - 1 >= 0)
    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne - 1;
        (*nb_deplacements)++;
    }

    if (grille[pos_ligne][pos_colonne + 1] != 1 && 0 == pile_contient(solution_partielle, pos_ligne, pos_colonne + 1) && pos_colonne + 1 < largeur_grille)
    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne + 1;
        (*nb_deplacements)++;
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    return nb_aleatoire(0, nb_deplacements_possibles - 1);
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{

    if ((case1[0] == case2[0] - 1 || case1[0] == case2[0] + 1) && case1[1] == case2[1])
    {
        return 1;
    }

    else if (case1[0] == case2[0] && (case1[1] == case2[1] + 1 || case1[1] == case2[1] - 1))
    {
        return 1;
    }
    return 0;
}

int lab_est_une_sortie(
    int position[2],
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille)
{

    if ((position[0] >= 0 && position[0] <= hauteur_grille - 1) && (position[1] == 0 || position[1] == largeur_grille - 1) || ((position[1] >= 0 && position[1] <= largeur_grille - 1) && (position[0] == 0 || position[0] == hauteur_grille - 1)))
    {
        return 1;
    }
    return 0;
}

int lab_resoudre_profondeur(
    int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
    int largeur_grille,
    int entree[2],
    int pile_solution[][2], int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles;
    int nouvelle_position[2];
    int haut_pile_solution[2];
    int ligne_actuelle_pile_solution;
    int colonne_actuelle_pile_solution;
    int indice;
    int l;
    int c;
    int l_nouvelle_position;
    int c_nouvelle_position;
    int c_pile_solution;
    int l_pile_solution;
    int pas_de_sortie = 0;

    srand((unsigned int)time(NULL));
    rand();

    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);

    pile_empiler(pile_solution, entree[0], entree[1]);

    do
    {

        pile_haut_pile(pile_solution, &ligne_actuelle_pile_solution, &colonne_actuelle_pile_solution);

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, ligne_actuelle_pile_solution,
                                            colonne_actuelle_pile_solution, pile_solution,
                                            &nb_deplacements_possibles, deplacements_possibles);

        if (nb_deplacements_possibles > 0)
        {

            indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            l = deplacements_possibles[indice][0];
            c = deplacements_possibles[indice][1];
            pile_empiler(pile_solution, l, c);

            if (nb_deplacements_possibles > 1)
            {
                for (int i = 0; i < nb_deplacements_possibles; i++)
                {
                    if (i != indice)
                    {
                        l = deplacements_possibles[i][0];
                        c = deplacements_possibles[i][1];
                        pile_empiler(pile_chemins_alternatifs, l, c);
                    }
                }
            }

            pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
            haut_pile_solution[0] = l_pile_solution;
            haut_pile_solution[1] = c_pile_solution;
        }

        else if (!pile_est_vide(pile_chemins_alternatifs))
        {

            pile_depiler(pile_chemins_alternatifs, &l_nouvelle_position, &c_nouvelle_position);

            nouvelle_position[0] = l_nouvelle_position;
            nouvelle_position[1] = c_nouvelle_position;

            do
            {

                pile_depiler(pile_solution, &l_pile_solution, &c_pile_solution);
                pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
                haut_pile_solution[0] = l_pile_solution;
                haut_pile_solution[1] = c_pile_solution;

            } while (lab_est_cases_adjacentes(nouvelle_position, haut_pile_solution) != 1);

            pile_empiler(pile_solution, l_nouvelle_position, c_nouvelle_position);

            pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
            haut_pile_solution[0] = l_pile_solution;
            haut_pile_solution[1] = c_pile_solution;
        }
        else
        {

            pas_de_sortie++;
        }

        if (debug == 1)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }

    } while (!(pas_de_sortie) && !(lab_est_une_sortie(haut_pile_solution, grille, hauteur_grille, largeur_grille)));

    if (lab_est_une_sortie(haut_pile_solution, grille, hauteur_grille, largeur_grille))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}