 

 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"
#include "pile.h"


 
int main(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int pile_solution[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2];  
    int point_entree[2];  
    int hauteur_grille, largeur_grille;  
    int succes_chargement = 0;  
    int solution_trouvee ;  
    int choix_utilisateur = 0;  
    int meilleur_score;  
    char nom_fichier[15];  
    int taille_nom_fichier = sizeof(nom_fichier);

     
    int debug = 0;

     
    srand((unsigned int) time(NULL));
    rand();

     
    while (choix_utilisateur < 4)
    {
         
        choix_utilisateur = selection_menu(succes_chargement);

         
        if (choix_utilisateur == 1) {

             
            pile_initialiser(pile_solution, TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);
             
            meilleur_score=0;
             
            menu_charger_labyrinthe(nom_fichier, taille_nom_fichier);

             
            int length = strlen(nom_fichier);
            if (nom_fichier[length - 1] == '\n')
            {
                nom_fichier[length - 1] = '\0';
            }

             
            succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

             
            if (!succes_chargement) {
                printf("Une erreur s'est produite lors du chargement de la grille.\n\n\n");

                systemPause();
            }

             
            else if(succes_chargement)
            {
                printf("Grille chargee avez succes:\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

                systemPause();
            }

        }

         
        else if (choix_utilisateur == 2 || choix_utilisateur == 3)
        {
            int pas_a_pas=0; 

            if(choix_utilisateur == 3) 
            {
                pas_a_pas = 1; 
            }

             
            solution_trouvee = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, pas_a_pas, debug);

            if (solution_trouvee == 0) 
            {
                printf("Aucune solution trouvee.\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution); 

                systemPause();
            }
            else
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution); 
                printf("Solution trouvee en %i mouvements.\n", pile_solution[0][1]); 
                printf("Le meilleur score est %i mouvements\n", meilleur_score); 

                if(debug){afficher_pile(pile_solution);}

                if(pile_solution[0][1]-1 < meilleur_score || meilleur_score == 0)  
                {
                    meilleur_score = pile_solution[0][1]-1;
                }

                systemPause();
            }

        }


         
        else if (choix_utilisateur == 4) 
        {
            return EXIT_SUCCESS;
        }

    }

     
    return EXIT_SUCCESS;
}
