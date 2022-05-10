#include <stdio.h>
#include <stdlib.h>
#include "deplacement.h"
#include "display.h"
#include "defines.h"

int choix()
{
    int choice;
    printf("\n\nVous pouvez :");
    printf("\n\t1. Deplacer votre tuile desert");
    printf("\n\t2. Retourner la pyramide");
    printf("\n\t3. Parier sur cette manche");
    printf("\n\t4. Parier sur la course");
    do
    {
        printf("\nEntrez un nombre entre 1 et 4 pour choisir");
        scanf("%d", &choice);
    }while(choice<1 || choice>4);
    return choice;
}

int place_desert()
{
    printf("\npas encore implemente");
    return 0;
}

int use_pyramid(S_case piste[], int pos[], int couleur, int valeur)
{
    /*printf("\npas encore implemente");*/
    printf("\nLe chameau numero %d avance de %d cases", couleur, valeur);
    move_chamal(piste, pos, couleur, valeur);
    disp_piste(piste);
    return 1;
}

int pari_manche(int cartes_manche[][3],int num_joueur)
{
    int CouleurChameau;
    do{
    printf("\nSur quel chameau souhaitez vous parier? si vous souhaitez revenir au menu des choix d'action, tapez 0 ");
    scanf("%d",&CouleurChameau);
    }while(CouleurChameau<0||CouleurChameau>5);
    int i;

    if(CouleurChameau==0)
        return 0;

    for (i=0;i<3;i++)   //balaie tous les slots jusqu'à en trouver un de libre
    {
            /*if (i==3)
            {
                printf("vous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");
                return 0;
            }*/
        if (cartes_manche[CouleurChameau-1][i]==0)  //inscrit le num du joueur dans le 1er slot libre
            {
                cartes_manche[CouleurChameau-1][i]=num_joueur;
                return 1;
            }

    }
    printf("\nvous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");  //si pas de slot libre, arrive jusqu'ici
    return 0;
}

int pari_course()
{
    printf("\npas encore implemente");
    return 0;
}
