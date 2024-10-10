 

 
#include <stdio.h>
#include "pile.h"
#include "labyrinthe.h"
#include "utilitaires.h"

 
 
#define MUR_LAB 219
 
#define SOL_LAB 88
 
#define COULOIR_LAB 32


 
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                         int largeur_grille, int pile_solution[][2])
{
    int ligne, colonne;  

     
    for (ligne = 0; ligne < hauteur_grille; ligne++)
    {
         
        for (colonne = 0; colonne < largeur_grille; colonne++)
        {
             
            if (grille[ligne][colonne] == 1)
                printf("%c", MUR_LAB);
            else
            {
                 
                if (pile_est_vide(pile_solution) != 1)
                {
                     
                    if (pile_contient(pile_solution, ligne, colonne) == 1)
                        printf("%c", SOL_LAB);
                    else
                         
                        printf("%c", COULOIR_LAB);
                }
                else
                     
                    printf("%c", COULOIR_LAB);
            }
        }
         
        printf("\n");
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille, int largeur_grille,
                                         int pos_ligne, int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements, int deplacements[4][2])
{
     
    int directions[4][2] = {{-1, 0},     
                            {1,  0},     
                            {0,  -1},    
                            {0,  1}};    
    int nouvelle_ligne;
    int nouvelle_colonne;

     
    *nb_deplacements = 0;

    for (int i = 0; i < 4; i++)
    {
        nouvelle_ligne = pos_ligne + directions[i][0];
        nouvelle_colonne = pos_colonne + directions[i][1];

         
        if (nouvelle_ligne >= 0 && nouvelle_ligne < hauteur_grille - 1 &&
            nouvelle_colonne >= 0 && nouvelle_colonne < largeur_grille - 1)
        {
             
            if (grille[nouvelle_ligne][nouvelle_colonne] != 1 &&
                !pile_contient(solution_partielle, nouvelle_ligne, nouvelle_colonne))
            {
                deplacements[*nb_deplacements][0] = nouvelle_ligne;
                deplacements[*nb_deplacements][1] = nouvelle_colonne;
                (*nb_deplacements)++;
            }
        }
    }
}


int lab_choisir_deplacement(int deplacements_possibles[][2],
                            int nb_deplacements_possibles)
{
     
    int indice_choisi;

     
    indice_choisi = -1;
    indice_choisi = nb_aleatoire(0, nb_deplacements_possibles - 1);

    return indice_choisi;
}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
     
    if ((case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1) ||
        (case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1))
        return 1;
    else
         
        return 0;
}


int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille, int largeur_grille)
{
     
    int est_une_sortie = 0;

     
    if (position[0] == 0 || position[0] == hauteur_grille - 1 ||
        position[1] == 0 || position[1] == largeur_grille - 1)
    {
         
        if (grille[position[0]][position[1]] != 1)
            est_une_sortie = 1;  
    }
    return est_une_sortie;
}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                            int largeur_grille, int entree[2], int pile_solution[][2],
                            int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];

    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = -1;
    int nouvelle_position[2];

    int case_haut_pile[2];
    int choix_deplacement;
    int pos_ligne, pos_colonne;

     
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

     
    pile_empiler(pile_solution, entree[0], entree[1]);

     
    while (nb_deplacements_possibles != 0 &&
           lab_est_une_sortie(case_haut_pile, grille, hauteur_grille, largeur_grille) != 1)
    {
         
        pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);

         
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                            pos_ligne, pos_colonne, pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possibles);
         
        if (nb_deplacements_possibles > 0)
        {
             
            choix_deplacement = lab_choisir_deplacement(deplacements_possibles,
                                                        nb_deplacements_possibles);

             
            pile_empiler(pile_solution, deplacements_possibles[choix_deplacement][0],
                         deplacements_possibles[choix_deplacement][1]);

             
            for (int i = 0; i < nb_deplacements_possibles; i++)
            {
                if (i != choix_deplacement)
                    pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0],
                                 deplacements_possibles[i][1]);
            }

        }
             
        else if (pile_est_vide(pile_chemins_alternatifs) != 1 &&
                 lab_est_une_sortie(case_haut_pile, grille, hauteur_grille, largeur_grille) != 1)
        {
             
            pile_depiler(pile_chemins_alternatifs,
                         &nouvelle_position[0], &nouvelle_position[1]);

            pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);

             
             
            while (lab_est_cases_adjacentes(case_haut_pile, nouvelle_position) != 1)
            {
                pile_depiler(pile_solution, &pos_ligne, &pos_colonne);
                pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);
            }

             
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                                pos_ligne, pos_colonne, pile_solution,
                                                &nb_deplacements_possibles,
                                                deplacements_possibles);

        }
        else
             
            break;
         
        if (debug)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            printf("\n");
            system("pause");
        }
        pile_haut_pile(pile_solution, &case_haut_pile[0], &case_haut_pile[1]);
    }
     
    return lab_est_une_sortie(pile_solution[1], grille, hauteur_grille, largeur_grille);
}
