#include <stdio.h>

#define TAILLE_MAX 100
#define VAL1 10

int main() {

    //Initialise les 5 premières cases aux valeurs spécifiées,
    //Le reste des 100 cases du tableau est mis à 0.
    int mon_tab[TAILLE_MAX] = { 10, 20 , 30 , 40 , 50};

    //Ce tableau aura une taille maximale de 5.
    int tab2[] = {1, 2, 3, 4, 5};

    for(int i=0; i< TAILLE_MAX; i++)
    {
        printf("%i\n", mon_tab[i]);
    }

    //INTERDIT: On ne peut faire ça que lors de la déclaration d'un
    //tableau
    //mon_tab = {34, 56, 78};

    /*
     * Pour initialiser un tableau à une valeur autre que 0,
     * on n'a pas le choix que de faire une boucle.
     */
    for(int i=0; i<TAILLE_MAX ; i++)
    {
        mon_tab[i] = 10;
    }

    return 0;
}
