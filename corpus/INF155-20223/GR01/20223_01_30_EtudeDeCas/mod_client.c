#include "mod_client.h"


t_client* client_init(const char* num_ass_sociale, 
	const char* nom, 
	const char* prenom)
{
	t_client* nouv_client;

	nouv_client = (t_client*)malloc(sizeof(t_client));
	if (nouv_client == NULL)
	{
		printf("ERREUR: Plus de memoire!\n");
		exit(EXIT_FAILURE);
	}

	nouv_client->nom = (char*)malloc(sizeof(char) * (strlen(nom) + 1));
	if (nouv_client->nom == NULL)
	{
		free(nouv_client);
		printf("ERREUR: Plus de memoire!\n");
		exit(EXIT_FAILURE);
	}
	strcpy(nouv_client->nom, nom);

	nouv_client->prenom = (char*)malloc(sizeof(char) * (strlen(prenom) + 1));
	if (nouv_client->prenom == NULL)
	{
		free(nouv_client->nom);
		free(nouv_client);
		printf("ERREUR: Plus de memoire!\n");
		exit(EXIT_FAILURE);
	}
	strcpy(nouv_client->prenom, prenom);

	/*nouv_client->comptes = (t_compte**)malloc(50 * sizeof(t_compte*));
	if (nouv_client->comptes == NULL)
	{
		free(nouv_client->prenom);
		free(nouv_client->nom);
		free(nouv_client);
		printf("Erreur: Plus de mémoire!\n");
		exit(EXIT_FAILURE);
	}*/
	nouv_client->comptes = NULL;



	//NOTE: Le numero d'assurance sociale est défini
	//comme un tableau statique dans la structure t_client.
	//Il ne faut donc pas l'allouer avec un malloc!

	strcpy(nouv_client->num_ass_sociale, num_ass_sociale);
	nouv_client->date_naiss.jour = 0;
	nouv_client->date_naiss.mois = 0;
	nouv_client->date_naiss.annee = 0;
	nouv_client->nb_comptes = 0;

	return nouv_client;
}


void client_destroy(t_client* le_client)
{
	//Modifier cette fonction pour tenir compte des changements
	//au champs "comptes" d'un client.
	free(le_client->nom);
	free(le_client->prenom);
	free(le_client);
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
		printf("\tNum. Compte: %s\n", client->comptes[i]->identifiant);
		printf("\tSolde: %.2lf\n", client->comptes[i]->solde);
		printf("\tDecouvert autorise: %.2lf\n", client->comptes[i]->limite_decouvert);
		printf("\tTaux d'interets: %.2lf\n", client->comptes[i]->taux_interets);
		printf("\t--------------------------------\n");
	}
}


void client_ajouter_compte(t_client* le_client)
{
	t_compte** nouv_adresse; 

	le_client->nb_comptes++;

	if (le_client->comptes != NULL)
	{
		nouv_adresse = (t_compte**)realloc(le_client->comptes,
			le_client->nb_comptes * sizeof(t_compte*));
		if (nouv_adresse == NULL)
		{
			printf("Impossible d'ajouter un compte. Plus de memoire.\n");
			return;
		}
		le_client->comptes = nouv_adresse;
	}
	else
	{
		le_client->comptes = (t_compte**)malloc(
			le_client->nb_comptes * sizeof(t_compte*));
		if (le_client->comptes == NULL)
		{
			printf("Impossible d'ajouter un compte. Plus de memoire.\n");
			return;
		}
	}

	le_client->comptes[le_client->nb_comptes - 1] = compte_init();

}

void client_supprimer_compte(t_client* le_client, int indice_compte)
{
	t_compte** nouv_adresse; 

	compte_destroy(le_client->comptes[indice_compte]);

	for (int i = indice_compte+1; i < le_client->nb_comptes; i++)
	{
		le_client->comptes[i - 1] = le_client->comptes[i];
	}

	le_client->nb_comptes--;

	nouv_adresse = (t_compte**)realloc(le_client->comptes,
		le_client->nb_comptes * sizeof(t_compte*));
	if (nouv_adresse == NULL)
	{
		printf("Impossible de supprimer un compte. \n");
		return;
	}
	le_client->comptes = nouv_adresse;
}