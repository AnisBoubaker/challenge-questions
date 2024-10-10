#ifndef MOD_PROVINCE__H_
#define MOD_PROVINCE__H_

#include "mod_capteur.h"

typedef struct province
{
	char* nom;
	t_capteur** capteurs; //Tab 1D de t_capteur*
	int nb_capteurs; //Taille effective du tableau de capteurs "capteurs".
	int nb_max_capteurs; //Taille maximale du tableau de capteurs. 
} t_province;

t_province* province_init(const char* nom, int max_capteurs);

void province_destroy(t_province* la_province);

void afficher_province(const t_province* prov);

#endif