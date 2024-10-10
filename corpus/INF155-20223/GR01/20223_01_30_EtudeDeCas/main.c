
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mod_client.h"


int main(void)
{

	t_client* liste_clients[1000];

	liste_clients[0] = client_init("345 673 123", "Laporte", "Jean");
	// 10/05/1998
	
	// 10/05/1562
	liste_clients[0]->date_naiss.jour = 10;
	liste_clients[0]->date_naiss.mois = 5;
	liste_clients[0]->date_naiss.annee = 1562;

	liste_clients[0]->nb_comptes = 0;

	client_ajouter_compte(liste_clients[0]);
	strcpy(liste_clients[0]->comptes[0]->identifiant, "AB5676");
	liste_clients[0]->comptes[0]->solde = 2000;
	liste_clients[0]->comptes[0]->limite_decouvert = 1500;
	liste_clients[0]->comptes[0]->taux_interets = 1.5;

	client_ajouter_compte(liste_clients[0]);
	liste_clients[0]->comptes[1] = compte_init();
	strcpy(liste_clients[0]->comptes[1]->identifiant, "DF6789");
	liste_clients[0]->comptes[1]->solde = 150;
	liste_clients[0]->comptes[1]->limite_decouvert = 0;
	liste_clients[0]->comptes[1]->taux_interets = 0.4;

	client_afficher(liste_clients[0]);

	client_supprimer_compte(liste_clients[0], 0);

	client_afficher(liste_clients[0]);

	client_destroy(liste_clients[0]);
	liste_clients[0] = NULL;



	/*t_client* client2; 

	client2 = client_init();

	client_afficher(client2);*/


	system("pause");
	return EXIT_SUCCESS;
}
