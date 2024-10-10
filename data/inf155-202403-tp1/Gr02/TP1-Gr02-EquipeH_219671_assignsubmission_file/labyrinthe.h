/*
Module: labyrinthe
Description: Fournit l'ensemble de fonction permettant de resoudre un labyrinthe

Auteurs:    - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier


Date: 12 novembre 2023
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

/*** CONSTANTES ***/
#define TAILLE_MAX_GRILLE 100 //Taille maximale en lignes et colonnes d'une grille de labyrinthe
#define TAILLE_MAX_PILE 1000

/*  Fonction : lab_choisir_deplacement
 *  Description : Cette fonction permet de choisir le déplacement, dans le labyrinthe, de manière aléatoire.
 *  Paramètres :
 * deplacements_possibles : Ce paramètre est un tableau en 2D qui contient les coordonnées des déplacements aléatoire possible. Ce tableau 2D va dépendre des données du tableau deplacements[4][2] de la fonction lab_calculer_deplacement_possible
 * nb_deplacements_possibles :  Ce paramètre prend le nombre de déplacement possible obtenu dans la fonction deplacements_possibles.
 * Retour : Case du chemin pris aléatoirement
 * Paramètres modifiés : Aucun
 */
int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles);

/* Fonction: lab_est_cases_adjacentes
 * Description: Determine si deux cases sont adjacentes.
 * Parametres: -case1 (tableau de deux entiers)= contient les coordonnees de la premiere case
 *             -case2 (tableau de deux entiers)= contient les coordonnees de la deuxieme case.
 * Retour: 1 si les cases sont adjacentes
 *         0 si les cases ne sont pas adjacentes
*/
int lab_est_cases_adjacentes(int case1[2],int case2[2]);

/*
Fonction: LAB_AFFICHER_GRILLE
Description: Affiche la grille du labyrinthe dans la console. La fonction doit parcourir
                la grille et afficher des murs où la grille contient un 1, et un espace où il n’y
                en a pas. Pour afficher un mur, on utilise le caractère ayant pour code
                ASCII 219.
                Si une solution est fournie (pile_solution != NULL), on doit identifier, sur
                la grille affichée, toutes les cases faisant partie de la solution (ex. par des X).
Paramètres:
- grille: tableau à deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonnées contenant la solution (partielle ou complète) du
labyrinthe.
Retour: Aucun.
Paramètre modifiés: Aucun.
*/
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

/* Fonction : LAB_CALCULER_DEPLACEMENTS_POSSIBLES
 * Description : fonction qui reçoit une coordonnée dans le labyrinthe et trouves tous les déplacements possibles dans
 * des coordonnées immédiatement adjacentes (pas en diagonal). Pour qu'un déplacement soit possible et valide, il ne
 * faut pas qu'il donne dans un mur ou dans une case où on a déjà été (dans la solution).
 * Paramètres :
 *      -grille : tableau qui contient une grille qui représente le labyrinthe , les 1 étant des murs et les 0 des
 *              chemins.
 *      -hauteur_grille : nombre de ligne dans la grille
 *      -largeur_grille : nombre de colonnes dans la grille
 *      -pos_ligne : ligne de la position actuelle
 *      -pos_colonne : colonne de la position actuelle
 *      -solution_partielle : pile qui contient les déplacements de la solution actuelle
 *      -*nb_deplacements : pointeur vers l'adresse du nombre (0 à 4) de déplacements possibles dans l'appelant.
 *      -deplacements : tableau qui contient tous les déplacements possibles (maximum 4).
 * Retour : Aucun
 * Paramètres modifiés :
 *      -nb_deplacement
 *      -deplacements
 * */
void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);

/*
Fonction: LAB_EST_UNE_SORTIE
Description: Fonction qui renvoie Vrai si "position" est une sortie de la grille, sinon elle
                renvoie Faux. "position" est une sortie si elle se trouve en périphérie de la grille
                et que ce n'est pas un mur.
Paramètres:
- position: (tableau de deux entiers) coordonnées de la case du labyrinthe que nous souhaitons
            vérifier si c'est une sortie.
- grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Paramètre modifiés: Aucun.
*/

int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);

/*
 * Fonction: LAB_RESOUDRE_PROFONDEUR
 * Description: Cette fonction permet de résoudre les labyrinthes a l'aide de l'algorithme de parcours en profondeur, donné dans l'énoncé du projet.
 * Paramètre:
 * - grille : paramètre qui contient la structure du labyrinthe à l'aide d'un tableau à deux dimensions d'entiers.
 * - hauteur_grille : entier qui contient le nombre de ligne de la grille.
 * - largeur_grille : entier qui contient le nombre de colonnes de la grille.
 * - entree : (tableau de 2 entiers) coordonées du point d'entrée dans le labyrinthe.
 * - pile_solutions : (tableau 2D) pile de coordonnées. La pile doit avoir été initialisé avant d'appeler cette fonction. Les coordonnées de la solution seront empilées dans cette pile.
 * - debug : (entier) valeur booléenne. Si sa valeur est vraie, la fontion affichera la grille au fur et à mesure qu'on ajoute des cases à la solution.
 * Retour : (entier) valeur vraie si une solution a été trouvée, ou fausse sinon.
 * Paramètre modifiés: pile_solution.
 */

int lab_resoudre_profondeur(
        int grille [][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);

#endif