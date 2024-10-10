 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;  
	int compteur; 
	int resultat = 0; 

	printf("Saisir la valeur de n: ");
	scanf("%d", &n);

	compteur = 1; 
	resultat = 0;
	while (compteur <= n)
	{
		resultat = resultat + compteur; 
		compteur++;
	}

	printf("La somme des valeurs entre 1 et %d est: %d\n", n, resultat);

	system("pause");
	return EXIT_SUCCESS;
}