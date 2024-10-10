#include "mod_capteur.h"

t_capteur* capteur_init(char* ville, double lat, double longi, int max_jours)
{
	t_capteur* nouv_capteur; 

	nouv_capteur = (t_capteur*)malloc(sizeof(t_capteur));
	if (nouv_capteur == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouv_capteur->ville = (char*)malloc(sizeof(char) * (strlen(ville) + 1));
	if (nouv_capteur->ville == NULL)
	{
		free(nouv_capteur);
		exit(EXIT_FAILURE);
	}

	/*
	FAIRE L'ALLOCATION DU TABLEAU 2D mesures
	*/

	nouv_capteur->latitude = lat;
	nouv_capteur->longitude = longi;
	strcpy(nouv_capteur->ville, ville);
	nouv_capteur->nb_jours = 0;

	return nouv_capteur;
}

void capteur_destroy(t_capteur* capteur)
{
	free(capteur->ville);
	free(capteur);
}