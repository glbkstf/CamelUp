#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "display.h"
#include "setup.h"
#include "deplacement.h"
#include "tirage_pyramide.h"
#include "actions.h"

int main()
{
    //init de toutes les variables du jeu
    srand(time(NULL));
    int nb_joueurs=4;
    S_case piste[17];                   // circuit
    S_pyr pyramide[5];
    S_joueur joueurs[4];                // données des joueurs
    int carte_manche[5][3];             // paris-manche
    int pari_win[nb_joueurs*5][2];      // paris sur la victoire
    int pari_loose[nb_joueurs*5][2];    // paris sur la défate
    int pos_cham[5]={1,2,3,4,5};        // position des chamaux (R,Y,G,B,W)
    int avcnt_pyr=0;                    // avancement dans la pyramide

    setup(piste, carte_manche, joueurs, nb_joueurs);
    setup_pari_course(pari_win, nb_joueurs);
    setup_pari_course(pari_loose, nb_joueurs);

    //placement initial des chameaux
    tirage_pyramide(pyramide);
    for(int a=0; a<5; a++)
        pos_cham[pyramide[a].couleur-1]=setup_chamal(piste, pyramide[a].couleur, pyramide[a].valeur);

    //début de la manche
    int player=1;
    do
    {
        disp_piste(piste);
        choice: switch(choix())
        {
            case 1 : if(place_desert()==0)
                        goto choice;
                    break;
            case 2 : if(use_pyramid()==0)
                        goto choice;
                    avcnt_pyr++;
                    break;
            case 3 : if(pari_manche()==0)
                        goto choice;
                    break;
            case 4 : victoireoufefaite:
                    printf("\nparier sur la defaite ou la victoire ? (entrez -1 ou 1)");
                    int var;
                    scanf("%d", &var);
                    switch(var)
                    {
                        case -1 : if(pari_course()==0)
                                {
                                    goto choice;
                                }
                                break;
                        case 1 : if(pari_course()==0)
                                {
                                    goto choice;
                                }
                                break;
                        default : goto victoireoufefaite;
                    }
                    break;
        }
        player++;
    }while(avcnt_pyr<4);     //tant que toute la pyramide n'a pas été utilisée


    return 0;
}
