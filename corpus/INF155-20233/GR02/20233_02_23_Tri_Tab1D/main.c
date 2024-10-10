#include <stdio.h>
#include "tri_tab1d.h"

int main() {
    int mon_tableau[] = {45, 10, 2, 28, 55, 46, 78, 32};
    int mon_tableau2[] = {45, 10, 2, 28, 55, 46, 78, 32};
    int mon_tableau3[] = {45, 10, 2, 28, 55, 46, 78, 32};

    tri_insertion(mon_tableau, 8);
    afficher_tab(mon_tableau, 8);

    tri_selection(mon_tableau2, 8);
    afficher_tab(mon_tableau2, 8);

    tri_bulles(mon_tableau3, 8);
    afficher_tab(mon_tableau3, 8);

    return 0;
}

