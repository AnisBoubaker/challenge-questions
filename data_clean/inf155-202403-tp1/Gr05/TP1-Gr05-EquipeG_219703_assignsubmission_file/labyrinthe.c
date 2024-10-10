 

 
#include <stdlib.h>
#include <stdio.h>
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include "time.h"

 
 
#define TAILLE_MAX_GRILLE 100
 
#define TAILLE_MAX_PILE 100

 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                         int largeur_grille, int pile_solution[][2])
{
    int colonne;  
    int ligne;  
    int etat_pile;  
    unsigned char mur = 219;  
    char couloir = 32;  
    char pion = 88;  


     
     if (pile_solution == NULL)
     {
         for (ligne = 0; ligne < hauteur_grille; ligne++)
         {
             for (colonne = 0; colonne < largeur_grille; colonne++)
             {
                 if (grille[ligne][colonne] == 1)
                 {
                     printf("%c", mur);
                 }
                 if (grille[ligne][colonne] == 0)
                 {
                     printf("%c", couloir);
                 }
             }
             printf("\n");
         }
     }
   
    if (pile_solution != NULL)
    {
        for (ligne = 0; ligne < hauteur_grille; ligne++)
        {
            for (colonne = 0; colonne < largeur_grille; colonne++)
            {
                etat_pile = pile_contient(pile_solution,ligne, colonne);

                if (grille[ligne][colonne] == 1)
                {
                    printf("%c", mur);
                }
                if (grille[ligne][colonne] == 0 && etat_pile == 0)
                {
                    printf("%c", couloir);
                }

                if (grille[ligne][colonne] == 0 && etat_pile == 1)
                {
                    printf("%c", pion);
                }
            }
            printf("\n");
        }
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille, int largeur_grille,int pos_ligne,
                                         int pos_colonne, int solution_partielle[][2], int *nb_deplacements,
                                         int deplacements[4][2])
{

    int pos_temp[2] = {0};  
    int verif_sol;  

     
    *nb_deplacements = 0;  

     
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           deplacements[i][j] = 0;
        }
    }

     
     
    dplc_haut(pos_temp, pos_ligne, pos_colonne);
     
    verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

     
    if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
        grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
    {
        if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
        {
             
            deplacements[*nb_deplacements][0] = pos_temp[1];
             
            deplacements[*nb_deplacements][1] = pos_temp[0];
             
            (*nb_deplacements)++;
        }
    }

         
         
        dplc_bas(pos_temp, pos_ligne, pos_colonne);
         
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);


         
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
            grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                 
                deplacements[*nb_deplacements][0] = pos_temp[1];
                 
                deplacements[*nb_deplacements][1] = pos_temp[0];
                 
                (*nb_deplacements)++;

            }
        }
         
         
        dplc_gauche(pos_temp, pos_ligne, pos_colonne);
         
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

         
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
            grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                 
                deplacements[*nb_deplacements][0] = pos_temp[1];
                 
                deplacements[*nb_deplacements][1] = pos_temp[0];
                 
                (*nb_deplacements)++;
            }
        }

         
         
        dplc_droite(pos_temp, pos_ligne, pos_colonne);
         
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

         
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille && grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                 
                deplacements[*nb_deplacements][0] = pos_temp[1];
                 
                deplacements[*nb_deplacements][1] = pos_temp[0];
                 
                (*nb_deplacements)++;
             }
        }
}


