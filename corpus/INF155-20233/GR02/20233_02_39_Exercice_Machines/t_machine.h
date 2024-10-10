//
// Created by Anis Boubaker on 2023-11-23.
//

#ifndef EXERCICE_MACHINES_T_MACHINE_H
#define EXERCICE_MACHINES_T_MACHINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_date.h"

typedef enum categorie { CAT1, CAT2, CAT3, CAT4 } e_categorie;

#define NB_CATEGORIES 4

typedef struct t_machine {
    int num;
    char* num_modele;
    e_categorie categorie;
    t_date date_mise_service;
    t_date date_maintenance;
} t_machine;

//JE donne le nom t_machine_ptr aux él;éments de type t_machine*
typedef t_machine* t_machine_ptr;


/*
Alloue et initialise une nouvelle machine. Le numéro de la machine et
le numéro de modèle reçus en paramètres permettent d'initialiser les champs
num et num_modele.
ENTREES:
num (chaine): numéro de la machine dans le parc
num_modele (chaine): le numéro de modèle de la nouvelle machine
SORTIE:
Une référence vers la nouvelle machine allouée avec les champs
num et num_modele initialisés. Les dates de mise en service et de
 maintenance seront les dates nulles (0-0-0).
 En cas d'erreur d'allocation mémoire, la fonction retourne NULL.
*/
t_machine* machine_init(int num, const char* num_modele);


/*
Libère l'espace mémoire d'une machine.
ENTREES:
machine (référence vers une machine): la machine à libérer SORTIE:
Aucune.
*/
void machine_free(t_machine* machine);

/*
 * Fonction qui affiche une machine dans la console
 */
void machine_afficher(const t_machine* m);

/*
 *
 */
void machine_jeu_machines(t_machine* machines[], int taille_max);


/*
Identifie toutes les machines qui doivent subir une opération de maintenance.
Ces machines sont celles dont la date de dernière maintenance est nulle (0-0-0)
ou celles dont la date de dernière maintenance est antérieure à une date_min. ENTREES:
- liste_machines: Tableau de références des machines du parc
- nb_machines: nombre de machines dans le tableau liste_machines
- date_min: Date minimale
SORTIE:
Tableau dynamique de références vers des machines qui doivent être maintenues.
*/
t_machine** machines_a_maintenir(t_machine* liste_machines[], int nb_machines, t_date date_min,int* nb_a_maintenir);



/*
 * Écrire la fonction machine_classer_categories qui reçoit un tableau de références
 * vers des machines et qui les classe par catégorie. Votre fonction retourne un tableau
 * à deux dimensions de références vers des machines.
 *
 * Il n’y aura pas plus de 100 machines par catégorie.
 */
t_machine_ptr** machine_classer_machines(t_machine_ptr [], int taille);


/*
 * Écrire la fonction machine_sauvegarder_machines qui crée un fichier texte ayant
 * le format suivant :
Nb_machines
id_machine1 num_modele jour_mes mois_mes annee_mes jour_main mois_main annee_main
id_machine2 num_modele jour_mes mois_mes annee_mes jour_main mois_main annee_main
id_machine3 num_modele jour_mes mois_mes annee_mes jour_main mois_main annee_main
...
 */
int machine_sauvegarder_machines(t_machine* machines[], int nb, char* nom_fichier);


/*
 *
 */
t_machine_ptr* machine_charge_machines(const char* nom_fichier, int* nb_machines);


#endif //EXERCICE_MACHINES_T_MACHINE_H
