#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines2.h"
#include "tirage_pyramide2.h"
#include "display2.h"


int main()
{

    S_case circuit[16];
    S_pyr pyramide[5];
    srand(time(NULL));
    int chameaux[5]={1,2,3,4,5};    // position des chamaux (R,Y,G,B,W)
    int avcnt_pyr=0;

    for (int i=0; i<16; i++)        // mise � z�ro de la piste
    {
        circuit[i].desert=0;
        for (int j=0; j<5; j++)
        {
            circuit[i].chameaux[j]=0;
        }
    }

    tirage_pyramide(pyramide);
    disp_pyramide(pyramide);




    return 0;
}
