
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min_max_de_3(int val1, int val2, int val3, int* adr_max)
{
	int min = val1;
	int max = val1;

	min = val2 < min ? val2 : min;
	min = val3 < min ? val3 : min;

	max = val2 > max ? val2 : max;
	max = val3 > max ? val3 : max;

	*adr_max = max;

	return min; 
}



int main(void)
{
	int le_min, le_max; 

	le_min = min_max_de_3(10, 28, 3, &le_max);

	printf("Le minimum: %d, Le maximum: %d\n", le_min, le_max);

	system("pause");
	return EXIT_SUCCESS;

}

