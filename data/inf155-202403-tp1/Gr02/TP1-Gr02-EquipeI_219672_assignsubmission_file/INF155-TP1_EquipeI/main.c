/*
TP2 - Labirynthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.


Auteurs: Émile Madore, Charles-Antoine Masson, Alexandre Racine

Date: 2023-10-31

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
#define TAILLE 1000
int main(void) {

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int point_entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int succes_chargement; //Stocke une valeur vraie si la grille a été chargée correctement

    char nom_ficher;
    int sol_par[TAILLE_MAX_GRILLE][2] ;
    int pile_solution[1000][2];

    do {



        switch (selection_menu(0)) {
            case 1:


                do {

                    menu_charger_labyrinthe(&nom_ficher, TAILLE);
                    succes_chargement = charger_labyrinthe(&nom_ficher, grille, point_entree, &hauteur_grille,
                                                           &largeur_grille);

                    if (!succes_chargement) {
                        printf("Une erreur s'est produite lors du chargement de la grille.\n");
                        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                        system("pause");

                    }

                } while (!succes_chargement);


                lab_afficher_grille(grille, hauteur_grille, largeur_grille, 0);
                system("pause");

                switch ( selection_menucharge(0)) {
                    case 2: // appeler fonction pour résoudre le labyrinthe.



                        pile_initialiser(sol_par, TAILLE_MAX_GRILLE) ;
                       lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0);
                       lab_afficher_grille(grille,hauteur_grille,largeur_grille, pile_solution );
                        system("pause");

                        break;


                    case 4:
                        exit(0);
                        break;


                    case 3:



                        break;




                }




            case 4 :

                exit(0);
                break;


        }





    }while(1);




}