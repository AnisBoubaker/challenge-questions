
/*
 * Titre: labyrinthe.c
 * Description: Impl�mentation des fonctions du module labyrinthe
 *
 * Auteur: Iman Assameur, Hoang Yen Pham, Cory Gallego, Emily Wu
 * Date: 16-10-2023
 *
 */
#include "labyrinthe.h"
#define TAILLE_MAX_GRILLE 100

void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{
    char etoile = '*';
    int ligne;//REVOIR ICI LIGNE ET COLONNES NON UTILISÉES
    int colonne;
    for(int i = 0 ; i < hauteur_grille; i++)
    {
        for(int j = 0; j < largeur_grille; j++ )
        {
            if(grille[i][j] == 1 )
            {
                printf(" %c ", etoile);
            }
            else if(pile_est_vide(pile_solution) == 0)
            {
                if(pile_contient(pile_solution, i, j) == 1)
                {
                    printf(" X ");
                }

            }
            else
            {
                printf(" ");
            }
        }
            printf("\n");
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille,
                                         int largeur_grille,
                                         int pos_ligne,
                                         int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements,
                                         int deplacements[4][2]) {


    *nb_deplacements = 0;

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {


            int case1[2] = {i, j};
            int case2[2] = {pos_ligne, pos_colonne};


            if (lab_est_cases_adjacentes(case1, case2) == 1)
            {
                if (pile_contient(solution_partielle, i, j) == 0)
                {
                    if (grille[i][j] == 1)
                    {
                        //fait rien car mur
                    }
                    if (grille[i][j] == 0)
                    {
                        pile_empiler(deplacements, i, j);
                        (*nb_deplacements)++;
                    }
                } else if (pile_contient(solution_partielle, i, j) ==1)
                    //pile_contient retourne 1 si solution est deja dans pile
                    {
                    // nothing

                    }

            }
        }
    }

}

int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles) {

    int indice;
    int mn = 1;
    int mx = nb_deplacements_possibles;
    int nb_indices = pile_taille_pile(deplacements_possibles); //nombre d'elements dans deplacements_possibles (indice)


    indice = nb_aleatoire(mn, mx);

    while (0 > indice || indice > nb_indices) { // verifier si indice fait pari de la pile
        nb_aleatoire(mn, mx);
    }

    return indice;
}

/************** FONCTION LAB_EST_UNE_SORTIE *************/

int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille){

    int x = position [0];
    int y = position [1];

    // Verifier que la sortie est en peripherie
    if (x==0 || x==hauteur_grille-1 || y==0 || y==largeur_grille-1)
    {

        //Verifier si la position est un mur
         if (grille[x][y] != 0)
         {

             printf("%d, %d est une sortie !", position[0], position[1]);
         }
         return 1; //retour vrai si c'est une sortie
    }
    else
    {
        return 0;// retour faux si n'est pas une sortie
    }
}

/******* FONCTION LAB_EST_CASES_ADJACENTES **********/
int lab_est_cases_adjacentes (int case1[2], int case2[2])
{
    if(case1[0]==case2[0]|| case1[1]==case2[1])
    { //Des cases adjacentes se partagent soit la premiere position (0) ou la deuxième position(1)

        return 1;// retour de vrai si adjacentes
    }
    else
    {
        return 0;//retour de faux si ne sont pas adjacentes
    }

}


/************** FONCTION LAB_RESOUDRE_PROFONDEUR *************/
int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)

        {
             int pile_chemin_alt[][2]={};

             pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);
             pile_initialiser(pile_chemin_alt, TAILLE_MAX_GRILLE);

             pile_empiler(pile_solution, entree[0], entree[1]);

             int solutionTF=0; //si une solution a ete trouvee 1=true 0=pas trouvee
             int pos_ligne;
             int pos_colonne;
             int nb_deplacements; //nb deplacements possibles
             int deplacements_possibles[4][2];
             int nouvelle_position[2];
             int case_adj= 0;
             int poubelle[2];
             int haut_pile_sol[2];


             while(solutionTF==0 && pile_est_vide(pile_chemin_alt) && nb_deplacements!=0) //while il est possible de se deplacer et solution pas trouvee
             {
                 debug=0;

                 pile_initialiser(deplacements_possibles, 4); //initialiser
                 pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);

                 lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pos_ligne, pos_colonne, pile_solution, &nb_deplacements,&deplacements_possibles);

                 if (nb_deplacements>0)
                 {
                        int indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements); //choisir deplacement
                        pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]); //empiler dans solutions
                        for (int i = 0; i <= nb_deplacements; i++) // mettre le reste dans la pile chemins alternatifs
                        {
                            if (i != indice)
                            {
                                pile_empiler(pile_chemin_alt, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                                debug=1;
                            }

                        }

                     if(debug==1){
                         lab_afficher_grille(grille,hauteur_grille, largeur_grille, pile_solution);
                         debug=0;
                     }
                 }
                 else if(pile_est_vide(pile_chemin_alt) == 0 ) //si chemin_alt n'est pas vide
                 {
                     debug=0;
                     pile_depiler(pile_chemin_alt, &nouvelle_position[0], &nouvelle_position[1]); //depiler la pile chemin alt a nouvelle position
                     pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]); //case haut de la pile solution stocker dans haut_pile_sol
                     case_adj= lab_est_cases_adjacentes(haut_pile_sol, nouvelle_position); //verifier si les cases sont adjacentes

                         while (case_adj==0) //depiler jusqua ce que la case du haut pile solution soit adj a celle de la nouvelle position
                         {
                             pile_depiler(pile_solution, &poubelle[0], &poubelle[1]); //deipler pile_solution
                             pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]); //stocker nouvelle case du haut de la pile dans haut_ pile_sol

                             case_adj= lab_est_cases_adjacentes(nouvelle_position, haut_pile_sol); //verifier si elles sont adj
                         }
                         if (case_adj==1)
                        {

                         pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]); //empiler dans la pile solution lorsqu'elle est adjacente
                         debug=1;

                        }
                         if(debug==1){
                             lab_afficher_grille(grille,hauteur_grille, largeur_grille, pile_solution); //afficher grille
                             debug=0;
                         }

                 }
                 pile_haut_pile(pile_solution, &haut_pile_sol[0], &haut_pile_sol[1]); //stocker haut de la pile solution dans haut_pile_sol
                 solutionTF=(lab_est_une_sortie(haut_pile_sol, grille, hauteur_grille, largeur_grille)); //verifier si on est arrivé à une sortie


                 if(solutionTF==1){ // si c'est une sortie:
                     return 1;//vrai
                 }
                 if (solutionTF==0 && nb_deplacements==0 && pile_est_vide(pile_chemin_alt) == 0){ //si on n'a plus de deplacements possibles et on n'a pas trouvé la sortie:
                     return 0;//faux
                 }


            }


        }


