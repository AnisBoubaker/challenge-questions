/*
Module: utilitaires
Description: Contient les fonctions ne faisant partis d'aucun des
             autres modules

Auteur: Ferdaws Aljane, Milena Busuioc, Rachid Hamza et William Lavoie

Date: 12 Novembre 2023
*/

#include "pile.h"
#include "labyrinthe.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef INF_155_EQUIPED_UTILITAIRES_H
#define INF_155_EQUIPED_UTILITAIRES_H

/*
 * DEPLACEMENT_EST_POSSIBLE
 * Description: D�termine si une coordonn�e correspond � un d�placement possible selon
 *              les crit�res suivant: la coordonn�e fait partie du labyrinthe,
 *              n'est pas dans la pile solution et n'est pas un mur
 *
 * Paramètres:
 *      -grille (int[][]) : tableau contenant les informations de la grille du labyrinthe
 *      -hauteur_grille (int): nombre de lignes effectives de la grille
 *      -largeur_grille (int): nombre de colonnes effectives de la grille
 *      -pos_ligne (int): ligne de la coordonnée à traiter
 *      -pos_colonne (int) colonne de la coordonnée à traiter
 *      -solution partielle (int[][]): pile contenant les coordonnées de la solution partielle
 *
 * Retour:
 *      (int): 0 si la coordonée est un déplacement possible, 1 autrement
 */

int deplacement_est_possible( int grille[][TAILLE_MAX_GRILLE],
                              int hauteur_grille,
                              int largeur_grille,
                              int pos_ligne,
                              int pos_colonne,
                              int solution_partielle[][2]);


/*
 * EFFACER_TERMINAL
 * Description: Réinitialise le terminal. Exécute une commande différente sous Windows et Mac/Linux
 * Notez que cette fonction affecte le terminal directement avec une commande CLI ou bash
 * et donc n'affectera pas le programme si celui-ci est lancé directement dans l'interface CLion
 *
 * Cette fonction a été écrite à l'aide de l'IA, Bing
 * Tous les crédits appartiennent à Microsoft Corporation
 */
void effacer_terminal(void);


/*
 * AFFICHER_MENU
 * Description: Affiche le menu indiquant les différentes options offertes à l'utilisateur,
 *              selon le fait qu'une grille ait été chargée ou non, soit charger un labyrinthe,
 *              résoudre un labyrinthe, résoudre pas à pas et fermer le programme
 *
 * Paramètres: void
 *
 * Retour: void
 */
void afficher_menu(int grille_chargee);

#endif
