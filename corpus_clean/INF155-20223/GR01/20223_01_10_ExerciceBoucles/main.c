 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int debut; 
	int fin; 
	int k; 
	int compteur; 

	printf("Valeur de debut: ");
	scanf("%d", &debut);

	printf("Valeur de fin: ");
	scanf("%d", &fin);

	printf("Valeur de k: ");
	scanf("%d", &k);

	printf("Tous les multiples de %d entre %d et %d sont:\n", k, debut, fin);
	for (compteur = debut; compteur <= fin; compteur++)
	{
		if (compteur % k == 0)
		{
			printf("%d\n", compteur);
		}
	}
	
	
	 
	 
	 
	 
	 
	 
	 
	 
	 



	system("pause");
	return EXIT_SUCCESS;
}