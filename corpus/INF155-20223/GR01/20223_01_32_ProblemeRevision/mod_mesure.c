#include "mod_mesure.h"


t_mesure* mesure_init(void)
{
	t_mesure* nouv_mesure; 

	nouv_mesure = (t_mesure*)malloc(sizeof(t_mesure));
	if (nouv_mesure == NULL)
	{
		printf("Plus de memoire!");
		exit(EXIT_FAILURE);
	}


	return nouv_mesure;
}

void mesure_destroy(t_mesure* la_mesure)
{
	free(la_mesure);
}