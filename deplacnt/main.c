#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines2.h"
#include "tirage_pyramide2.h"
#include "display2.h"
#include "deplacement.h"



int main()
{

    S_case circuit[16];
    S_pyr pyramide[5];
    srand(time(NULL));
    int pos_cham[5]={1,2,3,4,5};    // position des chamaux (R,Y,G,B,W)

    for (int i=0; i<16; i++)        // mise à zéro de la piste
    {
        circuit[i].desert=0;
        for (int j=0; j<5; j++)
        {
            circuit[i].cham[j]=0;
        }
    }

    tirage_pyramide(pyramide);
    disp_pyramide(pyramide);
    //disp_piste(circuit);

    // placement de départ des chameaux
    for(int a=0; a<5; a++)
        pos_cham[pyramide[a].couleur-1]=setup_chamal(circuit, pyramide[a].couleur, pyramide[a].valeur);

    disp_position(pos_cham);
    disp_piste(circuit);
    tirage_pyramide(pyramide);
    disp_pyramide(pyramide);

    //int a=0;
    for (int a=0; a<5; a++)
    {
        printf("\na=%d",a);
        move_chamal(circuit, pos_cham, pyramide[a].couleur, pyramide[a].valeur);

        //test
        /*int coulr=pyramide[a].couleur, pas=pyramide[a].valeur;
        int h_depart, h_arrivee, case_dep=pos_cham[coulr-1];
        printf("\n\tcase_dep=%d", case_dep);

        printf("\nreperage depart");

        for(int b=0; b<5; b++)      //repère la hauteur du chameau à déplacer
            if(circuit[case_dep].cham[b]==coulr)
            {
                h_depart=b;
                break;
            }
        printf("\n\th_depart=%d", h_depart);

        printf("\nreperage arrivee");

        for(int b=0; b<5; b++)      //repère la hauteur où le placer
            if(circuit[case_dep+pas].cham[b]==0)
            {
                h_arrivee=b;
                break;
            }
        printf("\n\th_arrivee=%d", h_arrivee);

        printf("\ndeplacement");

        for(int b=0; b<5-h_depart; b++)     //déplace le chameau et ceux au dessus
        {
            printf("\n\theight=%d", h_depart+b);
            if(circuit[case_dep].cham[h_depart+b]!=0)
            {
                printf("\n\tmove=%d", b);
                circuit[case_dep+pas].cham[h_arrivee+b]=circuit[case_dep].cham[h_depart+b]; //place chameau dans nouvelle case
                pos_cham[circuit[case_dep].cham[h_depart+b]-1]=case_dep+pas;                //maj la position du chameau
                circuit[case_dep].cham[h_depart+b]=0;                                       //libère ancienne case
            }
        }*/
        //test

        printf("\na=%d",a);
        disp_position(pos_cham);
        disp_piste(circuit);
    }

    printf("\n\nend");

    return 0;
}

