#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "defines.h"
#include "deplacement.h"

int move_chamal(S_case piste[], int pos[], int coulr, int pas)
{
    int h_depart, h_arrivee, case_dep=pos[coulr-1], case_arr=case_dep+pas, finish=0;

    if(case_arr<16)    //évite qu'on sorte du plateau
        switch (piste[case_arr].desert) //application des deserts/oasis
        {
        case 1 :
            case_arr=case_arr-1;
            break;
        case 2 :
            case_arr=case_arr+1;
            break;
        }
    else
    {
        case_arr=16;
    }
    if(case_arr>=16)
    {
        case_arr=16;
        finish=1;
    }

    if(case_arr==case_dep)      //cas où les chameaux ne bougent pas à cause d'un desert
        return 1;


    //printf("\nreperage depart");

    for(int b=0; b<5; b++)      //repère la hauteur du chameau à déplacer
        if(piste[case_dep].cham[b]==coulr)
        {
            h_depart=b;
            break;
        }

    //printf("\nreperage arrivee");

    for(int b=0; b<5; b++)      //repère la hauteur où le placer
        if(piste[case_arr].cham[b]==0)
        {
            h_arrivee=b;
            break;
        }

    //printf("\ndeplacement");

    for(int b=0; b<5-h_depart; b++)     //déplace le chameau et ceux au dessus
    {
        if(piste[case_dep].cham[h_depart+b]!=0)
        {
            piste[case_arr].cham[h_arrivee+b]=piste[case_dep].cham[h_depart+b]; //place chameau dans nouvelle case
            pos[piste[case_dep].cham[h_depart+b]-1]=case_arr;                   //maj la position du chameau
            piste[case_dep].cham[h_depart+b]=0;                                     //libère ancienne case
        }
    }

    return finish;
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
