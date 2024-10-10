
#include "labyrinthe.h"
#include "utilitaire.h"
#include "pile.h"

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {
     
    int solution;
     
    for (int i = 0; i < hauteur_grille; i++)
    { 
        for (int j = 0; j < largeur_grille; j++)
        { 
            if (grille[i][j] == 1)
            {
                printf("%c", 219);   
            }
            else
            { 
                if (pile_solution != NULL)
                {
                    solution = 0;
                     
                    for (int k = 0; k < TAILLE_MAX_GRILLE; k++)
                    {
                        if (pile_solution[k][0] == i && pile_solution[k][1] == j)
                        { 
                            printf("X");
                             
                            solution = 1;
                        }
                    }
                    if (solution == 0)
                    {  
                        printf(" ");
                    }
                } else
                { 
                    printf(" ");
                }
            }
        } 
        printf("\n");
    }
}

void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int pos_ligne,int pos_colonne,int solution_partielle[][2], int *nb_deplacements,int deplacements[][2]) {
    
    *nb_deplacements = 0;
    int nouv_ligne;
    int nouv_colonne;

      int position_possible[4][2] =
             {
                    {pos_ligne - 1, pos_colonne},
                    {pos_ligne + 1, pos_colonne},
                    {pos_ligne,     pos_colonne - 1},
                    {pos_ligne,     pos_colonne + 1}
             };

     
    for (int i = 0; i < 4; i++) {
        int verif = 0;
        nouv_ligne = position_possible[i][0];
        nouv_colonne = position_possible[i][1];
         

        if (nouv_ligne < hauteur_grille && nouv_ligne > 0 &&
            nouv_colonne < largeur_grille && nouv_colonne > 0)
             
            if (grille[nouv_ligne][nouv_colonne] == 0) {
                 

                for (int l = 0; l < TAILLE_MAX_GRILLE; l++)
                {
                    for (int t = 0; t < 2; t++){
                        if (solution_partielle[l][0] == nouv_ligne && solution_partielle[l][1] == nouv_colonne) {
                            verif++;
                        }
                    }
                }
                if(verif== 0) {

                    deplacements[i][0] = nouv_ligne;       
                    deplacements[i][1] = nouv_colonne;    
                    nb_deplacements++;                    
                }
            }
    }
}


    int lab_choisir_deplacement(int deplacements_possible[][2], int nb_deplacement_possible) {

        if(nb_deplacement_possible>0) 
        {
           int choix = nb_aleatoire(0, nb_deplacement_possible - 1);

            return choix;

        }
        return 0; 
    }


    int lab_est_cases_adjacentes(int case1[2], int case2[2]) {
         
        if (case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1 || case1[1] == case2[1] && (case1[0] - case2[0] == 1))
        {
            return 1;  
        }
        return 0;  

    }



    int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int largeur_grille,
                           int hauteur_grille)

    {  
        if (position[0] == 0 && position[0] == hauteur_grille || position[1] == 0 && position[1] ==
                                                                                     largeur_grille) 
        {
            if (grille[position[0]][position[1]]== 0) {
                return 1;  
            }
        }
        return 0; 

    }




    int lab_resoudre_profondeur(
                     int grille[][TAILLE_MAX_GRILLE],
                     int hauteur_grille,
                     int largeur_grille,
                     int entree[2],
                     int pile_solution[][2],
                     int debug)
                     {


                 int pile_chemins_alternatif[hauteur_grille][largeur_grille];
                 int deplacement_possibles[4][2];
                 int nb_deplacements_possibles;
                 int nouvelle_position[2];
                 int ligne;
                 int colonne;
                 int linge_deplacement_possible;
                 int i;
                 int comparer_adj[2];
                 int tab_junk[100][2];
                 int k = 0;



                          
                 pile_initialiser(pile_solution, 1000);

                  
                 pile_initialiser(pile_chemins_alternatif, 1000);


                  
                 pile_empiler(pile_solution, entree[0], entree[1]);


                  
                 nouvelle_position[0] = entree[0];
                 nouvelle_position[1] = entree[1];

                 while (!lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille))
                 {
                     pile_haut_pile(pile_solution, &ligne, &colonne);

                     if (debug)
                     {
                         lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                     }


                     lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                                         ligne, colonne, pile_solution, &nb_deplacements_possibles,
                                                         deplacement_possibles);    

                     if (nb_deplacements_possibles > 0)
                     {

                          
                         linge_deplacement_possible = lab_choisir_deplacement(deplacement_possibles, nb_deplacements_possibles);
                                  


                 
                  pile_empiler(pile_solution, deplacement_possibles[linge_deplacement_possible][0],
                             deplacement_possibles[linge_deplacement_possible][1]);


                 
                pile_haut_pile(pile_solution, &nouvelle_position[0], &nouvelle_position[1]);


                 
                 
                for (i = 0; i < nb_deplacements_possibles; i++)
                {

                    if (i != linge_deplacement_possible)
                    {
                        pile_empiler(pile_chemins_alternatif, deplacement_possibles[i][0], deplacement_possibles[i][1]);

                    }

                }


            } else if (pile_est_vide(pile_chemins_alternatif) == 0)
            {
                 
                 
                pile_depiler(pile_chemins_alternatif, &nouvelle_position[0], &nouvelle_position[1]);

                 
                pile_haut_pile(pile_solution, &comparer_adj[0], &comparer_adj[1]);

                 
                 
                while (!lab_est_cases_adjacentes(nouvelle_position, comparer_adj)) {

                     
                     
                    pile_depiler(pile_solution, &tab_junk[k][0], &tab_junk[k][1]);

                     
                     
                    pile_haut_pile(pile_solution, &comparer_adj[0], &comparer_adj[1]);

                    k++;

                }

                 
                pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);


            } else
            {
                return 0;
            }


        }

        return 1;
    }