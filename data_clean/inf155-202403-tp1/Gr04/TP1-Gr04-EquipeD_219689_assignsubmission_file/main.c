 


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "Utilitaires.h"

#define TAILLE_MAX_PILE 1000  


int main(void)
{



	 
	 
	int la_pile[TAILLE_MAX_PILE][2];  
	int depile_x;  
	int depile_y;  

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
	int point_entree[2];  
	int hauteur_grille, largeur_grille;  
	int succes_chargement;  

	 
	 
	pile_initialiser(la_pile, TAILLE_MAX_PILE);

	 
	pile_empiler(la_pile, 10, 5);
	pile_empiler(la_pile, 11, 6);
	pile_empiler(la_pile, 12, 7);
	pile_empiler(la_pile, 19, 8);
	pile_empiler(la_pile, 5, 3);
	pile_empiler(la_pile, 0, 1);
	pile_empiler(la_pile, 21, 8);

	 
	pile_haut_pile(la_pile, &depile_y, &depile_x);
	printf("Le haut de la pile contient la coordonnee: (%d, %d)\n", depile_y, depile_x);

	 
	if (pile_contient(la_pile, 12, 7))
	{
		printf("La pile contient bien la coordonnee 12,7\n");
	}
	else
	{
		printf("La coordonnee 12,7 n'est pas dans la pile!\n");
	}
	if (pile_contient(la_pile, 45, 8))
	{
		printf("La pile contient bien la coordonnee 45,8\n");
	}
	else
	{
		printf("La coordonnee 45,8 n'est pas dans la pile!\n");
	}

	 
	 
	printf("\n*** Contenu de la pile: ***\n");
	while (!pile_est_vide(la_pile))
	{
		pile_depiler(la_pile, &depile_y, &depile_x);
		printf("(%d, %d)\n", depile_y, depile_x);
	}

	 
	printf("\n\n");
	
	 

	if (!succes_chargement)
	{
		printf("Une erreur s'est produite lors du chargement de la grille.\n");
		printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
		system("pause");
		return EXIT_FAILURE;
	}

	 
	printf("La grille comporte: %d lignes et %d colonnes\n", hauteur_grille, largeur_grille);
	printf("Le point d'entree se trouve à la coordonnée (%d, %d)\n", point_entree[0], point_entree[1]);
	
	if (grille[0][9] == 1)
	{
		printf("La case (0,9) est un mur.\n");
	}
	else
	{
		printf("La case (0,9) est un couloir.\n");
	}

	if (grille[3][10] == 1)
	{
		printf("La case (3,10) est un mur.\n");
	}
	else
	{
		printf("La case (3,10) est un couloir.\n");
	}


    Executable_labyrinthe();


	system("pause");
	return EXIT_SUCCESS;
}
