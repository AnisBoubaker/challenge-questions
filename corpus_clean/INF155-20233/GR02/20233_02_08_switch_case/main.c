#include <stdio.h>

int main(void) {
    char choix;
    printf("Pressez 'A', 'B' ou 'C' pour continuer:");
    scanf("%c", &choix);

    switch(choix)
    {
        case 'A':
            printf("Vous avez choisi A, bon choix!\n");
            break;  
        case 'B':
            printf("Vous avez choisi B, pas mal!\n");
            break;
        case 'C':
            printf("Vous avez choisi C, c’est bien!\n");
            break;
        default:
            printf("vous deviez saisir A, B ou C… Quel dommage!");
    }


     

}
