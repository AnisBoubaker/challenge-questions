/*
TP2 - Labirynthe 
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée. 


Auteurs: 

Date: 

*/


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
#define TAILLE_MAX_FICHIER 300

int main(void)
{
	//NOTE: Ce code vous est fourni à titre d'exemple pour que vous compreniez 
	//le fonctionnement d'une pile. Vous ne devez pas conserver ce code avec votre projet!
	int la_pile[TAILLE_MAX_PILE][2]; //Tableau qui sera utilisé pour stocker la pile d'exemple
	int depile_x; //Stocke la coordonnée x dépilée 
	int depile_y; //Stocke la coordonnée y dépilée

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2];                                //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
	int succes_chargement ; //Stocke une valeur vraie si la grille a été chargée correctement.
    int choix_menu;
    char nom_fichier[TAILLE_MAX_FICHIER];
    int resultat;

    do {
        choix_menu = selection_menu(succes_chargement);
        switch (choix_menu) {
            case 1:
                menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
                charger_labyrinthe(nom_fichier,grille,point_entree,&hauteur_grille,&largeur_grille);
                if(!succes_chargement)
                {
                    printf("Erreur lors du chargement du labyrinthe...\n");
                }
                break;

            case 2:
                if (succes_chargement)
                {
                    resultat= lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,point_entree,la_pile,0);
                    if (resultat)
                    {
                        printf("Labyrinthe resolu avec succes!\n");
                    } else
                    {
                        printf("Impossible de résoudre le labyrinhte...\n");
                    }

                }else
                {
                    printf("ERREUR: Aucun labyrinthe chargé. Veuillez charger un labyrinthe avant de le résoudre.\n");

                }
                break;
            case 3:
                printf("Au revoir!\n");
                break;

            default:
                printf("Votre choix est invalide. Veuillez saisir un choix valide.\n");
        }
    } while (choix_menu!=3);


    return EXIT_SUCCESS;
}
