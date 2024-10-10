/*
TP1 - Labirynthe

Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.

Auteurs: Anis Boubaker (professeur, fournissant une partie du code aux étudiants)
         Jafar Al-Khaiat
         Tayeb Amrouche
         Jose David Molina Penaloza
         William Zamudio-Turcotte

Date: 2023-11-12 (contributions de l'équipe d'étudiants)
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles

int main(void)
{
    /* //Partie programmee par William, mise en commentaires pour pas empecher la compilation du code
     * surtout pendant mon transport//*/
  //  int une_grille_chargee = 0;
  //  selection_menu(une_grille_chargee);/**/
//	//NOTE: Ce code vous est fourni à titre d'exemple pour que vous compreniez
//	//le fonctionnement d'une pile. Vous ne devez pas conserver ce code avec votre projet!
	int pile_solution[TAILLE_MAX_PILE][2]; //Tableau qui sera utilisé pour stocker la pile d'exemple
	int depile_x; //Stocke la coordonn�e x d�pil�e
	int depile_y; //Stocke la coordonn�e y d�pil�e
    int case2[2]={1,10};
    int case1[2]={1,9};

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
	int succes_chargement; //Stocke une valeur vraie si la grille a été chargée correctement.


    succes_chargement=charger_labyrinthe("grille1.txt", grille, point_entree, &hauteur_grille, &largeur_grille);

    if (!succes_chargement)
    {
        printf("Une erreur s'est produite lors du chargement de la grille.\n");
        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
        system("pause");
        return EXIT_FAILURE;
    }

//
//	On initialise la pile
	pile_initialiser(pile_solution, TAILLE_MAX_PILE);


//	//On empile un ensemble de valeurs solution
	pile_empiler(pile_solution, point_entree[0], point_entree[1]);
    printf("case: %i,%i\n",case1[0],case1[1]);
    printf("case: %i,%i\n",case2[0],case2[1]);
    printf("Adjacent si 1,non adjacent si 0: ");
    printf("%i\n",lab_est_cases_adjacentes(case1,case2));
    printf("\n*** Affichage du tableau avec solution: ***\n");
    lab_afficher_grille(grille,hauteur_grille,largeur_grille, pile_solution);

//	Dépile tous les éléments de la pile en les affichant, jusqu'à ce qu'elle soit vide.
	printf("\n*** Contenu de la pile solution: ***\n");
	while (!pile_est_vide(pile_solution))
	{
		pile_depiler(pile_solution, &depile_y, &depile_x);
	    printf("(%d, %d)\n", depile_y, depile_x);
	}


//	system("pause");
//	return EXIT_SUCCESS;
}