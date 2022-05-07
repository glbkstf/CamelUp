#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "display.h"

void disp_position(int pos[])
{
    printf("\npositions :\n");
    for(int x=0; x<5; x++)
        printf("%d\t", pos[x]);
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
