#ifndef MOD_COMPTE__H_
#define MOD_COMPTE__H_

#define TAILLE_MAX_ID 20
typedef struct compte
{
	char identifiant[TAILLE_MAX_ID];
	double solde;
	double limite_decouvert;
	double taux_interets;
} t_compte;



#endif