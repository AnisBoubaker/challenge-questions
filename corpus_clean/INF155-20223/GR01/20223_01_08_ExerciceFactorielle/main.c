 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int saisie; 
	int resultat = 1 ; 
	int compteur;

	printf("Saisir la valeur pour le calcul de la factorielle: ");
	scanf("%d", &saisie);

	for (compteur = 1; compteur <= saisie; compteur++)
	{
		resultat = resultat * compteur; 
	}

	printf("La factorielle de %d est: %d\n", saisie, resultat);

	system("pause");
	return EXIT_SUCCESS;
}