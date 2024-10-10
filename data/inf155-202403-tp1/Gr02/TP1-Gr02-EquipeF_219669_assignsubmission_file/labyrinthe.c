
/*
Titre: labyrinthe.c
Description: Fonctions nécessaires à la résolution du labyrinthe

Auteurs: Imane, Rayan, Stephanie, Ghita
Date: 2023-11-06.
*/

/***********COMMANDES PR�PROCESSEUR*************/

#include "labyrinthe.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilitaires.h"



/***********CONSTANTES DE COMPILATION*************/


/********* D�FINITION DES FONCTION **************/

/// GHITA
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
        {
            printf("\n");
            char mur = 219; /// Pour afficher un mur, on utilise le caractère ayant pour code ASCII 97.

            ///On parcour tout la grille a deux dimention a l'aide des deux boucles for.
            for(int i=0; i<hauteur_grille; i++)
            {
                for (int j = 0; j < largeur_grille; j++)
                {
                        if(grille[i][j] == 2)
                        {
                            printf("E");
                        }

                        else if(pile_solution != NULL && pile_contient(pile_solution, i, j))
                        {
                            printf("X");    /// Affiche toutes les cases faisant partie de la solution.
                        }

                        else if (grille[i][j] == 1)
                        {
                            printf("%c", mur);  /// Affiche un mur s'il y a un 1.
                        }
                        else
                        {
                            printf(" ");    /// Affiche un espace pour représenter un couloir vide.
                        }
                     }

                printf("\n");// Passe à la ligne suivante après avoir affiché une ligne de la grille.
            }
        }

///GHITA
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
            *nb_deplacements = 0; ///initialise le nombre de deplacement a 0.

            ///evaluation (y, x+1) => droite
            ///Si la case a droite de notre position n'est pas un mur, et que nous ne sommes pas deja passées a cette position et qu'on est encore dans la grille, on rentre dans le if.
            if((grille[pos_ligne][pos_colonne+1] == 0) && (pile_contient(solution_partielle, pos_ligne, pos_colonne+1) == 0) && (pos_colonne+1 <= largeur_grille))
            {
                deplacements[*nb_deplacements][0] = pos_colonne+1;
                deplacements[*nb_deplacements][1] = pos_ligne;
                (*nb_deplacements)++; ///Incrementation du nombre de deplacements.
            }
            ///evaluation (y, x-1) => gauche
            ///Si la case a gauche de notre position n'est pas un mur, et que nous ne sommes pas deja passées a cette position et qu'on est encore dans la grille, on rentre dans le if.
            if((grille[pos_ligne][pos_colonne-1] == 0) && (pile_contient(solution_partielle, pos_ligne, pos_colonne-1) == 0) && (pos_colonne-1 >= 0))
            {
                deplacements[*nb_deplacements][0] = pos_colonne++; //revoir avec stephanie si on ne met pas ++;
                deplacements[*nb_deplacements][1] = pos_ligne;
                *nb_deplacements++; ///Incrementation du nombre de deplacements.
            }
            ///evaluation (y+1, x) => haut
            ///Si la case du haut n'est pas un mur, et que nous ne sommes pas passées a cette position et qu'on est encore dans la grille, on rentre dans le if.
            if((grille[pos_ligne+1][pos_colonne] == 0) && (pile_contient(solution_partielle, pos_ligne+1, pos_colonne) == 0) && (pos_ligne+1 >= 0))
            {
                deplacements[*nb_deplacements][0] = pos_colonne;
                deplacements[*nb_deplacements][1] = pos_ligne++;
                *nb_deplacements++; ///Incrementation du nombre de deplacements.
            }
            ///evaluation (y-1, x) => bas
            ///Si la case du bas n'est pas un mur, et que nous ne sommes pas passées a cette position et qu'on est encore dans la grille, on rentre dans le if.
            if((grille[pos_ligne-1][pos_colonne] == 0) && (pile_contient(solution_partielle, pos_ligne-1, pos_colonne) == 0) && (pos_ligne-1 <= hauteur_grille))
            {
                deplacements[*nb_deplacements][0] = pos_colonne;
                deplacements[*nb_deplacements][1] = pos_ligne++;
                *nb_deplacements++; ///Incrementation du nombre de deplacements.
            }
            ///renvoyer le nombre de deplacement possible
            ///renvoyer le tableau deplacement.
        }

///RAYAN
int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice_deplacements_possible;    ///indice dans le tableau deplacements_possibles qui a été choisi aléatoirement comme prochain déplacement.

    ///Sélection d'un chemin aléatoire donnes par le tableau deplacements_possibles[][2] .
    srand((unsigned)time(NULL));

    /// Pour choisir aléatoirement l'un des déplacements possibles.
    indice_deplacements_possible = rand()  % nb_deplacements_possibles;

    return indice_deplacements_possible;    ///Le résultat renvoyé est l'indice du prochain déplacement à effectuer.
}


