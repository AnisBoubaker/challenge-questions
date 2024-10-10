/*
Module: labyrinthe

Auteurs: Paul Ayoub, Mohammad Hamadé, David Mushimiyimana et Vincenzo Jean Vincent Pirot

Date: 16 octobre 2023
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include <stdio.h>
#include "pile.h"
#include "labyrinthe.h"
#include "utilitaires.h"

/************CONSTANTES************/
/* Code ASCII pour afficher un mur */
#define MUR_LAB 219
/* Code ASCII pour identifier une case faisant partie de la solution (lettre X) */
#define SOL_LAB 88
/* Code ASCII pour afficher un couloir (espace) */
#define COULOIR_LAB 32


/*******IMPLEMENTATION DES FONCTIONS***********/
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                         int largeur_grille, int pile_solution[][2])
{
    int ligne, colonne; /* Compteur de lignes et de colonnes dans le tableau */

    /* Boucle pour parcourir les lignes du tableau */
    for (ligne = 0; ligne < hauteur_grille; ligne++)
    {
        /* Boucle pour parcourir les colonnes du tableau */
        for (colonne = 0; colonne < largeur_grille; colonne++)
        {
            /* Affichage d'un mur lorsqu'une valeur de la grille == 1*/
            if (grille[ligne][colonne] == 1)
                printf("%c", MUR_LAB);
            else
            {
                /* Vérifier si la pile contenant la solution est vide */
                if (pile_est_vide(pile_solution) != 1)
                {
                    /* Vérifier si les coordonnées (ligne, colonne)
                       font partie de la solution et affiche un 'X' si vrai */
                    if (pile_contient(pile_solution, ligne, colonne) == 1)
                        printf("%c", SOL_LAB);
                    else
                        /* Sinon affiche un couloir */
                        printf("%c", COULOIR_LAB);
                }
                else
                    /* Sinon affiche un couloir */
                    printf("%c", COULOIR_LAB);
            }
        }
        /* Saut de ligne pour passer à la ligne suivante */
        printf("\n");
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille, int largeur_grille,
                                         int pos_ligne, int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements, int deplacements[4][2])
{
    // Quatres directions possibles
    int directions[4][2] = {{-1, 0},    // Vers le bas
                            {1,  0},    // Vers le haut
                            {0,  -1},   // Vers la gauche
                            {0,  1}};   // Vers la droite
    int nouvelle_ligne;
    int nouvelle_colonne;

    // Initialisation du nombre de déplacements possibles
    *nb_deplacements = 0;

    for (int i = 0; i < 4; i++)
    {
        nouvelle_ligne = pos_ligne + directions[i][0];
        nouvelle_colonne = pos_colonne + directions[i][1];

        // On vérifie que les nouvelles coordonnées sont à l'intérieur des limites de la grille
        if (nouvelle_ligne >= 0 && nouvelle_ligne < hauteur_grille - 1 &&
            nouvelle_colonne >= 0 && nouvelle_colonne < largeur_grille - 1)
        {
            // On vérifie si la case n'est pas un mur ET n'est pas dans la solution partielle
            if (grille[nouvelle_ligne][nouvelle_colonne] != 1 &&
                !pile_contient(solution_partielle, nouvelle_ligne, nouvelle_colonne))
            {
                deplacements[*nb_deplacements][0] = nouvelle_ligne;
                deplacements[*nb_deplacements][1] = nouvelle_colonne;
                (*nb_deplacements)++;
            }
        }
    }
}


int lab_choisir_deplacement(int deplacements_possibles[][2],
                            int nb_deplacements_possibles)
{
    /* Variable pour l'indice choisi dans le tableau deplacement_possibles */
    int indice_choisi;

    /* Générer un indice aléatoire */
    indice_choisi = -1;
    indice_choisi = nb_aleatoire(0, nb_deplacements_possibles - 1);

    return indice_choisi;
}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    /* On vérifie si les deux cases sont sur la même ligne et si la différence entre leurs
       colonnes est de 1 OU si les deux cases ont la même colonne et si la différence
       entre leurs lignes est de 1 */
    if ((case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1) ||
        (case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1))
        return 1;
    else
        // s'ils ne sont pas adjacents, on retourne 0
        return 0;
}


