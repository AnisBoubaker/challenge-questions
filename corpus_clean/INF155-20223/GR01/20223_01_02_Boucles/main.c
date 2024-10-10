#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int compteur; 

	compteur = 0; 
	while (compteur < 20)
	{
		printf("Je suis fatigant!\n");
		compteur++;
	}

	system("pause");
	return EXIT_SUCCESS;
}