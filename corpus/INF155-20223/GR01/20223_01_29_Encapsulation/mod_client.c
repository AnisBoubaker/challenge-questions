#include "mod_client.h"


t_client* client_init(void)
{
	t_client* nouv_client;

	nouv_client = (t_client*)malloc(sizeof(t_client));
	if (nouv_client == NULL)
	{
		printf("ERREUR: Plus de memoire!\n");
		exit(EXIT_FAILURE);
	}

	strcpy(nouv_client->num_ass_sociale, "");
	strcpy(nouv_client->nom, "");
	strcpy(nouv_client->prenom, "");	
	nouv_client->date_naiss.jour = 0;
	nouv_client->date_naiss.mois = 0;
	nouv_client->date_naiss.annee = 0;
	nouv_client->nb_comptes = 0;

	return nouv_client;
}



void client_afficher(const t_client* client)
{
	printf("FICHE DU CLIENT: \n ---------------------\n");
	printf("Num. Assurance sociale: %s\n", client->num_ass_sociale);
	//printf("Num. Assurance sociale: %s", (*client).num_ass_sociale);
	printf("Nom et prenom: %s, %s\n", client->nom, client->prenom);
	printf("Date de naissance: %d/%d/%d\n",
		client->date_naiss.jour,
		client->date_naiss.mois,
		client->date_naiss.annee);
	printf("LISTE DES COMPTES:\n");
	for (int i = 0; i < client->nb_comptes; i++)
	{
		printf("\tNum. Compte: %s\n", client->comptes[i].identifiant);
		printf("\tSolde: %.2lf\n", client->comptes[i].solde);
		printf("\tDecouvert autorise: %.2lf\n", client->comptes[i].limite_decouvert);
		printf("\tTaux d'interets: %.2lf\n", client->comptes[i].taux_interets);
		printf("\t--------------------------------\n");
	}
}