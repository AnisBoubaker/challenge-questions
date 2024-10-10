/*
TP2 - Labirynthe 
Ce projet vise � r�soudre un labyrinthe en trouvant un chemin qui nous m�ne vers
la sortie du labyrinthe en partant de son entr�e.



Auteurs:    Julien Mateus, Julien Tremblay, Michel Samaan et Walid Outaleb
Note: juste pour que vous ne soyez pas confus, nous avons eu un problème avec notre premier dépot github
    nous avons du en recréer un nouveau git, cependant noter que le début du projet à été
    commencer sur le précédent et ensuite nous avons tranferer nos fonction dans le nouveau
    qui comporte la version finale.

Date: 2023-11-11

*/


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
#define TAILLE_MAX_GRILLE 100//taille maximale de la grille



int main() {

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];//declaration des variables
    int hauteur_grille = 0, largeur_grille = 0;
    char nom_fichier[100];
    int point_entree[2];
    int pile_solution[TAILLE_MAX_PILE][2]; // Pile pour stocker la solution
    int debug = 0; // Mettre à 1 pour le mode debug
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);// Initialiser la pile de solution
    int choix;
    int grille_chargee = 0;  //chargement de la grille

    while ((choix = selection_menu(grille_chargee)) != 4)  //boucle de menu
         {

        switch (choix) {
            case 1: {
                menu_charger_labyrinthe(nom_fichier, sizeof(nom_fichier));//charger le lab

                if (charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille)) {
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    printf("Labyrinthe chargé avec succès.\n");
                } else {
                    printf("Erreur lors du chargement du labyrinthe.\n");
                }
            }
                grille_chargee=charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
                break;

            case 2:
                if (charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille)) // Résoudre le labyrinthe
                     {
                    if (lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug)) {
                        printf("Solution trouvée.\n");
                        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    } else {
                        printf("Aucune solution trouvée.\n");
                    }
                } else {
                    printf("Aucun labyrinthe chargé.\n");
                }
                break;

            case 3:
                if (grille_chargee) { // Afficher la grille
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, NULL); // Afficher sans solution
                } else {
                    printf("Aucun labyrinthe chargé.\n");
                }
                break;

            case 4:
                printf("Fin du programme.\n");// Quitter
                break;

            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}




