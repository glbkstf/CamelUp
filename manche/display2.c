#include <stdio.h>
#include <stdlib.h>
#include "defines2.h"
#include "display2.h"

void disp_pyramide(S_pyr pyramide[])
{
    printf("\ncouleur : ");
    for (int i=0; i<5; i++)
        printf(" %d ", pyramide[i].couleur);
    printf("\nvaleur :  ");
    for (int i=0; i<5; i++)
        printf(" %d ", pyramide[i].valeur);
}

void disp_piste(S_case piste[])
{
    printf("\ndesert : \n");
    for (int i=0; i<16; i++)
        printf("  %d  ", piste[i].desert);
    printf("\nchamal : \n");
    for (int j=4; j>=0; j--)
    {
        for (int i=0; i<16; i++)
            printf("  %d  ", piste[i].cham[j]);
        printf("\n");
    }
}
