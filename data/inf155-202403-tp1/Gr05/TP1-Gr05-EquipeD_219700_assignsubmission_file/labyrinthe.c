/*
Titre:
Description: Implementation des fonctions du module labyrinthe
Auteur: Nadir, Francois, Francis, Massin
Date: 2023-10-27
*/

/***********COMMANDES PR?PROCESSEUR*************/
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "labyrinthe.h"
#include "utilitaires.h"
#include <time.h>

/***********CONSTANTES DE COMPILATION*************/

#define Taille_max_grille 100
/********* D?FINITION DES FONCTION **************/


//////*************lab_afficher_grille*********************///////

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {
    //Parcouris la grille au complet

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            /* ce if affiche un mur */
            if (grille[i][j] == 1 )
            {
                printf("*");
            }
                /* ce else if affiche si la case fait partie de la solution */
            else
            {
                if ( !pile_est_vide(pile_solution) ) // verifie si pile_solution n'est pas vide
                {
                    /* On regarde si la case est dans la solution */
                    int solution = 0;

                    if(pile_contient(pile_solution, i, j))
                    {
                        solution=1;
                        printf("X"); // Afficher un marquage de solution (par exemple, 'X')
                    }
                    else
                    {
                        /* Afficher un espace */
                        printf(" ");
                    }

                }
                else
                {
                    /* Si aucune solution n'est fournie, afficher un espace */
                    printf(" ");

                }


            }
        }

        /* Affiche la prochaine rangee */
        printf("\n");

    }

}

//////*************lab_calculer_deplacements_possibles*********************///////
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
    /* on initialise le pointeur à 0 */
    *nb_deplacements = 0;

    /* Coordonnées des cases adjacentes possibles (haut, bas, gauche, droite) */
    int adjacents[4][2] = {
            {-1, 0},  // Haut
            {1, 0},   // Bas
            {0, -1},  // Gauche
            {0, 1}    // Droite
    };

    /* Boucle for pour que l'on puisse parcourir les cases adjacentes */
    for (int i = 0; i < 4; i++)
    {

        int nouvelle_ligne = pos_ligne + adjacents[i][0];
        int nouvelle_colonne = pos_colonne + adjacents[i][1];

        /* Vérifier si la nouvelle case est à l'intérieur de la grille && La case n'est pas un mur &&la nouvelle case ne fait pas partie de la solution partielle */
        if (
                (nouvelle_ligne >= 0 && nouvelle_ligne < hauteur_grille) &&  (nouvelle_colonne >= 0 && nouvelle_colonne < largeur_grille)
                && grille[nouvelle_ligne][nouvelle_colonne] != 1
                && !pile_contient(solution_partielle, nouvelle_ligne, nouvelle_colonne)
                )
        {
            /* Ajouter la nouvelle case aux déplacements possibles si ce n'est pas dans la solution*/
            deplacements[*nb_deplacements][0] = nouvelle_ligne;
            deplacements[*nb_deplacements][1] = nouvelle_colonne;
            *nb_deplacements = *nb_deplacements  + 1;
        }
    }
}



//////*************lab_choisir_deplacement*********************///////
int lab_choisir_deplacement (int deplacement_possibles[][2],int nb_deplacements_possibles)
{
    int prochain_deplacement;
    if(nb_deplacements_possibles == 0)
    {
        return -1; //la fonction n'est pas appliquée s'il n'ya pas de deplacement possible
    }
    srand((unsigned int)time(NULL));
    rand();

    prochain_deplacement= nb_aleatoire(0,nb_deplacements_possibles-1); //generer deplacement aleatoire
    return prochain_deplacement;

}

//////*************lab_est_cases_adjacentes*********************///////
int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    // Comparaison c'est case1 est adjacente a case 2
    if (case1[0] == case2[0] && case1[1] == case2[1] + 1  || case1[0] == case2[0] && case1[1] == case2[1]  -1 )
    {
        return 1; //comparaison horizontale retun 1 si vrai
    }

    else if(case1[1] == case2[1] && case1[0] == case2[0] + 1 || case1[1] == case2[1] && case1[0] == case2[0] -1 )
    {
        return 1; //comparaion verticale return 1 si vrai
    }

    else
    {
        return 0; //cases pas adjacentes faux
    }


}





//////*************lab_est_une_sortie*********************///////
int lab_est_une_sortie(int position[2],int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{

    // Verification que c'est pas un mur
    if (grille[position[0]][position[1]] != 1)
    {
        // Verifier qu'elle se trouve au extr�mite de labyrinthe
        if (position[0] == 0 ||  position[0] == hauteur_grille-1)
        {
            return 1;
        }
        else if (position[1] == 0 ||  position[1] == largeur_grille-1)
        {
            return 1;
        }
        else
        {
            return 0 ; // la position n'est pas une sortie
        }

    }
    else
    {
        return 0; // la position est un mur
    }

}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pos_ligne;
    int pos_colonne;
    int nb_deplacements;
    int deplacements[4][2];
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE][2];
    int nouvelle_position[2];
    int prochain_deplacement;
    int position[2];
    int i,j;

    //Initialiser les deux piles
    pile_initialiser(pile_solution, TAILLE_MAX_Pile);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_Pile);
    //Empiler l'entree
    pile_empiler(pile_solution, entree[0],entree[1]);
    do
    {
        //Trouver les cordonnees du haut de la pile
        pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);
        //calculer d�placements possibles et nb_deplacements
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,pos_ligne,pos_colonne,pile_solution,&nb_deplacements,deplacements);
        if(nb_deplacements >0 )
        {
            ///Choisir un des d�placements obtenus et l�empiler dans pile_solution
            prochain_deplacement =  lab_choisir_deplacement(deplacements,nb_deplacements);
            ///Empiler le d�placement obtenu dans pile_solution
            pile_empiler(pile_solution, deplacements[prochain_deplacement][0],deplacements[prochain_deplacement][1]);

            ///Empiler les autres d�placements possibles dans la pile_chemins_alternatifs
            if(nb_deplacements >1)
            {
                for(i=0;i<nb_deplacements;i++)
                {
                    if(i != prochain_deplacement  )
                    {
                        pile_empiler(pile_chemins_alternatifs, deplacements[i][0],deplacements[i][1]);
                    }
                }
            }


        }else if( pile_est_vide(pile_chemins_alternatifs) == 0 )
        {
            //nouvelle_position <-- D�piler(pile_chemin_alternatifs) ;
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0],&nouvelle_position[1]);

            //D�piler de pile_solution jusqu�� ce que le haut de la pile contienne une case adjacente � nouvelle_position
            do
            {
                pile_depiler(pile_solution, &pos_ligne,&pos_colonne);

                //Trouver la position haut de la pile
                pile_haut_pile(pile_solution, &position[0] ,&position[1]);

            }
            while(lab_est_cases_adjacentes(nouvelle_position, position) == 0);
            ///Empiler nouvelle_position dans pile_solution
            pile_empiler(pile_solution, nouvelle_position[0],nouvelle_position[1]);
        }else
        {
            return 0; //Ce n'est plus possible de se deplacer
        }
        // Afficher les deplacements dans la grille
        if( debug == 1)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }

        //Trouver la position haut de la pile
        pile_haut_pile(pile_solution, &position[0] ,&position[1]);
    }while(lab_est_une_sortie(position,grille,hauteur_grille,largeur_grille) != 1);


    if(lab_est_une_sortie(position,grille,hauteur_grille,largeur_grille) == 1)
    {
        return 1; //une solution a ete trouvee,
    }else
    {
        return 0; //aucune solution n'a ete trouvee,
    }
}


