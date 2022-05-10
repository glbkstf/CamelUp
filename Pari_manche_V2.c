#include <stdio.h>
#include <stdlib.h>

//pari_manche demande au joueur sur quel chameau parier (nb entre 0 et 5, 0 pour annuler), vérifie qu'il à le droit et modifie "cartes_manche" en conséquence ; renvoie 1 si il y a eu pari, 0 sinon.
// protoype :
int cartes_manche[5][3];


int pari_manche(int cartes_manche[][3],int joueur)                 //
{
    int CouleurChameau;
    do{
    printf("Sur quel chameau souhaitez vous parier? si vous souhaitez rebenir au menu des choix d'action, tapez 0");
    scanf("%d",&CouleurChameau);
    }while(CouleurChameau<0||CouleurChameau>5);
int i;
for (i=0;i<4;i++)
{
        if (i==3)
        {
            printf("vous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");
            return 0;
        }
    if (cartes_manche[CouleurChameau-1][i]=0)
        {
            cartes_manche[CouleurChameau-1][i]=joueur;
            return 1;
        }

    }
}
