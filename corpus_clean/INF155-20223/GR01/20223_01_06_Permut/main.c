 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int val_a;  
	int val_b;  
	int val_copie; 

	 
	printf("Veuillez saisir la valeur de val_a: ");
	scanf("%d", &val_a);

	printf("Veuillez saisir la valeur de val_b: ");
	scanf("%d", &val_b);

	 
	val_copie = val_a; 
	val_a = val_b; 
	val_b = val_copie; 
	 

	 
	printf("Vous avez saisi %d pour val_a et %d pour val_b.\n", val_a, val_b);

	system("pause");
	return EXIT_SUCCESS;
}