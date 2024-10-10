#include <stdio.h>
#include "t_date.h"
#include "t_machine.h"

#define MAX_MACHINES 1000

int main() {
    t_machine* machines[100];
    t_date date_seuil;
    machine_jeu_machines(machines, 50);
    t_machine** a_maintenir;
    int nb_a_maintenir;

 
 
 

    date_set_date(&date_seuil, 1, JUILLET, 2023);

    a_maintenir = machines_a_maintenir(machines, 50, date_seuil, &nb_a_maintenir);

    for(int i=0; i< nb_a_maintenir; i++)
    {
        machine_afficher(a_maintenir[i]);
    }



 
 
 
 

     

    return 0;
}
