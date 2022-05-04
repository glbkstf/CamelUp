#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines2.h"
#include "deplacement.h"

void move_chamal(S_case piste[], int pos[], int coulr, int pas)
{
    int h_depart, h_arrivee, case_dep=pos[coulr]-1;

    for(int a=0; a<5; a++)      //repère la hauteur du chameau à déplacer
        if(piste[case_dep].cham[a]==coulr)
        {
            h_depart=a;
            break;
        }

    for(int a=0; a<5; a++)      //repère la hauteur où le placer
        if(piste[case_dep+pas].cham[a]==0)
        {
            h_arrivee=a;
            break;
        }

    for(int a=0; a<5-h_depart; a++)     //déplace le chameau et ceux au dessus
    {
        piste[case_dep+pas].cham[h_arrivee+a]=piste[case_dep].cham[h_depart+a]; //place chameau dans nouvelle case
        pos[piste[case_dep].cham[h_depart+a]]=case_dep+pas;                     //maj la position du chameau
        piste[case_dep].cham[h_depart+a]=0;                                     //libère ancienne case
    }
}

int setup_chamal(S_case piste[], int coulr, int pas)
{
    int height=0;
    for(height; height<5; height++)     //repère la 1ère hauteur libre
        if(piste[pas-1].cham[height]==0)
            break;

    piste[pas-1].cham[height]=coulr;    //y place le chameau

    return pas-1;
}
