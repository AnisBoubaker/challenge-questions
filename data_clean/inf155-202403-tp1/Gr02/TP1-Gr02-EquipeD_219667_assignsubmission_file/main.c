 

#include "test_des_fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void)
{
    srand(time(NULL));

     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int nb_lignes, nb_colonnes;
    int entree[2];
    int grille_chargee = 0;  
    int debug;
    int choix = selection_menu(grille_chargee);
    char fichier[TAILLE_MAX_GRILLE];



     
    while (choix != 4)
    {

        int solution[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2] = {};
        pile_initialiser(solution, TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);
        fflush(stdout);

         
        if (choix == 1)
        {
            fflush(stdin);

             
            menu_charger_labyrinthe(fichier, TAILLE_MAX_GRILLE);
            if(charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes))
            {
                grille_chargee = 1;  
                effacer_terminal();
                printf("Grille chargee avec success:\n");
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, solution);
            }
            printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
            getchar();  
            effacer_terminal();
        }

         
        if (choix == 3)
        {
            debug = 1;

            if(!lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, solution,debug))
            {
                printf("Aucune solution trouvee");
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar();  
                effacer_terminal();
                afficher_menu(grille_chargee);

            }
            else
            {
                fflush(stdout);
            }

             
            charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes);
        }

         
        if (choix == 2)
        {
            debug = 0;

            if(!lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, solution, debug))
            {
                printf("Aucune solution trouvee");
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                fflush(stdin);
                getchar();  
                effacer_terminal();
                afficher_menu(grille_chargee);

            }
            else
            {
                effacer_terminal();
                afficher_menu(grille_chargee);
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, solution);
                fflush(stdin);
                printf("\nAppuyez sur n'importe quelle touche pour continuer\n");
                getchar();  

            }

             
            charger_labyrinthe(fichier, grille, entree, &nb_lignes, &nb_colonnes);
        }
        effacer_terminal();
        choix = selection_menu(grille_chargee);
    }

    return EXIT_SUCCESS;
}
