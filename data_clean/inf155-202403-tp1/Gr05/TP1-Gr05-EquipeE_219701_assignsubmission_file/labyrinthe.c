 
#include "labyrinthe.h"
#include "utilitaires.h"


 
#include <stdio.h>

#define TAILLE_MAX_GRILLE 100




void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]) {


    int sol;



     
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            int trouve_dans_solution = 0;

            if (pile_solution != NULL) {
             
            if (grille[i][j] == 1)
            {
                printf("%c", 219);   
            }
            else if (pile_solution[0][0]== 1000)
            {
                for(int k=0; k<100; k++)
                {
                    if (i == pile_solution[k][0] && j == pile_solution[k][1])
                    {
                        printf("x");  
                        trouve_dans_solution++;
                    }
                }
                if(trouve_dans_solution == 0)
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
    printf("\n");

}


void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,int largeur_grille,
                                          int pos_ligne,int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,int deplacements[4][2])
{
    int tab1[2];
    int tab2[2];

    tab1[0] = pos_ligne;
    tab1[1] = pos_colonne;

    int cases_adjacentes;
    int n =0;
    *nb_deplacements =0 ;

    for(int i=0; i<hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            tab2[0] = i;
            tab2[1] = j;

            cases_adjacentes = lab_est_cases_adjacentes(tab1, tab2);

            if (cases_adjacentes == 1)
            {
                 

                if (grille[i][j] != 1)
                {
                     

                    if (pile_contient(solution_partielle, i, j) == 0)
                    {
                         

                        deplacements[n][0] = tab2[0];    

                        deplacements[n][1] = tab2[1];    

                        *nb_deplacements = *nb_deplacements + 1;      
                        n++;     
                    }
                }
            }
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice;

    indice = nb_aleatoire(0, nb_deplacements_possibles-1);

     

    return indice;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int difference_x;
    int difference_y;

    difference_x = case1[0] - case2[0];
    difference_y = case1[1] - case2[1];

     
     
     

    if (( difference_x == 0 && ( difference_y == 1 || difference_y == -1)) || (difference_y == 0 && (difference_x == 1 || difference_x == -1)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lab_est_une_sortie(int position[2],     int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille,  int largeur_grille)
{
    int x = position[0];
    int y = position[1];

     
    if (x == 0 || x == hauteur_grille - 1 || y == 0 || y == largeur_grille - 1) {
         
        if (grille[x][y] != 1) {
             
            return 1;
        }
    }
     
    return 0;
}
int test_lab_est_une_sortie(){
    int position[]={0,2};
    int grille[100][TAILLE_MAX_GRILLE];
    if (lab_est_une_sortie( position, grille, 200,200)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                            int largeur_grille,             int entree[2],
                            int pile_solution[][2],         int debug){

 
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2] = {TAILLE_MAX_GRILLE, 0};
    int deplacement_possible[4][2];
    int nb_deplacements = 0;
    int nouvelle_position[2];

    int pile_solution_depilee[2];  
    int indice;  
    int ligne;
    int colonne;
    int k = 1;  


    pile_empiler(pile_solution, entree[0], entree[1]);   

    do     
    {

        lab_calculer_deplacements_possibles(grille,hauteur_grille, largeur_grille,
                                            pile_solution[k][0], pile_solution[k][1],
                                            pile_solution,
                                            &nb_deplacements, deplacement_possible);

        if (nb_deplacements > 0)     
        {

            indice = lab_choisir_deplacement(deplacement_possible, nb_deplacements);

             
            pile_empiler(pile_solution, deplacement_possible[indice][0], deplacement_possible[indice][1]);


            for (int i = 0; i < nb_deplacements; i++)    
            {
                if (i != indice && nb_deplacements > 1)  
                {

                    pile_empiler(pile_chemins_alternatifs, deplacement_possible[i][0],
                                                                deplacement_possible[i][1]);
                }

            }

            if (debug == 1)  
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }

        } else if (pile_est_vide(pile_chemins_alternatifs) == 0) {

             
            pile_depiler(pile_chemins_alternatifs, &ligne, &colonne);
            nouvelle_position[0] = ligne;
            nouvelle_position[1] = colonne;

             
             
            do {
                pile_depiler(pile_solution, &ligne, &colonne);
                pile_solution_depilee[0] = ligne;
                pile_solution_depilee[1] = colonne;
                k--;
            }while (lab_est_cases_adjacentes(pile_solution_depilee, nouvelle_position) == 0);

             
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }
        }
        else  
        {
            return 0;
        }

        k++;

        pile_haut_pile(pile_solution, &ligne, &colonne);

        pile_solution_depilee[0] = ligne;
        pile_solution_depilee[1] = colonne;

    }while (deplacement_possible[0][0] != 0 && lab_est_une_sortie(pile_solution_depilee, grille, hauteur_grille, largeur_grille) != 1);

     
    if (lab_est_une_sortie(pile_solution_depilee, grille, hauteur_grille, largeur_grille) == 1)
        {
            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");

            }
            return 1;
        }
        else
        {
            return 0;
        }

}
