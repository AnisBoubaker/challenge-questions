#ifndef MOD_PROVINCE__H_
#define MOD_PROVINCE__H_

#include "mod_capteur.h"

typedef struct province
{
	char* nom;
	t_capteur** capteurs;  
	int nb_capteurs;  
	int nb_max_capteurs;  
} t_province;

t_province* province_init(const char* nom, int max_capteurs);

void province_destroy(t_province* la_province);

void afficher_province(const t_province* prov);

#endif