 

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
