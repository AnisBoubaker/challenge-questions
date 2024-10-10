 
 


 

#include "labyrinthe.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilitaires.h"



 


 




void tester_fonction_lab_choisir_deplacement()
{
    int deplacements_possibles[][2]={{1,2},{3,2},{4,1},};
    int nb_deplacements_possibles = 3;

    printf("L'indice choisi aléatoirement : %d \n", lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles));

    int deplacements_possibles_2[][2]={{4,2},{1,7}};
    int nb_deplacements_possibles_2 = 2;

    printf("L'indice choisi aléatoirement : %d \n", lab_choisir_deplacement(deplacements_possibles_2,nb_deplacements_possibles_2));

}


void tester_fonction_lab_est_adjacentes()
{
    int case1[] ={5,3};
    int case2[] ={5,2};
    int case3[] ={2,5};
    int case4[] ={3,5};

     


    if(lab_est_cases_adjacentes(case1,case2)==1)
    {
        printf("La case 5,3 et la case 5,2 sont adjacentes ");
    }
    else
    {
        printf("Error")   ;
    }

     

    if(lab_est_cases_adjacentes(case3,case4)==1)
    {
        printf("La case 2,5 et la case 3,5 sont adjacentes ");
    }
    else
    {
        printf("Error")   ;
    }

}




void tester_fonction_lab_est_une_sortie()
{
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE] = {

            {1,1,1},
            {1,0,1},
            {1,0,1}
    };
    int position[2]={3,1};

     
     
    if(lab_est_une_sortie(position,grille,3,3) == 1)
    {
        printf("La case est une sortie") ;
    }
     
    else
    {
        printf("Error");
    }

}






#include "Fichier_tests_des_fonctions.h"
