#include "labyrinthe.h"
#include <stdio.h>
#include "pile.h"
#include <time.h>
#include <stdlib.h>


void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille,int pile_solution[][2])
{
    for (int i=0; i<hauteur_grille; i++)
    {
        for (int j=0; j<largeur_grille; j++)
        {
            if (grille[i][j]==1)
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }
            if (j==largeur_grille-1)
            {
                printf("\n");
            }
            if (pile_solution!=NULL)
            {
                if (pile_contient(pile_solution, i, j))
                    {
                        printf("X");
                    }
                }
            }
        }
}

void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille,int pos_ligne,int pos_colonne,int solution_partielle[][2],int *nb_deplacements,int deplacements[4][2]) {
    int i = 0;
    *nb_deplacements = 0;
    //on regarde si la position adjacente est un mur ou non et si elle fait partie du tableau des solution partielle
    //si cette position adjacente n'est pas un mur , qu'elle ne se trouve pas dans le tableau de solutions partelles et qu'elle se trouve a l'intérieur de la grille
    //on ajoute cette position au tableau des deplacements possibles a la ligne adéquate
    if (grille[pos_ligne+1][pos_colonne]==0 && pile_contient(solution_partielle, pos_ligne+1, pos_colonne)==0 && pos_ligne+1<hauteur_grille && pos_colonne<largeur_grille && pos_ligne+1>=0 && pos_colonne>=0)
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne + 1;
        deplacements[i][1] = pos_colonne;
        i++;
    }
    if (grille[pos_ligne][pos_colonne+1]==0 && pile_contient(solution_partielle, pos_ligne, pos_colonne+1)==0 && pos_ligne<hauteur_grille && pos_colonne+1<largeur_grille && pos_ligne>=0 && pos_colonne+1>=0)
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne+1;
        i++;
    }
    if (grille[pos_ligne-1][pos_colonne]==0 && pile_contient(solution_partielle, pos_ligne-1, pos_colonne)==0 && pos_ligne-1<hauteur_grille && pos_colonne<largeur_grille && pos_ligne-1>=0 && pos_colonne>=0)
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne-1;
        deplacements[i][1] = pos_colonne;
        i++;
    }
    if (grille[pos_ligne][pos_colonne-1]==0 && pile_contient(solution_partielle, pos_ligne, pos_colonne-1)==0&& pos_ligne<hauteur_grille && pos_colonne-1<largeur_grille && pos_ligne>=0 && pos_colonne-1>=0)
    {
        (*nb_deplacements)++;
        deplacements[i][0] = pos_ligne;
        deplacements[i][1] = pos_colonne-1;
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles){
    int ligne_deplacement_choisit;
    srand((unsigned int)time(NULL));
    rand();
    //choisit une ligne aleatoire dans le tableau des deplacements possibles
    ligne_deplacement_choisit = nb_aleatoire(0, nb_deplacements_possibles-1);
    return ligne_deplacement_choisit;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2]){
    //si la case1 et case2 partagent soit une ligne ou une colone en commun et qu'elles se trouve à soit une ligne ou colone de distance de ±1 l'une de l'autre alors elles sont adjacentes
    if(case1[0] == case2[0]+1 || case1[0] == case2[0]-1 && case1[1] == case2[1]){
        return 1;
    }
    if(case1[1] == case2[1]+1 || case1[1] ==case2[1]-1 && case1[0] == case2[0]){
        return 1;
    }
    return 0;
}

int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille){
    //si la position se trouve sur une des lignes de contour du labyrinthe et qu'il ne se trouve pas de mur a cet espace cela signifie que c'est la sortie
    if(position[0]==0 || position[0]==hauteur_grille-1 && grille[position[0]][position[1]]==0){
        return 1;
    }
    if(position[1]==0 || position[1]==largeur_grille-1 && grille[position[0]][position[1]]==0){
        return 1;
    }
    return 0;
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pile_chemins_alternatifs[1000][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles;
    int nouvelle_position[2];
    int ligne_deplacement_choisit;
    int tab_temp[2];

    //Initialiser les deux piles
    pile_initialiser(pile_solution, 1000);
    pile_initialiser(pile_chemins_alternatifs, 1000);

    //Empiler(pile_solution, entrée)
    pile_empiler(pile_solution, entree[0], entree[1]);

    do{
        //Calculer les déplacements possibles à partir des coordonnées en haut de pile_solution, stocker le
        //résultat dans déplacements_possibles et le nombres de déplacements obtenus dans
        //nb_deplacements
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pile_solution[pile_solution[0][1]][0], pile_solution[pile_solution[0][1]][1], pile_solution, &nb_deplacements_possibles, deplacements_possibles);

        if(nb_deplacements_possibles>0){
            //Choisir un des déplacements obtenus et l’empiler dans pile_solution
            ligne_deplacement_choisit= lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            pile_empiler(pile_solution, deplacements_possibles[ligne_deplacement_choisit][0], deplacements_possibles[ligne_deplacement_choisit][1]);


            //Empiler les autres déplacements possibles dans la pile_chemins_alternatifs
            for (int i = 0; i < nb_deplacements_possibles - 1; ++i) {
                if (i != ligne_deplacement_choisit) {
                    pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                }
            }
        }
        else if(pile_chemins_alternatifs[0][1]>0){
            //nouvelle_position <- Dépiler ( pile_chemin_alternatifs)
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0], &nouvelle_position[1]);

            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pile_solution[pile_solution[0][1]][0], pile_solution[pile_solution[0][1]][1], pile_solution, &nb_deplacements_possibles, deplacements_possibles);
            //Dépiler de pile_solution jusqu’à ce que le haut de la pile contienne une case adjacente à
            //nouvelle_position
            do{
                pile_depiler(pile_solution, &tab_temp[0], &tab_temp[1]);
            }while(lab_est_cases_adjacentes(pile_solution[pile_solution[0][1]], nouvelle_position)==0);

            //Empiler nouvelle_position dans pile_solution
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);
            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pile_solution[pile_solution[0][1]][0], pile_solution[pile_solution[0][1]][1], pile_solution, &nb_deplacements_possibles, deplacements_possibles);
        }
    }while(nb_deplacements_possibles>0 && lab_est_une_sortie(pile_solution[pile_solution[0][1]], grille, hauteur_grille, largeur_grille)==0);

    return 1;
}