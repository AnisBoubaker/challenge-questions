#include <stdio.h>

int main() {
    int val;
    int resultat;

    val = 10;
    resultat = (val > 0) + val /2;

    printf("Resultat = %i\n", resultat);

    if( val == 10)
    {
        printf("Val vaut bien 10!\n");
    }

    return 0;
}
