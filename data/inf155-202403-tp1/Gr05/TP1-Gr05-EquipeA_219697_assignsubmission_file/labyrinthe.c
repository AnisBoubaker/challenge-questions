/*
Module: labyrinthe.c
Description: Module de fonction d'entr�e/sortie en lien avec le programme du labyrinthe

Auteur:Mba Nzudie,Aubin Sylva;Kramar,Timothy;Orantes Benitez, Elias et Jeudy,Melody

Date: 08 novembre 2023
*/

#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <stdlib.h>
#include <stdio.h>




void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int pile_solution[][2]) {
    int i, j;
    int ascii_219 = 219;


    if (pile_solution != NULL) {

        for (i = 0; i < hauteur_grille; i++) {
            for (j = 0; j < largeur_grille; j++) {

                if (grille[i][j] == 1) {
                    printf("%c", ascii_219);

                }
                else if (pile_contient(pile_solution, i, j) == 1 && grille[i][j]==0) {
                    printf("X");

                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }

    }
}
    void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,
                                             int pos_ligne, int pos_colonne, int solution_partielle[][2],
                                             int *nb_deplacements, int deplacements[4][2]) {

        int nb_deplacement = 0;
        pile_initialiser(deplacements, 100);
        if (grille[pos_ligne + 1][pos_colonne] == 0) {
            nb_deplacement++;
            pile_empiler(deplacements, (pos_ligne + 1), (pos_colonne));
            pile_empiler(solution_partielle, (pos_ligne + 1), (pos_colonne));
        }
        if (grille[pos_ligne][pos_colonne + 1] == 0) {
            nb_deplacement++;
            pile_empiler(deplacements, pos_ligne, pos_colonne + 1);
            pile_empiler(solution_partielle, pos_ligne, pos_colonne + 1);

        }
        if (grille[pos_ligne][pos_colonne - 1] == 0) {
            nb_deplacement++;
            pile_empiler(deplacements, pos_ligne, pos_colonne - 1);
            pile_empiler(solution_partielle, pos_ligne, pos_colonne - 1);
        }
        if (grille[pos_ligne - 1][pos_colonne] == 0) {
            nb_deplacement++;
            pile_empiler(deplacements, pos_ligne - 1, pos_colonne);
            pile_empiler(solution_partielle, pos_ligne - 1, pos_colonne);

        }

            *nb_deplacements = nb_deplacement;
    }




    int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles) {

        return nb_aleatoire(0, nb_deplacements_possibles - 1);//(A.Boubaker,communication personnelle,2023)

    }


    int lab_est_cases_adjacentes(int case1[2], int case2[2]) {
        int resultat;
        if (((case1[0] == case2[0]) && ((case1[1] - case2[1] == 1) || (case1[1] - case2[1] == -1))) ||
            ((case1[1] == case2[1]) && ((case1[0] - case2[0] == 1) || (case1[0] - case2[0] == -1))))
            resultat = 1;

        else
            resultat = 0;

        return resultat;


    }


    int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille) {
        int vrai = 0;
        int pos[3][3] = {};
        pos[0][0] = position[0];
        pos[0][1] = position[1];
        for (int i = 0; i < largeur_grille - 1; i++) {
            if (pos[0][0] == 0 && pos[0][1] == i || pos[0][0] == hauteur_grille - 1 && pos[0][1] == i) {
                if (grille[position[0]][position[1]] == 0) {
                    vrai++;
                }

            }
        }
        for (int i = 0; i < hauteur_grille - 1; i++) {
            if (pos[0][0] == i && pos[0][1] == 0 || pos[0][0] == i && pos[0][1] == largeur_grille - 1) {
                if (grille[position[0]][position[1]] == 0) {
                    vrai++;

                }
            }

        }
        return vrai;
    }



    int lab_resoudre_profondeur(
            int grille[][TAILLE_MAX_GRILLE],
            int hauteur_grille,
            int largeur_grille,
            int entree[2],
            int pile_solution[][2],
            int debug) {

        int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2];
        int deplacements_possibles[4][2];
        int nb_deplacements_possibles;
        int nouvelle_position[2];
        int indice, deplacement_impossible = 0;
        int tableau_tampon[100][2];
        int tableau_tampon2[2];
        int resultat;

        // initialisation des deux piles

        pile_initialiser(pile_chemins_alternatifs, 100);
        pile_empiler(pile_solution, entree[0], entree[1]);
        nouvelle_position[0] = entree[0];
        nouvelle_position[1] = entree[1];
         do {
             lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, nouvelle_position[0],
                                                 nouvelle_position[1], tableau_tampon, &nb_deplacements_possibles,
                                                 deplacements_possibles);

             if (nb_deplacements_possibles > 0) {
                 pile_empiler(pile_solution, deplacements_possibles[1][0], deplacements_possibles[1][1]);
                 nouvelle_position[0] = deplacements_possibles[1][0];
                 nouvelle_position[1] = deplacements_possibles[1][1];
                 indice= lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
                 for (int i = 1; i != nb_deplacements_possibles; i++) {
                     if (i != indice) {
                         pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0],
                                      deplacements_possibles[i][1]);
                     }
                 }
                 pile_empiler(pile_solution,deplacements_possibles[indice][0],deplacements_possibles[indice][1]);
                 deplacement_impossible = 0;
             } else if ((pile_est_vide(pile_chemins_alternatifs) == 1)) {
                 deplacement_impossible++;
             } else {
                 while (lab_est_cases_adjacentes(tableau_tampon2, nouvelle_position) == 0) {
                     pile_depiler(pile_chemins_alternatifs, &tableau_tampon2[0], &tableau_tampon2[1]);
                     pile_empiler(pile_solution, tableau_tampon2[0], tableau_tampon2[1]);
                     nouvelle_position[0] = tableau_tampon2[0];
                     nouvelle_position[1] = tableau_tampon2[1];

                     deplacement_impossible = 0;
                 }
             }

         }while (deplacement_impossible == 0);
        resultat = lab_est_une_sortie(&nouvelle_position[2], grille, hauteur_grille, largeur_grille);
        return resultat;
    }

