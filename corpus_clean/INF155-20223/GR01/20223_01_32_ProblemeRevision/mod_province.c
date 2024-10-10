#include "mod_province.h"


t_province* province_init(const char* nom, int max_capteurs)
{
	t_province* nouv_prov;

	nouv_prov = (t_province*)malloc(sizeof(t_province));
	if (nouv_prov == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouv_prov->nom = (char*)malloc(sizeof(char) * (strlen(nom) + 1));
	if (nouv_prov->nom == NULL)
	{
		free(nouv_prov);
		exit(EXIT_FAILURE);
	}

	nouv_prov->capteurs = (t_capteur**)malloc(sizeof(t_capteur*) * max_capteurs);
	if (nouv_prov->capteurs == NULL)
	{
		free(nouv_prov->nom);
		free(nouv_prov);
		exit(EXIT_FAILURE);
	}

	strcpy(nouv_prov->nom, nom);
	nouv_prov->nb_capteurs = 0;
	nouv_prov->nb_max_capteurs = max_capteurs;
	
	return nouv_prov;
}

void province_destroy(t_province* la_province)
{
	free(la_province->nom);
	for (int i = 0; i < la_province->nb_capteurs; i++)
	{
		capteur_destroy(la_province->capteurs[i]);
	}
	free(la_province->capteurs);
	free(la_province);
}