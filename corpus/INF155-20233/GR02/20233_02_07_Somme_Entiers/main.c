#include <stdio.h>

int main() {
   int n; //Entier maximal pour la somme
   int somme = 0;
   int compteur = 1;

   printf("Saisir le maximum de la somme: ");
   scanf("%i", &n);

   while( compteur <= n )
   {
       somme = somme + compteur;
       compteur++;
   }

   printf("La somme des entiers entre 1 et %i est: %i", n, somme);
    return 0;
}
