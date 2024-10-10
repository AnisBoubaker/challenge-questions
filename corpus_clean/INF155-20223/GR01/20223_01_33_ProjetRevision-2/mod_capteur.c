#include "mod_capteur.h"

t_capteur* capteur_init(const char* ville, double latitude, double longitude, int nb_max_jours_mesures)
{
	t_capteur* nouv_capteur; 

	nouv_capteur = (t_capteur*)malloc(sizeof(t_capteur));
	if (nouv_capteur == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouv_capteur->ville = (char*)malloc(sizeof(char)*(strlen(ville)+1));
	if (nouv_capteur->ville == NULL)
	{
		free(nouv_capteur);
		exit(EXIT_FAILURE);
	}

	 
	nouv_capteur->mesures = (t_mesure**)malloc(sizeof(t_mesure*) * nb_max_jours_mesures);
	if (nouv_capteur->mesures == NULL)
	{
		free(nouv_capteur->ville);
		free(nouv_capteur);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nb_max_jours_mesures; i++)
	{
		nouv_capteur->mesures[i] = (t_mesure*)malloc(sizeof(t_mesure) * NB_MAX_MESURES_PAR_JOUR);
		if (nouv_capteur->mesures[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(nouv_capteur->mesures[j]);
			}
			free(nouv_capteur->mesures);
			free(nouv_capteur->ville);
			free(nouv_capteur);
			exit(EXIT_FAILURE);
		}
	}

	nouv_capteur->latitude = latitude;
	nouv_capteur->longitude = longitude;
	strcpy(nouv_capteur->ville, ville);
	nouv_capteur->nb_jours_mesures = 0;
	nouv_capteur->max_jours_mesures = nb_max_jours_mesures;
	return nouv_capteur;
}

void capteur_destroy(t_capteur* le_capteur)
{
	free(le_capteur->ville);
	 
	for (int i = 0; i < le_capteur->max_jours_mesures; i++)
	{
		free(le_capteur->mesures[i]);
	}
	 
	free(le_capteur->mesures);
	free(le_capteur);
}


void capteur_afficher(const t_capteur* capteur)
{
	printf("Ville: %s, Lat: %.2lf, Lon: %.2lf\n", 
		capteur->ville,
		capteur->latitude,
		capteur->longitude);

	for (int i = 0; i < capteur->nb_jours_mesures; i++)
	{
		printf("Jour #%d: \n", i);
		for (int j = 0; j < NB_MAX_MESURES_PAR_JOUR; j++)
		{
			mesure_afficher(&(capteur->mesures[i][j]));
		}
	}

}
