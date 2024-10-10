 

 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"


 


 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    int valeur_pile = pile_solution[0][2];

    for(int i = 0; i < hauteur_grille; i++)
    {
        for(int j = 0; j < largeur_grille; j++)
        {
            if(grille[i][j] == 1)
            {
                printf("%c", 219);
            }

            int temporaire = 0;

            for(int temp = 1; temp<=valeur_pile; temp++)
            {
                if(pile_solution[temp][0] == i && pile_solution[temp][1] == j)
                {
                    temporaire = 1;
                }
            }

            if(temporaire != NULL && grille[i][j] == 0)
            {
                printf("X");
            }
            else if(grille[i][j] == 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}



void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{

    int compteur=0;

    if(grille[pos_ligne + 1][pos_colonne] == 0 && pos_ligne+1 <= largeur_grille && pile_contient(solution_partielle,pos_ligne + 1,pos_colonne)==0)
    {
        compteur++;
        deplacements[0][0]=pos_ligne + 1;
        deplacements[0][1]=pos_colonne;

    }
    if(grille[pos_ligne-1][pos_colonne] == 0 && pos_ligne-1 >= 1 && pile_contient(solution_partielle,pos_ligne-1,pos_colonne)==0)
    {
        compteur++;
        deplacements[1][0]= pos_ligne - 1;
        deplacements[1][1]=pos_colonne;
    }
    if(grille[pos_ligne][pos_colonne+1] == 0 && pos_colonne+1 <= hauteur_grille && pile_contient(solution_partielle,pos_ligne,pos_colonne+1)==0)
    {
        compteur++;
        deplacements[2][0]= pos_ligne;
        deplacements[2][1]= pos_colonne +1;
    }
    if(grille[pos_ligne][pos_colonne-1] == 0 && pos_colonne-1 >= hauteur_grille && pile_contient(solution_partielle,pos_ligne,pos_colonne-1)==0)
    {
        compteur++;
        deplacements[3][0]= pos_ligne;
        deplacements[3][1]= pos_colonne - 1;
    }

    *nb_deplacements = compteur;
}


int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
    {
        srand((unsigned int) time(NULL));
        rand();

        if(nb_deplacements_possibles==0)
        {
            return 0;
        }
        return nb_aleatoire(1,nb_deplacements_possibles);
    }

int lab_est_cases_adjacentes(int case1[2], int case2[2])
    {
        if(case1[0] + 1 == case2[0] || abs(case1[0] - 1) == case2[0])
        {
            return 1;
        }

        else if(case1[1] + 1 == case2[1] || abs(case1[1] - 1) == case2[1])
        {
            return 1;
        }

        return 0;
    }

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
    {
        int ligne, colonne;

        ligne = position[0];
        colonne = position[1];

        if (grille[ligne][colonne] != 0 && (ligne == 0 || ligne == hauteur_grille - 1 || colonne == 0 || colonne == largeur_grille - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int pile_chemain_alternatif[TAILLE_MAX_GRILLE][2];
    int deplacement_possible[4][2];
    int nombre_deplacement_possible;
    int sortie = 0;

    int *nb_deplacements;
    int nb_deplacement_temp = 0;
    nb_deplacements = &nb_deplacement_temp;

    int top_pile;

     
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);
    pile_initialiser(pile_chemain_alternatif, TAILLE_MAX_GRILLE);

     
    pile_empiler(pile_solution, entree[0], entree[1]);
    top_pile = pile_solution[0][1];

    int position[2] = {pile_solution[top_pile][0], pile_solution[top_pile][1]};
 

 
    while((!(lab_est_une_sortie(pile_solution[top_pile], grille, hauteur_grille, largeur_grille)) || ((pile_solution[top_pile][0] == entree[0]) && (pile_solution[top_pile][1] == entree[1]))) && (!pile_est_vide(pile_solution)))
    {
        top_pile = pile_solution[0][1];


        position[0] = pile_solution[top_pile][0];
        position[1] = pile_solution[top_pile][1];

         

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, position[0], position[1],
                                            pile_solution, nb_deplacements, deplacement_possible);
         
        nombre_deplacement_possible = *nb_deplacements;

         
        int le_deplacement = lab_choisir_deplacement(deplacement_possible, nombre_deplacement_possible);

         
        if (nombre_deplacement_possible == 1) {
             
            pile_empiler(pile_solution, deplacement_possible[le_deplacement][0],
                         deplacement_possible[le_deplacement][1]);
        }
        if (nombre_deplacement_possible == 2) {
            if (le_deplacement == 1) {
                pile_empiler(pile_chemain_alternatif, deplacement_possible[2][0], deplacement_possible[2][1]);
                pile_empiler(pile_solution, deplacement_possible[1][0], deplacement_possible[1][1]);
            } else {
                pile_empiler(pile_chemain_alternatif, deplacement_possible[1][0], deplacement_possible[1][1]);
                pile_empiler(pile_solution, deplacement_possible[2][0], deplacement_possible[2][1]);
            }
        }
        if (nombre_deplacement_possible == 3) {
            if (le_deplacement == 1) {
                pile_empiler(pile_chemain_alternatif, deplacement_possible[2][0], deplacement_possible[2][1]);
                pile_empiler(pile_chemain_alternatif, deplacement_possible[3][0], deplacement_possible[3][1]);
                pile_empiler(pile_solution, deplacement_possible[1][0], deplacement_possible[1][1]);
            }
            if (le_deplacement == 2) {
                pile_empiler(pile_chemain_alternatif, deplacement_possible[1][0], deplacement_possible[1][1]);
                pile_empiler(pile_chemain_alternatif, deplacement_possible[3][0], deplacement_possible[3][1]);
                pile_empiler(pile_solution, deplacement_possible[2][0], deplacement_possible[2][1]);
            }
            if (le_deplacement == 3) {
                pile_empiler(pile_chemain_alternatif, deplacement_possible[1][0], deplacement_possible[1][1]);
                pile_empiler(pile_chemain_alternatif, deplacement_possible[2][0], deplacement_possible[2][1]);
                pile_empiler(pile_solution, deplacement_possible[3][0], deplacement_possible[3][1]);
            }
        }

        if (nombre_deplacement_possible == 0)
        {
             
            if (pile_est_vide(pile_chemain_alternatif) == 0)
            {
                int top_alternatif = pile_chemain_alternatif[0][1];
                int position_alternative[2] = {pile_chemain_alternatif[top_alternatif][0],
                                               pile_chemain_alternatif[top_alternatif][1]};

                while (!lab_est_cases_adjacentes(position_alternative, position))
                {
                    pile_depiler(pile_solution, &position[0], &position[1]);
                    top_pile = pile_solution[0][1];
                    position[0] = pile_solution[top_pile][0];
                    position[1] = pile_solution[top_pile][1];
                }

                top_alternatif = pile_chemain_alternatif[0][1];
                position_alternative[0] = pile_chemain_alternatif[top_alternatif][0];
                position_alternative[1] = pile_chemain_alternatif[top_alternatif][1];

                 

                pile_depiler(pile_chemain_alternatif, &position_alternative[0], &position_alternative[1]);
                pile_empiler(pile_solution, position_alternative[0], position_alternative[1]);
            }
            else
            {
                printf("Le déplacement est impossible\n");
            }
        }

         

        top_pile = pile_solution[0][1];

        if (debug) {
             
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            printf("Press any key to continue...\n");
            fflush(stdin);
            getchar();
        }
    }
    top_pile = pile_solution[0][1];

    printf(" Le labyrinthe fut complété avec brio! \n");

    printf("la sortie possède les coordonnées suivantes :%d, %d\n", pile_solution[top_pile][0], pile_solution[top_pile][1]);
    return lab_est_une_sortie(pile_solution[top_pile], grille, hauteur_grille, largeur_grille);
}




