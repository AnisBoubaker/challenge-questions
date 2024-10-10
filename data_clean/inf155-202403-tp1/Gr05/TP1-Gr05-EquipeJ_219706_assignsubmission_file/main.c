 

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

#define TAILLE_MAX_PILE 1000  

int main(void)
{
     
   
   
 
 
	int pile_solution[TAILLE_MAX_PILE][2];  
	int depile_x;  
	int depile_y;  
    int case2[2]={1,10};
    int case1[2]={1,9};

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
	int point_entree[2];  
	int hauteur_grille, largeur_grille;  
	int succes_chargement;  


    succes_chargement=charger_labyrinthe("grille1.txt", grille, point_entree, &hauteur_grille, &largeur_grille);

    if (!succes_chargement)
    {
        printf("Une erreur s'est produite lors du chargement de la grille.\n");
        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
        system("pause");
        return EXIT_FAILURE;
    }

 
 
	pile_initialiser(pile_solution, TAILLE_MAX_PILE);


 
	pile_empiler(pile_solution, point_entree[0], point_entree[1]);
    printf("case: %i,%i\n",case1[0],case1[1]);
    printf("case: %i,%i\n",case2[0],case2[1]);
    printf("Adjacent si 1,non adjacent si 0: ");
    printf("%i\n",lab_est_cases_adjacentes(case1,case2));
    printf("\n*** Affichage du tableau avec solution: ***\n");
    lab_afficher_grille(grille,hauteur_grille,largeur_grille, pile_solution);

 
	printf("\n*** Contenu de la pile solution: ***\n");
	while (!pile_est_vide(pile_solution))
	{
		pile_depiler(pile_solution, &depile_y, &depile_x);
	    printf("(%d, %d)\n", depile_y, depile_x);
	}


 
 
}