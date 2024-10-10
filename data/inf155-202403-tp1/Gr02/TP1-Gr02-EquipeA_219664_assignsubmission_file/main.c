/*
TP2 - Labyrinthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée. 

Auteur: Jonathan Mongrain, Anthony de Marco, Etienne Barriere, Mohammadsam Karimi

Date: 12 novembre 2023

*/


#include <time.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void) {

    //initialisation pour le generateur de chiffre aleatoire
    srand((unsigned int) time(NULL));

    //declaration des variables
    char nom_grille[TAILLE_MAX_NOM_FICHIER];//le nom de la grille
    int succes_chargement = 0; //Stocke une valeur vraie si la grille a été chargée correctement.
    int la_pile[TAILLE_MAX_PILE][2]; //la pile que lon va utiliser pour se deplacer dans le labyrinthe
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int point_entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int choix_menu = 0;
    bool labyrinthe_resolu;


    //le main loop du programme, continue tant que l'utilisateur ne demande pas de quitter le programme
    while (choix_menu!=4) {
        choix_menu = selection_menu(succes_chargement);

        //On initialise la pile
        pile_initialiser(la_pile, TAILLE_MAX_PILE);

        //choix de charger une grille
        if (choix_menu == 1) {
            menu_charger_labyrinthe(nom_grille, TAILLE_MAX_NOM_FICHIER);
            succes_chargement = charger_labyrinthe(nom_grille, grille,
                                                   point_entree, &hauteur_grille, &largeur_grille);

            if (!succes_chargement) {
                printf("Une erreur s'est produite lors du chargement de la grille.\n");
                printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                system("pause");
            }
            else{
                printf("Grille chargee avec succes!\n");
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,la_pile);
                system("pause");
            }
        }
        //pas besoin de verifier si les choix sont valides, selection_menu le fait deja
        //choix de resoudre la grille d'un seul coup
        else if (choix_menu == 2) {
            labyrinthe_resolu = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,
                                                        point_entree,la_pile,false);
            if (!labyrinthe_resolu){
                printf("Le labyrinthe a aucune solution!\n");
            }
            else{
                printf("Labyrinthe resolu!\n");
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,la_pile);
            }
            system("pause");
        }
        //choix de resoudre la grille en mode debug
        else if (choix_menu == 3) {
            labyrinthe_resolu = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,
                                                        point_entree,la_pile,true);
            if (!labyrinthe_resolu){
                printf("Le labyrinthe a aucune solution!\n");
            }
            system("pause");
        }
    }
	return EXIT_SUCCESS;
}
