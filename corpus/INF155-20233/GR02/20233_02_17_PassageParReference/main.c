#include <stdio.h>
#include <stdlib.h>


void min_max_de_3(int val1, int val2, int val3, int* adr_pour_min, int* adr_pour_max)
{
    int min = val1;
    int max = val1;

    if(val2 < min){
        min = val2;
    }
    if(val2 > max){
        max = val2;
    }

    if(val3 < min){
        min = val3;
    }
    if(val3 > max){
        max = val3;
    }

    *adr_pour_min = min;
    *adr_pour_max = max;

}

int main(void) {
    int plus_petit, plus_grand;

    min_max_de_3(10, 34, 12, &plus_petit, &plus_grand);

    printf("Le minimum: %i\n", plus_petit);
    printf("Le maximum: %i\n", plus_grand);

    return 0;
}
