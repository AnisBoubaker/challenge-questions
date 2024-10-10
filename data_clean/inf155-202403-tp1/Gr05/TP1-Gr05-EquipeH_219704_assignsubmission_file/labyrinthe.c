 

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <time.h>


void lab_afficher_grille ( int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    int i, j;  

    for (i = 0; i < hauteur_grille; i++)
    {
        for (j = 0; j < largeur_grille; j++)
        {
            if (grille [i][j] == 1)
            {
                printf("%c", 219);  
            }
            else if (grille [i][j] == 0)
            {
                printf(" ");  
            }
            else if (pile_contient(pile_solution,i,j))
            {
                printf("%c", 88);  
            }
        }

        printf("\n");
    }
}

void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacement[4][2])
{
    int deplacement_possible = 0;  
    int position_actuelle[2] ={pos_ligne, pos_colonne};  
    int position_en_haut[2] = {pos_ligne - 1, pos_colonne};  
    int position_en_bas[2] = {pos_ligne + 1, pos_colonne};  
    int position_droite[2] = {pos_ligne, pos_colonne + 1};  
    int position_gauche[2] = {pos_ligne, pos_colonne - 1};  

     
    if (grille[pos_ligne][pos_colonne - 1] == 0 && !pile_contient(solution_partielle,pos_ligne,pos_colonne - 1 ))
    {
         
        if (lab_est_cases_adjacentes(position_gauche, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne,pos_colonne - 1);
            deplacement_possible++;
        }
    }

     
    if (grille[pos_ligne][pos_colonne + 1] == 0 && !pile_contient(solution_partielle,pos_ligne,pos_colonne + 1 ))
    {
         
        if (lab_est_cases_adjacentes(position_droite, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne,pos_colonne + 1);
            deplacement_possible++;
        }
    }

     
    if (grille[pos_ligne - 1][pos_colonne] == 0 && !pile_contient(solution_partielle,pos_ligne - 1,pos_colonne))
    {
         
        if (lab_est_cases_adjacentes(position_en_haut, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne - 1,pos_colonne);
            deplacement_possible++;
        }
    }

     
    if (grille[pos_ligne + 1][pos_colonne] == 0 && !pile_contient(solution_partielle,pos_ligne + 1,pos_colonne))
    {
         
        if (lab_est_cases_adjacentes(position_en_bas, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne + 1,pos_colonne);
            deplacement_possible++;
        }
    }
    *nb_deplacements = deplacement_possible;
}

int lab_choisir_deplacement(int deplacement_possible[][2], int nb_deplacements_possibles)
{
    int choix;  

     
    srand((unsigned int) time(NULL));
    rand();


    if (nb_deplacements_possibles >= 2)
    {
         
        choix = nb_aleatoire(1, nb_deplacements_possibles);
    }else
    {
        choix = 1;
    }
    
    return choix;
}

int lab_est_cases_adjacentes(int case1[2],int case2[2])
{

     
    if(case1[0]==case2[0] && case1[1]-case2[1]!=1||case1[1]==case2[1] && case1[0]-case2[0]!=1)
    {
        return 1;  
    }
    else
    {
        return 0;  
    }
}


int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille) {
    int position_ligne = position[0]; 
    int position_colonne = position[1]; 

    if ((position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0 ||
        position[1] == largeur_grille - 1)&& grille[position_ligne][position_colonne] != 1)
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
    int pile_chemins_alternatifs [TAILLE_MAX_PILE][2];  
    int deplacements_possibles[4][2]; 
    int nb_deplacements_possibles; 
    int nouvelle_position[2]; 
    int nouvelle_positon_x; 
    int nouvelle_positon_y; 
    int choix_deplacement; 
    int deplacement_x; 
    int deplacement_y; 
    int coordonne_utilise[2]; 

     
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

     
    pile_empiler(pile_solution, entree[0], entree[1]);

    do
    {
         
        pile_haut_pile(pile_solution, &nouvelle_positon_x, &nouvelle_positon_y);

        if(debug == 1)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }
        if (debug == 0)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
        }
         
        nouvelle_position[0] = nouvelle_positon_x;
        nouvelle_position[1] = nouvelle_positon_y;

         
        lab_calculer_deplacements_possibles(grille, hauteur_grille,largeur_grille,nouvelle_positon_x, nouvelle_positon_y, pile_solution, &nb_deplacements_possibles, deplacements_possibles);

         
        deplacement_x = nouvelle_positon_x;
        deplacement_y = nouvelle_positon_y;

         
        pile_empiler(deplacements_possibles,deplacement_x,deplacement_y);

        if (nb_deplacements_possibles > 0)
        {
            choix_deplacement = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);
            deplacement_x = deplacements_possibles[choix_deplacement][0];
            deplacement_y = deplacements_possibles[choix_deplacement][1];

            pile_empiler(pile_solution, deplacement_x, deplacement_y);

            nouvelle_position[0] = deplacement_x;
            nouvelle_position[1] = deplacement_y;

            while (!pile_est_vide(deplacements_possibles))
            {
                pile_empiler(pile_chemins_alternatifs,deplacement_x,deplacement_y);
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
            pile_depiler(pile_chemins_alternatifs,&deplacement_x,&deplacement_y);
            nouvelle_position[0] = deplacement_x;
            nouvelle_position[1] = deplacement_y;
            do
            {
                pile_haut_pile(pile_solution,&deplacement_x,&deplacement_y);
                coordonne_utilise[0] = deplacement_x;
                coordonne_utilise[1] = deplacement_y;

                pile_depiler(pile_solution,&deplacement_x,&deplacement_y);

            } while (!lab_est_cases_adjacentes(nouvelle_position, coordonne_utilise));

            pile_empiler(pile_solution,nouvelle_position[0],nouvelle_position[1]);

        }
        else
        {
            return 0;
        }
    } while (!lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille));
    return 1;
}