//
// Created by versha aamir on 2023-11-12.
//

#ifndef TP_LABYRINTHE_AAMIRVERSHA_PILE_H
#define TP_LABYRINTHE_AAMIRVERSHA_PILE_H

int pile_empiler(int pile[][2], int new_ligne, int new_colonne);
int pile_depiler(int pile[][2], int* ligne, int* colonne);
int pile_est_vide(int pile[][2]);
int pile_contient(int pile[][2], int ligne, int colonne);
int pile_taille_pile(int pile[][2]);
void pile_initialiser(int pile[][2], int taille_max);
void pile_haut_pile(int pile[][2], int* ligne, int* colonne);
void pile_copier(int pile_originale[][2], int pile_copie[][2]);

#endif //TP_LABYRINTHE_AAMIRVERSHA_PILE_H
