#ifndef MOD_COMPTE__H_
#define MOD_COMPTE__H_

#include <stdlib.h>

#define TAILLE_MAX_ID 20
typedef struct compte
{
	char identifiant[TAILLE_MAX_ID];
	double solde;
	double limite_decouvert;
	double taux_interets;
} t_compte;


t_compte* compte_init(void);

void compte_destroy(t_compte* le_compte);

#endif