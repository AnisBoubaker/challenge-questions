#include <stdio.h>

double cube(double valeur)
{
    double resultat;

    resultat = valeur * valeur * valeur;

    return resultat;
}

// void: la fonction ne prend aucun paramètre
int saisir_entier_positif( void )
{
    int saisie;

    do
    {
        printf("Saisir un entier positif: ");
        scanf("%i", &saisie);
    } while (saisie <= 0 );

    return saisie;
}

void afficher_message_bienvenue(void)
{
    printf("********************************************\n");
    printf("Bienvenue dans SUPER PROGRAMME!\n");
    printf("Qui calcule le cube et le max de deux nombres\n");
    printf("********************************************\n");
}


int main(void) {
    double val;
    int val1, val2;
    int max;

    afficher_message_bienvenue();

    printf("Saisir la valeur pour le cube: ");
    scanf("%lf", &val);
    printf("Le cube de %lf est: %lf\n", val, cube(val) );

    val1 = saisir_entier_positif();
    val2 = saisir_entier_positif();

    max = val1;
    if(val2>max)
    {
        max = val2;
    }
    printf("Le maximum entre les deux valeurs saisies est: %i\n", max);

    return 0;
}
