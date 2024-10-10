/*
Créer les structures de données suivantes à l'aide d'enregistrements (struct)
- Un compte bancaire est identifié par un numéro (alphanumérique). Il a un
  solde courant ainsi qu'une limite de découvert. De plus, chaque compte
  a un taux d'intérêts permettant le calcul des intérêts annuellement.
- Le client d'une banque est identifié par son numéro d'assurance sociale.
  Pour chaque client, nous devons connaitre son nom et prénom ainsi que sa
  date de naissance.
- Les clients ont également des comptes dans la banque. Chaque client peut
  détenir plusieurs comptes bancaires.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAILLE_MAX_ID 20
typedef struct compte
{
	char identifiant[TAILLE_MAX_ID];
	double solde; 
	double limite_decouvert; 
	double taux_interets; 
} t_compte;


typedef struct date
{
	int jour; 
	int mois;
	int annee;
} t_date;

#define TAILLE_MAX_ASS_SOCIALE 20
#define TAILLE_MAX_NOM 50
#define NB_MAX_COMPTES 50
typedef struct client
{
	char num_ass_sociale[TAILLE_MAX_ASS_SOCIALE];
	char nom[TAILLE_MAX_NOM];
	char prenom[TAILLE_MAX_NOM];
	//int date_naiss[3]; Prone a l'erreur
	/*int jour;  //Favorise la redondance de code
	int mois; 
	int annee; */
	t_date date_naiss; 
	t_compte comptes[NB_MAX_COMPTES];
	int nb_comptes;
} t_client;
/*
- Les clients ont également des comptes dans la banque. Chaque client peut
  détenir plusieurs comptes bancaires.
*/


void client_afficher(const t_client* client);


int main(void)
{
	t_client un_client; 

	strcpy(un_client.num_ass_sociale , "345 673 123");
	strcpy(un_client.nom, "Valjean");
	strcpy(un_client.prenom, "Jean");
	// 10/05/1562
	un_client.date_naiss.jour = 10;
	un_client.date_naiss.mois = 5; 
	un_client.date_naiss.annee = 1562;

	un_client.nb_comptes = 0;

	strcpy(un_client.comptes[0].identifiant,  "AB5676");
	un_client.comptes[0].solde = 2000;
	un_client.comptes[0].limite_decouvert = 1500;
	un_client.comptes[0].taux_interets = 1.5;

	un_client.nb_comptes++;

	strcpy(un_client.comptes[1].identifiant, "DF6789");
	un_client.comptes[1].solde = 150;
	un_client.comptes[1].limite_decouvert = 0;
	un_client.comptes[1].taux_interets = 0.4;

	un_client.nb_comptes++; 

	client_afficher(&un_client);

	system("pause");
	return EXIT_SUCCESS;
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