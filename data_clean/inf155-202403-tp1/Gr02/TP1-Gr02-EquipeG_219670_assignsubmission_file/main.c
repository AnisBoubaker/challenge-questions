 

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "pile.h"
#include "utilitaires.h"

#define TAILLE_MAX_GRILLE 100        
#define TAILLE_MAX_NOM_FICHIER 100   
#define TAILLE_MAX_PILE 1000         

int main(void){

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];    
    int nb_lignes;                                       
    int nb_colonnes;                                     
    int entree[2];                                       
    int choix_menu;                                      
    char buf_nom_fichier[TAILLE_MAX_NOM_FICHIER];        
    int pile_solution[TAILLE_MAX_PILE][2];               
    int succes_chargement=0;                               
    int solution_trouve;                                 

     
    do
    {
         
        choix_menu = selection_menu(succes_chargement);

         
        if(choix_menu == 1)
        {
             
            pile_initialiser(pile_solution, TAILLE_MAX_PILE);

             
            menu_charger_labyrinthe(buf_nom_fichier, TAILLE_MAX_NOM_FICHIER);
            succes_chargement = charger_labyrinthe(buf_nom_fichier, grille, entree, &nb_lignes, &nb_colonnes);

             
            if(succes_chargement)
            {
                printf("Grille chargee avec success: \n");
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
            }
            else
            {
                printf("Une erreur c'est produite lors du chargement de la grille.\n");
            }
            demande_pour_continuer();
        }

         
        else if (choix_menu == 2)
        {
            solution_trouve = lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 0);
            if(solution_trouve)
            {
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
            }
            else
            {
                printf("Aucune solution trouvee :-(\n");
            }
            demande_pour_continuer();
        }

         
        else if (choix_menu == 3)
        {
            solution_trouve = lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 1);
            if(!solution_trouve)
            {
                printf("Aucune solution trouvee :-(\n");
            }
            system("cls");
        }

     
    }while(choix_menu != 4);

    return EXIT_SUCCESS;
}