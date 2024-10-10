 

#include "labyrinthe.h"
#include "pile.h"
#include "labyrinthe_io.h"

#include "test_des_fonctions.h"

void test_lab_afficher_grille(void)
{
    printf("Test1: X en position (2,3), (2,4), (1,3)\n");
    int grille1[][TAILLE_MAX_GRILLE] = {{ 1,0, 0, 1, 1, 1}, {0, 1, 1, 0, 1, 1}, {1,1,1,0,0,1}};
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<6; j++)
        {
            printf("%d", grille1[i][j]);
        }
        printf("\n");
    }
    int pile_solutions[TAILLE_MAX_GRILLE][2] = {{TAILLE_MAX_GRILLE,3}, {2,4}, {2,3}, {1,3}};
    lab_afficher_grille(grille1,3,6,pile_solutions);

    printf("\nTest2: Grille vide \n");
    int grille2[][TAILLE_MAX_GRILLE] = {};
    int pile_solutions2[TAILLE_MAX_GRILLE][2] = {{TAILLE_MAX_GRILLE,0}};
    lab_afficher_grille(grille2,0,0, pile_solutions2);

    printf("\nTest3: Grille 4x4 remplie de murs\n");
    int grille3[][TAILLE_MAX_GRILLE] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int pile_solutions3[TAILLE_MAX_GRILLE][2] = {{TAILLE_MAX_GRILLE,0}};
    lab_afficher_grille(grille3, 4,4,pile_solutions3);

    printf("\nTest4: Grille 3x3 remplie d'espaces\n");
    int grille4[][TAILLE_MAX_GRILLE] = {{0,0,0},{0,0,0},{0,0,0}};
    int pile_solutions4[TAILLE_MAX_GRILLE][2] = {{TAILLE_MAX_GRILLE,0}};
    lab_afficher_grille(grille4, 3,3,pile_solutions4);

    printf("\nTest5: Grille 2x3 remplie de solutions\n");
    int grille5[][TAILLE_MAX_GRILLE] = {{1,0,1}, {0,0,1}};
    int pile_solutions5[TAILLE_MAX_GRILLE][2] = {{TAILLE_MAX_GRILLE,6},{0,0}, {0,1},{0,2},{1,0},{1,1},{1,2} };
    lab_afficher_grille(grille5, 2,3,pile_solutions5);

}

void test_lab_calculer_deplacements_possibles(void)
{
int grille1[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE] = {{1,1,1},
                                                     {1,0,0},
                                                     {0,0,1}};
int solution[TAILLE_MAX_GRILLE][2] = {0,2};
int deplacements[4][2];
int nb_deplacements;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d", grille1[i][j]);
        }
        printf("\n");
    }
    printf("(0,2) est dans la pile solution\n\n");
    lab_calculer_deplacements_possibles(grille1,3,3,1,1,solution,&nb_deplacements,deplacements);
    printf("Test1: Case (1,1) a 2 cases adjacente, (2,1) et (1,2)\n");
    printf("nb_deplacements: %d     (%d,%d) et (%d,%d)", nb_deplacements, deplacements[0][0],deplacements[0][1]
           ,deplacements[1][0],deplacements[1][1]);

    lab_calculer_deplacements_possibles(grille1,3,3,2,1,solution,&nb_deplacements,deplacements);
    printf("\n\nTest2: Case (2,1) a 1 cases adjacente, (1,1)\n");
    printf("nb_deplacements: %d     (%d,%d)", nb_deplacements, deplacements[0][0],
           deplacements[0][1]);

    lab_calculer_deplacements_possibles(grille1,3,3,2,1,solution,&nb_deplacements,deplacements);
    printf("\n\nTest2: Case (2,1) a 1 cases adjacente, (1,1)\n");
    printf("nb_deplacements: %d     (%d,%d)", nb_deplacements, deplacements[0][0],
           deplacements[0][1]);

    lab_calculer_deplacements_possibles(grille1,3,3,0,0,solution,&nb_deplacements,deplacements);
    printf("\n\nTest2: Case (0,0) a 0 cases adjacente,\n");
    printf("nb_deplacements: %d", nb_deplacements);



}

void test_lab_choisir_deplacement(void)
{
    int tab[2][2];

    printf("Test lab choisir deplacement: 3 nombres aleatoires entre [0,3[\n");
    printf("%d ", lab_choisir_deplacement(tab, 3));
    printf("%d ", lab_choisir_deplacement(tab, 3));
    printf("%d ", lab_choisir_deplacement(tab, 3));

    printf("\nTest lab choisir deplacement: si nb_deplacements <= 0 (doit donner -1)\n");
    printf("%d ", lab_choisir_deplacement(tab, 0));
    printf("%d ", lab_choisir_deplacement(tab, -2));

    printf("\nTest lab choisir deplacement: si nb_deplacements == 1 (doit donner 0)\n");
    printf("%d ", lab_choisir_deplacement(tab, 1));
}

void test_lab_est_cases_adjacentes(void)
{
    int tab1[2] = {5,6};
    int tab2[2] = {7,5};

    printf("Test lab cases adjacentes: (5,6) et (7,5) ne sont pas adjacents, donc retour 0\n");
    printf("%d", lab_est_cases_adjacentes(tab1, tab2));

    int tab3[2] = {5,6};
    int tab4[2] = {5,7};

    printf("\nTest lab cases adjacentes: (5,6) et (5,7) sont adjacents, donc retour 1\n");
    printf("%d", lab_est_cases_adjacentes(tab3, tab4));

    int tab5[2] = {9,2};
    int tab6[2] = {10,2};

    printf("\nTest lab cases adjacentes: (9,2) et (10,2) sont adjacents, donc retour 1\n");
    printf("%d", lab_est_cases_adjacentes(tab5, tab6));

    int tab7[2] = {1,1};
    int tab8[2] = {1,1};

    printf("\nTest lab cases adjacentes: (1,1) et (1,1) ne sont pas adjacents, donc retour 0\n");
    printf("%d", lab_est_cases_adjacentes(tab7, tab8));

    int tab9[2] = {};
    int tab10[2] = {};

    printf("\nTest lab cases adjacentes: Les cases vides ne sont pas adjacents, donc retour 0\n");
    printf("%d", lab_est_cases_adjacentes(tab9, tab10));

    int tab11[2] = {0,0};
    int tab12[2] = {0,-1};

    printf("\nTest lab cases adjacentes: (0,0) et (0,-1) sont adjacents, donc retour 1\n");
    printf("%d", lab_est_cases_adjacentes(tab11, tab12));
}

void test_lab_est_une_sortie(void)
{
    int grille1[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE] = {{1,1,1},
                                                         {1,0,0},
                                                         {0,0,1}};

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d", grille1[i][j]);
        }
        printf("\n");
    }

     
    int tab1[2] = {2,0};
    printf("(2,0) est une sortie, donc donne vrai\n%d",lab_est_une_sortie(tab1, grille1, 3, 3));

    int tab2[2] = {0,0};
    printf("\n(0,0) est un mur, donc donne faux\n%d",lab_est_une_sortie(tab2, grille1, 3, 3));

    int tab4[2] = {1,1};
    printf("\n(1,1) n'est pas sur les cotes de la grille, donc donne faux\n%d",lab_est_une_sortie(tab4, grille1, 3, 3));
}