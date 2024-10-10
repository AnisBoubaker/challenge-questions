

#include <stdio.h>
#include <stdlib.h>
#include "mod_mesure.h"


int main(void)
{

	t_mesure ma_mesure; 

	ma_mesure.jour = VENDREDI;

	printf("La valeur numerique du jour est: %d\n", ma_mesure.jour);



	system("pause");
	return EXIT_SUCCESS;
}