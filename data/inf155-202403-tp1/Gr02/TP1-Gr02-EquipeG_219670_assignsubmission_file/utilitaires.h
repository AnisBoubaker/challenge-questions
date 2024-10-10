/*
Module: utilitaires
Description: fonctions complementaires pour les autres modules
Auteurs:
Tommy Parent,
Maude Gallant-Mercier,
Camille Landry,
Saguira Neysa Charles
Date: 2023-11-07
*/

#ifndef TP1_LE_LABYRINTHE_UTILITAIRES_H
#define TP1_LE_LABYRINTHE_UTILITAIRES_H

//TP1_LE_LABYRINTHE_UTILITAIRES_H

/*****Constantes de preprocesseur******/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*** Prototypes des fonctions ***/

/*
 * NB_ALEATOIRE
 *
 * par: Anis Boubaker
 *
 * descripiton: Cette fonction retourne une valeur al�atoire dans l'intervalle entier [min,max]. Chaque valeur poss�de
 * la m�me probabilit� d'�tre g�n�r�e.
 * Param�tres:
 *  -min: la plus petite valeur pouvant �tre g�n�r�e (type:int)
 *  -max: la plus grande valeur pouvant �tre g�n�r�e (type:int)
 *  valeur de retour: une se trouvant dans l'inntervalle [min,max] (type:int).
 *  antecedents:
 *  -on suppose que la fonction srand a pr�alablement �t� appel�.
 */
int nb_aleatoire(int min,int max);

/*
 * DEMANDE_POUR_CONTINUER
 * description: demande a l'utilisateur d'appuyer sur une touche pour continuer et efface se qui se trouve a l'ecran
 * param�tre:
 * -aucun
 * retour:
 * -aucun
 */
void demande_pour_continuer(void);

#endif