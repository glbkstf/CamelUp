#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "setup.h"
#include "display.h"
#include "result_course.h"


int main()
{
    int nb_joueurs=4;
    S_case piste[17];
    S_joueur joueurs[4];
    int pari_win[nb_joueurs*5][2];
    int pari_loose[nb_joueurs*5][2];

    setup(piste, joueurs, nb_joueurs);
    setup_pari_course(pari_win, nb_joueurs);
    setup_pari_course(pari_loose, nb_joueurs);

    //mise en situation
    int pos_cham[5]={14,16,16,13,15};

    piste[14].cham[0]=1;
    piste[16].cham[0]=2;
    piste[16].cham[1]=3;    //chameau 3 est en tête
    piste[13].cham[0]=4;
    piste[15].cham[0]=5;

    disp_piste(piste);

    //exemple inspiré de celui de la règle
    pari_win[0][0]=1;   //J1 a parié pour n°3
    pari_win[0][1]=3;
    pari_win[1][0]=2;   //J2 a parié pour n°4
    pari_win[1][1]=4;
    pari_win[2][0]=2;   //J2 a parié pour n°2
    pari_win[2][1]=2;
    pari_win[3][0]=3;   //J3 a parié pour n°2
    pari_win[3][1]=2;

    pari_loose[0][0]=2;   //J2 a parié contre n°4;
    pari_loose[0][1]=4;
    pari_loose[1][0]=1;   //J1 a parié contre n°1;
    pari_loose[1][1]=1;
    pari_loose[2][0]=2;   //J2 a parié contre n°3;
    pari_loose[2][1]=3;
    pari_loose[3][0]=3;   //J3 a parié contre n°4;
    pari_loose[3][1]=4;
    pari_loose[4][0]=1;   //J1 a parié contre n°4;
    pari_loose[4][1]=4;

    //attribue les gains du pari sur la défaite
    result_course(joueurs, piste, pos_cham, pari_loose, -1);

    //affiche le pognon des joueurs
    for(int a=0; a<nb_joueurs; a++)
        printf("\nJ%d a %d livres", a+1, joueurs[a].argent);

    //attribue les gains du pari sur la victoire
    result_course(joueurs, piste, pos_cham, pari_win, 1);

    //affiche le pognon des joueurs
    for(int a=0; a<nb_joueurs; a++)
        printf("\nJ%d a %d livres", a+1, joueurs[a].argent);

    return 0;
}
