
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


 
void afficher_tab(const double tab[], int nb_elts)
{
	for (int i = 0; i < nb_elts; i++)
	{
		printf("Case %d: %lf\n", i, tab[i]);
	}
}


double moyenne_tab(const double tab[], int nb_elts)
{
	double moyenne = 0;
	for (int i = 0; i < nb_elts; i++)
	{
		moyenne += tab[i];
	}
	moyenne /= nb_elts;

	return moyenne;
}

 
 
 


void saisir_tab(double tab[], int nb_elts)
{
	for (int i = 0; i < nb_elts; i++)
	{
		printf("Prix du produit %d: ", i);
		scanf("%lf", &tab[i]);
	}
}

int main(void)
{
	 
	 
	double produits[1000];
	double moyenne; 

	int nb_produits=0;  

	printf("Combien de produits avez-vous? ");
	scanf("%d", &nb_produits);

	 
	saisir_tab(produits, nb_produits);

	 
	afficher_tab(produits, nb_produits);

	 

	 
	 
	moyenne = moyenne_tab(produits, nb_produits);

	printf("La moyenne des prix est: %lf\n", moyenne);


	 




	 

	system("pause");
	return 0;
}