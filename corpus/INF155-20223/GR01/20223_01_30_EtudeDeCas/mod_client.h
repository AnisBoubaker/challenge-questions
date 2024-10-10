#ifndef MOD_CLIENT__H_
#define MOD_CLIENT__H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mod_date.h"
#include "mod_compte.h"


#define TAILLE_MAX_ASS_SOCIALE 20
#define TAILLE_MAX_NOM 50
#define NB_MAX_COMPTES 50
typedef struct client
{
	char num_ass_sociale[TAILLE_MAX_ASS_SOCIALE];
	char* nom;
	char* prenom;
	t_date date_naiss;
	int nb_comptes;
	//t_compte* comptes[NB_MAX_COMPTES];
	t_compte** comptes; //Tableau dynamique 1D de t_compte*
} t_client;


void client_afficher(const t_client* client);

t_client* client_init(const char* num_ass_sociale,
	const char* nom, 
	const char* prenom);

/*
Fonction destructeur d'un client: 
libère l'intégralité de la mémoire occupée par un client donné. 
*/
void client_destroy(t_client* le_client);


/*
Crée et ajoute un nouveau compte bancaire à la liste de comptes 
du client
*/
void client_ajouter_compte(t_client* le_client);


/*
Supprime le compte ayant pour indice indice_compte dans le tableau
de comptes du client le_client.
*/
void client_supprimer_compte(t_client* le_client, int indice_compte);


#endif