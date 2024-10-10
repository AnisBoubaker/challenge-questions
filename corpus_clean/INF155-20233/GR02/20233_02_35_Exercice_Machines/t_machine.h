 
 
 

#ifndef EXERCICE_MACHINES_T_MACHINE_H
#define EXERCICE_MACHINES_T_MACHINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_date.h"

typedef enum categorie { CAT1, CAT2, CAT3, CAT4 } e_categorie;

typedef struct t_machine {
    int num;
    char* num_modele;
    e_categorie categorie;
    t_date date_mise_service;
    t_date date_maintenance;
} t_machine;

 
t_machine* machine_init(int num, const char* num_modele);


 
void machine_free(t_machine* machine);

 
void machine_afficher(const t_machine* m);

 
void machine_jeu_machines(t_machine* machines[], int taille_max);


 
t_machine** machines_a_maintenir(t_machine* liste_machines[], int nb_machines, t_date date_min,int* nb_a_maintenir);

#endif  
