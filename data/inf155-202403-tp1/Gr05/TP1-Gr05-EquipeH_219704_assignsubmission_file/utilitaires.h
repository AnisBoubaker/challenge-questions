/*
Module: labyrinthe_io
Description: Module de fonction d'entr�e/sortie en lien avec le programme du labyrinthe

Auteur: Ken Whittom ,Anthony Carhuallanqui Nerio, Franck Kamwa

Date: 2023-11-12
*/

#ifndef UTILITAIRES_H
#define UTILITAIRES_H

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


#endif
