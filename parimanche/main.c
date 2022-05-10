#include <stdio.h>
#include <stdlib.h>

//pari_manche demande au joueur sur quel chameau parier (nb entre 0 et 5, 0 pour annuler), vérifie qu'il à le droit et modifie "cartes_manche" en conséquence ; renvoie 1 si il y a eu pari, 0 sinon.
// protoype :
int pari_manche(int cartes_manche[][3],int joueur);

int main()
{
    int cartes_manche[5][3];
    for(int a=0; a<5; a++)
        for(int b=0; b<3; b++)
            cartes_manche[a][b]=0;

    for(int a=1; a<=4; a++)
    {
        printf("\njoueur %d :", a);
        do{}while(pari_manche(cartes_manche, a)!=1);
    }

    return 0;
}

int pari_manche(int cartes_manche[][3],int joueur)                 //
{
    int CouleurChameau;
    do{
    printf("\nSur quel chameau souhaitez vous parier? si vous souhaitez revenir au menu des choix d'action, tapez 0 ");
    scanf("%d",&CouleurChameau);
    }while(CouleurChameau<0||CouleurChameau>5);
    int i;

    if(CouleurChameau==0)
        return 0;

    for (i=0;i<4;i++)
    {
            /*if (i==3)
            {
                printf("vous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");
                return 0;
            }*/
        if (cartes_manche[CouleurChameau-1][i]==0)
            {
                cartes_manche[CouleurChameau-1][i]=joueur;
                return 1;
            }

    }
    printf("\nvous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");
    return 0;
}
