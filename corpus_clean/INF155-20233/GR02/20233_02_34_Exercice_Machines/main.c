#include <stdio.h>
#include "t_date.h"
#include "t_machine.h"

#define MAX_MACHINES 1000

int main() {
    t_date date1, date2;
    t_machine* machine1;
    int nb_machines;
     
    t_machine** machines;

    printf("Combien de machines? ");
    scanf("%i", &nb_machines);

    machines = (t_machine**)malloc(sizeof(t_machine*) * nb_machines);
    if(machines == NULL)
    {
        printf("Erreur d'allocation!\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<nb_machines; i++)
    {
        machines[i] = machine_init(i, "R678S45");
        if(machines[i]==NULL)
        {
            printf("Desole vous êtes limite à %i machines", i);
            nb_machines = i;
            break;
        }
    }

     
    for(int i=0; i<nb_machines; i++)
    {
        machine_afficher(machines[i]);
    }

 
 
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 


    return 0;
}
