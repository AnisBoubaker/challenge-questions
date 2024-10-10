
/***********COMMANDES PRÉPROCESSEUR*************/
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"



/*******IMPLEMENTATION DES FONCTIONS***********/
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                         int largeur_grille,int pile_solution[][2])
{
    for(int i = 0; i < hauteur_grille; i++){    //parcour le tableau de l'horizontal
        for(int j = 0; j < largeur_grille; j++) {    //parcour le tableau du vertical
            if (grille[i][j] == 1) {      //si la valeur est egale a 1, print ASCII 219
                printf("%c", 219);                         //pour le mur
            }
            else if (!pile_est_vide(pile_solution) && pile_contient(pile_solution,i,j)) {
                printf("x"); //si la pile solution est pas vide et quelle contient cette case on met un x
            }
            else {
                printf(" "); //sinon cest une case vide, on met un espace
            }
        }
        printf("\n");   //une fois une ligne horizontal complete, saute une ligne
    }
}

// assumes that solution_partielle is correct, no verification that the given values work
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                                         int largeur_grille,int pos_ligne,
                                         int pos_colonne,int solution_partielle[][2],
                                         int *nb_deplacements,int deplacements[4][2]) {
    *nb_deplacements = 0;

    //initialiser deplacement possibles a -1
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            deplacements[i][j] = -1;
        }
    }
    //check down if not at bottom
    if (pos_ligne != hauteur_grille - 1) {
        if (grille[pos_ligne + 1][pos_colonne] == 0 && !pile_contient(solution_partielle, pos_ligne + 1,
                                                                      pos_colonne)) {
            *nb_deplacements = *nb_deplacements + 1;
            //Stocker coordonees dans deplacements
            deplacements[0][0] = (pos_ligne + 1);
            deplacements[0][1] = (pos_colonne);
        }
    }

    //check up if not at top
    if (pos_ligne != 0) {
        if (grille[pos_ligne - 1][pos_colonne] == 0 && !pile_contient(solution_partielle, pos_ligne - 1,
                                                                      pos_colonne)) {
            *nb_deplacements = *nb_deplacements + 1;
            //Stocker coordonees dans deplacements
            deplacements[1][0] = (pos_ligne - 1);
            deplacements[1][1] = (pos_colonne);
        }
    }

    //check left if not on left
    if (pos_colonne != 0) {
        if (grille[pos_ligne][pos_colonne - 1] == 0 && !pile_contient(solution_partielle, pos_ligne,
                                                                      pos_colonne - 1)) {
            *nb_deplacements = *nb_deplacements + 1;
            //Stocker coordonees dans deplacements
            deplacements[2][0] = (pos_ligne);
            deplacements[2][1] = (pos_colonne - 1);
        }
    }

    //check right if not on right
    if (pos_colonne != largeur_grille - 1) {
        if (grille[pos_ligne][pos_colonne + 1] == 0 && !pile_contient(solution_partielle, pos_ligne,
                                                                      pos_colonne + 1)) {
            *nb_deplacements = *nb_deplacements + 1;
            //Stocker coordonees dans deplacements
            deplacements[3][0] = (pos_ligne);
            deplacements[3][1] = (pos_colonne + 1);
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{

    int deplacement_choisi = 3;

    while(deplacements_possibles[deplacement_choisi][1] == -1){
        deplacement_choisi--;
    }

    return deplacement_choisi;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int j = 1;
    //regarde si adjencents en x, ensuite en y
    for(int i=0; i < 2; i++)
    {
        if((case1[i] == case2[i] + 1 || case1[i] == case2[i] - 1) && case1[j] == case2[j])
        {
            return 1;
        }
        j--;
    }
    return 0;
}


int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE]
                       ,int hauteur_grille,int largeur_grille)
{
    if (position[0] == 0 || position[0] == hauteur_grille-1 || position[1] == 0
    || position[1]==largeur_grille-1){ //si on est sur le contour du labyrinthe
        if (grille[position[0]][position[1]]!=1){ //si la case nest pas un mur
            return true;
        }
    }
    return false;
}

//algorithme pris de l'enonce du TP
int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                            int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];
    int deplacements_possible[4][2] = {{0}};
    int nb_deplacements_possibles=0;
    int nouvelle_position[2] = {entree[0],entree[1]};
    int position_actuelle[2] = {entree[0],entree[1]};
    int case_adjacentes[2];
    int deplacement_choisi;
    int ligne;
    int colonne;
    int nouvelle_ligne;
    int nouvelle_colonne;
    bool possible_de_se_deplacer = true;

    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0],entree[1]);

    while (possible_de_se_deplacer && (pos_est_entree(nouvelle_position,entree) ||
    !lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille)))
    {
        pile_haut_pile(pile_solution,&ligne,&colonne);
        lab_calculer_deplacements_possibles(grille,hauteur_grille,
                                            largeur_grille,ligne
                                            ,colonne,pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possible);
        if (nb_deplacements_possibles>0)
        {

            deplacement_choisi = lab_choisir_deplacement
                    (deplacements_possible,
                     nb_deplacements_possibles); //choisir un des deplacements obtenue

            //choisir emplacement qui correspond au bon
            nouvelle_ligne = deplacements_possible[deplacement_choisi][0];
            nouvelle_colonne = deplacements_possible[deplacement_choisi][1];

            pile_empiler(pile_solution, nouvelle_ligne, nouvelle_colonne);

            //stocke autre deplacement dans alternatifs
            for(int i = 0;i < 4;i++)
            {
                    if(deplacements_possible[i][0] != -1 && i != deplacement_choisi)
                    {
                        pile_empiler(pile_chemins_alternatifs,deplacements_possible[i][0],
                                     deplacements_possible[i][1]);
                    }
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0],
                         &nouvelle_position[1]);

            do{
                pile_depiler(pile_solution, &case_adjacentes[0],
                             &case_adjacentes[1]);
            }while (!lab_est_cases_adjacentes(nouvelle_position,
                                              case_adjacentes));
            pile_empiler(pile_solution,case_adjacentes[0],case_adjacentes[1]);
            pile_empiler(pile_solution, nouvelle_position[0],
                         nouvelle_position[1]);
        }
        else
        {
            possible_de_se_deplacer = false;
        }

        if (debug)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }
        pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);
    }

    if (lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille))
    {
        return true;
    }
    return false;


}