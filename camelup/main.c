#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "display.h"
#include "setup.h"
#include "deplacement.h"
#include "tirage_pyramide.h"
#include "actions.h"
#include "gainsmanche.h"


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

    setup(piste, carte_manche, joueurs, nb_joueurs);
    setup_pari_course(pari_win, nb_joueurs);
    setup_pari_course(pari_loose, nb_joueurs);

    //placement initial des chameaux
    tirage_pyramide(pyramide);
    for(int a=0; a<5; a++)
        pos_cham[pyramide[a].couleur-1]=setup_chamal(piste, pyramide[a].couleur, pyramide[a].valeur);

    //début de la manche
    int avcnt_pyr=0;        // avancement dans la pyramide
    int player=0;           // joueur dont c'est le tour
    do
    {
        printf("\nC'est au joueur %d", player+1);
        disp_piste(piste);
        choice: switch(choix())     //choix des actions
        {
            case 1 : if(place_desert()==0)     //si action retourne 0, elle n'a pas été réalisé : il faut choisir à nouveau
                        goto choice;
                    break;
            case 2 : if(use_pyramid(piste, pos_cham, pyramide[avcnt_pyr].couleur, pyramide[avcnt_pyr].valeur)==0)
                        goto choice;
                    joueurs[player].pyra++; //gain d'une tuile pyramide
                    avcnt_pyr++;    //dé suivant
                    break;
            case 3 : if(pari_manche(carte_manche, player+1)==0)
                        goto choice;
                    break;
            case 4 : victoireoudefaite:
                    printf("\nParier sur la defaite ou la victoire ? (entrez -1 ou 1)");
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
                        default : goto victoireoudefaite;
                    }
                    break;
        }
        player=(player+1) % (nb_joueurs);
        printf("\n\n\n\n");
        /*printf("\n\nAppuyez sur Entree pour continuer");
        scanf("");*/
    }while(avcnt_pyr<4);     //tant que toute la pyramide n'a pas été utilisée

    printf("\nFin de la manche.");

    //calcule les gains de fin de manche
    gains_manche(piste, pos_cham, carte_manche, joueurs, nb_joueurs);

    for(int a=0; a<nb_joueurs; a++)
        printf("\nJoueur %d, vous avez %d livres.", a+1, joueurs[a].argent);




    return 0;
}
