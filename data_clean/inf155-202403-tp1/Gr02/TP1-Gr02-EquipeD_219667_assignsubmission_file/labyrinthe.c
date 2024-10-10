 

#include "labyrinthe.h"
#include "pile.h"
#include <stdio.h>
#include "utilitaires.h"


void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],
                         int hauteur_grille,
                         int largeur_grille,
                         int pile_solution[][2])
{
     
    int pile_copie[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2];
    pile_copier(pile_solution, pile_copie);

     
    while (!pile_est_vide(pile_copie))
    {
        int ligne, colonne;
        pile_depiler(pile_copie, &ligne, &colonne);
        grille[ligne][colonne] = 2;
    }

     
    for (int i = 0; i < hauteur_grille; i++ )   
    {
        for (int j = 0; j < largeur_grille; j++)  
        {
            if (grille[i][j] == 1)
            {
                printf("%c", 219);  
            }
            else if (grille[i][j] == 0 || grille[i][j] == 3 )
            {
                printf(" ");  
            }
            else if (grille[i][j] == 2)
            {
                printf("X");  
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
    int i = 0;

     
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne+1,pos_colonne,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne+1;
        deplacements[i][1] = pos_colonne;
        i++;
    }

    
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne-1,pos_colonne,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne-1;
        deplacements[i][1] = pos_colonne;
        i++;
    }

     
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne+1,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne+1;
        i++;
    }

     
    if (deplacement_est_possible(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne-1,solution_partielle))
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne-1;
    }
}

int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles)
{
     
    if (nb_deplacements_possibles <= 0)
    {
        return -1;
    }

     
     
    int choix = rand() % nb_deplacements_possibles;

     
    return choix;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int dx, dy;

    dx = case1[0] - case2[0];  
    dy = case1[1] - case2[1];  

     
     
    if ((abs(dx) + abs(dy)) == 1)
    {
        return 1;  
    }
    else
    {
        return 0;  
    }
}

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
     
    if (position[0] == 0 || position[1] == 0 || position[0] == hauteur_grille-1 || position[1] == largeur_grille-1)
    {
         
        if (grille[position[0]][position[1]] != 1)
        {
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
     
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = 0;
    int nouvelle_position[2];
    int position[2] = {};
    int done = 0;
    int ligne,colonne;

     
    int comp[2];

    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);

     
    pile_empiler(pile_solution, entree[0], entree[1]);
    lab_calculer_deplacements_possibles(grille,
                                        hauteur_grille,
                                        largeur_grille,
                                        entree[0],
                                        entree[1],
                                        pile_solution,
                                        &nb_deplacements_possibles,
                                        deplacements_possibles);


     
    while (!lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille) && done != 1)
    {
        if (nb_deplacements_possibles > 0)
        {
             
            int indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]);

                 
                if (debug)
                {
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                    fflush(stdin);
                    getchar();
                }

             
            for (int i = 1; i < nb_deplacements_possibles ; i++ )
            {
                 
                if (grille[deplacements_possibles[(indice+i)%nb_deplacements_possibles][0]]
                          [deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]] != 3)
                {
                     
                    pile_empiler(pile_chemins_alternatifs,
                                 deplacements_possibles[(indice+i)%nb_deplacements_possibles][0],
                                 deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]);

                     
                    grille[deplacements_possibles[(indice+i)%nb_deplacements_possibles][0]]
                          [deplacements_possibles[(indice+i)%nb_deplacements_possibles][1]] = 3;
                }
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
             
            pile_depiler(pile_chemins_alternatifs, &ligne, &colonne);

            nouvelle_position[0] = ligne;
            nouvelle_position[1] = colonne;

             
            while (!lab_est_cases_adjacentes(nouvelle_position, comp))
            {
                pile_depiler(pile_solution,&ligne,&colonne);
                grille[ligne][colonne] = 0;
                pile_haut_pile(pile_solution, &ligne, &colonne);
                comp[0] = ligne;
                comp[1] = colonne;
            }

             
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

             
            if (debug)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar();
            }

        }
        else
        {
            done = 1;  
        }

         
        pile_haut_pile(pile_solution, &ligne, &colonne);
        nb_deplacements_possibles = 0;
        lab_calculer_deplacements_possibles(grille,
                                            hauteur_grille,
                                            largeur_grille,
                                            ligne, colonne, pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possibles);
        position[0] = ligne;
        position[1] = colonne;
    }

     
    if (lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille))
    {
        pile_empiler(pile_solution, position[0], position[1]);

        return 1;  
    }

    return 0;  
}