////Modules inlcuant les fonctions utilitaires
// Created by admin on 2023-10-25.
//Auteur: Jonathan Mongrain, Anthony de Marco, Etienne Barriere, Mohammadsam Karimi
//
//
//Date: 12 novembre 2023
//

#ifndef INF155_TP1_EQUIPEA_UTILITAIRES_H
#define INF155_TP1_EQUIPEA_UTILITAIRES_H



//fonction qui retourne un entier aleatoire entre le min et le max
//et qui prend comme arguments 2 entiers : le minimum et la maximum de la plage de valeurs
int Chiffre_Aleatoire(int min, int max);

//Fonction qui retourne 1 si la position passé en parametre est une entree
//Parametre: position (tableau d'entier): tableau qui contien coordonnees de la position
//           entree (tableau d'entier): tableau qui contien coordonees de l'entree
int pos_est_entree(int position[2],int entree[2]);

#endif //INF155_TP1_EQUIPEA_UTILITAIRES_H
