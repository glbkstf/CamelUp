#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "display.h"

void disp_piste(S_case piste[])
{
    printf("\ndesert : \n|");
    for(int i=0; i<16; i++)
        switch(piste[i].desert)
        {
            case 0 : printf("     |");
                    break;
            default : printf("  %d  |", piste[i].desert);
        }
    printf("\nchameaux : \n");
    for (int j=4; j>=0; j--)
    {
        for (int i=0; i<16; i++)
            switch(piste[i].cham[j])
            {
                case 0 : printf("|     ");
                        break;
                default : printf("|  %d  ", piste[i].cham[j]);
            }
        printf("|");
        switch(piste[16].cham[j])
            {
                case 0 : printf("|     ");
                        break;
                default : printf("|  %d  ", piste[16].cham[j]);
            }
        printf("\n");
    }
    /*printf(" depart\t\t\t\t\t\t\t\t\t\t\t\t                 arrivee\n");*/
}
