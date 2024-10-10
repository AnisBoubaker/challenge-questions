
 
#ifndef TEMPERATURES_H_
#define TEMPERATURES_H_
 
#include <stdio.h>

#define MAX_LIGNES 10
#define MAX_COLONNES 20

 
double moyenne_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes);
 
void afficher_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes);

 
int temperature_excedant(double tab[][MAX_COLONNES],
                         int nb_lignes,
                         int nb_colonnes,
                         double temp_seuil);

#endif