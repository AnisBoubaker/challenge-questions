/*
Module: labyrinthe
Description: Fournit l'ensemble de fonction permettant de r�soudre un labyrinthe

Auteurs: Paul Ayoub, Mohammad Hamad�, David Mushimiyimana et Vincenzo Jean Vincent Pirot

Date: 16 octobre 2023
*/

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

/*** CONSTANTES ***/
/* Taille maximale en lignes et colonnes d'une grille de labyrinthe */
#define TAILLE_MAX_GRILLE 100

/* La taille maximale des piles */
#define TAILLE_MAX_PILE 1000


/*
Fonction: LAB_AFFICHER_GRILLE
Description: Affiche la grille du labyrinthe dans la console. La fonction doit parcourir
             la grille et afficher des murs o� la grille contient un 1, et un espace o� il
             n�y en a pas. Pour afficher un mur, on utilise le caract�re ayant pour
             code ASCII 219.
             Si une solution est fournie (pile_solution != NULL), on doit identifier, sur
             la grille affich�e, toutes les cases faisant partie de la solution
             (ex. par des X).
Param�tres:
- grille: tableau � deux dimensions d'entiers qui contient les informations
          de la structure du labyrinthe (1=mur, 0=couloir).
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pile_solution : (tableau 2D) pile de coordonn�es contenant la solution
                   (partielle ou compl�te) du labyrinthe.
Retour: Aucun.
Param�tres modifi�s: Aucun.
*/
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                         int largeur_grille, int pile_solution[][2]);


/*
Fonction: LAB_CALCULER_DEPLACEMENTS_POSSIBLES
Description: D�termine la liste de d�placements possibles depuis une position
             donn�e. Un d�placement vers une case X est possible depuis la position P si:
             - X n�est pas un mur
             - P et X sont deux cases adjacentes
             - X ne fait pas partie de la solution partielle en cours d'�laboration
             (pour ne pas revenir en arri�re).
Param�tres:
- grille: tableau � deux dimensions d'entiers qui contient les informations
           de la grille.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- pos_ligne: la ligne de la grille sur laquelle nous sommes pr�sentement positionn�s.
- pos_colonne: la colonne de la grille sur laquele nous sommes pr�sentement positionn�s.
- solution_partielle: pile de coordonn�es qui comprend les coordonn�es de la solution en
                      cours d'�laboration.
- nb_deplacements : adresse o� stocker le nombre de d�placements possible trouv�s.
- deplacements: tableau d'entiers (taille 4x2) qui contiendra le r�sultats:
                les coordonn�es des cases o� un d�placement est possible depuis
                la position actuelle (max 4 possibilit�s).
Retour : Aucun
Param�tres modifi�s : nb_deplacement, deplacements.
*/
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille, int largeur_grille,
                                         int pos_ligne, int pos_colonne,
                                         int solution_partielle[][2],
                                         int *nb_deplacements, int deplacements[4][2]);


/*
Fonction: LAB_CHOISIR_DEPLACEMENT
Description: Choisit un d�placement parmi les d�placements possibles pass�s en param�tre.
             Dans cette version, le choix du d�placement se fait de fa�on al�atoire
             parmi les d�placement possibles. Cependant, si nous souhaitons faire �voluer
             notre programme et choisir le prochain d�placement en utilisant
             une autre approche, il suffit de changer cette fonction.
Param�tres:
- deplacements_possibles: tableau 2D contenant les coordonn�es des d�placements possibles.
                          Les donn�es de ce tableau devraient �tre celles qui ont �t�
                          obtenues par la fonction lab_calculer_deplacements_possibles.
- nb_deplacements_possibles: Nombre d'�l�lements dans le tableau deplacements_possibles.

Retour : (Entier) indice, dans le tableau deplacements_possibles qui a �t� choisi comme
         prochain d�placement.
Param�tres modifi�s : Aucun.
*/
int lab_choisir_deplacement(int deplacement_possibles[][2],
                            int nb_deplacements_possibles);


/*
Fonction: LAB_EST_CASES_ADJACENTES
Description: Renvoie Vrai si les deux cases case1 et case2 sont adjacentes, et faux sinon.
             Deux cases sont adjacentes si elles sont coll�es l�une � l�autre
             dans la grille. Ex.: les cases (5,3) et (5,4) sont adjacentes.
Param�tres:
- case1: (tableau de deux entiers) coordonn�es de la premi�re case.
- case1: (tableau de deux entiers) coordonn�es de la seconde case.

Retour: (Entier) Valeur vraie si les deux cases sont adjacentes, faux sinon.
Param�tres modifi�s: Aucun.
*/
int lab_est_cases_adjacentes(int case1[2], int case2[2]);


/*
Fonction: LAB_EST_UNE_SORTIE
Description: Fonction qui renvoie Vrai si "position" est une sortie de la grille,
             sinon elle renvoie Faux. "position" est une sortie si elle se trouve en
             p�riph�rie de la grille et que ce n'est pas un mur.
Param�tres:
- position: (tableau de deux entiers) coordonn�es de la case du labyrinthe que nous
            souhaitons v�rifier si c'est une sortie.
- grille: (tableau 2D d'entiers) Tableau qui contient la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.

Retour: (Entier) Valeur vraie si "position" est une sortie, faux sinon.
Param�tre modifi�s: Aucun.
*/
int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE],
                       int hauteur_grille, int largeur_grille);


/*
Fonction: LAB_RESOUDRE_PROFONDEUR
Description: Fonction principale du module qui a pour objectif de r�soudre le labyrinthe
             en utilisant l'algorithme de parcours en profondeur (d�crit en d�tail � la
             page 11 de l��nonc�). La fonction construit une solution du labyrinthe
             "grille" dans "pile_solution".
             Cette fonction peut �tre ex�cut�e en mode "debug", auquel cas, la fonction
             affiche � l'�cran la grille avec une solution partielle � chaque fois qu'une
             case est ajout�e � la solution.
             La fonction retourne une valeur vraie si une solution a �t� trouv�e, ou une
             valeur fausse sinon.
Param�tres:
- grille: tableau � deux dimensions d'entiers qui contient les informations de
          la structure du labyrinthe.
- hauteur_grille : entier qui contient le nombre de lignes de la grille.
- largeur_grille : entier qui contient le nombre de colonnes de la grille.
- entree : (tableau de 2 entiers) coordonn�es du point d'entr�e dans le labyrinthe
- pile_solution : (tableau 2D) pile de coordonn�es. La pile doit avoir �t� initialis�e
                  avant d'appeler cette fonction. Les coordonn�es de la solution seront
                  empil�es dans cette pile.
- debug : (entier) valeur bool�enne. Si sa valeur est Vraie, la fonction affichera la
          grille au fur et � mesure qu'on ajoute des cases � la solution.

Retour: (Entier) Valeur vraie si une solution a �t� trouv�e, ou fausse sinon.
Param�tre modifi�s: pile_solution.
*/
int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
                            int largeur_grille, int entree[2], int pile_solution[][2],
                            int debug);

#endif