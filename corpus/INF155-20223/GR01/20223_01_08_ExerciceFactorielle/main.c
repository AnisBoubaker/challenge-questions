/*
Écrire un programme qui calcule la factorielle d'un nombre n saisi par 
l'usager.
factorielle de n: 1 * 2 * 3 * 4 * 5 * ... * n
factorielle de 5: 1 * 2  * 3 * 4 * 5 = 120
Vous devez utiliser la boucle la plus adaptée.
Exemple:
--------
Saisir la valeur de n: 5
La factorielle de 5 est: 120
*/

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