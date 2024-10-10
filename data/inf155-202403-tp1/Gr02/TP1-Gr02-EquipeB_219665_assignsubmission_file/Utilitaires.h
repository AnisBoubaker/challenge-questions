/*
Module: Utilitaires
Description: Module qui contient des fonctions utilitaires.

Auteur: Alexis Roy-Tessier, Donald Vu, Mayas Kaced
Date: 12 novembre 2023
*/
#ifndef UTILITAIRES_H
#define UTILITAIRES_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


/*Fonction: deplacement_aleatoire

Description:        Choisi un déplacement aléeatoire selon le tableau de déplacements possible.(4 possibilités)

Paramètres:
-min :              entier qui contient valeur minimum aléatoire.
-max :              entier qui contient valeur maximum aléatoire.

Retour:             Valeur du déplacement aléatoire.
Paramètre modifiés: Aucun.
Antécédents :       On suppose que la fonction srand a préalablement été appelée.
*/

int deplacement_aleatoire(int min, int max);

/*Fonction: mise_a_jour_position

Description:        Mise à jour d'un tableau de position et la position de la ligne et de la colonne.

Paramètres:
-pile:              Pile à vérifier (haut)
-position:          Tableau à mettre à jour
-pos_ligne:         Pointeur de la position de la ligne
-pos_colonne        Pointeur de la position de la colonne


Retour:             Aucun
Paramètre modifiés: position,pos_ligne,pos_colonne.
*/
void mise_a_jour_position(int pile[][2],int position[2],int *pos_ligne,int *pos_colonne);
#endif
