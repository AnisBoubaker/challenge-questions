

#include <stdio.h>
#include <stdlib.h>
#include "mod_tab2d.h"



int main(void)
{
	int demo[NB_MAX_LIGNES][NB_MAX_COLONNES] = { {0} };  

	double temperatures[NB_MAX_LIGNES][NB_MAX_COLONNES] = {
		{25.5, 20.2, 23.5},
		{12.5, 13.3},
		{24.0, 20.4, 26.2}
	};

	 

	printf("Temperatures en Celcius: \n");
	afficher_tab2d(temperatures, 3, 3);

	convertir_fahreneith(temperatures, 3, 3);

	printf("Temperatures en Fahreneith: \n");
	afficher_tab2d(temperatures, 3, 3);


	 
	system("pause");
	return 0;
}

