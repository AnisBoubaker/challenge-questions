 

 
#include "labyrinthe.h"

 

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
     
    for (int i=0; i<hauteur_grille; i++)
    {
        for (int j=0; j<largeur_grille; j++)
        {
             
            if (grille[i][j] != 0)
            {
                printf("%c", 219);
            }
            else
            {
                 
                if (pile_contient(pile_solution, i, j))
                {
                    printf("X");
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
    system("pause");
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
    *nb_deplacements = 0;

     
     
    int direction_evaluee;

     
    int case_evaluee_ligne;
    int case_evaluee_colonne;

     
     
    for (direction_evaluee = 0; direction_evaluee < 4; direction_evaluee++)
    {
         
        case_evaluee_ligne = direction_evaluee % 2 ? pos_ligne : pos_ligne + direction_evaluee - 1;
        case_evaluee_colonne = direction_evaluee % 2 ? pos_colonne - (direction_evaluee - 2): pos_colonne;

         
        if (0 <= case_evaluee_ligne && case_evaluee_ligne < hauteur_grille
            && 0 <= case_evaluee_colonne && case_evaluee_colonne < largeur_grille)
        {
             
             
            if (grille[case_evaluee_ligne][case_evaluee_colonne] != 1
                && !pile_contient(solution_partielle, case_evaluee_ligne, case_evaluee_colonne))
            {
                 
                deplacements[*nb_deplacements][0] = case_evaluee_ligne;
                deplacements[*nb_deplacements][1] = case_evaluee_colonne;
                (*nb_deplacements)++;
            }
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice_deplacement = 0;  
    time_t temps;  

     
    srand((unsigned) time(&temps));

     
     if (nb_deplacements_possibles > 1)
     {
         indice_deplacement = rand() % nb_deplacements_possibles;
     }
    return(indice_deplacement);
}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int distance;  

     
    distance = abs(case1[0] - case2[0]) + abs(case1[1]- case2[1]);

     
    return distance == 1;
}

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
     
    return ( (grille[position[0]][position[1]] == 0)
        && (   (position[1] == (hauteur_grille - 1))
            || (position[1] == 0)
            || (position[0] == (largeur_grille - 1))
            || (position[0] == 0)
        )
    );
}

int lab_resoudre_profondeur( int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int continuer = 1;
    int resolution = 0;

    int chemins_alternatifs [TAILLE_MAX_PILE][2];  
    int position_alternative [2] = {0,0};  

    int position[2] = {0,0};  

     
    int deplacements_possibles[4][2]= {{0,0}, {0,0}, {0,0}, {0,0}};
    int nb_deplacements_possibles;  
    int indice;  

     
    pile_initialiser(chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0], entree[1]);

     
    position[0] = entree[0];
    position[1] = entree[1];

     
    do {
         
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,position[0],position[1],pile_solution, &nb_deplacements_possibles, deplacements_possibles);

         
        if(nb_deplacements_possibles != 0)
        {
             
            indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);

             
            pile_empiler(pile_solution,deplacements_possibles[indice][0], deplacements_possibles[indice][1]);
            position[0] = deplacements_possibles[indice][0];
            position[1] = deplacements_possibles[indice][1];

             
            if(nb_deplacements_possibles > 1)
            {
                for (int i = 0; i < nb_deplacements_possibles; i++)
                {
                    if(i != indice)
                    {
                        pile_empiler(chemins_alternatifs, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                    }
                }
            }
        }
         
        else if (!pile_est_vide(chemins_alternatifs))
        {
            pile_depiler(chemins_alternatifs,&position_alternative[0],&position_alternative[1]);
            do
            {
                pile_depiler(pile_solution, &position[0], &position[1]);
            }while(!lab_est_cases_adjacentes(position,position_alternative));

            pile_empiler(pile_solution, position[0],position[1]);
            pile_empiler(pile_solution, position_alternative[0],position_alternative[1]);
        }
         
        else
        {
            return 0;
        }

         
        pile_haut_pile(pile_solution,&position[0],&position[1]);

        if (lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille))
        {
            return 1;
        }

        if (debug)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
        }
    }while(1);
}
