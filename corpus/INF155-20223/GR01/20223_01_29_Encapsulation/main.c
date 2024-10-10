
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mod_client.h"


int main(void)
{
	t_client* un_client = NULL;

	un_client = client_init();



	strcpy(un_client->num_ass_sociale, "345 673 123");
	strcpy(un_client->nom, "Valjean");
	strcpy(un_client->prenom, "Jean");
	// 10/05/1562
	un_client->date_naiss.jour = 10;
	un_client->date_naiss.mois = 5;
	un_client->date_naiss.annee = 1562;

	un_client->nb_comptes = 0;

	strcpy(un_client->comptes[0].identifiant, "AB5676");
	un_client->comptes[0].solde = 2000;
	un_client->comptes[0].limite_decouvert = 1500;
	un_client->comptes[0].taux_interets = 1.5;

	un_client->nb_comptes++;

	strcpy(un_client->comptes[1].identifiant, "DF6789");
	un_client->comptes[1].solde = 150;
	un_client->comptes[1].limite_decouvert = 0;
	un_client->comptes[1].taux_interets = 0.4;

	un_client->nb_comptes++;

	client_afficher(un_client);

	free(un_client);


	t_client* client2; 

	client2 = client_init();

	client_afficher(client2);


	system("pause");
	return EXIT_SUCCESS;
}
