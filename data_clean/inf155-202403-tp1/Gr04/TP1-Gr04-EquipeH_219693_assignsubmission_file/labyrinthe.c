 


#include "labyrinthe_io.h"
#include "labyrinthe.h"
#include "utilitaires.h"

void lab_afficher_grille(int tab[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {
    int check =0;   
    int couleur = 31;   


    for (int i = 0; i < hauteur_grille; ++i)       
    {
        for (int j = 0; j < largeur_grille; ++j)
        {
            if(tab[i][j] == 1)   
            {
                printf("%c", 219);
            }
            else {      
                if (pile_solution != NULL) {  
                    check = 0;

                    if (valider_coords_dans_pile(pile_solution,pile_solution[0][1],j,i) == 1)  
                    {                                                                                          
                        printf("\033[0;%im", couleur);  
                        printf("X");
                        printf("\033[0m");    
                        couleur++;   
                        if (couleur == 37)
                        {
                            couleur = 31;
                        }
                        check = 1;                   
                    }

                    if (check == 0){             
                        printf(" ");
                    }

                }
                else{
                    printf(" ");       
                }
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
        int* nb_deplacements,
        int deplacements[4][2]
)
{
    int position_x,position_y = 0;  

    *nb_deplacements = 0;

     
    for (int i = 0; i < 4; ++i) {

        switch (i) {
            case 0:
                position_x = pos_ligne - 1;
                position_y = pos_colonne;
                break;
            case 1:
                position_x = pos_ligne + 1;
                position_y = pos_colonne;
                break;
            case 2:
                position_x = pos_ligne;
                position_y = pos_colonne - 1;
                break;
            case 3:
                position_x = pos_ligne;
                position_y = pos_colonne + 1;
                break;

        }
         
        if(position_x >= 0 && position_x < largeur_grille && position_y >= 0 && position_y < hauteur_grille) {

             
            if (grille[position_y][position_x] == 1) {
                continue;
            }
             
            else if (valider_coords_dans_pile(solution_partielle, solution_partielle[0][1], position_x, position_y) == 1) {
                continue;
            } else {
                deplacements[*nb_deplacements][0] = position_x;  
                deplacements[*nb_deplacements][1] = position_y;
                *nb_deplacements += 1;
            }
        }
    }
}


int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)  
{
    srand((unsigned int)time(NULL));
    rand();

    return nb_aleatoire(0,nb_deplacements_possibles-1);  
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    if(abs(case1[0] - case2[0]) + abs(case1[1] - case2[1]) == 1)   
    {                                                                    
        return 1;
    }
    return 0;
}

int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{
    if((position[0] == 0 || position[1] == 0 || position[0] == largeur_grille-1 || position[1] == hauteur_grille-1) && grille[position[1]][position[0]] == 0)
    {                        
        return 1;
    }
    return 0;
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    pile_initialiser(pile_solution,pile_solution[0][0]);   
    int pile_chemins_alternatifs[pile_solution[0][0]][2] = {};   
    int deplacements_possibles[4][2] = {};     
    int nb_deplacements =1;                    
    int nouvelle_position[2] = {};             
    int success = 1;                           

    pile_initialiser(pile_chemins_alternatifs,100);   

    pile_empiler(pile_solution, entree[1],entree[0]);   

    do {
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                            pile_solution[pile_solution[0][1]][0],
                                            pile_solution[pile_solution[0][1]][1],
                                            pile_solution,
                                            &nb_deplacements, deplacements_possibles);  

        if (nb_deplacements > 0) {   

            pile_empiler(pile_solution,      
                         deplacements_possibles[lab_choisir_deplacement(deplacements_possibles, nb_deplacements)][0],
                         deplacements_possibles[lab_choisir_deplacement(deplacements_possibles, nb_deplacements)][1]);

            for (int i = 0; i < nb_deplacements; ++i) {   
                if (pile_solution[pile_solution[0][1]][0] != deplacements_possibles[i][0] || pile_solution[pile_solution[0][1]][1] != deplacements_possibles[i][1])
                {
                    pile_empiler(pile_chemins_alternatifs,
                                 deplacements_possibles[i][0],
                                 deplacements_possibles[i][1]);
                }
            }
        }
        else if (pile_est_vide(pile_chemins_alternatifs) != 1)  
        {                                                            
            nouvelle_position[0] = pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][0];  
            nouvelle_position[1] = pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][1];  
            pile_depiler(pile_chemins_alternatifs,           
                         &pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][0],
                         &pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][1]);

            do {                                      
                pile_depiler(pile_solution,      
                             &pile_solution[pile_solution[0][1]][0],
                             &pile_solution[pile_solution[0][1]][1]);

            } while (lab_est_cases_adjacentes(pile_solution[pile_solution[0][1]], nouvelle_position) == 0);

            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);  
        }
        else   
        {
            success = 0;
            printf("Aucune solution trouvee :-(\n");
            system("pause");
            break;   
        }

        if (debug != 0)   
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }



    }while (lab_est_une_sortie(pile_solution[pile_solution[0][1]], grille, hauteur_grille, largeur_grille) == 0);
     

    if (debug == 0 && success == 1)  
    {
        lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
    }

    if (success == 1) {
        printf("\n"                                          
               "  _____             __     __     __     __\n"
               " / ___/__  ___  ___/ / __ / /__  / /    / /\n"
               "/ (_ / _ \\/ _ \\/ _  / / // / _ \\/ _ \\  /_/ \n"
               "\\___/\\___/\\___/\\_,_/  \\___/\\___/_.__/ (_)  \n"
               "                                           \n");
        system("pause");
    }
    return success;
}




