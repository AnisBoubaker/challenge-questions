 

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

int main(void)
{
    int grille_chargee = 0;  
    int choix_selectionne = 0;  
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE] = {};  
    int point_entree[2];  
    int hauteur_grille;  
    int largeur_grille;  
    int pile_solution[TAILLE_MAX_PILE][2];  
    char buf_nom_fichier[TAILLE_MAX_NOM_FICHIER];  
    int solution_est_trouve;  

     
    while (choix_selectionne != 4)
    {
         
        choix_selectionne = selection_menu(grille_chargee);
        switch (choix_selectionne) {
            case 1:
                 
                menu_charger_labyrinthe(buf_nom_fichier, TAILLE_MAX_NOM_FICHIER);
                grille_chargee = charger_labyrinthe(buf_nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
                pile_initialiser(pile_solution, TAILLE_MAX_PILE);
                afficher_chargement_grille(grille_chargee, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
            case 2:
                 
                solution_est_trouve = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0);
                afficher_solution(solution_est_trouve, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
            case 3:
                 
                solution_est_trouve = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 1);
                afficher_solution(solution_est_trouve, grille, hauteur_grille, largeur_grille, pile_solution);
                break;
        }
    }
	return EXIT_SUCCESS;
}
