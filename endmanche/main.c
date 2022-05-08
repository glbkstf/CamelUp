#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "setup.h"
#include "display.h"
#include "result_manche.h"


int main()
{
    S_case piste[16];
    S_joueur joueurs[4];
    int carte_manche[5][3];
    int nb_joueurs=4;

    setup(piste, carte_manche, joueurs, nb_joueurs);

    //mise en situation
    int pos_cham[5]={4,6,6,3,5};

    piste[4].cham[0]=1;
    piste[6].cham[0]=2;
    piste[6].cham[1]=3;     //chameau 3 est en tête
    piste[3].cham[0]=4;
    piste[5].cham[0]=5;

    disp_piste(piste);

    carte_manche[4][0]=2;   //J2 a pris la 1re carte du chameau 5
    carte_manche[1][0]=2;   //J2 a pris la 2e carte du chameau 2
    carte_manche[2][1]=2;   //J2 a pris la 2e carte du chameau 3
    carte_manche[3][0]=3;   //J3 a pris la 1re carte du chameau 4
    carte_manche[2][0]=3;   //J3 a pris la 1re carte du chameau 3
    carte_manche[2][2]=1;   //J1 a pris la 3e carte du chameau 3
    carte_manche[0][0]=1;   //J1 a pris la 1re carte du chameau 1
    carte_manche[3][1]=4;   //J4 a pris la 2e carte du chameau 4
    carte_manche[0][1]=4;   //J4 a pris la 2e carte du chameau 1
    carte_manche[1][1]=4;   //J4 a pris la 3e carte du chameau 2

    //attribue les gains
    result_manche(piste, pos_cham, carte_manche, joueurs);

    //affiche le pognon des joueurs
    for(int a=0; a<nb_joueurs; a++)
        printf("\nJ%d a %d livres", a+1, joueurs[a].argent);

    return 0;
}
