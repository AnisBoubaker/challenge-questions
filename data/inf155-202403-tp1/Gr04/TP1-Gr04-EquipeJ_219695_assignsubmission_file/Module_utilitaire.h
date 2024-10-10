//
// Created by Shamz on 2023-11-06.
//

#ifndef TP1_INF155_FICHIERS_MODULE_UTILITAIRE_H
#define TP1_INF155_FICHIERS_MODULE_UTILITAIRE_H


//Dépendance du module

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/*
 * FONCTION: nb_aleatoire (récupérée dans le laboratoire 3 en INF155)
 * Cette fonction retourne un nombre aléatoire dans l'intervalle entier
   [min, max]. Chaque valeur possède la même probabilité d'être générée.

   PARAMÈTRES :
        - min : La plus petite valeur pouvant être générée (type : int).
        - max : La plus grande valeur pouvant être générée (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a préalablement été appelée.
 */
int nb_aleatoire(int min, int max);

/*
 * Fonction: affiche_titre
 * Description: Cette fonction affiche le titre du labyrinthe expert.
 * Paramètre: Aucun
 * Retourne rien
 */
void affiche_titre(void);

#endif //TP1_INF155_FICHIERS_MODULE_UTILITAIRE_H
