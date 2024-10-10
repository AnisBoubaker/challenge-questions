#ifndef MOD_MESURE__H_
#define MOD_MESURE__H_


#include <stdlib.h>

typedef enum jour_semaine {
	DIMANCHE, LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI
} e_jour_semaine;

typedef struct mesure
{
	e_jour_semaine jour; //0: dimanche, ... 6: samedi
	double temperature; 
	double pression; 
	double humidite;
} t_mesure;


t_mesure* mesure_init(void);


void mesure_destroy(t_mesure* la_mesure);


#endif