///RAYAN
int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    /// Vérifie si les cases sont adjacentes horizontalement(même ligne et différence d'une colonne).
    if((case1[0] - case2[0] == 1   || case1[0] - case2[0] == -1) && (case1[1] == case2[1]))
    {
        return 1;     ///Les deux cases sont adjacentes verticalement.
    }
    /// Vérifie si les cases sont adjacentes verticalement(même colonne et différence d'une ligne).
    else if((case1[0] ==  case2[0] ) && (case1[1] - case2[1]  == 1 || case1[1] - case2[1] == -1 ))
    {
        return 1;     ///Les deux cases sont adjacentes horizontalement.
    }
    ///Si les cases sont ni adjacentes horizontalement, ni verticalement, on rentre dans le else.
    else
    {
        return 0;     ///Les deux cases ne sont pas adjacentes.
    }
}

/// IMANE
int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{
    /// Si la valeur de la grille liée à la position x et y = 0, on est dans un couloir
    if(grille[position[1]][position[0]] == 0)
    {
        if(position[0] == 0 || position[0] == largeur_grille) /// Si la position en x est egale a 0 ou nbr
        {
            return 1;
        }
        if (position[1] == 0 || position[1] == hauteur_grille)/// Si la position en y est egale a 0 ou 12
        {
            return 1;
        }
    }
    else
    {
        return 0;/// Si la sortie n'est ni un couloir ou en peripherie alors la position n'est pas une sortie
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
    //Arguments
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles=0;
    int nouvelle_position[2]; ///tableau contenant des coordonnées d’un point sur la grille

    //Initialisation des deux piles
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE );
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_GRILLE );

    //Empiler entree dans pile solution
    pile_empiler(pile_solution, entree[0], entree[1]);

    ///Tant qu'il est possible de se deplacer et qu'aucune solution na ete trouvee
    do
    {
        pile_haut_pile(pile_solution, &nouvelle_position[0], &nouvelle_position[1]);
        int valeurs_haut_pile[2];//Tableau contenant les valeurs de l'entree, soit le haut de la pile solution
        valeurs_haut_pile[0] = nouvelle_position[0];
        valeurs_haut_pile[1] = nouvelle_position[1];


        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,
        nouvelle_position[0],nouvelle_position[1], pile_solution, &nb_deplacements_possibles,
        deplacements_possibles); //Calcul des deplacements possibles

        if(nb_deplacements_possibles>0) //Si il est possible de se deplacer..
        {
            ///Choisir un des déplacements obtenus et l’empiler dans pile_solution.
            int choix_deplacement = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles); /// Choisir un deplacement et mettre dans une variable
            pile_empiler(pile_solution,deplacements_possibles[choix_deplacement][0], deplacements_possibles[choix_deplacement][1]);//Empiler les autres deplacements dans pile_chemins_alternatifs

            ///Empiler les autres déplacements dans le pile_chemins_alternatifs
            for(int i = 0 ; i < nb_deplacements_possibles; i++){
                if(i != choix_deplacement) //Si c'est pas le choix qu'on a mis dans la pile solution on pourra mettre ca dans la pile_chemins_alternatifs
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                }
            }
        }
        else if(pile_est_vide(pile_chemins_alternatifs)!=0) //Si pile_chemins_alternatifs n'est pas vide
        {
            pile_depiler(pile_chemins_alternatifs,&nouvelle_position[0], &nouvelle_position[1]); //on depile pile_chemin alternatif et on met dans nouvelle_position

            ///Dépiler de pile_solution jusqu’à ce que le haut de la pile contienne une case adjacente à nouvelle_position.
            while(pile_est_vide(pile_solution) != 0 && lab_est_cases_adjacentes(valeurs_haut_pile,nouvelle_position)==0)
            {
                pile_haut_pile(pile_solution,&valeurs_haut_pile[0],&valeurs_haut_pile[1]);
                pile_depiler(pile_solution,&valeurs_haut_pile[0],&valeurs_haut_pile[1]);
            }
            ///Empiler nouvelle_position dans pile_solution.
            pile_empiler(pile_solution,nouvelle_position[0],nouvelle_position[1]);
        }
        else
        {
            return 0; /// Plus possible de se déplacer.
        }
        //Mode debug
        if(debug == 1)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            printf("\nPour continuer, cliquez sur la touche [ENTER]");
            system("pause");
        }

    }while(pile_est_vide(pile_solution) != 0 && lab_est_une_sortie(nouvelle_position,grille,hauteur_grille,largeur_grille)!=0);

    if(pile_est_vide(pile_solution) == 0)
    {
        return 0; ///une solution a été trouvée, renvoyer vrai
    }
    else
    {
        return 1; ///une solution n'a pas été trouvée, renvoyer FAUX
    }
}