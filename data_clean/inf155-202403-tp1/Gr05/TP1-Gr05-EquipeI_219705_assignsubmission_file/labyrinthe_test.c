 

 
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_test.h"
#include "labyrinthe_io.h"
#include <assert.h>

 
void lab_afficher_grille_test(void)
{
     
    int pile_solution[TAILLE_MAX_PILE][2];
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
     
    int point_entree[2];
     
    int hauteur_grille, largeur_grille;

     
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

     
    pile_empiler(pile_solution, 0, 10);
    pile_empiler(pile_solution, 1, 10);
    pile_empiler(pile_solution, 1, 9);
    pile_empiler(pile_solution, 1, 8);
    pile_empiler(pile_solution, 1, 7);
    pile_empiler(pile_solution, 1, 11);
    pile_empiler(pile_solution, 6, 10);
    pile_empiler(pile_solution, 5, 10);
    pile_empiler(pile_solution, 5, 9);
    pile_empiler(pile_solution, 5, 11);


     
    printf("grille1.txt\n");
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");


     
    printf("grille2.txt\n");
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");


     
    printf("grille3.txt\n");
    charger_labyrinthe("grille3.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");

     
    printf("grille4.txt\n");
    charger_labyrinthe("grille4.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");
}


void lab_calculer_deplacements_possibles_test(void)
{
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int *nb_deplacements;
    int deplacements[4][2];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int m;
    int hauteur_grille, largeur_grille;
    int point_entree[2];
    nb_deplacements = &m;


     
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 0, 10);
    pile_empiler(sol_par, 1, 10);
    pile_empiler(sol_par, 1, 9);
    pile_empiler(sol_par, 1, 8);
    pile_empiler(sol_par, 2, 8);
    pile_empiler(sol_par, 3, 8);

    lab_calculer_deplacements_possibles(grille, 12, 12, 3, 8, sol_par, nb_deplacements,
                                        deplacements);
    printf("\n%i\n", m);


    for (int i = 0; i < *nb_deplacements; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i", deplacements[i][j]);
        }
        printf("\n");
    }
}


void lab_calculer_deplacements_possibles_test2(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int *nb_deplacements;
    int deplacements[4][2];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int m;
    int hauteur_grille, largeur_grille;
    int point_entree[2];
    nb_deplacements = &m;


     
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 6, 10);
    pile_empiler(sol_par, 5, 10);

    lab_calculer_deplacements_possibles(grille, 7, 25, 5, 10, sol_par, nb_deplacements,
                                        deplacements);
    printf("\n%i\n", m);

     
    for (int i = 0; i < *nb_deplacements; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i ", deplacements[i][j]);
        }
        printf("\n");
    }
}


void lab_calculer_deplacements_possibles_test4(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int *nb_deplacements;
    int deplacements[4][2];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int m;
    int hauteur_grille, largeur_grille;
    int point_entree[2];
    nb_deplacements = &m;


     
    charger_labyrinthe("grille4.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 10, 1);
    pile_empiler(sol_par, 9, 1);

    lab_calculer_deplacements_possibles(grille, 11, 47, 9, 1, sol_par, nb_deplacements,
                                        deplacements);
    printf("\n%i\n", m);

     
    for (int i = 0; i < *nb_deplacements; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i ", deplacements[i][j]);
        }
        printf("\n");
    }
}


void lab_choisir_deplacements_test(void)
{
     
    int sol_par[TAILLE_MAX_PILE][2];
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
     
    int point_entree[2];
     
    int hauteur_grille, largeur_grille;

     
    int deplacements_possibles[4][2];
     
    int nb_deplacements;

     
    int case_choisie;


     
    printf("grille1.txt\n");
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 0, 10);
    pile_empiler(sol_par, 1, 10);
    pile_empiler(sol_par, 1, 9);
    pile_empiler(sol_par, 1, 8);
    pile_empiler(sol_par, 2, 8);
    pile_empiler(sol_par, 3, 8);

    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, 3, 8,
                                        sol_par, &nb_deplacements, deplacements_possibles);

    printf("Il y a %d deplacements possibles a partir de cette position.\n", nb_deplacements);

    case_choisie = lab_choisir_deplacement(deplacements_possibles, nb_deplacements);
    printf("Le prochain deplacement est : (%d, %d)\n\n",
           deplacements_possibles[case_choisie][0],
           deplacements_possibles[case_choisie][1]);


     
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            deplacements_possibles[i][j] = 0;
        }
    }

     
    printf("grille2.txt\n");
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 6, 10);
    pile_empiler(sol_par, 5, 10);

    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, 5, 10,
                                        sol_par, &nb_deplacements, deplacements_possibles);

    printf("Il y a %d deplacements possibles a partir de cette position.\n", nb_deplacements);

    case_choisie = lab_choisir_deplacement(deplacements_possibles, nb_deplacements);
    printf("Le prochain deplacement est : (%d, %d)\n",
           deplacements_possibles[case_choisie][0],
           deplacements_possibles[case_choisie][1]);
}


void lab_est_cases_adjacentes_test(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
     
    int point_entree[2];
     
    int hauteur_grille, largeur_grille;

     
    int case1[2];
     
    int case2[2];

     
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
    case1[0] = 3;
    case1[1] = 4;
    case2[0] = 3;
    case2[1] = 5;
    assert(lab_est_cases_adjacentes(case1, case2) == 1);

     
    case1[0] = 2;
    case1[1] = 1;
    case2[0] = 3;
    case2[1] = 1;
    assert(lab_est_cases_adjacentes(case1, case2) == 1);

     
    case1[0] = 1;
    case1[1] = 1;
    case2[0] = 2;
    case2[1] = 2;
    assert(lab_est_cases_adjacentes(case1, case2) == 0);

     
    case1[0] = 0;
    case1[1] = 0;
    case2[0] = 2;
    case2[1] = 3;
    assert(lab_est_cases_adjacentes(case1, case2) == 0);
}


void lab_est_une_sortie_test(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
     
    int point_entree[2];
     
    int hauteur_grille, largeur_grille;

     
    int position[2];

     
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

     
     
    position[0] = 0;
    position[1] = 10;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 1);

     
    position[0] = 6;
    position[1] = 5;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 0);

     
    position[0] = 5;
    position[1] = 0;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 1);

     
    position[0] = 11;
    position[1] = 11;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 0);
}


void lab_resoudre_profondeur_test(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
     
    int point_entree[2];
     
    int hauteur_grille, largeur_grille;

     
    int succes_chargement;

     
    int pile_solution[TAILLE_MAX_PILE][2];

     
    int debug = 1;

    succes_chargement = charger_labyrinthe("grille1.txt", grille, point_entree,
                                           &hauteur_grille, &largeur_grille);

    lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille,
                            point_entree, pile_solution, debug);
}
