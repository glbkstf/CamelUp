#include <stdio.h>
#include <stdlib.h>
#include "deplacement.h"
#include "defines.h"

int choix()
{
    int choice;
    printf("\nVpous pouvez :");
    printf("\n\t1. Deplacer votre tuile desert");
    printf("\n\t2. Retourner la pyramide");
    printf("\n\t3. Parier sur cette manche");
    printf("\n\t4. Parier sur la course");
    do
    {
        printf("\nEntrez un nombre entre 1 et 4 pour choisir");
        scanf("%d", &choice);
    }while(choice<1 || choice>4);
    return choice;
}

int place_desert()
{
    printf("\npas encore implemente");
    return 0;
}

int use_pyramid(S_case piste[], int pos[], int couleur, int valeur)
{
    /*printf("\npas encore implemente");*/
    printf("\nLe chameau numero %d avance de %d cases", couleur, valeur);
    move_chamal(piste, pos, couleur, valeur);
    return 1;
}

int pari_manche()
{
    printf("\npas encore implemente");
    return 0;
}

int pari_course()
{
    printf("\npas encore implemente");
    return 0;
}
