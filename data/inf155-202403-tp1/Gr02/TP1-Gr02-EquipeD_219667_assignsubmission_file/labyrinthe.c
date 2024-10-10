/*
Module: labyrinthe

Auteur: Ferdaws Aljane, Milena Busuioc, Rachid Hamza et William Lavoie

Date: 12 novembre 2023
*/

#include "labyrinthe.h"
#include "pile.h"
#include <stdio.h>
#include "utilitaires.h"


void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],
                         int hauteur_grille,
                         int largeur_grille,
                         int pile_solution[][2])
{
    // Création d'une copie de pile_solution
    int pile_copie[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2];
    pile_copier(pile_solution, pile_copie);

    // Marquer les coordonnées de la pile_solution avec la valeur 2 dans la grille
    while (!pile_est_vide(pile_copie))
    {
        int ligne, colonne;
        pile_depiler(pile_copie, &ligne, &colonne);
        grille[ligne][colonne] = 2;
    }

    // Parcourir la grille et afficher s'il y a un mur ou un espace
    for (int i = 0; i < hauteur_grille; i++ )  // Itèrer sur les lignes
    {
        for (int j = 0; j < largeur_grille; j++) // Itèrer sur les colonnes
        {
            if (grille[i][j] == 1)
            {
                printf("%c", 219); // Placer un mur si la grille contient un 1
            }
            else if (grille[i][j] == 0 || grille[i][j] == 3 )
            {
                printf(" "); // Placer un espace si la grille contient un 0
            }
            else if (grille[i][j] == 2)
            {
                printf("X"); // Placer un X si la grille contient un 2
            }
        }
        printf("\n");  // Saut de ligne
    }
}

void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2])
{
    int i = 0;

    // Déterminer si la case inférieure constitue un déplacement possible
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne+1,pos_colonne,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne+1;
        deplacements[i][1] = pos_colonne;
        i++;
    }

   // Déterminer si la case supérieure constitue un déplacement possible
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne-1,pos_colonne,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne-1;
        deplacements[i][1] = pos_colonne;
        i++;
    }

    //Déterminer si la case à droite constitue un déplacement possible
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne+1,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne+1;
        i++;
    }

    //Déterminer si la case à gauche constitue un déplacement possible
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne-1,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne-1;
    }
}

int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles)
{
    // Retourner -1 si aucun déplacement possible
    if (nb_deplacements_possibles <= 0)
    {
        return -1;
    }

    // Choisir un déplacement aléatoire possible (deplacements_possibles[choix][2])
    // entre 0 et nb_deplacements_possibles
    int choix = rand() % nb_deplacements_possibles;

    // Retourner l'indice (deplacements_possibles[choix][2])
    return choix;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int dx, dy;

    dx = case1[0] - case2[0]; // Différence en x: dx = x1 - x2
    dy = case1[1] - case2[1]; // Différence en y: dy = y1 - y2

    // Vérifier si les cases sont adjacentes
    // Deux cases sont adjacentes si la distance d = |dx| + |dy| est égale à 1 (donc si déplacement de 1 en x ou y)
    if ((abs(dx) + abs(dy)) == 1)
    {
        return 1; // Vrai: les cases sont adjacentes
    }
    else
    {
        return 0; // Faux: les cases ne sont pas adjacentes
    }
}

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    // Vérifie si la position est sur le bord du labyrinthe
    if (position[0] == 0 || position[1] == 0 || position[0] == hauteur_grille-1 || position[1] == largeur_grille-1)
    {
        // Vérifie que la position n'est pas un mur
        if (grille[position[0]][position[1]] != 1)
        {
            return 1; // Vrai: la position est une sortie
        }
    }

    return 0; // Faux: la position n'est pas une sortie
}

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
{
    // Initialisation des variables
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = 0;
    int nouvelle_position[2];
    int position[2] = {};
    int done = 0;
    int ligne,colonne;

    // Tableau à une dimension servant de comparaison
    int comp[2];

    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);

    // Empiler l'entrée et calculer les déplacements possibles
    pile_empiler(pile_solution, entree[0], entree[1]);
    lab_calculer_deplacements_possibles(grille,
                                        hauteur_grille,
                                        largeur_grille,
                                        entree[0],
                                        entree[1],
                                        pile_solution,
                                        &nb_deplacements_possibles,
                                        deplacements_possibles);


    // Boucler s'il est possible de se déplacer et si la solution n'est pas trouvée
    while (!lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) && done != 1)
    {
        if (nb_deplacements_possibles > 0)
        {
            // Choisir aléatoirement un déplacement possible et l'empiler dans pile_solution
            int indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]);

                // Affichage en mode pas-à-pas
                if (debug)
                {
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                    fflush(stdin);
                    getchar();
                }

            // Stocker les déplacements alternatifs dans la pile des chemins alternatifs
            for (int i = 1; i < nb_deplacements_possibles ; i++ )
            {
                // Vérifie si la case n'a pas déjà été parcouru ou mise dans pile_chemins_alternatifs
                if (grille[deplacements_possibles[(indice+i)%nb_deplacements_possibles][0]]
                          [deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]] != 3)
                {
                    // Empiler le déplacement alternatif dans la pile des chemins alternatifs
                    pile_empiler(pile_chemins_alternatifs,
                                 deplacements_possibles[(indice+i)%nb_deplacements_possibles][0],
                                 deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]);

                    // Marquer la case dans la grille afin qu'elle ne soit pas mise plusieurs fois dans la pile
                    grille[deplacements_possibles[(indice+i)%nb_deplacements_possibles][0]]
                          [deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]] = 3;
                }
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
            // Retour en arrière à la case sur le dessus de la pile de chemins alternatifs
            pile_depiler(pile_chemins_alternatifs, &ligne, &colonne);

            nouvelle_position[0] = ligne;
            nouvelle_position[1] = colonne;

            // Dépiler la pile_solution jusqu'à atteindre une position adjacente à nouvelle_position
            while (!lab_est_cases_adjacentes(nouvelle_position, comp))
            {
                pile_depiler(pile_solution,&ligne,&colonne);
                grille[ligne][colonne] = 0;
                pile_haut_pile(pile_solution, &ligne, &colonne);
                comp[0] = ligne;
                comp[1] = colonne;
            }

            // Empiler la nouvelle position
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            // Affichage
            if (debug)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar();
            }

        }
        else
        {
            done = 1; // Aucun déplacement possible
        }

        // Mettre à jour la position actuelle et recalculer les déplacements possibles
        pile_haut_pile(pile_solution, &ligne, &colonne);
        nb_deplacements_possibles = 0;
        lab_calculer_deplacements_possibles(grille,
                                            hauteur_grille,
                                            largeur_grille,
                                            ligne, colonne, pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possibles);
        position[0] = ligne;
        position[1] = colonne;
    }

    // Vérifier si la sortie a été atteinte
    if (lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille))
    {
        pile_empiler(pile_solution, position[0], position[1]);

        return 1; // Vrai: solution trouvée
    }

    return 0; // Faux: solution n'existe pas
}