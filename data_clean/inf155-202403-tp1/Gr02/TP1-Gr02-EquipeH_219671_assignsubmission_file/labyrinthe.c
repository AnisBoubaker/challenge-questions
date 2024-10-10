 


 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"
#include "utilitaires.h"
#include "pile.h"

 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if (!pile_est_vide(pile_solution) && pile_contient(pile_solution, i, j))  
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
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{

    if ((case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1) ||
        (case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1))  
    {
        return 1;
    }

    return 0;
}

void lab_calculer_deplacements_possibles (
        int grille [][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle [][2],
        int *nb_deplacements,
        int deplacements [4][2])

{
    int deplacement_test_x[]={-1,1,0,0};  
    int deplacement_test_y[]={0,0,-1,1};  
    int nb_deplacements_cal = 0;  

    for(int i=0;i<4;i++)   
    {
        int nouvelle_ligne = pos_ligne + deplacement_test_x[i];
        int nouvelle_colonne  = pos_colonne + deplacement_test_y[i];

         
        if((grille[nouvelle_ligne][nouvelle_colonne] == 0) && (nouvelle_ligne < hauteur_grille && nouvelle_ligne>=0) && (nouvelle_colonne < largeur_grille && nouvelle_colonne>=0) && (pile_contient(solution_partielle,nouvelle_ligne,nouvelle_colonne)==0))
        {
            deplacements [nb_deplacements_cal][0] = nouvelle_colonne;
            deplacements [nb_deplacements_cal][1] = nouvelle_ligne;
            nb_deplacements_cal++;

        }
        *nb_deplacements=nb_deplacements_cal;

    }

}


int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)  
{
    int case_choisi;
    srand((unsigned int) time(NULL));  
    rand();

    case_choisi = nb_aleatoire(0,nb_deplacements_possibles-1);

    return case_choisi;
}


int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
     
    if (position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0 || position[1] == largeur_grille - 1)
    {
         
        if (!grille[position[0]][position[1]])
        {
            return 1;
        }
    }

    return 0;
}

int lab_resoudre_profondeur(int grille [][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{

    int pile_chemin_alternatif [TAILLE_MAX_PILE][2];
    int deplacements_possibles [4][2];
    int nb_deplacements_possibles=0;
    int nouvelle_position [2];
    int pile_temp [2];
    int position_actuelle[2];

    pile_initialiser(pile_solution,TAILLE_MAX_PILE);  
    pile_initialiser(pile_chemin_alternatif,TAILLE_MAX_PILE);  

    pile_empiler(pile_solution,entree[0],entree[1]);

    int pos_actu_ligne=entree[0];
    int pos_actu_col=entree[1];

    do{
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,pos_actu_ligne,pos_actu_col,pile_solution,&nb_deplacements_possibles,deplacements_possibles);  

        if(nb_deplacements_possibles>0)
        {
            int indice= lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);  

            pile_empiler(pile_solution,deplacements_possibles[indice][1],deplacements_possibles[indice][0]);  

            for(int i=0;i<nb_deplacements_possibles;i++)
            {
                if(i!=indice)
                {
                    pile_empiler(pile_chemin_alternatif,deplacements_possibles[i][1],deplacements_possibles[i][0]);  
                }
            }

        }else if(pile_est_vide(pile_chemin_alternatif)!=1)  
        {
            pile_depiler(pile_chemin_alternatif,&nouvelle_position[0],&nouvelle_position[1]);  

            do{   
                pile_depiler(pile_solution, &pile_temp[0], &pile_temp[1]);
                pile_haut_pile(pile_solution,&pile_temp[0],&pile_temp[1]);

            }while (lab_est_cases_adjacentes(nouvelle_position, pile_temp) == 0);

            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);  
        }
        else
        {
            printf("Il n'est plus possible de se deplacer.\n");  
            break;
        }

        if(debug == 1)  
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }

         
        pile_haut_pile(pile_solution,&pos_actu_ligne,&pos_actu_col);
        position_actuelle[0]=pos_actu_ligne;
        position_actuelle[1]=pos_actu_col;
    }
    while(!lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille));

    if(lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille==1))  
    {
        return 1;
    }
    else  
    {
        return 0;
    }
}

