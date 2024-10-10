/*
Écrire la fonction "fibo" permettant de calculer le nième terme de
la suite de Fibonacci ainsi que le nombre d'or.
La suite de Fibonacci est définie comme suit:
Fibo(0) = 0
Fibo(1) = 1
Fibo(n) = Fibo(n-2)+Fibo(n-1)

Le nombre d'or se calcule en faisant le rapport entre deux termes
consécutifs de la suite.
Par exemple, le terme 6 de la suite de Fibonacci (Fibo(6)) est: 8. 
En effet:
Fibo(0) = 0
Fibo(1) = 1
Fibo(2) = 1
Fibo(3) = 2
Fibo(4) = 3
Fibo(5) = 5
Fibo(6) = 8
*/

#include <stdio.h>
#include <stdlib.h>

int fibo(int n, double* adr_nombre_or)
{
	int fibo_i_1; //Stocke le dernier terme calculé 
	int fibo_i_2; //L'avant dernier terme calculé
	int fibo_i;
	double nb_or; 

	if (n == 0 || n == 1)
	{
		*adr_nombre_or = 0;
		return n == 0 ? 0 : 1;
	}

	//Initialisation pour la premiere itération
	fibo_i_2 = 0;
	fibo_i_1 = 1;
	for (int i = 2; i <= n; i++)
	{
		fibo_i = fibo_i_1 + fibo_i_2;
		fibo_i_2 = fibo_i_1;
		fibo_i_1 = fibo_i;
	}

	//nb_or = (double)fibo_i / fibo_i_2;
	*adr_nombre_or = (double)fibo_i / fibo_i_2;
	return fibo_i;
}

//Version reccursive - Pour information seulement.
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