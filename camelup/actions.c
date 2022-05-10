#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

int choix()
{
    int choice;
    printf("\nVpous pouvez :");
    printf("\n\t1. Deplacer votre tuile desert");
    printf("\n\t2. Prendre un dé");
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

int use_pyramid()
{
    printf("\npas encore implemente");
    return 0;
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
