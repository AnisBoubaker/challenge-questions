#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t_etudiant.h"

int main() {
    t_etudiant* e1;

    e1 = t_etudiant_init("Baggins", "Bilbo");

    strcpy(e1->code_perm, "BAGB00000000");
    e1->intra = 75;
    e1->finale = 86.5;
    e1->tp1 = 80;
    e1->tp2 = 85;

    t_etudiant_afficher(e1);

    return 0;
}
