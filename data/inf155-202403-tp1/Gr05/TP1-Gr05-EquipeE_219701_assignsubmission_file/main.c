/*
TP2 - Labyrinthe

Description:

    Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous méne vers
    la sortie du labyrinthe en partant de son entrée.


Auteurs: Vito PELLEGRINELLI/ Mark AVRUTIN/ Romain LATREILLE/ Xavier MARTEL

Date: 16/10/2023

*/


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


#define TAILLE_MAX_PILE 1000 //La taille maximale des piles


int main(void) {
    int pile_solution[TAILLE_MAX_PILE][2]; //Tableau qui sera utilise pour stocker la pile d'exemple
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int depile_y, depile_x; // coordonnees des piles en x et y.
    int grille_chargee = 0; //chargement de la grille initiale
    int succes_chargement; //Stocke une valeur vraie si la grille a ete chargée correctement.
    int selection; // Appelle de la fonction selection_menu
    int debug; //si utilisateur selectionne debug
    int solution; // Si le labyrinthe est une solution
    char nom_fichier[50]; // chaine de charactere qui est saisi par l utilisateur pour le nom du fichier du labyrinthe


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

                        //On depile tous les elements de la pile en les affichant, jusqu'a ce qu'elle soit vide.
                        //Vous remarquerez que le dernier ajoute s'affiche en premier.
                        while (!pile_est_vide(pile_solution))
                        {
                            pile_depiler(pile_solution, &depile_y, &depile_x);
                            //printf("(%d, %d)\n", depile_y, depile_x);
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















