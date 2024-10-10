/*
TP2 - Labirynthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.


Auteur: Ferdaws Aljane, Milena Busuioc, Rachid Hamza et William Lavoie

Date: 12 novembre 2023
*/

#include "test_des_fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void)
{
    srand(time(NULL));

    // Déclaration des variables
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int nb_lignes, nb_colonnes;
    int entree[2];
    int grille_chargee = 0; // Indique si grille chargée ou pas
    int debug;
    int choix = selection_menu(grille_chargee);
    char fichier[TAILLE_MAX_GRILLE];



    // Tant qu'on ne quitte pas le programme
    while (choix != 4)
    {

        int solution[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2] = {};
        pile_initialiser(solution, TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);
        fflush(stdout);

        // Choix 1 : Charger un labyrinthe
        if (choix == 1)
        {
            fflush(stdin);

            // Charger la grille depuis le fichier
            menu_charger_labyrinthe(fichier, TAILLE_MAX_GRILLE);
            if(charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes))
            {
                grille_chargee = 1; // Grille chargée
                effacer_terminal();
                printf("Grille chargee avec success:\n");
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, solution);
            }
            printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
            getchar(); // Attendre l'entrée de l'utilisateur
            effacer_terminal();
        }

        // Choix 3 : Resoudre le labyrinthe pas-a-pas
        if (choix == 3)
        {
            debug = 1;

            if(!lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, solution,debug))
            {
                printf("Aucune solution trouvee");
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar(); // Attendre l'entrée de l'utilisateur
                effacer_terminal();
                afficher_menu(grille_chargee);

            }
            else
            {
                fflush(stdout);
            }

            // Recharger la grille
            charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes);
        }

        // Choix 2 : Resoudre le labyrinthe
        if (choix == 2)
        {
            debug = 0;

            if(!lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, solution, debug))
            {
                printf("Aucune solution trouvee");
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar(); // Attendre l'entrée de l'utilisateur
                effacer_terminal();
                afficher_menu(grille_chargee);

            }
            else
            {
                effacer_terminal();
                afficher_menu(grille_chargee);
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, solution);
                fflush(stdin);
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                getchar(); // Attendre l'entrée de l'utilisateur

            }

            // Recharger la grille
            charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes);
        }
        effacer_terminal();
        choix = selection_menu(grille_chargee);
    }

    return EXIT_SUCCESS;
}
