

#include "labyrinthe.h"
#define TAILLE_MAX_GRILLE 100

void lab_afficher_grille(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pile_solution[][2])
{
    char etoile = '*';
    int ligne;
    int colonne;
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if (grille[i][j] == 1)
            {
                printf(" %c ", etoile);
            }
            else if (pile_est_vide(pile_solution) == 0)
            {
                if (pile_contient(pile_solution, i, j) == 1)
                {
                    printf(" X ");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void *custom_malloc(size_t size)
{
    size_t total_allocated = 0;
    void *ptr = malloc(size);
    if (ptr)
    {
        total_allocated += size;
        printf("Allocated %zu bytes, Total Allocated: %zu bytes\n", size, total_allocated);
    }
    return ptr;
}

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

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {

            int case1[2] = {i, j};
            int case2[2] = {pos_ligne, pos_colonne};

            if (lab_est_cases_adjacentes(case1, case2) == 1)
            {
                if (pile_contient(solution_partielle, i, j) == 0)
                {
                    if (grille[i][j] == 1)
                    {
                    }
                    if (grille[i][j] == 0)
                    {
                        pile_empiler(deplacements, i, j);
                        (*nb_deplacements)++;
                    }
                }
                else if (pile_contient(solution_partielle, i, j) == 1)

                {
                }
            }
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{

    int indice;
    int mn = 1;
    int mx = nb_deplacements_possibles;
    int nb_indices = pile_taille_pile(deplacements_possibles);

    indice = nb_aleatoire(mn, mx);

    while (0 > indice || indice > nb_indices)
    {
        nb_aleatoire(mn, mx);
    }

    return indice;
}

int lab_est_une_sortie(
    int position[2],
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille)
{

    int x = position[0];
    int y = position[1];

    if (x == 0 || x == hauteur_grille - 1 || y == 0 || y == largeur_grille - 1)
    {

        if (grille[x][y] != 0)
        {

            printf("%d, %d est une sortie !", position[0], position[1]);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    if (case1[0] == case2[0] || case1[1] == case2[1])
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int lab_resoudre_profondeur(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int entree[2],
    int pile_solution[][2],
    int debug)

{
    int pile_chemin_alt[][2] = {};

    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);
    pile_initialiser(pile_chemin_alt, TAILLE_MAX_GRILLE);

    pile_empiler(pile_solution, entree[0], entree[1]);

    int solutionTF = 0;
    int pos_ligne;
    int pos_colonne;
    int nb_deplacements;
    int deplacements_possibles[4][2];
    int nouvelle_position[2];
    int case_adj = 0;
    int poubelle[2];
    int haut_pile_sol[2];

    while (solutionTF == 0 && pile_est_vide(pile_chemin_alt) && nb_deplacements != 0)
    {
        debug = 0;

        pile_initialiser(deplacements_possibles, 4);
        pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pos_ligne, pos_colonne, pile_solution, &nb_deplacements, &deplacements_possibles);

        if (nb_deplacements > 0)
        {
            int indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements);
            pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]);
            for (int i = 0; i <= nb_deplacements; i++)
            {
                if (i != indice)
                {
                    pile_empiler(pile_chemin_alt, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                    debug = 1;
                }
            }

            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                debug = 0;
            }
        }
        else if (pile_est_vide(pile_chemin_alt) == 0)
        {
            debug = 0;
            pile_depiler(pile_chemin_alt, &nouvelle_position[0], &nouvelle_position[1]);
            pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]);
            case_adj = lab_est_cases_adjacentes(haut_pile_sol, nouvelle_position);

            while (case_adj == 0)
            {
                pile_depiler(pile_solution, &poubelle[0], &poubelle[1]);
                pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]);

                case_adj = lab_est_cases_adjacentes(nouvelle_position, haut_pile_sol);
            }
            if (case_adj == 1)
            {

                pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);
                debug = 1;
            }
            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                debug = 0;
            }
        }
        pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]);
        solutionTF = (lab_est_une_sortie(haut_pile_sol, grille, hauteur_grille, largeur_grille));

        if (solutionTF == 1)
        {
            return 1;
        }
        if (solutionTF == 0 && nb_deplacements == 0 && pile_est_vide(pile_chemin_alt) == 0)
        {
            return 0;
        }
    }
}
