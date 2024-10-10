#include <stdio.h>

int main(void) {

    int val1;
    char val2 = 'A';
    int val3;
    int* adresse_val1 = &val1;
    char* adresse_val2 = &val2;

    int** ptr;

    ptr = &adresse_val1;

    val1 = 10;

    printf("Valeur bizarre: %p\n", &val1);
    printf("Contenu de adresse_val1: %p \n", adresse_val1);

    *adresse_val1 = 50;

    printf("La valeur de val1: %i\n", val1);

    **ptr = 100;

    printf("La valeur de val1: %i\n", val1);

    *ptr = &val3;

    *adresse_val1 = 25;
    //OU:  **ptr = 25;
    printf("La valeur de val3: %d\n", val3);

    printf("L'adresse de val1: %p\n", &val1);

    return 0;
}
