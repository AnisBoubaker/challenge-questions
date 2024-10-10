/*
Programme qui demande à l'usager une valeur positive. 
Si la valeur saisie n'est pas positive, on lui redemande
jusqu'à obtention d'une valeur positive.

Exemple d'exécution: 

Veuillez saisir un nombre positif: -40
Veuillez saisir un nombre positif: -10
Veuillez saisir un nombre positif: 5
Merci!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int saisie; 

	printf("Saisir une valeur positive: ");
	scanf("%d", &saisie);

	while (saisie < 0)
	{
		printf("Saisir une valeur positive: ");
		scanf("%d", &saisie);
	}
	printf("Merci!\n");

	system("pause");
	return EXIT_SUCCESS;
}
