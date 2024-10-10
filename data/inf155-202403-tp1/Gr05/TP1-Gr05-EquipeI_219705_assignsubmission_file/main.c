/*
TP1 - Labyrinthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.

Auteurs: Paul Ayoub, Mohammad Hamadé, David Mushimiyimana et Vincenzo Jean Vincent Pirot

Date: 16 octobre 2023
*/

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

int main()
{
    // Indique si on a quitté le programme
    int sortie = 0;
    // Variable pour le choix du menu
    int choix_menu = -1;
    // Indique si la grille a été chargée
    int grille_chargee = 0;
    // Mode débug désactivé par défaut
    int debug = 0;
    // Indique si le labyrinthe a été résolu
    int est_resolu = 0;

    // Tableau 2D qui contient la grille du labyrinthe
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    // Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
    int point_entree[2];
    // Stocke la taille de la grille chargée depuis le disque
    int hauteur_grille, largeur_grille;
    // Tableau qui sera utilisé pour stocker la pile de coordonnées contenant la solution
    int pile_solution[TAILLE_MAX_PILE][2];

    // Stocke le nom du fichier à charger
    char nom_fichier[TAILLE_MAX_NOM_FICHIER];

    /* Initialisation du générateur de nombres aléatoires */
    srand((unsigned int) time(NULL));

    /* Initialisation de la pile */
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);

    do
    {
        choix_menu = selection_menu(grille_chargee);

        switch (choix_menu)
        {
            // Charger un labyrinthe
            case 1:
                menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
                grille_chargee = charger_labyrinthe(nom_fichier, grille, point_entree,
                                                    &hauteur_grille, &largeur_grille);
                if (grille_chargee)
                {
                    // Effacer l'écran
                    system("cls");
                    // Message de réussite du chargement de la grille
                    printf("Grille chargee avec succes:\n");
                    // Affichage de la grille dans la console
                    lab_afficher_grille(grille, hauteur_grille,
                                        largeur_grille, pile_solution);
                    system("pause");
                }
                else
                {
                    // Message d'erreur
                    printf("Erreur lors du chargement de la grille.\n");
                    system("pause");
                }
                // Effacer l'écran
                system("cls");
                break;

            case 2: // Resoudre le labyrinthe
                est_resolu = lab_resoudre_profondeur(grille, hauteur_grille,
                                                     largeur_grille, point_entree,
                                                     pile_solution, debug);
                if (!est_resolu)
                    printf("La solution a ete trouvee :-)\n");
                else
                    printf("Aucune solution trouvee :-(\n");
                break;
            case 3: // Resoudre le labyrinthe pas-a-pas
                debug = 1;
                est_resolu = lab_resoudre_profondeur(grille, hauteur_grille,
                                                     largeur_grille, point_entree,
                                                     pile_solution, debug);
                if (est_resolu)
                    system("cls");
                break;
            case 4: // Quitter le programme
                sortie = 1;
        }
    }
    while (!sortie);
    return EXIT_SUCCESS;
}