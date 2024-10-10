 


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int saisie;  

	 
	 
	 

	do
	{
		printf("Veuillez saisir un nombre positif: ");
		scanf("%d", &saisie);
	} while (saisie < 0);

	 

	 
	 
	 
	 
	 
	 

	 
	printf("Merci!\n");

	system("pause");
	return EXIT_SUCCESS;
}