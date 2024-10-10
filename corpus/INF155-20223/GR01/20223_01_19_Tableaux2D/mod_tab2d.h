
#ifndef MOD_TAB2d__H //La garde du module
#define MOD_TAB2d__H

//D�pendances du module
#include <stdio.h>



//Constantes sp�cifiques aux fonctions du module
#define NB_MAX_LIGNES 100
#define NB_MAX_COLONNES 100

//Prototypes des fonctions


/*
AFFICHER_TAB2D
Affiche le contenu d'un tableau � deux dimensions de doubles.
Param�tres: 
tab: Tableau`� deux dimensions de double (MAX colonnes: NB_MAX_COLONNES)
nb_lignes: taille effective en lignes (>0)
nb_colonne: taille effective en colonnes (>0)
*/
void afficher_tab2d(double tab[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes);
/*
Entete de la fonction...
*/
void convertir_fahreneith(double temps[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes);
#endif