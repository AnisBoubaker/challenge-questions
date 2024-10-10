#include "mod_compte.h"

t_compte* compte_init(void)
{
	t_compte* nouv_compte;

	nouv_compte = (t_compte*)malloc(sizeof(t_compte));
	if (nouv_compte == NULL)
	{
		printf("ERREUR: Plus de mémoire\n");
		exit(EXIT_FAILURE);
	}


	nouv_compte->solde = 0; 
	nouv_compte->taux_interets = 0;
	nouv_compte->limite_decouvert = 0;
	//strcpy(nouv_compte->identifiant ,  "");
	//OU plus simplement: 
	nouv_compte->identifiant[0] = '\0';

	return nouv_compte;
}

void compte_destroy(t_compte* le_compte)
{
	free(le_compte);
}