int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    int choix_al;  
    if(nb_deplacements_possibles == 1)
    {
        return 0;
    }
    else if (nb_deplacements_possibles > 1)
    {
         
        srand((unsigned int) time(NULL));
        rand();

        choix_al = nb_aleatoire(1, nb_deplacements_possibles);
         
        return choix_al -1;
    }
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int coordonnee_x1;  
    int coordonnee_y1;  
    int coordonnee_x2;  
    int coordonnee_y2;  

    coordonnee_x1 = case1[0];  
    coordonnee_y1 = case1[1];  
    coordonnee_x2 = case2[0];  
    coordonnee_y2 = case2[1];  

     
    if (coordonnee_x1 == coordonnee_x2 && (coordonnee_y1 - coordonnee_y2 == -1
        || coordonnee_y1 - coordonnee_y2 == 1))
    {
         
        return 1;
    }

     
    if (coordonnee_y1 == coordonnee_y2 && (coordonnee_x1 - coordonnee_x2 == -1
        || coordonnee_x1 - coordonnee_x2 == 1))
    {
         
        return 1;
    }
         
        return 0;
    }

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
     
     
     

     
    if (position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0
        || position[1] == largeur_grille - 1)
    {
         
        if (grille[position[0]][position[1]] != 1)
        {
             
            return 1;
        }
        else
        {
             
            return 0;
        }
    }
    else
    {
         
        return 0;
    }
}



int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int pos_ligne = 0;  
    int pos_colonne = 0;  
    int pile_historique[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2];  
    int deplacements_possibles[4][2];  
    int nb_deplacements_possibles = 0;  
    int deplacement_choisie;  
    int nouvelle_position[2];  
    int pos_a_comparer[2];  
    int sortie = 0;  
    int cas = 0;  
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2];  
     
    pos_ligne=entree[0];
    pos_colonne=entree[1];

     
     
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
     
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
     
    pile_initialiser(pile_historique, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);

     
     
    pile_empiler(pile_solution, entree[0], entree[1]);
     
    pile_empiler(pile_historique, entree[0], entree[1]);

     
    do
    {
         
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pos_ligne,
                                            pos_colonne,pile_historique,
                                            &nb_deplacements_possibles,deplacements_possibles);



         
        if (nb_deplacements_possibles > 0)
        {
             
            deplacement_choisie = lab_choisir_deplacement(deplacements_possibles,
                                                          nb_deplacements_possibles);

             
             
            nouvelle_position[0]=deplacements_possibles[deplacement_choisie][0];
             
            nouvelle_position[1]=deplacements_possibles[deplacement_choisie][1];

             
             
             
            pos_ligne=deplacements_possibles[deplacement_choisie][0];
             
            pos_colonne=deplacements_possibles[deplacement_choisie][1];

             
            pile_empiler(pile_solution, pos_ligne,pos_colonne);
            pile_empiler(pile_historique, pos_ligne,pos_colonne);

             
            sortie = lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille);

             
            if(nb_deplacements_possibles>1)
            {
                 
                for (int j = 0; j <nb_deplacements_possibles; j++)
                {
                    if (j != deplacement_choisie)
                    {
                        pile_empiler(pile_chemins_alternatifs,
                                     deplacements_possibles[j][0], deplacements_possibles[j][1]);
                    }
                }
            }

             
            if(debug==1)
            {
                printf("\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }

         
        else if (pile_chemins_alternatifs != NULL)
        {

             
            pile_depiler(pile_chemins_alternatifs, &pos_ligne, &pos_colonne);

             
            nouvelle_position[0] = pos_ligne;
             
            nouvelle_position[1] = pos_colonne;

             
            do
            {

                 
                pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);
                 
                pos_a_comparer[0]=pos_ligne;
                 
                pos_a_comparer[1]=pos_colonne;
                 
                cas=lab_est_cases_adjacentes(nouvelle_position, pos_a_comparer);


                 
                if(cas==0)
                {
                    pile_depiler(pile_solution, &pos_ligne, &pos_colonne);
                }
              
            }while(cas == 0);

             
            pile_empiler(pile_solution, nouvelle_position[0],nouvelle_position[1]);
            pile_empiler(pile_historique, nouvelle_position[0],nouvelle_position[1]);

            pos_ligne=nouvelle_position[0];
            pos_colonne=nouvelle_position[1];
             
            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                                nouvelle_position[0], nouvelle_position[1],
                                                pile_historique, &nb_deplacements_possibles,
                                                deplacements_possibles);
        }


 
    } while (nb_deplacements_possibles > 0 && sortie == 0);

    if(debug==0)
    {
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
    if(debug==1)
    {
        printf("\n");
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }

     
    if (sortie == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}