 

 
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "labyrinthe.h"
#include "utilitaires.h"
#include <time.h>

 

#define Taille_max_grille 100
 


 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {
     

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
             
            if (grille[i][j] == 1 )
            {
                printf("*");
            }
                 
            else
            {
                if ( !pile_est_vide(pile_solution) )  
                {
                     
                    int solution = 0;

                    if(pile_contient(pile_solution, i, j))
                    {
                        solution=1;
                        printf("X");  
                    }
                    else
                    {
                         
                        printf(" ");
                    }

                }
                else
                {
                     
                    printf(" ");

                }


            }
        }

         
        printf("\n");

    }

}

 
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
     
    *nb_deplacements = 0;

     
    int adjacents[4][2] = {
            {-1, 0},   
            {1, 0},    
            {0, -1},   
            {0, 1}     
    };

     
    for (int i = 0; i < 4; i++)
    {

        int nouvelle_ligne = pos_ligne + adjacents[i][0];
        int nouvelle_colonne = pos_colonne + adjacents[i][1];

         
        if (
                (nouvelle_ligne >= 0 && nouvelle_ligne < hauteur_grille) &&  (nouvelle_colonne >= 0 && nouvelle_colonne < largeur_grille)
                && grille[nouvelle_ligne][nouvelle_colonne] != 1
                && !pile_contient(solution_partielle, nouvelle_ligne, nouvelle_colonne)
                )
        {
             
            deplacements[*nb_deplacements][0] = nouvelle_ligne;
            deplacements[*nb_deplacements][1] = nouvelle_colonne;
            *nb_deplacements = *nb_deplacements  + 1;
        }
    }
}



 
int lab_choisir_deplacement (int deplacement_possibles[][2],int nb_deplacements_possibles)
{
    int prochain_deplacement;
    if(nb_deplacements_possibles == 0)
    {
        return -1;  
    }
    srand((unsigned int)time(NULL));
    rand();

    prochain_deplacement= nb_aleatoire(0,nb_deplacements_possibles-1);  
    return prochain_deplacement;

}

 
int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
     
    if (case1[0] == case2[0] && case1[1] == case2[1] + 1  || case1[0] == case2[0] && case1[1] == case2[1]  -1 )
    {
        return 1;  
    }

    else if(case1[1] == case2[1] && case1[0] == case2[0] + 1 || case1[1] == case2[1] && case1[0] == case2[0] -1 )
    {
        return 1;  
    }

    else
    {
        return 0;  
    }


}





 
int lab_est_une_sortie(int position[2],int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{

     
    if (grille[position[0]][position[1]] != 1)
    {
         
        if (position[0] == 0 ||  position[0] == hauteur_grille-1)
        {
            return 1;
        }
        else if (position[1] == 0 ||  position[1] == largeur_grille-1)
        {
            return 1;
        }
        else
        {
            return 0 ;  
        }

    }
    else
    {
        return 0;  
    }

}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pos_ligne;
    int pos_colonne;
    int nb_deplacements;
    int deplacements[4][2];
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2];
    int nouvelle_position[2];
    int prochain_deplacement;
    int position[2];
    int i,j;

     
    pile_initialiser(pile_solution, TAILLE_MAX_Pile);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_Pile);
     
    pile_empiler(pile_solution, entree[0],entree[1]);
    do
    {
         
        pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);
         
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne,pile_solution,&nb_deplacements,deplacements);
        if(nb_deplacements >0 )
        {
             
            prochain_deplacement =  lab_choisir_deplacement(deplacements,nb_deplacements);
             
            pile_empiler(pile_solution, deplacements[prochain_deplacement][0],deplacements[prochain_deplacement][1]);

             
            if(nb_deplacements >1)
            {
                for(i=0;i<nb_deplacements;i++)
                {
                    if(i != prochain_deplacement  )
                    {
                        pile_empiler(pile_chemins_alternatifs, deplacements[i][0],deplacements[i][1]);
                    }
                }
            }


        }else if( pile_est_vide(pile_chemins_alternatifs) == 0 )
        {
             
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0],&nouvelle_position[1]);

             
            do
            {
                pile_depiler(pile_solution, &pos_ligne,&pos_colonne);

                 
                pile_haut_pile(pile_solution, &position[0] ,&position[1]);

            }
            while(lab_est_cases_adjacentes(nouvelle_position, position) == 0);
             
            pile_empiler(pile_solution, nouvelle_position[0],nouvelle_position[1]);
        }else
        {
            return 0;  
        }
         
        if( debug == 1)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }

         
        pile_haut_pile(pile_solution, &position[0] ,&position[1]);
    }while(lab_est_une_sortie(position,grille,hauteur_grille,largeur_grille) != 1);


    if(lab_est_une_sortie(position,grille,hauteur_grille,largeur_grille) == 1)
    {
        return 1;  
    }else
    {
        return 0;  
    }
}


