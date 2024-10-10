 
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
 

void affiche_solution_grille(

    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pile_solution[][2]) {

        int trouve_dans_solution = 0;

         
        for (int i = 0; i < hauteur_grille; i++) {
            for (int j = 0; j < largeur_grille; j++) {

                 

                if (pile_solution != NULL) {

                     
                    for (int k = 0; k < TAILLE_MAX_GRILLE; k++) {
                        if (pile_solution[k][0] == i && pile_solution[k][1] == j) {
                            trouve_dans_solution = 1;
                            break;
                        }
                    }


                     
                    if (grille[i][j] == 1)
                    {
                        printf("%c", 219);   
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
                 

            }
            printf("\n");


        }
        printf("\n");


}


 

 
void affiche_solution_grille_pas_a_pas(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]) {

    int indice_solution = 0;

     
    while (pile_solution[indice_solution][0] != -1)
    {
         
         
        for (int i = 0; i < hauteur_grille; i++)
        {
            printf("\n");
        }

        int x = pile_solution[indice_solution][0];
        int y = pile_solution[indice_solution][1];

         
        for (int i = 0; i < hauteur_grille; i++)
        {
            for (int j = 0; j < largeur_grille; j++)
            {
                if (i == x && j == y)
                {
                    printf("X");  
                }
                else if (grille[i][j] == 1)
                {
                    printf("%c", 219);  
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

         
        printf("Appuyez sur Enter pour continuer...");
        fflush(stdout);

         
        while (getchar() != '\n')
            ;

        indice_solution++;
    }
    printf("\n");
}



