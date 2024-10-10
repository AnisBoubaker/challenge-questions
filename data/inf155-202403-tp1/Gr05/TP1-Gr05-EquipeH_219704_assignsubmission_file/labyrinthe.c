/*
Titre : labyrinthe.c

Description : fonctions qui vont resoudre le labyrinthe.

Auteur: Ken Whittom ,Anthony Carhuallanqui Nerio, Franck Kamwa

Date: 2023-11-12
*/

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <time.h>


void lab_afficher_grille ( int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    int i, j; // Ce sont des variables pour parcourir le contenue de ma grille.

    for (i = 0; i < hauteur_grille; i++)
    {
        for (j = 0; j < largeur_grille; j++)
        {
            if (grille [i][j] == 1)
            {
                printf("%c", 219); //Le code pour afficher une mur sur la grille.
            }
            else if (grille [i][j] == 0)
            {
                printf(" "); //Un espace pour afficher le chemin disponible sur la grille.
            }
            else if (pile_contient(pile_solution,i,j))
            {
                printf("%c", 88); //Le code pour afficher un X sur la grille qui signifie la solution.
            }
        }

        printf("\n");
    }
}

void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacement[4][2])
{
    int deplacement_possible = 0; //Le nombre de deplacement possible à un point.
    int position_actuelle[2] ={pos_ligne, pos_colonne}; //La position actuelle dans le labyrinthe.
    int position_en_haut[2] = {pos_ligne - 1, pos_colonne}; //La position en haut de notre position actuelle dans le labyrinthe.
    int position_en_bas[2] = {pos_ligne + 1, pos_colonne}; //La position en bas de notre possion actuelle dans le labyrinthe.
    int position_droite[2] = {pos_ligne, pos_colonne + 1}; //La position à droite de notre position actuelle dans le labyrinthe.
    int position_gauche[2] = {pos_ligne, pos_colonne - 1}; //La position à gauche de notre position actuelle dans le labyrinthe.

    //Si la position à gauche n'est pas un mur et il n'est pas dans la solution
    if (grille[pos_ligne][pos_colonne - 1] == 0 && !pile_contient(solution_partielle,pos_ligne,pos_colonne - 1 ))
    {
        //Si la position à gauche est adjacente avec notre postion actuelle.
        if (lab_est_cases_adjacentes(position_gauche, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne,pos_colonne - 1);
            deplacement_possible++;
        }
    }

    //Si la position à droite n'est pas un mur et il n'est pas dans la solution
    if (grille[pos_ligne][pos_colonne + 1] == 0 && !pile_contient(solution_partielle,pos_ligne,pos_colonne + 1 ))
    {
        //Si la position à droite est adjacente avec notre postion actuelle.
        if (lab_est_cases_adjacentes(position_droite, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne,pos_colonne + 1);
            deplacement_possible++;
        }
    }

    //Si la position en haut n'est pas un mur et il n'est pas dans la solution
    if (grille[pos_ligne - 1][pos_colonne] == 0 && !pile_contient(solution_partielle,pos_ligne - 1,pos_colonne))
    {
        //Si la position en haut est adjacente avec notre postion actuelle.
        if (lab_est_cases_adjacentes(position_en_haut, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne - 1,pos_colonne);
            deplacement_possible++;
        }
    }

    //Si la position en bas n'est pas un mur et il n'est pas dans la solution
    if (grille[pos_ligne + 1][pos_colonne] == 0 && !pile_contient(solution_partielle,pos_ligne + 1,pos_colonne))
    {
        //Si la position en bas est adjacente avec notre postion actuelle.
        if (lab_est_cases_adjacentes(position_en_bas, position_actuelle))
        {
            pile_empiler(deplacement,pos_ligne + 1,pos_colonne);
            deplacement_possible++;
        }
    }
    *nb_deplacements = deplacement_possible;
}

int lab_choisir_deplacement(int deplacement_possible[][2], int nb_deplacements_possibles)
{
    int choix; //Choix aléatoire d'un chemin possible.

    //Initialisation du générateur de nombre.
    srand((unsigned int) time(NULL));
    rand();


    if (nb_deplacements_possibles >= 2)
    {
        //choix aléatoire que le programme fait parmis les choix possible.
        choix = nb_aleatoire(1, nb_deplacements_possibles);
    }else
    {
        choix = 1;
    }
    
    return choix;
}

