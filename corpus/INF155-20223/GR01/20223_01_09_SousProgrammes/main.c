/*
Écrire un programme qui calcule le nombre de combinaisons possibles
en tirant k boules à partir d'une urne contenant n boules.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorielle(int n)
{
	int resultat = 1;

	for (int compteur = 1; compteur <= n; compteur++)
	{
		resultat *= compteur;
	}

	return resultat;
}

int saisir_entier_positif(void)
{
	int saisie; 

	do
	{
		printf("Saisir une valeur positive: ");
		scanf("%d", &saisie);
	} while (saisie < 0);

	return saisie; 
}

int nb_combinaisons(int n, int k)
{
	int resultat; 

	resultat = factorielle(n) / (factorielle(k) * factorielle(n - k));

	return resultat;
}

void bienvenue(void)
{
	printf("***************************************\n");
	printf("*  SUPER CALCULATEUR DE COMBINAISONS  *\n");
	printf("***************************************\n");
	
}


int main(void)
{
	int nb_tirees; 
	int nb_total; 
	int combinaisons; 

	bienvenue();

	printf("Combien de boules tirees: ");
	scanf("%d", &nb_tirees);

	printf("Combien de boules au total: ");
	scanf("%d", &nb_total);

	combinaisons = nb_combinaisons(nb_total, nb_tirees);

	/*combinaisons = factorielle(nb_total) /
		(factorielle(nb_tirees) * factorielle(nb_total-nb_tirees));*/

	printf("Nombre de combinaisons : %d\n", combinaisons);

	/*int valeur;
	int resultat; 

	printf("Saisir la valeur pour le calcul de la factorielle: '\n");
	valeur = saisir_entier_positif();

	resultat = factorielle(valeur);

	printf("Factorielle de %d: %d\n", valeur, resultat);*/


	/*int nb_tirees; 
	int nb_total;
	int fact_nb_total;
	int fact_nb_tirees;
	int fact_n_k;
	int resultat; 

	printf("Combien de boules tirees: ");
	scanf("%d", &nb_tirees);

	printf("Combien de boules au total: ");
	scanf("%d", &nb_total);

	fact_nb_total = 1;
	for (int compteur = 1; compteur <= nb_total; compteur++)
	{
		fact_nb_total = fact_nb_total * compteur;
	}

	fact_nb_tirees = 1;
	for (int compteur = 1; compteur <= nb_tirees; compteur++)
	{
		fact_nb_tirees = fact_nb_tirees * compteur;
	}

	fact_n_k = 1;
	for (int compteur = 1; compteur <= nb_total - nb_tirees; compteur++)
	{
		fact_n_k = fact_n_k * compteur;
	}


	resultat = fact_nb_total / (fact_nb_tirees * fact_n_k);

	printf("Nombre de combinaisons possibles: %d\n", resultat);*/

	system("pause");
	return EXIT_SUCCESS;
}