 


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

	 

	printf("Nombre de combinaisons : %d\n", combinaisons);

	 


	 

	system("pause");
	return EXIT_SUCCESS;
}