int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille, int largeur_grille)
{
    // Renvoie faux par défaut
    int est_une_sortie = 0;

    // On vérifie si la position est au bord de la grille.
    if (position[0] == 0 || position[0] == hauteur_grille - 1 ||
        position[1] == 0 || position[1] == largeur_grille - 1)
    {
        // On vérifie que la case du labyrinthe n'est pas un mur
        if (grille[position[0]][position[1]] != 1)
            est_une_sortie = 1; // Retourne vrai
    }
    return est_une_sortie;
}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                            int largeur_grille, int entree[2], int pile_solution[][2],
                            int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];

    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = -1;
    int nouvelle_position[2];

    int case_haut_pile[2];
    int choix_deplacement;
    int pos_ligne, pos_colonne;

    // Initialisation des piles
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

    // Empiler les coordonnées de l'entrée du labyrinthe dans pile_solution
    pile_empiler(pile_solution, entree[0], entree[1]);

    // Tant qu'il est possible de se déplacer et qu'une sortie n'a pas été trouvée (à revérifier!)
    while (nb_deplacements_possibles != 0 &&
           lab_est_une_sortie(case_haut_pile, grille, hauteur_grille, largeur_grille) != 1)
    {
        //On récupère les coordonnées du haut de la pile_solution
        pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);

        // On calcule les déplacements possibles à partir de cette coordonnée
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                            pos_ligne, pos_colonne, pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possibles);
        // Boucle IF pour choisir un déplacement possible et garder en mémoire les autres
        if (nb_deplacements_possibles > 0)
        {
            // On choisit un déplacement dans le tableau des déplacements possibles.
            choix_deplacement = lab_choisir_deplacement(deplacements_possibles,
                                                        nb_deplacements_possibles);

            // Le déplacement choisi est empilé dans pile_solution
            pile_empiler(pile_solution, deplacements_possibles[choix_deplacement][0],
                         deplacements_possibles[choix_deplacement][1]);

            // Empiler les autres déplacements possibles dans pile_chemins_alternatifs.
            for (int i = 0; i < nb_deplacements_possibles; i++)
            {
                if (i != choix_deplacement)
                    pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0],
                                 deplacements_possibles[i][1]);
            }

        }
            // Boucle ELSE IF pour revenir en arrière et prendre un autre chemin possible
        else if (pile_est_vide(pile_chemins_alternatifs) != 1 &&
                 lab_est_une_sortie(case_haut_pile, grille, hauteur_grille, largeur_grille) != 1)
        {
            // On dépile un chemin alternatif pour l'utiliser dans nouvelle_position
            pile_depiler(pile_chemins_alternatifs,
                         &nouvelle_position[0], &nouvelle_position[1]);

            pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);

            // Dépiler pile_solution jusqu'à ce que le haut de la pile contienne
            //  une case adjacente à nouvelle_position
            while (lab_est_cases_adjacentes(case_haut_pile, nouvelle_position) != 1)
            {
                pile_depiler(pile_solution, &pos_ligne, &pos_colonne);
                pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);
            }

            // On empile le nouveau chemin dans pile_solution
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                                pos_ligne, pos_colonne, pile_solution,
                                                &nb_deplacements_possibles,
                                                deplacements_possibles);

        }
        else
            // On conclut qu'il n'est plus possible de se déplacer!
            break;
        // Si le mode debug est activé, on affiche la grille avec la solution partielle
        if (debug)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            printf("\n");
            system("pause");
        }
        pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);
    }
    // On retourne VRAI si une solution a été trouvée, FAUX sinon.
    return lab_est_une_sortie(pile_solution[1], grille, hauteur_grille, largeur_grille);
}