int lab_est_cases_adjacentes(int case1[2],int case2[2])
{

    //Verifie si les cases sont adjacentes
    if(case1[0]==case2[0] && case1[1]-case2[1]!=1||case1[1]==case2[1] && case1[0]-case2[0]!=1)
    {
        return 1; // 1 = vrai
    }
    else
    {
        return 0; // 0 = faux
    }
}


int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille) {
    int position_ligne = position[0];//Position en fonction de la ligne
    int position_colonne = position[1];//position en fonction de la colonne

    if ((position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0 ||
        position[1] == largeur_grille - 1)&& grille[position_ligne][position_colonne] != 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int pile_chemins_alternatifs [TAILLE_MAX_PILE][2]; //tableau 2D qui contient les chemins alternatifs possibles.
    int deplacements_possibles[4][2];//Tableau 2D qui contient les deplacement possible à faire.
    int nb_deplacements_possibles;// Variable qui contient le nombre de déplacement possible à un certain point.
    int nouvelle_position[2];//Tableau 2D qui contient les coordonnées une nouvelle position
    int nouvelle_positon_x;//nouvelle position en x
    int nouvelle_positon_y;//nouvelle position en y
    int choix_deplacement;//Le choix aleatoire qui est fait
    int deplacement_x;//le deplacement dans le labyrinthe en x
    int deplacement_y;//le deplacement dans le labyrinthe en y
    int coordonne_utilise[2];//les points du labyrinthe que nous avons deja utilise.

    //initialisation des piles
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

    //mettre la position de l'entree dans la pile solution
    pile_empiler(pile_solution, entree[0], entree[1]);

    do
    {
        //Mettre notre nouvelle position dans la pile solution
        pile_haut_pile(pile_solution, &nouvelle_positon_x, &nouvelle_positon_y);

        if(debug == 1)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }
        if (debug == 0)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
        }
        //mettre la position acutelle dans la nouvelle position
        nouvelle_position[0] = nouvelle_positon_x;
        nouvelle_position[1] = nouvelle_positon_y;

        //calculer le nombre de deplacement possible.
        lab_calculer_deplacements_possibles(grille, hauteur_grille,largeur_grille,nouvelle_positon_x, nouvelle_positon_y, pile_solution, &nb_deplacements_possibles, deplacements_possibles);

        //mettre les coordonne en x et en y dans le deplacement
        deplacement_x = nouvelle_positon_x;
        deplacement_y = nouvelle_positon_y;

        //empiler le deplacement possible calculer en x et y
        pile_empiler(deplacements_possibles,deplacement_x,deplacement_y);

        if (nb_deplacements_possibles > 0)
        {
            choix_deplacement = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);
            deplacement_x = deplacements_possibles[choix_deplacement][0];
            deplacement_y = deplacements_possibles[choix_deplacement][1];

            pile_empiler(pile_solution, deplacement_x, deplacement_y);

            nouvelle_position[0] = deplacement_x;
            nouvelle_position[1] = deplacement_y;

            while (!pile_est_vide(deplacements_possibles))
            {
                pile_empiler(pile_chemins_alternatifs,deplacement_x,deplacement_y);
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
            pile_depiler(pile_chemins_alternatifs,&deplacement_x,&deplacement_y);
            nouvelle_position[0] = deplacement_x;
            nouvelle_position[1] = deplacement_y;
            do
            {
                pile_haut_pile(pile_solution,&deplacement_x,&deplacement_y);
                coordonne_utilise[0] = deplacement_x;
                coordonne_utilise[1] = deplacement_y;

                pile_depiler(pile_solution,&deplacement_x,&deplacement_y);

            } while (!lab_est_cases_adjacentes(nouvelle_position, coordonne_utilise));

            pile_empiler(pile_solution,nouvelle_position[0],nouvelle_position[1]);

        }
        else
        {
            return 0;
        }
    } while (!lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille));
    return 1;
}