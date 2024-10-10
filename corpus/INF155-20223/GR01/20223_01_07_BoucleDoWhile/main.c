/*
Écrire un programme qui saisit une valeur. Si la valeur saisie n'est pas
positive, redemander à l'usager jusqu'à obtention d'une valeur adéquate.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int saisie; //Valeur saisie par l'usager

	////On saisit une première fois.
	//printf("Veuillez saisir un nombre positif: ");
	//scanf("%d", &saisie);

	do
	{
		printf("Veuillez saisir un nombre positif: ");
		scanf("%d", &saisie);
	} while (saisie < 0);

	//saisie = -1; 

	////On répète tant que la valeur saisie n'est pas bonne
	//while (saisie < 0)
	//{
	//	printf("Veuillez saisir un nombre positif: ");
	//	scanf("%d", &saisie);
	//}

	//Si on sort de la boucle, c'est que la valeur saisie est bonne, on dit merci.
	printf("Merci!\n");

	system("pause");
	return EXIT_SUCCESS;
}