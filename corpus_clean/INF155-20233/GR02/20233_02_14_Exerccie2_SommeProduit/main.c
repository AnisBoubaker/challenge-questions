 

#include <stdio.h>
#include <stdlib.h>

 
void somme_produit(int n, int* adr_somme, double* adr_produit) ;

int main(void) {

    int somme;
    double produit;

    somme_produit(50, &somme, &produit);

    printf("La somme = %i, Le produit = %.0lf\n", somme, produit);

    return 0;
}


 

void somme_produit(int n, int* adr_somme, double* adr_produit)
{
    *adr_somme = 0;
    *adr_produit = 1;
    for(int i = 1; i<= n; i++)
    {
        *adr_somme += i;
        *adr_produit *= i;
    }
}