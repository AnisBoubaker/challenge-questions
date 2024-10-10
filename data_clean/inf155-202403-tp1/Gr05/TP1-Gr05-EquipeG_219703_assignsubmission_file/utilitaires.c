 

 
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilitaires.h"



 


 

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

 
void dplc_haut(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col;
    coordo[1]=pos_lig-1;
}

 
void dplc_bas(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col;
    coordo[1]=pos_lig+1;
}

 
void dplc_gauche(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col-1;
    coordo[1]=pos_lig;
}

 
void dplc_droite(int coordo[], int pos_lig, int pos_col)
{
    coordo[0]=pos_col+1;
    coordo[1]=pos_lig;
}
