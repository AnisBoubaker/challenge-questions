//
// Created by olarocque on 10/23/2023.
//

#ifndef TP1_UTILITAIRES_H
#define TP1_UTILITAIRES_H

/*
 * FONCTION: nb_aleatoire
 * Cette fonction retourne une valeur aleatoire dans l'intervalle entier
   [min, max]. Chaque valeur possede la meme probabilite d'etre generee.

   PARAMETRES :
        - min : La plus petite valeur pouvant etre generee (type : int).
        - max : La plus grande valeur pouvant etre generee (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a prealablement ete appelee.
 */

int nb_aleatoire(int min, int max);

//fonction qui affiche la pile
void afficher_pile(int pile[][2]);

//Fonction system pause
void systemPause();

#endif //TP1_UTILITAIRES_H
