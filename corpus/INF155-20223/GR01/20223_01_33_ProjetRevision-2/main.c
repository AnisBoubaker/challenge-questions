#include <stdio.h>
#include <stdlib.h>

#include "mod_mesure.h"
#include "mod_province.h"

int main(void)
{
	t_province* province;
	t_province* ontario;
	t_capteur* capteur_mtl;
	t_capteur* capteur_quebec;
	t_capteur* capteur_wagadougou;
	t_capteur* capteur_trois_rivieres;
	t_capteur* capteur_sherbrooke;

	FILE* mon_fichier;


	province = province_init("Quebec", 10);

	ontario = province_init("Ontario", 25);

	capteur_wagadougou = capteur_init("Wagadougou", 10, 20, 50);

	capteur_trois_rivieres = capteur_init("Trois Rivieres", 13, 45, 40);

	capteur_sherbrooke = capteur_init("Sherbrooke", 13, 47, 25);


	capteur_mtl = capteur_init("Montreal", 45.51, 73.55, 50);


	capteur_quebec = capteur_init("Ville de Quebec", 46, 75, 50);

	province->capteurs[province->nb_capteurs] = capteur_wagadougou;
	province->nb_capteurs++;
	province->capteurs[province->nb_capteurs] = capteur_trois_rivieres;
	province->nb_capteurs++;
	province->capteurs[province->nb_capteurs] = capteur_sherbrooke;
	province->nb_capteurs++;
	province->capteurs[province->nb_capteurs] = capteur_mtl;
	province->nb_capteurs++;
	province->capteurs[province->nb_capteurs] = capteur_quebec;
	province->nb_capteurs++;

	capteur_mtl->mesures[0][0].jour = DIMANCHE;
	capteur_mtl->mesures[0][0].temperature = 25.5;
	capteur_mtl->mesures[0][0].humidite = 45;
	capteur_mtl->mesures[0][0].pression = 101.5;

	capteur_mtl->mesures[0][1].jour = DIMANCHE;
	capteur_mtl->mesures[0][1].temperature = 28.5;
	capteur_mtl->mesures[0][1].humidite = 50;
	capteur_mtl->mesures[0][1].pression = 100;

	capteur_mtl->mesures[1][0].jour = LUNDI;
	capteur_mtl->mesures[1][0].temperature = 28;
	capteur_mtl->mesures[1][0].humidite = 50;
	capteur_mtl->mesures[1][0].pression = 102;

	capteur_mtl->mesures[1][1].jour = LUNDI;
	capteur_mtl->mesures[1][1].temperature = 30;
	capteur_mtl->mesures[1][1].humidite = 49;
	capteur_mtl->mesures[1][1].pression = 100;

	capteur_mtl->nb_jours_mesures = 2;


	capteur_quebec->mesures[0][0].jour = DIMANCHE;
	capteur_quebec->mesures[0][0].temperature = 25.5;
	capteur_quebec->mesures[0][0].humidite = 45;
	capteur_quebec->mesures[0][0].pression = 101.5;

	capteur_quebec->mesures[0][1].jour = DIMANCHE;
	capteur_quebec->mesures[0][1].temperature = 28.5;
	capteur_quebec->mesures[0][1].humidite = 50;
	capteur_quebec->mesures[0][1].pression = 100;

	capteur_quebec->mesures[1][0].jour = LUNDI;
	capteur_quebec->mesures[1][0].temperature = 28;
	capteur_quebec->mesures[1][0].humidite = 50;
	capteur_quebec->mesures[1][0].pression = 102;

	capteur_quebec->mesures[1][1].jour = LUNDI;
	capteur_quebec->mesures[1][1].temperature = 30;
	capteur_quebec->mesures[1][1].humidite = 51;
	capteur_quebec->mesures[1][1].pression = 102;

	capteur_quebec->nb_jours_mesures = 2;

	afficher_province(province);

	/*t_mesure* ma_mesure = mesure_init();

	ma_mesure->humidite = 40.5;
	ma_mesure->temperature = 25;
	ma_mesure->pression = 10.2;
	ma_mesure->jour = 10;

	mesure_afficher(ma_mesure);*/



	system("pause");
	return EXIT_SUCCESS;
}