/*
Module: utilitaires.c

Auteur: Vito PELLEGRINELLI/ Mark AVRUTIN/ Romain LATREILLE/ Xavier MARTEL

Date: 16/10/2023
*/
#include "utilitaires.h"
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#define TAILLE_MAX_GRILLE 100

int nb_aleatoire(int min, int max)
{
    if (min>max)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    srand((unsigned int) time(NULL));

    return rand() % (max - min + 1) + min;
}
//Verifie ie chemin selon les coorodnne fournis par la solution

void affiche_solution_grille(

    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pile_solution[][2]) {

        int trouve_dans_solution = 0;

        // Parcour la grille fourni
        for (int i = 0; i < hauteur_grille; i++) {
            for (int j = 0; j < largeur_grille; j++) {

                // Verifie si les coordonnees de font partie de la solution

                if (pile_solution != NULL) {

                    //Verifie ie chemin selon les coorodnne fournis par la solution
                    for (int k = 0; k < TAILLE_MAX_GRILLE; k++) {
                        if (pile_solution[k][0] == i && pile_solution[k][1] == j) {
                            trouve_dans_solution = 1;
                            break;
                        }
                    }


                    // Afficher le mur ou l'espace, et marquer la solution.
                    if (grille[i][j] == 1)
                    {
                        printf("%c", 219);  // Caractere ASCII 219 pour representer le mur
                    }
                    else if (trouve_dans_solution)
                    {
                        printf("X");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                // Aller à la ligne à la fin de chaque ligne

            }
            printf("\n");


        }
        printf("\n");


}


/*void affiche_solution_grille_pas_a_pas(
                int grille[][TAILLE_MAX_GRILLE],
                int hauteur_grille,
                int largeur_grille,
                int pile_solution[][2]) {

        int indice_solution = 0;

        // Parcourir la solution
        while (pile_solution[indice_solution][0] != -1)
        {
            // Effacer l'écran (facultatif)
            system("cls || clear");

            int x = pile_solution[indice_solution][0];
            int y = pile_solution[indice_solution][1];

            // Afficher la grille avec le chemin
            for (int i = 0; i < hauteur_grille; i++)
            {
                for (int j = 0; j < largeur_grille; j++)
                {
                    if (i == x && j == y)
                    {
                        printf("X"); // Marquer la position actuelle dans la solution
                    }
                    else if (grille[i][j] == 1)
                    {
                        printf("%c", 219); // Caractère ASCII 219 pour représenter le mur
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }

            // Attendre l'appui sur Enter avant de passer à l'étape suivante
            printf("Appuyez sur Enter pour continuer...");
            fflush(stdout);

            // Attendre que l'utilisateur appuie sur Enter
            while (getchar() != '\n')
                ;

            indice_solution++;
        }
        printf("\n");
    }*/

/* PROPOSITION 2 */
void affiche_solution_grille_pas_a_pas(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]) {

    int indice_solution = 0;

    // Parcourir la solution
    while (pile_solution[indice_solution][0] != -1)
    {
        // Effacer l'écran (facultatif)
        // Utilisez des caractères de saut de ligne pour "effacer" l'écran précédent
        for (int i = 0; i < hauteur_grille; i++)
        {
            printf("\n");
        }

        int x = pile_solution[indice_solution][0];
        int y = pile_solution[indice_solution][1];

        // Afficher la grille avec le chemin
        for (int i = 0; i < hauteur_grille; i++)
        {
            for (int j = 0; j < largeur_grille; j++)
            {
                if (i == x && j == y)
                {
                    printf("X"); // Marquer la position actuelle dans la solution
                }
                else if (grille[i][j] == 1)
                {
                    printf("%c", 219); // Caractère ASCII 219 pour représenter le mur
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Attendre l'appui sur Enter avant de passer à l'étape suivante
        printf("Appuyez sur Enter pour continuer...");
        fflush(stdout);

        // Attendre que l'utilisateur appuie sur Enter
        while (getchar() != '\n')
            ;

        indice_solution++;
    }
    printf("\n");
}



