/*
Module: labyrinthe_test

Auteurs: Paul Ayoub, Mohammad Hamadé, David Mushimiyimana

Date: 25 octobre 2023
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_test.h"
#include "labyrinthe_io.h"
#include <assert.h>

/*******IMPLEMENTATION DES FONCTIONS***********/
void lab_afficher_grille_test(void)
{
    /* Tableau qui sera utilise pour stocker la pile d'exemple */
    int pile_solution[TAILLE_MAX_PILE][2];
    /* Tableau 2D qui contient la grille du labyrinthe */
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    /* Stocke les coordonnees du point d'entree du labyrinthe lors du chargement */
    int point_entree[2];
    /* Stocke la taille de la grille chargee depuis le disque */
    int hauteur_grille, largeur_grille;

    // Initialisation de la pile
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

    //On empile un ensemble de valeurs.
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


    // Grille valide
    printf("grille1.txt\n");
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");


    // Grille valide
    printf("grille2.txt\n");
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");


    // Grille non-valide
    printf("grille3.txt\n");
    charger_labyrinthe("grille3.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    printf("\n\n");

    // Grille valide
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


    //charger la grille depuis le disque ici
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    //Ci-dessous, on reproduit la solution partielle telle qu’illustrée dans la figure
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
    //On teste la 2e grille
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int *nb_deplacements;
    int deplacements[4][2];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int m;
    int hauteur_grille, largeur_grille;
    int point_entree[2];
    nb_deplacements = &m;


    //charger la grille 2 depuis le disque ici
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    //Ci-dessous, on reproduit la solution partielle telle qu’illustrée dans la figure
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 6, 10);
    pile_empiler(sol_par, 5, 10);

    lab_calculer_deplacements_possibles(grille, 7, 25, 5, 10, sol_par, nb_deplacements,
                                        deplacements);
    printf("\n%i\n", m);

    //Affichage des coordonnées de déplacements possibles
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
    //On teste la grille 4
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int *nb_deplacements;
    int deplacements[4][2];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int m;
    int hauteur_grille, largeur_grille;
    int point_entree[2];
    nb_deplacements = &m;


    //charger la grille depuis le disque ici
    charger_labyrinthe("grille4.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    //Ci-dessous, on reproduit la solution partielle telle qu’illustrée dans la figure
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, 10, 1);
    pile_empiler(sol_par, 9, 1);

    lab_calculer_deplacements_possibles(grille, 11, 47, 9, 1, sol_par, nb_deplacements,
                                        deplacements);
    printf("\n%i\n", m);

    //Affichage des coordonnées des déplacements possibles
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
    /* Tableau qui sera utilise pour stocker la solution partielle */
    int sol_par[TAILLE_MAX_PILE][2];
    /* Tableau 2D qui contient la grille du labyrinthe */
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    /* Stocke les coordonnees du point d'entree du labyrinthe lors du chargement */
    int point_entree[2];
    /* Stocke la taille de la grille chargee depuis le disque */
    int hauteur_grille, largeur_grille;

    /* Tableau qui sera utilise pour stocker les deplacements possibles */
    int deplacements_possibles[4][2];
    /* Stocke le nombre de deplacements possibles */
    int nb_deplacements;

    /* Stocke l'indice choisi dans le tableau des deplacements disponibles */
    int case_choisie;


    // Grille valide
    printf("grille1.txt\n");
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    //Ci-dessous, on reproduit la solution partielle telle qu’illustrée dans la figure
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


    // Boucle pour effacer le tableau des deplacements possibles avant de poursuivre
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            deplacements_possibles[i][j] = 0;
        }
    }

    // On charge la deuxieme grille
    printf("grille2.txt\n");
    charger_labyrinthe("grille2.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    //On reproduit la solution partielle
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
    /* Tableau 2D qui contient la grille du labyrinthe */
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    /* Stocke les coordonnees du point d'entree du labyrinthe lors du chargement */
    int point_entree[2];
    /* Stocke la taille de la grille chargee depuis le disque */
    int hauteur_grille, largeur_grille;

    /* Tableau contenant les coordonnées de la première case */
    int case1[2];
    /* Tableau contenant les coordonnées de la deuxieme case */
    int case2[2];

    // On charge une grille valide
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    // Cas de test 1 : Deux cases adjacentes sur la même ligne.
    case1[0] = 3;
    case1[1] = 4;
    case2[0] = 3;
    case2[1] = 5;
    assert(lab_est_cases_adjacentes(case1, case2) == 1);

    // Cas de test 2 : Deux cases adjacentes sur la même colonne.
    case1[0] = 2;
    case1[1] = 1;
    case2[0] = 3;
    case2[1] = 1;
    assert(lab_est_cases_adjacentes(case1, case2) == 1);

    // Cas de test 3 : Deux cases non adjacentes (diagonales).
    case1[0] = 1;
    case1[1] = 1;
    case2[0] = 2;
    case2[1] = 2;
    assert(lab_est_cases_adjacentes(case1, case2) == 0);

    // Cas de test 4 : Deux cases non adjacentes (saut de ligne et de colonne).
    case1[0] = 0;
    case1[1] = 0;
    case2[0] = 2;
    case2[1] = 3;
    assert(lab_est_cases_adjacentes(case1, case2) == 0);
}


void lab_est_une_sortie_test(void)
{
    /* Tableau 2D qui contient la grille du labyrinthe */
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    /* Stocke les coordonnees du point d'entree du labyrinthe lors du chargement */
    int point_entree[2];
    /* Stocke la taille de la grille chargee depuis le disque */
    int hauteur_grille, largeur_grille;

    /* Tableau contenant les coordonnées de la position à vérifier */
    int position[2];

    // On charge une grille valide
    charger_labyrinthe("grille1.txt", grille, point_entree,
                       &hauteur_grille, &largeur_grille);

    // Cas de test 1 : Position au coin supérieur gauche
    // (une sortie; entrée du labyrinthe).
    position[0] = 0;
    position[1] = 10;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 1);

    // Cas de test 2 : Position au milieu de la grille (pas une sortie).
    position[0] = 6;
    position[1] = 5;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 0);

    // Cas de test 3 : Position au milieu du coin gauche (une sortie).
    position[0] = 5;
    position[1] = 0;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 1);

    // Cas de test 4 : Position au bord droit (pas une sortie).
    position[0] = 11;
    position[1] = 11;
    assert(lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) == 0);
}


void lab_resoudre_profondeur_test(void)
{
    /* Tableau 2D qui contient la grille du labyrinthe */
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    /* Stocke les coordonnees du point d'entree du labyrinthe lors du chargement */
    int point_entree[2];
    /* Stocke la taille de la grille chargee depuis le disque */
    int hauteur_grille, largeur_grille;

    //Stocke une valeur vraie si la grille a été chargée correctement.
    int succes_chargement;

    // Tableau qui sera utilisé pour stocker la pile de coordonnées contenant la solution
    int pile_solution[TAILLE_MAX_PILE][2];

    // Mode debug
    int debug = 1;

    succes_chargement = charger_labyrinthe("grille1.txt", grille, point_entree,
                                           &hauteur_grille, &largeur_grille);

    lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille,
                            point_entree, pile_solution, debug);
}
