/*
Titre: utilitaires.c
Description: Implémentation des fonctions du module utilitaires

Auteurs: Francis Gignac, Rachelle Sanscartier, Maxim St-Gelais, Abraham Suarez-Santizo
Date: 2023-11-12
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilitaires.h"



/***********CONSTANTES DE COMPILATION*************/


/********* DÉFINITION DES FONCTIONS **************/

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

/* Fonction pour enregistrer coordonnées dans un tableau 1d pour
   deplacement vers le HAUT.
*/
void dplc_haut(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col;
    coordo[1]=pos_lig-1;
}

/* Fonction pour enregistrer coordonnées dans un tableau 1d pour
   deplacement vers le BAS.
*/
void dplc_bas(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col;
    coordo[1]=pos_lig+1;
}

/* Fonction pour enregistrer coordonnées dans un tableau 1d pour
   deplacement vers la GAUCHE.
*/
void dplc_gauche(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col-1;
    coordo[1]=pos_lig;
}

/* Fonction pour enregistrer coordonnées dans un tableau 1d pour
   deplacement vers la DROITE.
*/
void dplc_droite(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col+1;
    coordo[1]=pos_lig;
}
