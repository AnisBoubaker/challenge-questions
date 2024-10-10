 
#include "labyrinthe.h"


void lab_afficher_grille (int grille[][TAILLE_MAX_GRILLE],
                          int hauteur_grille,
                          int largeur_grille,
                          int pile_solution[][2])
{
     
    for (int ligne = 0; ligne < hauteur_grille; ligne++)
    {
        for (int colone = 0; colone < largeur_grille; colone++)
        {
            if (grille[ligne][colone] == 1)
            {
                 
                 
                printf("%c", 219);
                printf(" ");
            }
            if (grille[ligne][colone] == 0)
            {
                 
                printf(" ");

                 
                 
                if (pile_solution != NULL)
                    if (pile_contient(pile_solution, ligne, colone) == 1)
                        printf("\bx");
            }
        }
        printf("\n");
    }
}


void test_lab_afficher_grille(void)
{
     
    int grille1[7][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 1, 0, 1, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 0, 1, 0, 0},
                                         {1, 0, 0, 1, 1},
                                         {1, 1, 1, 1, 1}};

     
    int pile_solution[10][2] = {{10, 8},
                                {0, 1},
                                {1, 1},
                                {1, 2},
                                {2, 2},
                                {3, 2},
                                {3, 3},
                                {4, 3},
                                {4, 4}};

     
    int pile_vide[10][2];


     
     
     
    lab_afficher_grille(grille1, 7, 5, pile_vide);
    printf("\n\n");
    lab_afficher_grille(grille1, 7, 5, pile_solution);
    printf("\n\n");
    lab_afficher_grille(grille1, 0, 2, pile_vide);

}



int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    srand((unsigned int)time(NULL));
    rand();

     
   return nb_aleatoire(0, nb_deplacements_possibles - 1);
}


int test_lab_choisir_deplacement(void)
{
     
    int deplacements_possibles[][2] = { {1,1}, {1,0}, {0,1}, {0,0}};
    int choix;

     
    for (int i = 0; i < 10; i++)
    {
        choix = lab_choisir_deplacement(deplacements_possibles, 4);
         
         
        if ((choix < 0) || (choix >= 4))
        {
            printf("Erreur");
            return 0;
        }
        else
            printf("%d\n", choix);
    }
    return 1;
 }





void lab_calculer_deplacements_possibles (int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,
                                          int largeur_grille,
                                          int pos_ligne,
                                          int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,
                                          int deplacements[4][2])
{
    *nb_deplacements = 0;
    int tab_pos_acc[] = {pos_ligne,
                         pos_colonne};                
    int copie_grille[2];                                                 
    int parcours;                                                       
    parcours = pile_taille_pile(solution_partielle);

    for (int i = 0; i < hauteur_grille; i++)                         
    {
        for (int a = 0; a < largeur_grille; a++)                      
        {
            copie_grille[0] = a;      
            copie_grille[1] = i;      
            if ((lab_est_cases_adjacentes(tab_pos_acc,copie_grille)))      
            {
                if (grille[a][i] != 1)                                                 
                {
                     
                     
                    for (int b = 0; b < (parcours -1); b++)
                    {
                        if (pile_est_vide(solution_partielle))
                        {
                            pile_empiler(deplacements, a + 1, i);

                            *nb_deplacements++;

                        }
                         
                        else if ((pile_contient(solution_partielle, a + 1, i)) == 0)  
                                                                                                         
                        {
                            pile_empiler(deplacements, a, i);
                            *nb_deplacements++;                                                  
                        }


                    }
                }
            }
        }
    }
}


