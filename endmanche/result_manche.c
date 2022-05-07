#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "result_manche.h"

int calcul_gain(int pos, int cartes);

void result_manche(S_case piste[], int pos[], int cartes[][3], S_joueur joueurs[])
{
    int top=0, btm=16;
    for(int a=0; a<5; a++)  //cherche la position des premier et dernier chameaux
    {
        if(pos[a]>top)
            top=pos[a];
        if(pos[a]<btm)
            btm=pos[a];
    }

    int place=0;
    for(int a=top; a>=btm; a--)
        for(int b=4; b>=0; b--)
            if(piste[a].cham[b]!=0) //chameau présent à cet emplecnt ?
            {
                if(cartes[piste[a].cham[b]-1][0]!=0)    //qqun a parié sur ce chameau ?
                    for(int c=0; c<3; c++)
                    {
                        if(cartes[piste[a].cham[b]-1][c]==0)    //qqun a pris cette carte ?
                            break;
                        joueurs[cartes[piste[a].cham[b]-1][c]-1].argent = joueurs[cartes[piste[a].cham[b]-1][c]-1].argent + calcul_gain(place, c);
                    }
                place++;
            }

}

// calcule la qté de livres a donner
int calcul_gain(int pos, int carte)
{
    switch(pos)
    {
        case 0 : switch(carte)
                {
                    case 0 : return 5;
                    case 1 : return 3;
                    case 2 : return 2;
                }
        case 1 : return 1;
        default : return -1;
    }
}
