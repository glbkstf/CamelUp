#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "setup.h"


void setup(S_case piste[], int cartes[][3], S_joueur joueurs[], int nb_plyr)
{
    for (int i=0; i<=16; i++)        // mise à zéro de la piste
    {
        piste[i].desert=0;
        for (int j=0; j<5; j++)
        {
            piste[i].cham[j]=0;
        }
    }
    for (int j=0; j<5; j++)
        {
            piste[16].cham[j]=0;
        }

    for(int a=0; a<nb_plyr; a++)    // joueurs à zéro
    {
        joueurs[a].argent=3;
        joueurs[a].desert=0;
        joueurs[a].pyra=0;
        for(int b=0; b<5; b++)
            joueurs[a].paricourse[b]=0;
    }

    for(int a=0; a<5; a++)
        for(int b=0; b<3; b++)
            cartes[a][b]=0;
}

void setup_pari_course(int cartes[][2], int nb_plyr)
{
    for(int a=0; a<nb_plyr*5; a++)          //cartes à zéro
        for(int b=0; b<2; b++)
            cartes[a][b]=0;
}
