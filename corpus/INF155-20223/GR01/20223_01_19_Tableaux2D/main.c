

#include <stdio.h>
#include <stdlib.h>
#include "mod_tab2d.h"



int main(void)
{
	int demo[NB_MAX_LIGNES][NB_MAX_COLONNES] = { {0} }; //Visual Studio accepte aussi {0}

	double temperatures[NB_MAX_LIGNES][NB_MAX_COLONNES] = {
		{25.5, 20.2, 23.5},
		{12.5, 13.3},
		{24.0, 20.4, 26.2}
	};

	/*for (int ligne = 0; ligne < 5; ligne++)
	{
		for (int colonne = 0; colonne < 4; colonne++)
		{
			printf("%.2lf\t", temperatures[ligne][colonne]);
		}
		printf("\n");
	}*/

	printf("Temperatures en Celcius: \n");
	afficher_tab2d(temperatures, 3, 3);

	convertir_fahreneith(temperatures, 3, 3);

	printf("Temperatures en Fahreneith: \n");
	afficher_tab2d(temperatures, 3, 3);


	/*int i;
	i = 0;
	for (int j = 0; j < 4; i++)
	{
		printf("%d ", temperatures[i][j]);
	}
	i = 1;
	for (int j = 0; j < 4; i++)
	{
		printf("%d ", temperatures[i][j]);
	}*/
	system("pause");
	return 0;
}

