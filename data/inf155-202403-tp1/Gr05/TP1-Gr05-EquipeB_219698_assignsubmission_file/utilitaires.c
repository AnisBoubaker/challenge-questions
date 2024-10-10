//
// Created by olarocque on 10/23/2023.
//
/***********COMMANDES PR�PROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "utilitaires.h"

/********* D�FINITION DES FONCTION **************/
/*
 * FONCTION: nb_aleatoire
 * Cette fonction retourne une valeur al?atoire dans l'intervalle entier
   [min, max]. Chaque valeur poss?de la m?me probabilit? d'?tre g?n?r?e.

   PARAM?TRES :
        - min : La plus petite valeur pouvant ?tre g?n?r?e (type : int).
        - max : La plus grande valeur pouvant ?tre g?n?r?e (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a pr?alablement ?t? appel?e.
 */
/* On initialise le g�n�rateur de nombres al�atoires. */

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

//fonction qui affiche la pile
void afficher_pile(int pile[][2])
{
    printf("Coordonnees dans la solution :");

    for(int i=1; i<pile[0][1]; i++)//Boucle qui parcour la pile
    {
        printf("(%i,%i)", pile[i][0], pile[i][1]);//Affiche le contenu de la pile
    }

    printf("\n");

}

//Fonction system pause
void systemPause()//Fonction system pause
{
    fflush(stdin);//Flussh la console
    printf("Appuyer sur ENTER pour continuer...\n");
    getchar();//Attend une qu'une valeur soit saisie
}