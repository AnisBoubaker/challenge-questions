#include <stdio.h>

typedef enum niveau_huile{
    TRES_BAS=10,
    BAS,
    MOYEN = 20,
    ELEVE,
    TRES_ELEVE
} e_niveau_huile;



int main() {

    e_niveau_huile le_niveau;

    le_niveau = TRES_ELEVE;

    printf("Le contenu: %i\n", le_niveau);

    if(le_niveau == MOYEN)
    {

    }


    return 0;
}
