 

#ifndef INF155_TP1_UTILITAIRES_H
#define INF155_TP1_UTILITAIRES_H

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labyrinthe.h"

 
#define MESSAGE_TITRE_LIGNE_1 "                *************************\n"
#define MESSAGE_TITRE_LIGNE_2 "                *** LABYRINTHE EXPERT ***\n"
#define MESSAGE_TITRE_LIGNE_3 "                *************************\n"

#define ESPACEMENT_OPTIONS "        %d. "
#define MESSAGE_OPTION_1 "Charger un labyrinthe\n", 1
#define MESSAGE_OPTION_2 "Resoudre le labyrinthe\n", 2
#define MESSAGE_OPTION_3 "Resoudre le labyrinthe pas-a-pas\n", 3
#define MESSAGE_OPTION_4 "Quitter le programme\n", 4
#define INDISPONIBLE "[Indisponible] "

#define MESSAGE_GRILLE_CHARGEE "        Grille chargee avec succes:\n\n"
#define MESSAGE_GRILLE_PAS_CHARGEE "Erreur lors du chargement de la grille.\n"

#define MESSAGE_AUCUNE_SOLUTIONS "Aucune solution trouvée :-(\n"

 
void afficher_options(int grille_chargee);

 
void afficher_chargement_grille(
        int grille_chargee,
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);

 
void afficher_solution(int solution_est_trouve, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]);

#endif  
