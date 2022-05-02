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
    int avcnt_pyr=0;

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

    disp_piste(circuit);

    for(int a=0; a<5; a++)
        pos_cham[a]=setup_chamal(circuit, pyramide[a].couleur, pyramide[a].valeur);

    disp_piste(circuit);


    return 0;
}
