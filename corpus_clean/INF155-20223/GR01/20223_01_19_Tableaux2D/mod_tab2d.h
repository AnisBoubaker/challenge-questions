
#ifndef MOD_TAB2d__H  
#define MOD_TAB2d__H

 
#include <stdio.h>



 
#define NB_MAX_LIGNES 100
#define NB_MAX_COLONNES 100

 


 
void afficher_tab2d(double tab[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes);
 
void convertir_fahreneith(double temps[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes);
#endif