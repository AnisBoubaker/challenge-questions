#include <stdio.h>

#define TAILLE_MAX 100
#define VAL1 10

int main() {

     
     
    int mon_tab[TAILLE_MAX] = { 10, 20 , 30 , 40 , 50};

     
    int tab2[] = {1, 2, 3, 4, 5};

    for(int i=0; i< TAILLE_MAX; i++)
    {
        printf("%i\n", mon_tab[i]);
    }

     
     
     

     
    for(int i=0; i<TAILLE_MAX ; i++)
    {
        mon_tab[i] = 10;
    }

    return 0;
}
