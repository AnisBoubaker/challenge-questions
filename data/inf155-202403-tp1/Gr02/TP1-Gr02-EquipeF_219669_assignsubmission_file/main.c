/*
TP2 - Labirynthe
Ce projet vise � r�soudre un labyrinthe en trouvant un chemin qui nous m�ne vers
la sortie du labyrinthe en partant de son entr�e.


Auteurs: Ghita El Kaissouni, Rayan Hani, Imane , Stephanie

Date: 2023-11-12

*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE     1000 //La taille maximale des piles
#define TAILLE_MAX_GRILLE   100  //La taille maximale de la grille a chargee
#define TAILLE_MAX_SAISIE   14  //La taille maximale de la grille a chargee




int main(void)
{
    //NOTE: Ce code vous est fourni � titre d'exemple pour que vous compreniez
    //le fonctionnement d'une pile. Vous ne devez pas conserver ce code avec votre projet!


    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe

    int hauteur_grille, largeur_grille; //Stocke la taille de la grille charg�e depuis le disque

        int *pile_solution[TAILLE_MAX_PILE][2]= {};
        int grille_chargee = 0; ///initililisation de la grille a 0
        int choix; ///choix dans le menu principal soit 1,2,3 ou 4
        //char buf_nom_fichier[TAILLE_MAX_GRILLE]="..\\grille1.txt";
        char buf_nom_fichier[TAILLE_MAX_GRILLE];
        int *entree[2]; ///Tableau: coordonnées du point d'entrée dans le labyrinthe.

        do{

            choix = selection_menu(grille_chargee); ///choix est retourne de la focntion selection_menu

            if (choix ==1) ///choix 1: on charge le fichier //je ne sais pas si je dois mettre choix 1 ici pcq choix 1 est deja dans fonction selection_menu
            {
                menu_charger_labyrinthe(buf_nom_fichier, sizeof(buf_nom_fichier));

                grille_chargee = charger_labyrinthe(buf_nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

            }

            ///Si on fait le choix 2: on resout le lab au complet (voir comment amener la fonction d'Imane)
            if (choix == 2) {
                lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree,
                                        &pile_solution, 0);
            }

            ///Si on fait le choix 3: on resout le lab au complet mais en mode debuguage (voir comment amener la fonction d'Imane)
            if (choix == 3) {
                lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree,
                                        &pile_solution, 1);
            }
            if(choix ==4)
            {
                printf("FIN");
                return EXIT_SUCCESS;
            }
        }while(choix!=4);




    return EXIT_SUCCESS;
}
