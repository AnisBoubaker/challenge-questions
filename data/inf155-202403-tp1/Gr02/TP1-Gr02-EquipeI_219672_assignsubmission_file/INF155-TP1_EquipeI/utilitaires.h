//
// Created by Charles-Antoine Masson on 2023-11-07.
//

#ifndef INF155_TP1_EQUIPEI_UTILITAIRES_H
#define INF155_TP1_EQUIPEI_UTILITAIRES_H

/*
 * FONCTION: nb_aleatoire
 * Cette fonction retourne une valeur al�atoire dans l'intervalle entier
   [min, max]. Chaque valeur poss�de la m�me probabilit� d'�tre g�n�r�e.

   PARAM�TRES :
        - min : La plus petite valeur pouvant �tre g�n�r�e (type : int).
        - max : La plus grande valeur pouvant �tre g�n�r�e (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a pr�alablement �t� appel�e.
 */
int nb_aleatoire(int min, int max);

/*
 * FONCTION: affiche_tab
 * DESCRIPTION: fonction qui affiche n'importe quelle tableau 2D a deux colones
 *
 * PAREMETRES:
 *      - tab[][] : tableau 2dDque l'on désire afficher
 *      - nb_lignes: nombres de lignes du tableau
 */
void affiche_tab(int tab[][2], int nb_lignes);

#endif //INF155_TP1_EQUIPEI_UTILITAIRES_H
