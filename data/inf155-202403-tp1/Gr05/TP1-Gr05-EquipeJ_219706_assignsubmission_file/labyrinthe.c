/*
Module: labyrinthe_io

Description: Implémentation des fonctions du module labyrinthe

Auteurs: Anis Boubaker (professeur, fournissant une partie du code aux étudiants)
         Jafar Al-Khaiat
         Tayeb Amrouche
         Jose David Molina Penaloza
         William Zamudio-Turcotte

Date: 2023-11-12 (contributions de l'équipe d'étudiants)
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include "labyrinthe.h"
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "utilitaires.h"

/*******IMPLÉMENTATION DES FONCTIONS***********/

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,int pile_solution[][2])
{// a ajouter la fonction pile_contient pour ajouter la solution a la grille
    for (int i=0;i<hauteur_grille;i++)
    {
        for(int j=0; j<largeur_grille; j++)
            {
              if( pile_contient( pile_solution,  i,  j) )
              {
                 printf("X");//Trace le chemin solutionnaire
              }
              else if  (grille[i][j] == 1)
              {
                printf("%c",219);// affiche des blocs pour indiquer des murs
              }
              else if  (grille[i][j] == 0 )
              {
                printf(" ");// affiche les couloirs.
              }
        }
        printf("\n");
    }
}

/*
 * Partie faite par JDM. Afin de trouver les cases adjacentes, je dois faire la differeces de deux coordonnees et trouver une valeur de 1.
 * Alors, si le resultat est 1 l'expresssion est vraie, si elle est fausse le resultat est 0;
 */




int lab_est_cases_adjacentes(const int case1[2],const int case2[2])
{
    int resultat=0;

    if(case1[0]==case2[0])//regarde si c est sur la meme ligne
    {
        if(case1[1]-case2[1]==-1  || case1[1]-case2[1]==1 )//si la difference entre les colones est de 1 alors
        {
            resultat=1;// retourne 1
            return resultat;
        }
    }
   else if(case1[1]==case2[1])//regarde si c est sur la meme colonne
   {
       if(case1[0]-case2[0]==-1  || case1[0]-case2[0]==1)//si la difference entre les lignes est de 1 alors
       {
           resultat=1;// retourne 1
           return resultat;
       }
   }
    return resultat;
}

/*
 * Partie realisee par JDM. Afin de voir si les coordonnees donnees sont une sortie.
 * Jai decide de regarder si une des deux coordonees se trouvent au debut du tableau, soiet x=0 ou bien y=0.
 * En outre, jai decide de chercher si les composantes se trouvent a la fin du tableau, soient x=hauteur_max ou bein y=largeur_max.
 * Donc, avec un if statement je suis capable de voir si ces conditions sont atteignees et return un 1=vrai, sinon je return un 0.
 */


int  lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    if(position[1]==hauteur_grille || position[2]==largeur_grille || position[1]==0 || position[2]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * Partie realisee par JDM. Explication: Alors, afin de chercher les deplacements disponible.
 * je realise un <<nested for loop>> afin scanner tout le labyrithm et sauver les espaces en blanc dans un autre tableau.
 */

void calcul_deplacements_possibles (int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
    int pos[2];
    pos[0] = pos_ligne;
    pos[1] = pos_colonne;

    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++)
        {
            if (grille[i][j] == 0 && lab_est_cases_adjacentes(grille, pos) == 1)
            {
                deplacements[i][j] = grille[i][j];
            }
        }
    }
}


int lab_choisir_deplacement (int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    if(nb_deplacements_possibles>0)
    {

        return deplacements_possibles[0][0];

    }

}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
   // while(){}
}

