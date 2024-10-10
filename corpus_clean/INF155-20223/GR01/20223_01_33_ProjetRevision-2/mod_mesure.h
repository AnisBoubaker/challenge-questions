#ifndef MOD_MESURE__H_
#define MOD_MESURE__H_

#include <stdlib.h>
#include <stdio.h>

typedef enum jour_semaine {
	DIMANCHE, LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI
} e_jour_semaine;

typedef struct mesure
{
	e_jour_semaine jour;
	double temperature;
	double humidite;
	double pression;
} t_mesure;


t_mesure* mesure_init(void);

void mesure_destroy(t_mesure* la_mesure);

void mesure_afficher(const t_mesure* mesure);

#endif