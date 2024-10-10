
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ma_variable = 10;
	int* adr; 
	int** adr_adr;

	adr = &ma_variable;

	printf("Ma variable se trouve a : %p\n", &ma_variable);

	printf("Le pointeur adr contient: %p\n", adr);

	printf("ma_variable contient (avant dereferencement): %d\n", ma_variable);

	*adr = 55;

	printf("ma_variable contient (apres dereferencement): %d\n", ma_variable);

	printf("La valeur se trouvant à l'adresse adr: %d\n", *adr);


	adr_adr = &adr;

	**adr_adr = 100;

	printf("ma_variable contient (apres le double dereferencement): %d\n", ma_variable);



	system("pause");
	return EXIT_SUCCESS;

}

