#include <stdio.h>
#include "t_date.h"
#include "t_machine.h"

#define MAX_MACHINES 1000

int main() {
    t_date date1, date2;
    t_machine* machine1;
    int nb_machines;
    //t_machine* machines[MAX_MACHINES];
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

    // ...
    for(int i=0; i<nb_machines; i++)
    {
        machine_afficher(machines[i]);
    }

//    machine1 = machine_init(1, "A25D08");
//    machine_afficher(machine1);
//    machine_free(machine1);




//    date1.annee = 2022;
//    date1.mois = DECEMBRE;
//    date1.jour = 1;
//
//    date2.annee = 2022;
//    date2.mois = DECEMBRE;
//    date2.jour = 1;
//
//    int comparaison = date_cmp(date1, date2);
//    if(comparaison > 0 )
//    {
//        printf("La date1 est plus récente que date2\n");
//    }
//    else if( comparaison <0 )
//    {
//        printf("La date1 est antérieure à la date 2\n");
//    }
//    else
//    {
//        printf("Les deux dates sont identiques.\n");
//    }

//    date1.annee = 2022;
//    date1.mois = DECEMBRE;
//    date1.jour = 1;
//
//    if(date_set_date(&date1, 29, FEVRIER, 2021))
//    {
//        printf("La date a ete definie!\n");
//    }
//    else
//    {
//        printf("La date est erronee!\n");
//    }
//    printf("Le contenu de date1: %i/%i/%i", date1.jour, date1.mois, date1.annee);


    return 0;
}
