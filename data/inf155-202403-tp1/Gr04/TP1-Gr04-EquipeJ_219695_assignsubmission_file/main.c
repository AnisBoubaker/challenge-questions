/*
INF155 - Gr04

Titre: TP1 - Labyrinthe
Description: Ce projet vise a resoudre un labyrinthe en trouvant un chemin qui nous mene vers
la sortie du labyrinthe en partant de son entree.

Auteures: Faria Haque, Rachel Khoury, Shama Louissaint et Ines Medjou
Date: 2023-11-09
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "Module_utilitaire.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
#define TAILLE_MAX_GRILLE 100 //La taille maximale d'une grille

int main(void)
{
    int la_pile[TAILLE_MAX_PILE][2]; //Tableau qui sera utilisé pour stocker la pile d'exemple
    int depile_x; //Stocke la coordonnée x dépilée
    int depile_y; //Stocke la coordonnée y dépilée

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int point_entree[2]; //Stocke les coordonnees du point d'entree du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int succes_chargement; //Stocke une valeur vraie si la grille a été chargée correctement.

    char nom_fichier[100];
    int grille_chargee = 0;
    int choix = 0;
    int pile_solution;

     // Initialisation du générateur de nombres aléatoires   POUR FONCTION LAB_CHOISIR_DEPLACEMENT
     srand(time(NULL));

     affiche_titre(); //Affichage du titre du labyrinthe expert

     switch (choix = selection_menu(grille_chargee))
     {
            case 1:
             menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_GRILLE);
             succes_chargement = charger_labyrinthe("grille1.txt", grille, &point_entree, &hauteur_grille, &largeur_grille);
             grille_chargee = succes_chargement;
             if (!succes_chargement)
             {
                 printf("Erreur lors du chargement du labyrinthe depuis le fichier.\n");
                 printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                 return EXIT_FAILURE;
             }
             break;

             case 2:
                if (!grille_chargee)
                {
                    printf("La résolution est indisponible tant que vous n'avez pas chargé un labyrinthe. Veuillez charger un labyrinthe.\n");
                }
                else
                {
                    // CODE POUR RESOUDRE LE LABYRINTHE
                    int resolu = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, &pile_solution, 1);
                    if (resolu)
                    {
                        printf("Bravo! Vous avez résolu le labyrinthe!\n");
                    }
                    else
                    {
                        printf("Désolé. Impossible de résoudre le labyrinthe.\n");
                    }
                }
                break;

            case 3:
                printf("Au revoir!\n");
                return 0; // Quitte le programme         

            default:
                printf("Choix indisponible. Veuillez saisir à nouveau.\n");
                scanf("%i", &choix);
                break;
     }

    return EXIT_SUCCESS;
}



