 

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

int main(void)
{
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int point_entree[2];  
    int hauteur_grille, largeur_grille;  
    int pile_solution[TAILLE_MAX_GRILLE][2];  

    int succes_chargement = 0;  
    char buf_nom_fichier[200];  
    int buf_taille=200;  
    int debug;  
    int solution_trouvee;  
    int choix;  

    pile_initialiser(pile_solution, TAILLE_MAX_Pile);  

    while (1)
    {
        choix = selection_menu(succes_chargement);     

        if (choix == 1) 
        {
             
            menu_charger_labyrinthe(buf_nom_fichier, buf_taille);  
            succes_chargement=charger_labyrinthe(buf_nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);  

            if (!succes_chargement)
            {
                printf("Une erreur s'est produite lors du chargement de la grille.\n");
                system("pause");
            }
            else
            {
                printf("Grille chargee avec succes:\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);  
                system("pause");
            }
        }
        else if (choix == 2) 
        {
            debug = 0;
            solution_trouvee = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,point_entree,pile_solution,debug);  

            if (solution_trouvee == 1) 
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);  
                system("pause");
            }
            else 
            {
                printf("Aucune solution trouvee :-(\n");
                system("pause");
            }
        }
        else if (choix == 3) 
        {
            debug = 1;
            lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,point_entree,pile_solution,debug);  
        }
        else if (choix == 4) 
        {
            return EXIT_SUCCESS;
        }
    }



}
