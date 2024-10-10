
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

int main(void)
{
	char prenom[TAILLE_MAX] = "Marie"; 
	int age = 10;
	char message[TAILLE_MAX]; 

	printf("%s a %d ans.\n", prenom, age);

	sprintf(message, "%s a %d ans.\n", prenom, age);

	printf("%s", message);

	system("pause");
	return 0;
}
