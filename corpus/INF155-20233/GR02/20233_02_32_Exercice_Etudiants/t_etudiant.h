//
// Created by Anis Boubaker on 2023-11-16.
//

#ifndef EXERCICE_ETUDIANTS_T_ETUDIANT_H
#define EXERCICE_ETUDIANTS_T_ETUDIANT_H

#define TAILLE_MAX_NOM_PRENOM 50
#define TAILLE_MAX_CODE_PERM 13

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etudiant{
    char* nom; //Pointeur vers un tableau de caractères
    char* prenom;
    char code_perm[TAILLE_MAX_CODE_PERM];
    double tp1;
    double tp2;
    double intra;
    double finale;
} t_etudiant;


/*
 *
 */
void t_etudiant_afficher(const t_etudiant* et);

/*
 * Fonction constructeur
 */
t_etudiant* t_etudiant_init(const char* nom, const char* prenom);

#endif //EXERCICE_ETUDIANTS_T_ETUDIANT_H
