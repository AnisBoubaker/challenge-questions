/*
Module: utilitaires
Description: Module des fonctions utilitaires en lien avec le programme du labyrinthe

Auteurs: Paul Ayoub, Mohammad Hamadé, David Mushimiyimana et Vincenzo Jean Vincent Pirot

Date: 16 octobre 2023
*/

#ifndef INF155_LABYRINTHE_UTILITAIRES_H
#define INF155_LABYRINTHE_UTILITAIRES_H

// Dépendances du modules
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/*
Fonction: NB_ALEATOIRE
Description: Cette fonction retourne une valeur aléatoire dans intervalle entier
             [min, max]. Chaque valeur posséde la méme probabilité d'étre générée.
Paramètres :
- min : La plus petite valeur pouvant être générée (type : int).
- max : La plus grande valeur pouvant être générée (type : int).

Retour : Une valeur se trouvant dans l'intervalle [min, max]  (type : int).
Antécédent :
 - On suppose que la fonction srand a préalablement été appelée.
*/
int nb_aleatoire(int min, int max);


#endif
