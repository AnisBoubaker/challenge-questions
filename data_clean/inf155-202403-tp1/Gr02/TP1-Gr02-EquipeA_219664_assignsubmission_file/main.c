 


#include <time.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void) {

     
    srand((unsigned int) time(NULL));

     
    char nom_grille[TAILLE_MAX_NOM_FICHIER]; 
    int succes_chargement = 0;  
    int la_pile[TAILLE_MAX_PILE][2];  
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int point_entree[2];  
    int hauteur_grille, largeur_grille;  
    int choix_menu = 0;
    bool labyrinthe_resolu;


     
    while (choix_menu!=4) {
        choix_menu = selection_menu(succes_chargement);

         
        pile_initialiser(la_pile, TAILLE_MAX_PILE);

         
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
