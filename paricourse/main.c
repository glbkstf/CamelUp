#include <stdio.h>
#include <stdlib.h>

struct joueur {                 // type structuré pour le joueur
                int desert;     // positions de la tuile desert du joueur
                int argent;     // self-explanatory
                int pyra;       // nb de tuiles pyramides possédées
                int paricourse[5];  // état de chacune des cartes pari-course du joueur (ordre univ.)
                };
typedef struct joueur S_joueur;


//pari_manche demande au joueur sur quel chameau parier (nb entre 0 et 5, 0 pour annuler), vérifie qu'il à le droit et modifie "cartes_manche" en conséquence ; renvoie 1 si il y a eu pari, 0 sinon.
// protoype :
int pari_course(S_joueur joueurs[], int pari[][2],int num_joueur, int nb_jr);

int main()
{
    int nb_joueurs=4;
    S_joueur joueurs[4];
    int pari_win[nb_joueurs*5][2];

    for(int a=0; a<nb_joueurs; a++)         //joueurs à 0
        for(int b=0; b<5; b++)
                joueurs[a].paricourse[b]=0;
    for(int a=0; a<nb_joueurs*5; a++)          //cartes à 0
        for(int b=0; b<2; b++)
            pari_win[a][b]=0;

    for(int a=1; a<=4; a++)
    {
        do{}while(pari_course(joueurs, pari_win, 1, nb_joueurs)!=1);
    }


    for(int a=0; a<nb_joueurs*5; a++)
    {
        printf("\n");
        for(int b=0; b<2; b++)
            printf("%d", pari_win[a][b]);
    }

    return 0;
}

int pari_course(S_joueur joueur[], int pari[][2],int num_joueur, int nb_jr)
{
    int CouleurChameau;
    do{
    printf("\nSur quel chameau souhaitez vous parier? si vous souhaitez revenir au menu des choix d'action, tapez 0 ");
    scanf("%d",&CouleurChameau);
    }while(CouleurChameau<0||CouleurChameau>5);

    if(CouleurChameau==0)
        return 0;

    if (joueur[num_joueur-1].paricourse[CouleurChameau-1]==1)
    {
        printf("\nvous avez deja utilise cette carte de chameau");
        return 0;
    }
    else{
            joueur[num_joueur-1].paricourse[CouleurChameau-1]=1;
            int i;
            for(i=0;i<nb_jr*5;i++)
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

