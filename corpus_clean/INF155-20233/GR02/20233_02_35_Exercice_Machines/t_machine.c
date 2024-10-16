 
 
 

#include "t_machine.h"

t_machine* machine_init(int num, const char* num_modele)
{
    t_machine* nouv_machine;

    nouv_machine = (t_machine*)malloc(sizeof(t_machine));
    if(nouv_machine == NULL)
    {
        return NULL;
    }

    nouv_machine->num_modele = (char*)malloc(sizeof(char)*(strlen(num_modele)+1));
    if(nouv_machine->num_modele==NULL)
    {
        free(nouv_machine);
        return NULL;
    }

    nouv_machine->num = num;
    strcpy(nouv_machine->num_modele, num_modele);

    nouv_machine->date_mise_service.jour = 0;
    nouv_machine->date_mise_service.mois = 0;
    nouv_machine->date_mise_service.annee = 0;

    nouv_machine->date_maintenance.jour = 0;
    nouv_machine->date_maintenance.mois = 0;
    nouv_machine->date_maintenance.annee = 0;

    return nouv_machine;
}

void machine_free(t_machine* machine)
{
    free(machine->num_modele);
    free(machine);
}


void machine_afficher(const t_machine* m)
{
    printf("****** MACHINE NUM %i ********\n", m->num);
    printf("Modele: %s\n", m->num_modele);
    printf("Date de mise en service: %i/%i/%i\n",
           m->date_mise_service.jour,
           m->date_mise_service.mois,
           m->date_mise_service.annee);
    printf("Date de derniere maintenance: %i/%i/%i\n",
           m->date_maintenance.jour,
           m->date_maintenance.mois,
           m->date_maintenance.annee);
}

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

void machine_jeu_machines(t_machine* machines[], int nb)
{
    char num_modele[10];
    for(int i=0; i<nb; i++)
    {
        sprintf(num_modele, "%c%i%c%i", (char)nb_aleatoire(65, 90), nb_aleatoire(100, 500), (char)nb_aleatoire(65, 90),
                nb_aleatoire(100, 500));
        machines[i] = machine_init(i, num_modele);
        date_set_date(&(machines[i]->date_mise_service), nb_aleatoire(1, 28), nb_aleatoire(1, 12), 2023);
        date_set_date(&(machines[i]->date_maintenance), nb_aleatoire(1, 28), nb_aleatoire(1, 12), 2023);
    }
}

t_machine** machines_a_maintenir(t_machine* liste_machines[],
                                 int nb_machines,
                                 t_date date_min,
                                 int* nb_a_maintenir)
{
    t_machine** a_maintenir;
    t_machine** tmp;  
    *nb_a_maintenir = 0;

    a_maintenir = (t_machine**)malloc(sizeof(t_machine*)*nb_machines);
    if(a_maintenir == NULL)
    {
        return NULL;
    }

    for(int i=0; i<nb_machines; i++)
    {
        if(date_cmp(liste_machines[i]->date_maintenance, date_min)<0)
        {
            a_maintenir[*nb_a_maintenir] = liste_machines[i];
            (*nb_a_maintenir)++;
        }
    }

    tmp = realloc(a_maintenir, sizeof(t_machine*)* *nb_a_maintenir);
    if(tmp == NULL)
    {
        return a_maintenir;
    }
    a_maintenir = tmp;

    return a_maintenir;
}











