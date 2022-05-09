#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "result_course.h"

int winner(S_case piste[], int pos[]);
int looser(S_case piste[], int pos[]);
int calcul_gain(int pos);

void result_course(S_joueur joueurs[], S_case piste[], int pos[], int pari[][2], int etat)
{
    int chamo;
    switch(etat)    //pari sur la victoire ou la défaite ?
    {
        case -1 : chamo=looser(piste, pos);
                break;
        case 1 : chamo=winner(piste, pos);
                break;
    }

    int place=0;
    for(int a=0; pari[a][1]; a++)
    {
        if(pari[a][1]==chamo)
        {
            joueurs[pari[a][0]-1].argent=joueurs[pari[a][0]-1].argent+calcul_gain(place);
            place++;
        }
        else
            joueurs[pari[a][0]-1].argent=joueurs[pari[a][0]-1].argent-1;
    }
}

// renvoie le n° du chmeau gagnant
int winner(S_case piste[], int pos[])
{
    int top=0;

    for(int a=0; a<5; a++)  //cherche la position du premier chameau
        if(pos[a]>top)
            top=pos[a];

    for(int a=4; a>=0; a--) //cherche le chameau le plus haut
        if(piste[top].cham[a]!=0)
            return piste[top].cham[a];
}

// renvoie le n° du chmeau perdant
int looser(S_case piste[], int pos[])
{
    int btm=16;

    for(int a=0; a<5; a++)  //cherche la position du dernier chameau
        if(pos[a]<btm)
            btm=pos[a];

    return piste[btm].cham[0];
}

// calcule la qté de livres a donner
int calcul_gain(int pos)
{
    switch(pos)
    {
        case 0 : return 8;
        case 1 : return 5;
        case 2 : return 3;
        case 3 : return 2;
        default : return 1;
    }
}
