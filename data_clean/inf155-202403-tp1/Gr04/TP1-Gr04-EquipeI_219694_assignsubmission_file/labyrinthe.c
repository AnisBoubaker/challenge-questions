#include <labyrinthe.h>

#define TAILLE_MAX_GRILLE 100

void lab_afficher_grille(int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE],int hauteur_grille, int largeur_grille,int pile_solution[][2])
{
    char mur=219;
    int solution;
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if(grille[i][j]==1)
            {
                printf("%c",mur);
            }
            if(grille[i][j]==0)
            {

                if (pile_solution != NULL) {
                    for (int k = 0; k <= pile_solution[k][0]; k++) {
                        if (pile_solution[k][0] == i && pile_solution[k][1] == j)
                        {
                            printf("X");
                            break;
                        }
                        else{
                            printf(" ");
                            break;
                        }

                    }
                }
            } else
            {
                printf(" ");
            }
        }

        printf("\n");

    }
}


int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice;
    srand(time(NULL));

    indice= rand()%nb_deplacements_possibles;

    return indice;

}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    return ((case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1) || (case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1));
}

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    if (position[0] == 0 || position[0] == largeur_grille - 1)
    {
        return 1;
    } else if (position[1] == 0 || position[1] == hauteur_grille - 1) {
        return 1;
    } else {
        return 0;
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

    *nb_deplacements=0;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    int nouvelle_ligne;
    int nouvelle_colonne;
    int mur;
    int solution;

            for (int i = 0; i < 4; i++)
            {
                nouvelle_ligne=pos_ligne+dx[i];
                nouvelle_colonne=pos_colonne+dy[i];
                if(nouvelle_ligne>=0 && nouvelle_ligne<hauteur_grille && nouvelle_colonne>=0 && nouvelle_colonne< largeur_grille)
                {
                mur=grille[nouvelle_ligne][nouvelle_colonne];
                solution=0;
                }
                for (int j = 0; solution_partielle[j][0]!=-1; j++)
                {
                if(solution_partielle[j][0]== nouvelle_ligne&& solution_partielle[j][1]==nouvelle_colonne)
                {
                solution=1;
                break;
                }
                }
                if(!mur && !solution)
                {
                deplacements[*nb_deplacements][0]=nouvelle_ligne;
                deplacements[*nb_deplacements][1]=nouvelle_colonne;
                *nb_deplacements++;
                }
            }
}
int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
        {
    int pile_chemin_alternatifs[TAILLE_MAX_GRILLE][2];
    int deplacement_possible[4][2];
    int nb_deplacement;
    int nouvelle_pos[2];
    int choix;
    int ligne,colonne;

            pile_initialiser(pile_solution,TAILLE_MAX_GRILLE);
            pile_empiler(pile_solution,entree[0],entree[1]);

            while(1)
            {
                if(debug){
                    printf("Position actuelle: [%d,%d]\n",pile_solution[0][0], pile_solution[0][1]);
                }
                lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,pile_solution[0][0],pile_solution[0][1],
                                                    pile_solution,&nb_deplacement,deplacement_possible);

               if(nb_deplacement>0)
               {
                   choix = rand() % nb_deplacement;

                   pile_empiler(pile_solution, deplacement_possible[choix][0], deplacement_possible[choix][1]);
                if(debug){
                    printf("Deplacement fait:[%d,%d]\n",deplacement_possible[choix][0],deplacement_possible[choix][1]);
                }

                   for (int i = 0; i < nb_deplacement; i++) {
                       if (i != choix) {

                           pile_empiler(pile_chemin_alternatifs, deplacement_possible[i][0],
                                        deplacement_possible[i][1]);
                       }
                   }
               }
                else if (!pile_est_vide(pile_chemin_alternatifs))
                {
                    if(pile_depiler(pile_chemin_alternatifs,&ligne,&colonne))
                    {
                        nouvelle_pos[0]=ligne;
                        nouvelle_pos[1]=colonne;
                    }

                    while (pile_solution[0][0]!= nouvelle_pos[0] || pile_solution[0][1]!= nouvelle_pos[1])
                    {
                        pile_depiler(pile_solution,NULL,NULL);
                    }
                    pile_empiler(pile_solution,nouvelle_pos[0],nouvelle_pos[1]);

                }
                else {
                    if(debug){
                        printf("Aucun deplacement possible et aucun chemin alternatif... Veuillez revenir en arriere.\n");
                    }
                    return 0;
                }

                if(grille[pile_solution[0][0]][pile_solution[0][1]]==2)
                {
                    return 1;
                }
            }

}