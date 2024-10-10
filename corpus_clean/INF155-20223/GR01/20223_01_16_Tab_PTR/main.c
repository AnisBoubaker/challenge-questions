

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int mon_tableau[100];

	mon_tableau[0] = 10; 
	mon_tableau[1] = 20;
	mon_tableau[2] = 30;
	mon_tableau[3] = 40;

	printf("%d\n", *mon_tableau);

	printf("%d\n", *(mon_tableau+1));

	system("pause");
	return EXIT_SUCCESS;
}