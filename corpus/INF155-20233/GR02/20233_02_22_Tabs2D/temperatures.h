
//ifndef: If Not Defined
#ifndef TEMPERATURES_H_
#define TEMPERATURES_H_
/*
 * Dépendances du module
 */
#include <stdio.h>

#define MAX_LIGNES 10
#define MAX_COLONNES 20

/*
 * MOYENNE_TAB2D
 * Calcule la moyenne des temperatures dans le tableau 2D de temperatures
 * reçu en parametre.
 * PARAMETRES:
 * - tab: Tableau 2D de temperatures (reels)
 * - nb_lignes: Taille effective du tableau en lignes
 * - nb_colonnes: Taille effective en nombre de colonnes
 * RETOUR: La moyenne des temperatures du tableau
 */
double moyenne_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes);
/*
 * AFFICHER_TAB2D
 * ...
 */
void afficher_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes);

/*
 * TEMPERATURE_EXCEDANT
 * ....
 */
int temperature_excedant(double tab[][MAX_COLONNES],
                         int nb_lignes,
                         int nb_colonnes,
                         double temp_seuil);

#endif