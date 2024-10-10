/*
Module: labyrinthe.c

Auteur: Vito PELLEGRINELLI/ Mark AVRUTIN/ Romain LATREILLE/ Xavier MARTEL

Date: 16/10/2023
*/
#include "labyrinthe.h"
#include "utilitaires.h"


/*******IMPLEMENTATION DES FONCTIONS***********/
#include <stdio.h>

#define TAILLE_MAX_GRILLE 100




void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]) {


    int sol;



    // Parcour la grille fourni
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            int trouve_dans_solution = 0;

            if (pile_solution != NULL) {
            // Afficher le mur ou l'espace, et marquer la solution.
            if (grille[i][j] == 1)
            {
                printf("%c", 219);  // Caractere ASCII 219 pour representer le mur
            }
            else if (pile_solution[0][0]== 1000)
            {
                for(int k=0; k<100; k++)
                {
                    if (i == pile_solution[k][0] && j == pile_solution[k][1])
                    {
                        printf("x"); // Imprime un X ou il y a un chemin menant a la solution
                        trouve_dans_solution++;
                    }
                }
                if(trouve_dans_solution == 0)
                {
                    printf(" "); // Imprime un espace selon les coordonnees de la grille
                }
            }
            else
            {
                printf(" ");
            }
        }
            // Aller à la ligne à la fin de chaque ligne

        }
        printf("\n");
    }
    printf("\n");

}


void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,int largeur_grille,
                                          int pos_ligne,int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,int deplacements[4][2])
{
    int tab1[2];
    int tab2[2];

    tab1[0] = pos_ligne;
    tab1[1] = pos_colonne;

    int cases_adjacentes;
    int n =0;
    *nb_deplacements =0 ;

    for(int i=0; i<hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            tab2[0] = i;
            tab2[1] = j;

            cases_adjacentes = lab_est_cases_adjacentes(tab1, tab2);

            if (cases_adjacentes == 1)
            {
                //printf("la case %i, %i est adjacentes\n", tab2[0], tab2[1]);

                if (grille[i][j] != 1)
                {
                    //printf("la case %i, %i n'est pas un mur\n", tab2[0], tab2[1]);

                    if (pile_contient(solution_partielle, i, j) == 0)
                    {
                        //printf("la case %i, %i n'est pas dans la solution\n", tab2[0], tab2[1]);

                        deplacements[n][0] = tab2[0];   //Enregistre la ligne de la coordonnee trouvee

                        deplacements[n][1] = tab2[1];   //Enregistre la colonne de la coordonnee trouvee

                        *nb_deplacements = *nb_deplacements + 1;     //Incremente le nombre de deplacements possible trouves
                        n++;    //Incremente les ligne du tableau ou l'on enregistre les coordonnees possible
                    }
                }
            }
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice;

    indice = nb_aleatoire(0, nb_deplacements_possibles-1);

    //printf("%i", indice);

    return indice;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int difference_x;
    int difference_y;

    difference_x = case1[0] - case2[0];
    difference_y = case1[1] - case2[1];

    // Verification si les cases sont adjacentes en regardant les difference entre les coordonnees x et y.
    // On retourne 1 si les cases sont adjacentes.
    // On retourne 0 si les cases ne sont pas adjacentes.

    if (( difference_x == 0 && ( difference_y == 1 || difference_y == -1)) || (difference_y == 0 && (difference_x == 1 || difference_x == -1)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lab_est_une_sortie(int position[2],     int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille,  int largeur_grille)
{
    int x = position[0];
    int y = position[1];

    // Vérifie si la position est en périphérie de la grille
    if (x == 0 || x == hauteur_grille - 1 || y == 0 || y == largeur_grille - 1) {
        // Vérifie si la position n'est pas un mur
        if (grille[x][y] != 1) {
            // C'est une sortie
            return 1;
        }
    }
    // Ce n'est pas une sortie
    return 0;
}
int test_lab_est_une_sortie(){
    int position[]={0,2};
    int grille[100][TAILLE_MAX_GRILLE];
    if (lab_est_une_sortie( position, grille, 200,200)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                            int largeur_grille,             int entree[2],
                            int pile_solution[][2],         int debug){

//INITIALISATION DES VARIABLES//
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2] = {TAILLE_MAX_GRILLE, 0};
    int deplacement_possible[4][2];
    int nb_deplacements = 0;
    int nouvelle_position[2];

    int pile_solution_depilee[2]; //tableau 1D prenant les valeurs des lignes et colonnes depliees de la pile_solution
    int indice; //Valeur aleatoire qui provient de la fonction lab_choisir_deplacement
    int ligne;
    int colonne;
    int k = 1; //Variable permettant de se déplacer dans la pile_solution


    pile_empiler(pile_solution, entree[0], entree[1]);  //Insertion coordonees de l'entree du labyrinthe dans la pile solution

    do    //Boucle tant qu'il y a des deplacements possibles ET qu'aucune solution n'a ete trouvee
    {

        lab_calculer_deplacements_possibles(grille,hauteur_grille, largeur_grille,
                                            pile_solution[k][0], pile_solution[k][1],
                                            pile_solution,
                                            &nb_deplacements, deplacement_possible);

        if (nb_deplacements > 0)    //Si des déplacements possible ont ete trouves
        {

            indice = lab_choisir_deplacement(deplacement_possible, nb_deplacements);

            //Empile dans la pile solution une ddes coordonnes possible trouvees
            pile_empiler(pile_solution, deplacement_possible[indice][0], deplacement_possible[indice][1]);


            for (int i = 0; i < nb_deplacements; i++)   //Boucle pour empiler les autre deplacements possibles dns une autre pile
            {
                if (i != indice && nb_deplacements > 1) //toute les deplacements sauf celui choisit un peu plus haut
                {

                    pile_empiler(pile_chemins_alternatifs, deplacement_possible[i][0],
                                                                deplacement_possible[i][1]);
                }

            }

            if (debug == 1) //Dans le cas que l'utilisateur a choisit en mode debug
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }

        } else if (pile_est_vide(pile_chemins_alternatifs) == 0) {

            //Depile la derniere coordonnees empiler dans la pile chemins alternatif
            pile_depiler(pile_chemins_alternatifs, &ligne, &colonne);
            nouvelle_position[0] = ligne;
            nouvelle_position[1] = colonne;

            //Boucle qui depile la pile solution jusqu'a ce qu'une coordonne soit adjacente a
            //la coordonnee depiler de la pile chemin alternatif
            do {
                pile_depiler(pile_solution, &ligne, &colonne);
                pile_solution_depilee[0] = ligne;
                pile_solution_depilee[1] = colonne;
                k--;
            }while (lab_est_cases_adjacentes(pile_solution_depilee, nouvelle_position) == 0);

            //Lorsqu'une coordonnee adjacente est trouvee, elle est empiler dans la la pile solution
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }
        }
        else //Si aucun deplacement n'a ete trouve, on retourne faux
        {
            return 0;
        }

        k++;

        pile_haut_pile(pile_solution, &ligne, &colonne);

        pile_solution_depilee[0] = ligne;
        pile_solution_depilee[1] = colonne;

    }while (deplacement_possible[0][0] != 0 && lab_est_une_sortie(pile_solution_depilee, grille, hauteur_grille, largeur_grille) != 1);

    //Si une solution a ete trouve, on retourne vrai, sinon on retourne faux
    if (lab_est_une_sortie(pile_solution_depilee, grille, hauteur_grille, largeur_grille) == 1)
        {
            if (debug == 1)
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");

            }
            return 1;
        }
        else
        {
            return 0;
        }

}
