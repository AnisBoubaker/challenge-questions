#include <stdio.h>


int somme_des_pairs( int debut, int fin )
{
    int somme = 0;
    int compteur;

    if(debut % 2 == 1)
    {
        debut ++;
    }
    for(compteur = debut; compteur <= fin; compteur= compteur +2)
    {
        somme = somme + compteur;
    }
    // Sors de la fonction en donnant comme résultat ce qui se trouve dans la
    // variable somme
    return somme;
}



int main(void)
{
    int resultat;
    int mon_debut;
    int ma_fin;

    printf("Saisir la valeur du debut: ");
    scanf("%i", &mon_debut);

    printf("Saisir la valeur de la fin: ");
    scanf("%i", &ma_fin);

    resultat =  somme_des_pairs( mon_debut, ma_fin);

    //Pas possible, il n'ya pas de variable compteur dans le main
    //la variable compteur n'existe que dans la fonction somme_pairs
    //printf("Le compteur s'est arrêté à %i\n", compteur);

    printf("Le resualtat est: %i\n", resultat);

    return 0;
}
