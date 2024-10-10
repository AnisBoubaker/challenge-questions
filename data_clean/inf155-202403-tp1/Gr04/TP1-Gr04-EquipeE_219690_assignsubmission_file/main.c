 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#define TAILLE_MAX_PILE 1000
#define BUF_TAILLE 12

int main(void) {

    int choix;
    int grille_chargee = 0;
    int entree[2] = {0, 10};
    srand((unsigned int) time(NULL));

    do {
        system("cls");
        choix = selection_menu(grille_chargee);
        fflush(stdin);  
        char nom_fichier[BUF_TAILLE];


        switch (choix) {
            case 1 :
                menu_charger_labyrinthe(nom_fichier, BUF_TAILLE);
                system("cls");

                int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
                int point_entree[2];  
                int hauteur_grille, largeur_grille;  
                int pile_solution[TAILLE_MAX_PILE][2];

                grille_chargee = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille,
                                                    &largeur_grille);
                pile_initialiser(pile_solution, 1000);

                if (!grille_chargee) {
                    printf("Erreur lors de chargement de la grille.\n");
                    printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                    system("pause");
                } else {
                    printf("Grille chargee avec succes: \n");
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    system("pause");
                }
                break;

            case 2 :
                if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0)) {
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    system("pause");
                } else {
                    printf("aucune solution trouvee :-(\n");
                    system("pause");
                }
                break;

            case 3 :
                if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 1)) {
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    system("pause");
                } else {
                    printf("aucune solution trouvee :-(\n");
                    system("pause");
                }
                break;
            default:
                exit(EXIT_SUCCESS);
        }
    } while (choix != 4);
}