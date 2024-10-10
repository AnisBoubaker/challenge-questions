/*
 * Écrire une fonction **somme_produit** qui calcule la somme et
 * le produit des entiers entre 1 et n (la valeur de *n* est reçue en paramètre).
 *
 * La fonction fournit à l'appelant le résultat de la somme ET du produit.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Fonction qui calcule la somme et le produit des entiers entre 1 et n.
 * Parametres:
 *  n (entier): Le maximum pour le calcul de la somme et le produit
 *  adr_somme (adresse): Adresse où stocker la somme
 *  adr_produit (adresse): Adresse où stocker le produit calculé.
 * RETOUR: Rien.
 */
void somme_produit(int n, int* adr_somme, double* adr_produit) ;

int main(void) {

    int somme;
    double produit;

    somme_produit(50, &somme, &produit);

    printf("La somme = %i, Le produit = %.0lf\n", somme, produit);

    return 0;
}


/*void somme_produit(int n, int* adr_somme, double* adr_produit)
{
    int somme;
    double produit;

    somme = 0;
    produit = 1;
    for(int i = 1; i<= n; i++)
    {
        somme += i;
        produit *= i;
    }

    *adr_somme = somme;
    *adr_produit = produit;
}*/

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