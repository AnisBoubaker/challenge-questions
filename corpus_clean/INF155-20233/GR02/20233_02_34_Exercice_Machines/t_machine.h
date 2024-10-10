 
 
 

#ifndef EXERCICE_MACHINES_T_MACHINE_H
#define EXERCICE_MACHINES_T_MACHINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_date.h"

typedef struct t_machine {
    int num;
    char* num_modele;
    t_date date_mise_service;
    t_date date_maintenance;
} t_machine;

 
t_machine* machine_init(int num, const char* num_modele);


 
void machine_free(t_machine* machine);

 
void machine_afficher(const t_machine* m);



#endif  
