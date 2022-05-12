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
#include "place_desert.h"
#include "endgame.h"


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
    int pos_cham[5]= {1,2,3,4,5};       // position des chamaux (R,Y,G,B,W)

    setup(piste, joueurs, nb_joueurs);
    setup_pari_manche(carte_manche);
    setup_pari_course(pari_win, nb_joueurs);
    setup_pari_course(pari_loose, nb_joueurs);

    //placement initial des chameaux
    tirage_pyramide(pyramide);
    for(int a=0; a<5; a++)
        pos_cham[pyramide[a].couleur-1]=setup_chamal(piste, pyramide[a].couleur, pyramide[a].valeur);

    //début de la manche
    int avcnt_pyr;        // avancement dans la pyramide
    int player=0;           // joueur dont c'est le tour
    do
    {
        avcnt_pyr=0;
        tirage_pyramide(pyramide);
        do
        {
            printf("\n\n\n\n\nC'est au joueur %d\n", player+1); //appel du joueur
            disp_piste(piste);
            printf("\nParis sur la victoire :");      //affichage des paris-course
            disp_paricourse(pari_win);
            printf("\nParis sur la defaite :");
            disp_paricourse(pari_loose);
            disp_parimanche(carte_manche);
            printf("\n\nVous possedez %d livres.", joueurs[player].argent);   //affichage des données joueur
            printf("\nVous possedez %d tuiles pyramide.", joueurs[player].pyra);

            choice:
            switch(choix())     //choix des actions. Si action retourne 0, elle n'a pas été réalisé : il faut choisir à nouveau
            {
            case 1 :    /*if(*/
                place_desert(&joueurs[player].desert, piste);/*==0)*/    //pas d'annulation implémentée
                /*goto choice;*/
                disp_piste(piste);
                break;

            case 2 :
                joueurs[player].pyra++; //gain d'une tuile pyramide
                if(use_pyramid(piste, pos_cham, pyramide[avcnt_pyr].couleur, pyramide[avcnt_pyr].valeur)==0)
                    goto findelapartie;
                avcnt_pyr++;    //dé suivant
                disp_piste(piste);
                break;

            case 3 :
                if(pari_manche(carte_manche, player+1)==0)
                    goto choice;
                break;

            case 4 :
                victoireoudefaite:
                printf("\nParier sur la defaite ou la victoire ? (entrez respectivement -1 ou 1, ou 0 pour annuler)");
                int var;
                scanf("%d", &var);
                if(var==0);
                goto choice;
                switch(var)
                {
                case -1 :
                    if(pari_course(joueurs, pari_loose, player, nb_joueurs)==0)  //pari sur la défaite
                        goto choice;
                    break;
                case 1 :
                    if(pari_course(joueurs, pari_win, player, nb_joueurs)==0)   //pari sur la victoire
                        goto choice;
                    break;
                default :
                    goto victoireoudefaite;
                }
                break;
            }
            player=(player+1) % (nb_joueurs);
            /*printf("\n\nAppuyez sur Entree pour continuer");*/

        }
        while(avcnt_pyr<4);      //tant que toute la pyramide n'a pas été utilisée

        printf("\nFin de la manche.");

        //calcule les gains de fin de manche
        gains_manche(piste, pos_cham, carte_manche, joueurs, nb_joueurs);

        for(int a=0; a<nb_joueurs; a++)
            printf("\nJoueur %d, vous avez %d livres.", a+1, joueurs[a].argent);

        setup_pari_manche(carte_manche);    //remet à 0 les paris-manche

        for(int a=0; a<nb_joueurs; a++)     //remet à 0 les tuiles pyramide
        {
            joueurs[a].pyra=0;
            joueurs[a].desert=0;
        }

        for(int a=0; a<16; a++)             //remet à 0 les tuiles desert
            piste[a].desert=0;

    }
    while(1);

    findelapartie:

    printf("\n\n\nFin de la partie !");
    disp_piste(piste);

    gains_manche(piste, pos_cham, carte_manche, joueurs, nb_joueurs);

    result_course(joueurs, piste, pos_cham, pari_loose, -1);
    result_course(joueurs, piste, pos_cham, pari_win, 1);

    printf("\n\nLes scores finaux sont :");
    for(int a=0; a<nb_joueurs; a++)
            printf("\nJoueur %d a %d livres.", a+1, joueurs[a].argent);

    return 0;
}
