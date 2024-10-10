 

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE     1000  
#define TAILLE_MAX_GRILLE   100   
#define TAILLE_MAX_SAISIE   14   




int main(void)
{
     
     


    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  

    int hauteur_grille, largeur_grille;  

        int *pile_solution[TAILLE_MAX_PILE][2]= {};
        int grille_chargee = 0;  
        int choix;  
         
        char buf_nom_fichier[TAILLE_MAX_GRILLE];
        int *entree[2];  

        do{

            choix = selection_menu(grille_chargee);  

            if (choix ==1)  
            {
                menu_charger_labyrinthe(buf_nom_fichier, sizeof(buf_nom_fichier));

                grille_chargee = charger_labyrinthe(buf_nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

            }

             
            if (choix == 2) {
                lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree,
                                        &pile_solution, 0);
            }

             
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
