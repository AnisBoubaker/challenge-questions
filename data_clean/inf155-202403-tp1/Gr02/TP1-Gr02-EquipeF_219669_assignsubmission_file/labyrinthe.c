
 

 

#include "labyrinthe.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilitaires.h"



 


 

 
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
        {
            printf("\n");
            char mur = 219;  

             
            for(int i=0; i<hauteur_grille; i++)
            {
                for (int j = 0; j < largeur_grille; j++)
                {
                        if(grille[i][j] == 2)
                        {
                            printf("E");
                        }

                        else if(pile_solution != NULL && pile_contient(pile_solution, i, j))
                        {
                            printf("X");     
                        }

                        else if (grille[i][j] == 1)
                        {
                            printf("%c", mur);   
                        }
                        else
                        {
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
        int deplacements[4][2])
        {
            *nb_deplacements = 0;  

             
             
            if((grille[pos_ligne][pos_colonne+1] == 0) && (pile_contient(solution_partielle, pos_ligne, pos_colonne+1) == 0) && (pos_colonne+1 <= largeur_grille))
            {
                deplacements[*nb_deplacements][0] = pos_colonne+1;
                deplacements[*nb_deplacements][1] = pos_ligne;
                (*nb_deplacements)++;  
            }
             
             
            if((grille[pos_ligne][pos_colonne-1] == 0) && (pile_contient(solution_partielle, pos_ligne, pos_colonne-1) == 0) && (pos_colonne-1 >= 0))
            {
                deplacements[*nb_deplacements][0] = pos_colonne++;  
                deplacements[*nb_deplacements][1] = pos_ligne;
                *nb_deplacements++;  
            }
             
             
            if((grille[pos_ligne+1][pos_colonne] == 0) && (pile_contient(solution_partielle, pos_ligne+1, pos_colonne) == 0) && (pos_ligne+1 >= 0))
            {
                deplacements[*nb_deplacements][0] = pos_colonne;
                deplacements[*nb_deplacements][1] = pos_ligne++;
                *nb_deplacements++;  
            }
             
             
            if((grille[pos_ligne-1][pos_colonne] == 0) && (pile_contient(solution_partielle, pos_ligne-1, pos_colonne) == 0) && (pos_ligne-1 <= hauteur_grille))
            {
                deplacements[*nb_deplacements][0] = pos_colonne;
                deplacements[*nb_deplacements][1] = pos_ligne++;
                *nb_deplacements++;  
            }
             
             
        }

 
int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice_deplacements_possible;     

     
    srand((unsigned)time(NULL));

     
    indice_deplacements_possible = rand()  % nb_deplacements_possibles;

    return indice_deplacements_possible;     
}


 
int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
     
    if((case1[0] - case2[0] == 1   || case1[0] - case2[0] == -1) && (case1[1] == case2[1]))
    {
        return 1;      
    }
     
    else if((case1[0] ==  case2[0] ) && (case1[1] - case2[1]  == 1 || case1[1] - case2[1] == -1 ))
    {
        return 1;      
    }
     
    else
    {
        return 0;      
    }
}

 
int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{
     
    if(grille[position[1]][position[0]] == 0)
    {
        if(position[0] == 0 || position[0] == largeur_grille)  
        {
            return 1;
        }
        if (position[1] == 0 || position[1] == hauteur_grille) 
        {
            return 1;
        }
    }
    else
    {
        return 0; 
    }
}


int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
{
     
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles=0;
    int nouvelle_position[2];  

     
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE );
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_GRILLE );

     
    pile_empiler(pile_solution, entree[0], entree[1]);

     
    do
    {
        pile_haut_pile(pile_solution, &nouvelle_position[0], &nouvelle_position[1]);
        int valeurs_haut_pile[2]; 
        valeurs_haut_pile[0] = nouvelle_position[0];
        valeurs_haut_pile[1] = nouvelle_position[1];


        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,
        nouvelle_position[0],nouvelle_position[1], pile_solution, &nb_deplacements_possibles,
        deplacements_possibles);  

        if(nb_deplacements_possibles>0)  
        {
             
            int choix_deplacement = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);  
            pile_empiler(pile_solution,deplacements_possibles[choix_deplacement][0], deplacements_possibles[choix_deplacement][1]); 

             
            for(int i = 0 ; i < nb_deplacements_possibles; i++){
                if(i != choix_deplacement)  
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                }
            }
        }
        else if(pile_est_vide(pile_chemins_alternatifs)!=0)  
        {
            pile_depiler(pile_chemins_alternatifs,&nouvelle_position[0], &nouvelle_position[1]);  

             
            while(pile_est_vide(pile_solution) != 0 && lab_est_cases_adjacentes(valeurs_haut_pile,nouvelle_position)==0)
            {
                pile_haut_pile(pile_solution,&valeurs_haut_pile[0],&valeurs_haut_pile[1]);
                pile_depiler(pile_solution,&valeurs_haut_pile[0],&valeurs_haut_pile[1]);
            }
             
            pile_empiler(pile_solution,nouvelle_position[0],nouvelle_position[1]);
        }
        else
        {
            return 0;  
        }
         
        if(debug == 1)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            printf("\nPour continuer, cliquez sur la touche [ENTER]");
            system("pause");
        }

    }while(pile_est_vide(pile_solution) != 0 && lab_est_une_sortie(nouvelle_position,grille,hauteur_grille,largeur_grille)!=0);

    if(pile_est_vide(pile_solution) == 0)
    {
        return 0;  
    }
    else
    {
        return 1;  
    }
}