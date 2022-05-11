#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "display.h"

int calcul_carte(int carte);

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
    printf("depart");
    for(int a=1; a<16; a++)
        printf("  %2d  ", a);
    printf("  arrivee\n");
}


void disp_paricourse(int pari[][2])
{
    if(pari[0][0]==0)
    {
        printf("\nAucun pari pour l'instant.\n");
    }else
    {
        printf("\nJoueur : ");
        for(int a=0; pari[a][0]!=0; a++)
            printf(" %d ", pari[a][0]);
        printf("\nChameau : ");
        for(int a=0; pari[a][1]!=0; a++)
            printf(" %d ", pari[a][1]);
    }
}


void disp_parimanche(int cartes[][3])
{
    printf("\nVoici les cartes pari-manche sur le dessus des piles :\n");
    printf("  Chameau 1   Chameau 2   Chameau 3   Chameau 4   Chameau 5\n  ");
    for(int a=0; a<5; a++)
        for(int b=0; b<3; b++)
            if(cartes[a][b]==0)
            {
                printf("Carte +%d    ", calcul_carte(b));
                break;
                if(b==2)
                    printf("    Vide    ");
            }
}

int calcul_carte(int carte)
{
    switch(carte)
    {
        case 0 : return 5;
        case 1 : return 3;
        case 2 : return 2;
    }

}
