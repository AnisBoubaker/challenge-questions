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

	nouv_prov->capteurs = (t_capteur**)malloc(sizeof(t_capteur*)*max_capteurs);
	if (nouv_prov->capteurs == NULL)
	{
		free(nouv_prov->nom);
		free(nouv_prov);
		exit(EXIT_FAILURE);
	}

	nouv_prov->nb_capteurs = 0;
	nouv_prov->nb_max_capteurs = max_capteurs;
	strcpy(nouv_prov->nom, nom);

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

void afficher_province(const t_province* prov)
{
	printf("Province: %s\n", prov->nom);
	printf("=====================================\n");

	for (int i = 0; i < prov->nb_capteurs; i++)
	{
		capteur_afficher(prov->capteurs[i]);
	}
}



















/*
printf("Nom: %s\n", prov->nom);
	printf("=============================\n");

	for (int i = 0; i < prov->nb_capteurs; i++)
	{
		//Afficbher le nom du capteur i:
		printf("\tVille: %s\n", prov->capteurs[i]->ville);
		for (int j = 0; j < prov->capteurs[i]->nb_jours_mesures; j++)
		{
			printf("\t\tJOUR %d:\n", j);
			for (int k = 0; k < NB_MAX_MESURES_PAR_JOUR; k++)
			{
				printf("\t\t");
				afficher_jour(prov->capteurs[i]->mesures[j][k].jour);
				printf(" / T: %.2lf, P: %.2lf, H: %.2lf\n",
					prov->capteurs[i]->mesures[j][k].temperature,
					prov->capteurs[i]->mesures[j][k].pression,
					prov->capteurs[i]->mesures[j][k].humidite);
			}
		}
	}

*/


/*
printf("Province: %s\n", prov->nom);
	printf("Nombre de capteurs: %d\n", prov->nb_capteurs);
	for (int i = 0; i < prov->nb_capteurs; i++)
	{
		printf("** Capteur #%d: **\n", i);
		printf("Ville: %s\n", prov->capteurs[i]->ville);
		printf("  Mesures:\n");
		for (int j = 0; j < prov->capteurs[i]->nb_jours_mesures; j++)
		{
			for (int k = 0; k < NB_MAX_MESURES_PAR_JOUR; k++)
			{
				printf("  T: %.2lf, H: %.2lf, P: %.2lf\n",
					prov->capteurs[i]->mesures[j][k].temperature,
					prov->capteurs[i]->mesures[j][k].humidite,
					prov->capteurs[i]->mesures[j][k].pression);
			}
		}
	}
*/