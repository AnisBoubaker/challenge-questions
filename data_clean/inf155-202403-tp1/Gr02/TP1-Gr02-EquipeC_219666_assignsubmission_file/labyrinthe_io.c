 

#include "labyrinthe_io.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX_PILE 1000  
#define TAILLE_MAX_GRILLE 100  



 


 

int charger_labyrinthe(char* nom_fichier,
                       int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2],
                       int* hauteur_grille,
                       int* largeur_grille)
{
    FILE* fichier;
    char caractere_lu;
    int i = 0,  
    j = 0;
    fichier = fopen(nom_fichier, "r");
    if (!fichier)
    {
        printf("ERREUR! Le fichier %s n'a pas ete trouve \n", nom_fichier);
        return 0;
    }

    *largeur_grille = -1;
    *hauteur_grille = -1;

    while ((caractere_lu = getc(fichier)) != EOF)
    {
        switch (caractere_lu)
        {
            case '*':
                grille[i][j] = 1;
                j++;
                break;
            case ' ':
                grille[i][j] = 0;
                j++;
                break;
            case 'E':
                grille[i][j] = 0;
                point_entree[0] = i;
                point_entree[1] = j;
                j++;
                break;
            case '\n':

                if (*largeur_grille != -1 && *largeur_grille != j) {
                    printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le meme nombre de colonnes.\n");
                    return 0;
                }
                *largeur_grille = j;
                j = 0;
                i++;
                break;
        }
    }
    *hauteur_grille = i + 1;
    fclose(fichier);
    return 1;
}

 

void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]) {
    int i, j;

    for (i = 0; i < hauteur_grille; i++) {
        for (j = 0; j < largeur_grille; j++) {
            if (pile_solution != NULL && pile_contient(pile_solution, i, j)) {
                printf("%c", 88);   
            } else if (grille[i][j] == 1) {
                printf("%c", 219);   
            } else {
                printf(" ");   
            }
        }
        printf("\n");
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
        int deplacements[4][2]) {


    *nb_deplacements = 0;

    for(int i = pos_ligne - 1; i <= pos_ligne + 1 && *nb_deplacements < 4; i++)
    {
        for(int j = pos_colonne - 1; j <= pos_colonne + 1 && *nb_deplacements < 4; j++)
        {
            if(i >= 0 && i < hauteur_grille && j >= 0 && j < largeur_grille && grille[i][j] != 1 && !pile_contient(solution_partielle, i, j)){

                pile_empiler(solution_partielle,i,j);

                deplacements[*nb_deplacements][0] = i;
                deplacements[*nb_deplacements][1] = j;
                (*nb_deplacements)++;
            }
        }
    }
}

 

int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles)
{
    return rand() % nb_deplacements_possibles;  
}


 

int lab_est_cases_adjacentes(int case1[2], int case2[2]) {
    if (case1[0] == case2[0] && case1[1] == case2[1] + 1) {
        return 1;
    } else if (case1[0] == case2[0] && case1[1] == case2[1] - 1) {
        return 1;
    } else if (case1[0] == case2[0] + 1 && case1[1] == case2[1]) {
        return 1;
    } else if (case1[0] == case2[0] - 1 && case1[1] == case2[1]) {
        return 1;
    } else {
        return 0;
    }
}

 

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    if (position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0 || position[1] == largeur_grille - 1)
    {
        if (grille[position[0]][position[1]] != 1) {
            return 1;
        }
    }
    return 0;  
}













