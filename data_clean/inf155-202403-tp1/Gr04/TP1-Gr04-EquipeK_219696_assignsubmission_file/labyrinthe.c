 

#include "labyrinthe.h"


void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{
    char ascii_219 = (char)219;  

    for (int i = 0; i < hauteur_grille; i++)  
    {
        for (int j = 0; j < largeur_grille; j++)  
        {
            if(grille[i][j] == 1)  
            {
                printf("%c", ascii_219);
            }
            else if (pile_contient(pile_solution,i,j))  
            {
                printf("X");
            }
            else  
            {
                printf(" ");
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
    int y = pos_ligne;  
    int x = pos_colonne;  
    int nb_possible = 0;  
    pile_initialiser(deplacements,4);  

    if(x >= 0 && x < largeur_grille && y>=0 && y<hauteur_grille)  
    {

         
        if(grille[y][x+1] == 0 && !pile_contient(solution_partielle,y,(x+1)) && (x+1) < largeur_grille)
        {
             
            nb_possible++;
             
            deplacements[nb_possible-1][0] = y;
            deplacements[nb_possible-1][1] = x+1;
        }

         
        if(grille[y+1][x] == 0 && !pile_contient(solution_partielle,(y+1),x) && (y+1) < hauteur_grille)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y+1;
            deplacements[nb_possible-1][1] = x;
        }

         
        if(grille[y-1][x] == 0 && !pile_contient(solution_partielle,(y-1),x) && (y-1) >= 0)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y-1;
            deplacements[nb_possible-1][1] = x;
        }

         
        if(grille[y][x-1] == 0 && !pile_contient(solution_partielle,y,(x-1)) && (x-1) >= 0)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y;
            deplacements[nb_possible-1][1] = x-1;
        }


    }
    *nb_deplacements = nb_possible;  
}

int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles)
{
    int choix = 0;  

     
     
    if(pile_est_vide(deplacements_possibles) == 0)
    {
        choix = nb_aleatoire(0,nb_deplacements_possibles-1);
    }

    return choix;

}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{

     
    if (case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1
    || case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1)
    {
        return 1;
    }

    return 0;  
}

int lab_est_une_sortie(
        const int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille)
{
    int y = position[0];  
    int x = position[1];  

     
    if(x == 0 || x == largeur_grille - 1 || y == 0 ||y == hauteur_grille - 1)  
    {
        if (grille[y][x] == 0)  
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
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = 1;  
    int nouvelle_position[2]= {0,0};

     
    int x_position_actuel = 0;
    int y_position_actuel = 0;

    int choix;  
    int haut_pile_sol[2]= {0,0};  

     
    int x_haut_pile_sol = 0;
    int y_haut_pile_sol = 0;

     
    srand((unsigned int)time(NULL));
    rand();

     
    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_PILE);

     
    pile_empiler(pile_solution,entree[0],entree[1]);
    pile_haut_pile(pile_solution,&y_position_actuel,&x_position_actuel);

     
    nouvelle_position[0] = y_position_actuel;
    nouvelle_position[1] = x_position_actuel;

     
    pas_a_pas(debug, grille, hauteur_grille, largeur_grille, pile_solution);


     
    do{

        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,y_position_actuel,x_position_actuel,pile_solution,&nb_deplacements_possibles,deplacements_possibles);

        if(nb_deplacements_possibles > 0)  
        {
             
            choix = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);
            pile_empiler(pile_solution,deplacements_possibles[choix][0],deplacements_possibles[choix][1]);

             
            pile_haut_pile(pile_solution,&y_haut_pile_sol,&x_haut_pile_sol);
            nouvelle_position[0] = y_haut_pile_sol;
            nouvelle_position[1] = x_haut_pile_sol;
            y_position_actuel = y_haut_pile_sol;
            x_position_actuel = x_haut_pile_sol;

             
            for(int i = 0; i < nb_deplacements_possibles; i++)
            {
                if(i != choix)
                {
                    pile_empiler(pile_chemins_alternatifs,deplacements_possibles[i][0],deplacements_possibles[i][1]);
                }
            }
        }

        else if(pile_est_vide(pile_chemins_alternatifs) == 0) 
        {
             
            pile_depiler(pile_chemins_alternatifs,&y_position_actuel,&x_position_actuel);
             
            nouvelle_position[0] = y_position_actuel;
            nouvelle_position[1] = x_position_actuel;

             
            pile_haut_pile(pile_solution,haut_pile_sol,haut_pile_sol+1);

             
            while(lab_est_cases_adjacentes(nouvelle_position,haut_pile_sol) == 0)
            {
                pile_depiler(pile_solution,&y_haut_pile_sol,&x_haut_pile_sol);
                haut_pile_sol[0] = y_haut_pile_sol;
                haut_pile_sol[1] = x_haut_pile_sol;

            }

             
            pile_empiler(pile_solution,y_haut_pile_sol,x_haut_pile_sol);
            pile_empiler(pile_solution,y_position_actuel,x_position_actuel);
             
            nb_deplacements_possibles = 1;
        }

         
        else
        {
            printf("Aucune solution trouvee :-(\n\n");
            return 0;
        }

         
        pas_a_pas(debug, grille, hauteur_grille, largeur_grille, pile_solution);


    }while(nb_deplacements_possibles > 0 && lab_est_une_sortie(nouvelle_position,grille,hauteur_grille,largeur_grille) == 0);


     
    return 1;

}