int test_lab_deplacements_possibles(void)
{
    int hauteur_grille = 7;
    int largeur_grille = 7;

     
    int grille[][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1, 1, 1, 1},
                                       {1, 0, 0, 0, 0, 0, 1},
                                       {1, 1, 0, 1, 1, 0, 1},
                                       {1, 0, 0, 0, 1, 0, 1},
                                       {1, 0, 1, 1, 1, 0, 1},
                                       {1, 0, 0, 0, 0, 0, 1},
                                       {1, 1, 1, 1, 1, 0, 1}};

     
    int solution_partielle[][2] = {{9, 4},
                                   {0, 1},
                                   {1, 1},
                                   {2, 2},
                                   {3, 2},
                                   {0, 0},
                                   {0, 0},
                                   {0, 0},
                                   {0, 0}};

    int nb_deplacements;
    int deplacements[4][2];


    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,3,1,
                                        solution_partielle, &nb_deplacements, deplacements);

     
    printf("%i\n", nb_deplacements);
    printf("Déplacements possibles: \n");

     
    for (int k = 0; k < 4; k++)
    {
        printf("[%d, %d]\n", deplacements[k][0], deplacements[k][1]);
    }

}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
     
    if(case1[0] == case2[0])
    {
         
        if(case1[1] == (case2[1]+1) || case1[1] == (case2[1]-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
         
    else if(case1[1] == case2[1])
    {
         
        if(case1[0] == (case2[0]+1) || case1[0] == (case2[0]-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

 
 
int test_lab_est_cases_adjacentes(void)
{
     
    int case1[] = {5,4};
    int case2[] = {5,3};

    return lab_est_cases_adjacentes(case1, case2);;

}


int lab_est_une_sortie(const int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
     
     

    if ((position[0] == 0) || (position[0] == largeur_grille) || (position[1] == 0) || (position[1] == hauteur_grille)
                                                                                       && (grille[position[0]][position[1]] == 0))
        return 1;

         
    else
        return 0;
}

int test_lab_est_une_sortie(void)
{
     
     
     
     
    int position1[2] = {0, 1};
    int position2[2] = {1, 1};
    int position3[2] = {1, 0};
    int exemple_grille[4][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1},
                                                {1, 0, 0, 1},
                                                {1, 0, 1, 1},
                                                {1, 1, 1, 1}};

     
     
    if ((lab_est_une_sortie(position1, exemple_grille, 4, 4) == 1)
        && (lab_est_une_sortie(position2, exemple_grille, 4, 4) == 0)
        && (lab_est_une_sortie(position3, exemple_grille, 4, 4) == 0))
        return 1;

    else
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
    int pile_chemin_alternatif[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements = 1;
    int nouvelle_position[2];

    int pile_temporaire[TAILLE_MAX_PILE][2];
    int pos_temp[2];
    int indice;

    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemin_alternatif, TAILLE_MAX_PILE);

    pile_empiler(pile_solution, entree[0], entree[1]);
     
    if (debug == 1)
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

     
    while ((nb_deplacements != 0) && (pile_solution != NULL))
    {
        pile_haut_pile(pile_solution, &nouvelle_position[0], &nouvelle_position[1]);

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, nouvelle_position[0],
                                            nouvelle_position[1],pile_temporaire,
                                            &nb_deplacements,deplacements_possibles);

         
         
        if (nb_deplacements > 0)
        {
            indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements);
            pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]);

            afficher_grille_debug(grille, hauteur_grille, largeur_grille, pile_solution, debug);

            for(int i=0; i<nb_deplacements-1; i++)  
            {
                if (i != indice) {

                    pile_empiler(pile_chemin_alternatif, deplacements_possibles[i][0], deplacements_possibles[i][0]);
                    pile_chemin_alternatif[0][1]++;
                }
            }
        }
         
        else if (pile_chemin_alternatif[0][1] > 0)
        {
            pile_haut_pile(pile_chemin_alternatif, &nouvelle_position[0], &nouvelle_position[1]);

            do                  
            {
                pile_depiler(pile_solution, &pos_temp[0], &pos_temp[1]);

            } while (lab_est_cases_adjacentes(nouvelle_position, pos_temp) == 0);

             
             
            pile_empiler(pile_solution, pile_chemin_alternatif[pile_chemin_alternatif[0][1]][0],
                         pile_chemin_alternatif[pile_chemin_alternatif[0][1]][1]);
            afficher_grille_debug(grille, hauteur_grille, largeur_grille, pile_solution, debug);

            pile_depiler(pile_chemin_alternatif, &pos_temp[0], &pos_temp[1]);
        }
         
        else
            break;
    }

     
    int sortie[2];
    sortie[0] = pile_solution[pile_solution[0][1]][0];
    sortie[1] = pile_solution[pile_solution[0][1]][1];
    if (lab_est_une_sortie(sortie, grille, hauteur_grille, largeur_grille))
        return 1;
    else
        return 0;
}
