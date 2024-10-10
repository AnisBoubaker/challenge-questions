 

#include <stdio.h>
#include <stdlib.h>

int fibo(int n, double* adr_nombre_or)
{
	int fibo_i_1;  
	int fibo_i_2;  
	int fibo_i;
	double nb_or; 

	if (n == 0 || n == 1)
	{
		*adr_nombre_or = 0;
		return n == 0 ? 0 : 1;
	}

	 
	fibo_i_2 = 0;
	fibo_i_1 = 1;
	for (int i = 2; i <= n; i++)
	{
		fibo_i = fibo_i_1 + fibo_i_2;
		fibo_i_2 = fibo_i_1;
		fibo_i_1 = fibo_i;
	}

	 
	*adr_nombre_or = (double)fibo_i / fibo_i_2;
	return fibo_i;
}

 
int fibo_recc(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibo_recc(n - 2) + fibo_recc(n - 1);
}

int main(void)
{
	int val_fibo;
	double nb_or;

	for (int i = 0; i < 30; i++)
	{
		val_fibo = fibo(i, &nb_or);

		printf("Fibo(%d) = %d - Nb d'or: %.30lf\n", i,  val_fibo, nb_or);
	}
	
	system("pause");
	return EXIT_SUCCESS;
}