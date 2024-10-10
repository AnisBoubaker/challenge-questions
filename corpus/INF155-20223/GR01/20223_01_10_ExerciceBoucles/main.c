/*
Écrire un programme qui affiche tous les multiples d'une valeur k, pour les
entiers entre une valeur debut et fin
Exemples:
Valeur de début: 4
Valeur de fin: 120
Valeur de k: 27
Tous les multiples de 27 entre 4 et 120 sont:
27
54
81
108
*/
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
	
	
	//compteur = debut;  //Instruction initialisation
	//while (compteur <= fin) //Condition
	//{
	//	if (compteur % k == 0)
	//	{
	//		printf("%d\n", compteur);
	//	}
	//	compteur++; //Instruction d'incrément
	//}



	system("pause");
	return EXIT_SUCCESS;
}