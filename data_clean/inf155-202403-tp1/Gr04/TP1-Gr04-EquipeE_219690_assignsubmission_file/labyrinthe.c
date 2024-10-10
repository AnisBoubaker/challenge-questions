 

#include "labyrinthe.h"
#include <stdlib.h>
#include <stdio.h>
#include "utilitaires.h"
#define TAILLE_MAX_GRILLE 100
#define TAILLE_MAX_PILE 1000

 

void
lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {

    char block = (char) 219;
    char space = (char) 32;
    char x = (char) 88;

    for (int i = 0; i < hauteur_grille; i++) {
        for (int j = 0; j < largeur_grille; j++) {
            if (pile_solution != NULL && pile_contient(pile_solution, i, j)) {
                printf("%c", x);
            } else if (grille[i][j] == 1) {
                printf("%c", block);     
            } else {
                printf("%c", space);     
            }
        }
        printf("\n");  
    }
}

 
void
lab_calculer_deplacements_possibles(  
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,  
        int pos_colonne,  
        int solution_partielle[][2],
        int *nb_deplacements_possibles,
        int deplacements_possibles[4][2]) {

    *nb_deplacements_possibles = 0;

    if (pos_ligne + 1 < hauteur_grille && grille[pos_ligne + 1][pos_colonne] != 1 &&
        !pile_contient(solution_partielle, pos_ligne + 1, pos_colonne)) {
        deplacements_possibles[*nb_deplacements_possibles][0] = pos_ligne + 1;
        deplacements_possibles[*nb_deplacements_possibles][1] = pos_colonne;
        (*nb_deplacements_possibles)++;
    }
    if (pos_colonne + 1 < largeur_grille && grille[pos_ligne][pos_colonne + 1] != 1 &&
        !pile_contient(solution_partielle, pos_ligne, pos_colonne + 1)) {

        deplacements_possibles[*nb_deplacements_possibles][0] = pos_ligne;
        deplacements_possibles[*nb_deplacements_possibles][1] = pos_colonne + 1;
        (*nb_deplacements_possibles)++;

    }
    if (pos_ligne - 1 >= 0 && grille[pos_ligne - 1][pos_colonne] != 1 &&
        !pile_contient(solution_partielle, pos_ligne - 1, pos_colonne)) {
        deplacements_possibles[*nb_deplacements_possibles][0] = pos_ligne - 1;
        deplacements_possibles[*nb_deplacements_possibles][1] = pos_colonne;
        (*nb_deplacements_possibles)++;
    }
    if (pos_colonne - 1 >= 0 && grille[pos_ligne][pos_colonne - 1] != 1 &&
        !pile_contient(solution_partielle, pos_ligne, pos_colonne - 1)) {

        deplacements_possibles[*nb_deplacements_possibles][0] = pos_ligne;
        deplacements_possibles[*nb_deplacements_possibles][1] = pos_colonne - 1;
        (*nb_deplacements_possibles)++;
    }
}

 
 
int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles) {

    return nb_aleatoire(0, nb_deplacements_possibles - 1);
}

 
 

int lab_est_cases_adjacentes(int case1[2], int case2[2]) {

    return case1[0] == case2[0] && (case1[1] == case2[1] + 1 || case1[1] == case2[1] - 1) ||
           case1[1] == case2[1] && (case1[0] == case2[0] + 1 || case1[0] == case2[0] - 1);
}


 
 

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille) {

    return position[0] < hauteur_grille && position[0] >= 0 && (position[1] == 0 ||
                                                                position[1] == largeur_grille - 1) ||
           position[1] < largeur_grille && position[1] >= 0 && (position[0] == 0 ||
                                                                position[0] == hauteur_grille - 1) &&
           grille[position[0]][position[1]] == 0;
}

 
int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                            int largeur_grille, int entree[2], int pile_solution[][2],
                            int debug) {


    int pile_chemin_alternatif[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles;
    int nouvelle_position[2] = {entree[0], entree[1]};
    int ligne;
    int colonne;

    pile_initialiser(pile_solution, TAILLE_MAX_PILE);   
    pile_initialiser(pile_chemin_alternatif, TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0], entree[1]);

    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, entree[0], entree[1],
                                        pile_solution, &nb_deplacements_possibles, deplacements_possibles);

    do {

        pile_haut_pile(pile_solution, &ligne, &colonne);

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, ligne, colonne,
                                            pile_solution, &nb_deplacements_possibles, deplacements_possibles);

        if (nb_deplacements_possibles > 0) {

            int indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            nouvelle_position[0] = deplacements_possibles[indice][0];
            nouvelle_position[1] = deplacements_possibles[indice][1];
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            for (int i = 0; i < nb_deplacements_possibles; ++i) {
                if (i != indice) {
                    pile_empiler(pile_chemin_alternatif, deplacements_possibles[i][0],
                                 deplacements_possibles[i][1]);
                }
            }

        } else if (!pile_est_vide(pile_chemin_alternatif)) {

            pile_depiler(pile_chemin_alternatif, &ligne, &colonne);  
            nouvelle_position[0] = ligne;
            nouvelle_position[1] = colonne;

            pile_haut_pile(pile_solution, &ligne, &colonne);
            int coor_haut[2] = {ligne, colonne};  

            while (!lab_est_cases_adjacentes(nouvelle_position, coor_haut)) {
                pile_depiler(pile_solution, &ligne, &colonne);

                pile_haut_pile(pile_solution, &coor_haut[0], &coor_haut[1]);
            }
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);
        } else {
            return 0;
        }

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, nouvelle_position[0],
                                            nouvelle_position[1],
                                            pile_solution, &nb_deplacements_possibles, deplacements_possibles);
        if (debug) {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }
    } while (!(nb_deplacements_possibles == 0 && lab_est_une_sortie(nouvelle_position, grille, hauteur_grille,
                                                              largeur_grille)));

    return !pile_est_vide(pile_solution);
}
