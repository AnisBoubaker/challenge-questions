 

 
#include "labyrinthe.h"
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "utilitaires.h"

 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,int pile_solution[][2])
{ 
    for (int i=0;i<hauteur_grille;i++)
    {
        for(int j=0; j<largeur_grille; j++)
            {
              if( pile_contient( pile_solution,  i,  j) )
              {
                 printf("X"); 
              }
              else if  (grille[i][j] == 1)
              {
                printf("%c",219); 
              }
              else if  (grille[i][j] == 0 )
              {
                printf(" "); 
              }
        }
        printf("\n");
    }
}

 




int lab_est_cases_adjacentes(const int case1[2],const int case2[2])
{
    int resultat=0;

    if(case1[0]==case2[0]) 
    {
        if(case1[1]-case2[1]==-1  || case1[1]-case2[1]==1 ) 
        {
            resultat=1; 
            return resultat;
        }
    }
   else if(case1[1]==case2[1]) 
   {
       if(case1[0]-case2[0]==-1  || case1[0]-case2[0]==1) 
       {
           resultat=1; 
           return resultat;
       }
   }
    return resultat;
}

 


int  lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    if(position[1]==hauteur_grille || position[2]==largeur_grille || position[1]==0 || position[2]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

 

void calcul_deplacements_possibles (int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
    int pos[2];
    pos[0] = pos_ligne;
    pos[1] = pos_colonne;

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if (grille[i][j] == 0 && lab_est_cases_adjacentes(grille, pos) == 1)
            {
                deplacements[i][j] = grille[i][j];
            }
        }
    }
}


int lab_choisir_deplacement (int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    if(nb_deplacements_possibles>0)
    {

        return deplacements_possibles[0][0];

    }

}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    
}

