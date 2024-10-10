#include <stdio.h>
#include "t_date.h"
#include "t_machine.h"

#define MAX_MACHINES 1000

int main() {
    t_machine* machines[100];
    t_machine_ptr** machines_classees;
    t_machine_ptr* machines_lues;
    int nb_machines;

    machines_lues = machine_charge_machines("../sauvegarde_machines.txt", &nb_machines);
    if(machines_lues == NULL)
    {
        printf("Erreur lors de la lecture du fichier.");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<nb_machines; i++)
    {
        machine_afficher(machines_lues[i]);
    }


 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

    return 0;
}
