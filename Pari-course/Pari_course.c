#include <stdio.h>
#include <stdlib.h>

//pari_manche demande au joueur sur quel chameau parier (nb entre 0 et 5, 0 pour annuler), v�rifie qu'il � le droit et modifie "cartes_manche" en cons�quence ; renvoie 1 si il y a eu pari, 0 sinon.
// protoype :
int cartes_manche[5][3];


int pari_course(S_joueur joueur, int pari[][2],int num_joueur)           //
{
    int CouleurChameau;
    printf("Sur quel chameau souhaitez vous parier? si vous souhaitez rebenir au menu des choix d'action, tapez 0");
    scanf("%d",&CouleurChameau);
    if (joueur.pari[CouleurChameau-1]==1)
    {
        printf("vous avez deja utilise cette carte de chameau");
        return 0;
    }
    else{
            (*joueur).pari[CouleurChameau-1]=1;
            int i;
            for(i=0;i<nb_joueurs*5;i++)
            {
                if(pari[i][0]==0)
                {
                    pari[i][0]=num_joueur;
                    pari[i][1]=CouleurChameau;
                    return 1;
                }
            }
        }

}

/*int i;
for (i=0;i<6;i++)
{
        if (i==6)
        {
            printf("vous ne pouvez pas parier sur ce chameau: il n'y a plus de cartes");
            return 0;
        }
    if (cartes_manche[CouleurChameau-1][i]=0)
        {
            cartes_manche[CouleurChameau-1][i]=joueur;
            return 1;
        }

    }*/

