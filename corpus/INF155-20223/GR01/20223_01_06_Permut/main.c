/*
Programme qui saisit deux valeurs et qui les affiche. 
Auteur: 
Date: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int val_a; //Premiere valeur saisie
	int val_b; //Seconde valeur saisie
	int val_copie; 

	//Saisie de val_a et val_b
	printf("Veuillez saisir la valeur de val_a: ");
	scanf("%d", &val_a);

	printf("Veuillez saisir la valeur de val_b: ");
	scanf("%d", &val_b);

	/*DEBUT*/
	val_copie = val_a; 
	val_a = val_b; 
	val_b = val_copie; 
	/*FIN*/

	//Affichage 
	printf("Vous avez saisi %d pour val_a et %d pour val_b.\n", val_a, val_b);

	system("pause");
	return EXIT_SUCCESS;
}