/*
Titre: Utilitaires
Description: Module qui contient des fonctions utilitaires.

Auteur: Alexis Roy-Tessier, Donald Vu, Mayas Kaced
Date: 12 novembre 2023
*/
#include "Utilitaires.h"
#include "pile.h"



int deplacement_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

void mise_a_jour_position(int pile[][2],int position[2],int *pos_ligne,int *pos_colonne)
{
    pile_haut_pile(pile,pos_ligne,pos_colonne);
    position[0]= *pos_ligne;
    position[1]= *pos_colonne;
}
