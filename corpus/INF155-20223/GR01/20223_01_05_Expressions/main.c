


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int saisie; 

	printf("Saisir une valeur: ");
	scanf("%d", &saisie);

	if (saisie == 0)
	{
		printf("Vous avaez saisi une valeur nulle!\n");
	}
	else
	{
		printf("Vous avez saisi une valeur non-nulle!\n");
	}



	/*
	printf("Saisir une valeur: ");
	scanf("%d", &saisie);

	//Vérifier si la valeur est dans l'intervalle ]-30..-10[
	if (-30 < saisie && saisie < -10)
	{
		printf("La valeur est dans l'intervalle.\n");
	}
	else
	{
		printf("La valeur n'est pas dans l'intervalle.\n");
	}
	*/

	/*int resultat;

	resultat = (10 < 5) + 2;

	printf("Resultat : %d\n", resultat);*/


	/*int x, y, z; 

	x = 11; 
	y = 3; 

	z = x / y; 
	

	printf("z contient: %d\n", z);
	printf("x contient: %d\n", x);*/


	/*int val_a; 
	int val_b; 
	double resultat; 
	int le_modulo; 

	val_a = 10; 
	val_b = 3; 

	
	resultat = val_a*1.0 / val_b;
	le_modulo = val_a % val_b;

	printf("Le resultat est: %lf\n", resultat);
	printf("Le module est: %d\n", le_modulo);
	*/

	system("pause");
	return EXIT_SUCCESS;
}