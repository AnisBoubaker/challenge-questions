 


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000  
#define TAILLE_MAX_FICHIER 300

int main(void)
{
	 
	 
	int la_pile[TAILLE_MAX_PILE][2];  
	int depile_x;  
	int depile_y;  

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
	int point_entree[2];                                 
	int hauteur_grille, largeur_grille;  
	int succes_chargement ;  
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
