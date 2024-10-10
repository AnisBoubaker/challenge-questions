 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "pile.h"


#define TAILLE_MAX_PILE 1000  
#define TAILLE_MAX_GRILLE 100

int main(void) {

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int nb_lignes, nb_colonnes;
    int entree[2];
    int pile_solution2[TAILLE_MAX_PILE][2];
    int choix = 0;
    char nom[256];
    int temporaire = 0;
    int chargement_grille = 0;
    int debug = 0;

    pile_initialiser(pile_solution2, TAILLE_MAX_PILE);

    do {
        choix = selection_menu(chargement_grille);
        switch (choix) {
            case 1:
                menu_charger_labyrinthe(nom, 256);
                charger_labyrinthe(nom, grille, entree, &nb_lignes, &nb_colonnes);
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution2);
                chargement_grille = charger_labyrinthe(nom, grille, entree, &nb_lignes, &nb_colonnes);
                break;
            case 2:
                if (chargement_grille == 0) {
                    printf("Choix invalide !");
                } else {
                     lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution2, debug); {
                        lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution2);
                    }
                    break;
                    case 3:
                        printf("Choix invalide !");
                    break;
                    case 4:
                        temporaire++;
                    break;

                }
        }


    } while (temporaire == 0);
    return EXIT_SUCCESS;
}