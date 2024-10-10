 


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


#define TAILLE_MAX_PILE 1000  


int main(void) {
    int pile_solution[TAILLE_MAX_PILE][2];  
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int entree[2];  
    int hauteur_grille, largeur_grille;  
    int depile_y, depile_x;  
    int grille_chargee = 0;  
    int succes_chargement;  
    int selection;  
    int debug;  
    int solution;  
    char nom_fichier[50];  


    selection = selection_menu(grille_chargee);

    if (selection == 1)
    {
        do
        {
            menu_charger_labyrinthe(nom_fichier, 50);


            succes_chargement = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);


            if (!succes_chargement)
            {
                printf("Une erreur s'est produite lors du chargement de la grille.\n");
                printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                system("pause");
            }
        } while (!succes_chargement);

        printf("La grille comporte: %d lignes et %d colonnes\n", hauteur_grille, largeur_grille);
        printf("Le point d'entree se trouve a la coordonnee (%d, %d)\n", entree[0], entree[1]);

        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
        system("pause");
        system("cls");
        while (1)
        {
            pile_initialiser(pile_solution, TAILLE_MAX_PILE);
            selection = selection_menu(succes_chargement);
            switch (selection)
            {
                case 1:
                    menu_charger_labyrinthe(nom_fichier, 50);

                    succes_chargement = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille,
                                                           &largeur_grille);
                    if (!succes_chargement)
                    {
                        printf("Une erreur s'est produite lors du chargement de la grille.\n");
                        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                        system("pause");
                        system("cls");

                    }
                    else
                    {
                        printf("La grille comporte: %d lignes et %d colonnes\n", hauteur_grille, largeur_grille);
                        printf("Le point d'entree se trouve a la coordonnee (%d, %d)\n", entree[0], entree[1]);
                        system("pause");
                    }
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    break;
                case 2:
                    debug = 0;

                    solution = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution,
                                                       debug);

                    if (solution == 1) {
                        printf("\n*** Contenu de la pile: ***\n");

                         
                         
                        while (!pile_est_vide(pile_solution))
                        {
                            pile_depiler(pile_solution, &depile_y, &depile_x);
                             
                        }
                        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                        system("pause");
                    }
                    else
                    {
                        printf("Il n'y a pas de solution.\n");
                        system("pause");
                    }
                    break;

                case 3:

                    debug = 1;
                    solution = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution,debug);

                    if (solution == 0)
                    {
                        printf("Il n'y a pas de solution.\n");
                        system("pause");
                    }
                    break;

                case 4:
                    system("pause");
                    return EXIT_SUCCESS;

                default:
                    system("pause");

            }
        }
        if (selection == 4)
        {
            system("pause");
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}















