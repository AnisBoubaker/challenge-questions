#ifndef MOD_CAPTEUR__H_
#define MOD_CAPTEUR__H_

#include "mod_mesure.h"

typedef struct capteur
{
	char* ville; 
	double longitude; 
	double latitude; 
	//t_mesure mesures[365][10];
	//Tableau dynamique avec un nombre de colonnes fixe à 10
	t_mesure** mesures; //Tableau dynamique 2D de t_mesure
	int nb_jours; //La taille effective en lignes du tableau mesures
	int nb_max_jours; 
} t_capteur;

t_capteur* capteur_init(char* ville, double lat, double longi, int max_jours);

void capteur_destroy(t_capteur* capteur);

#endif