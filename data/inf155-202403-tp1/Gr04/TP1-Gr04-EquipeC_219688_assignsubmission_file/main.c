/*
TP2 - Labyrinthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.

Auteurs: Ã‰mile Yergeau
         Sabrina Poulin
         Xavier Brassard

Date: 2023-10-16
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

int main(void)
{
    int grille_chargee = 0; // valeur booléenne: vrai si la grille a déjà été chargée, faux sinon.
    int choix_selectionne = 0; // Valeur du choix qui a été sélectionné
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE] = {}; // Tableau contenant la grille
    int point_entree[2]; // Coordonnées du point d'entrée
    int hauteur_grille; // Hauteur de la grille
    int largeur_grille; // Largeur de la grille
    int pile_solution[TAILLE_MAX_PILE][2]; // Tableau contenant la pile de la solution/solution partielle
    char buf_nom_fichier[TAILLE_MAX_NOM_FICHIER]; // chaine de caractères contenant le nom du fichier
    int solution_est_trouve; // Bool, 1 si on a trouvé une solution, 0 sinon.

    // On quitte si le choix est 4
    while (choix_selectionne != 4)
    {
        // Affichage + saisie du menu de sélection
        choix_selectionne = selection_menu(grille_chargee);
        switch (choix_selectionne) {
            case 1:
                // chargement de la grille
                menu_charger_labyrinthe(buf_nom_fichier, TAILLE_MAX_NOM_FICHIER);
                grille_chargee = charger_labyrinthe(buf_nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
                pile_initialiser(pile_solution, TAILLE_MAX_PILE);
                afficher_chargement_grille(grille_chargee, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
            case 2:
                // Résolution
                solution_est_trouve = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0);
                afficher_solution(solution_est_trouve, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
            case 3:
                // Résolution pas à pas
                solution_est_trouve = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 1);
                afficher_solution(solution_est_trouve, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
        }
    }
	return EXIT_SUCCESS;
}
