#ifndef MOD_PROVINCE__H_
#define MOD_PROVINCE__H_

#include "mod_capteur.h"

typedef struct province
{
	char* nom;
	t_capteur** capteurs; //Tableau 1D, chaque case contient un t_capteur*
	int nb_capteurs; //Taille effective du tableau capteurs
	int nb_max_capteurs; //Taille maximale du tableau capteurs
}t_province;

t_province* province_init(const char* nom, int max_capteurs);

#endif