/*
Module: utilitaires
Description: Fournit l'ensemble de fonction utilitaires qui seront appelés souvent dans le programme.

Auteurs:     - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier


Date: 12 novembre 2023
*/

#ifndef TP1_UTILITAIRES_H
#define TP1_UTILITAIRES_H

/* Fonction : nb_aleatoire
 * Descriptions : Permet de générer un nombre de manière aléatoire entre deux valeurs (une minimum et une maximale)
 * Paramètres :
 * min : La valeur entière minimale que le nombre peux prendre.
 * max : La valeur entière maximale que le nombre peux prendre.
 * Retour : Une valeur aléatoire etre le min et le max.
 */

int nb_aleatoire(int min,int max);

/* Fonction : laby_expert
 * Description: Affiche titre dans l'executable
 * Parametres: Aucun
 * Retour: Aucun
 */

void laby_expert();

#endif
