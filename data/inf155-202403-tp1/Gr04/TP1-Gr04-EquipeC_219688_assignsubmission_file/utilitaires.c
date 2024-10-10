/*
Module: utilitaires.c
Description: Module de fonctions utilitaires pour le programme du labyrinthe.

Auteur: Émile Yergeau

Date: 2023-11-06
*/

#include "utilitaires.h"


void afficher_options(int grille_chargee)
{
    system("cls");
    // Afficher le titre
    printf(MESSAGE_TITRE_LIGNE_1 MESSAGE_TITRE_LIGNE_2 MESSAGE_TITRE_LIGNE_3 "\n");

    // Afficher les options
    // Option 1
    printf(ESPACEMENT_OPTIONS MESSAGE_OPTION_1);

    // Option 2
    if (grille_chargee)
        printf(ESPACEMENT_OPTIONS MESSAGE_OPTION_2);
    else
        printf(ESPACEMENT_OPTIONS INDISPONIBLE MESSAGE_OPTION_2);

    // Option 3
    if (grille_chargee)
        printf(ESPACEMENT_OPTIONS MESSAGE_OPTION_3);
    else
        printf(ESPACEMENT_OPTIONS INDISPONIBLE MESSAGE_OPTION_3);

    // Option 4
    printf(ESPACEMENT_OPTIONS MESSAGE_OPTION_4);
}


void afficher_chargement_grille(
        int grille_chargee,
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{
    if (grille_chargee)
    {
        system("cls");
        printf(MESSAGE_GRILLE_CHARGEE);
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
    else
    {
        printf(MESSAGE_GRILLE_PAS_CHARGEE);
        system("pause");
    }
}


void afficher_solution(int solution_est_trouve, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    if (solution_est_trouve)
    {
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
    else
    {
        printf(MESSAGE_AUCUNE_SOLUTIONS);
        system("pause");
    }
}