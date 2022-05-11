#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "place_desert.h"

/*quelle case il veut
chameau desert autour ?
mettre à 0 ancienne case
actualiser sur position joueur
*/

/*d'abord check le chameau
ensuite check si c'est pas la premiere
en fonction de ça check si case desert avant apres
demander si case mirage ou oasis
*/

int place_desert(int *position, S_case piste[])
{
    //rappeler les regles de placement dans le printf

    int newposition;
    int choice_case;

    printf("Sur quelle case souhaitez vous placer votre tuile desert (entre 1 et 15) : ");
    scanf("%d \n", &newposition);

    while (newposition <1 || newposition >15)
    {
       printf("Votre saisie est invalide, la case ne fait pas partie du plateau. \nVotre nombre doit etre entre 1 et 15 : ");
       scanf("%d \n", &newposition);
    }

    if (piste[newposition].cham[0]==0)
    {

        switch(newposition)
        {
            case 1:
                if(piste[2].desert==0)
                {
                    printf("Que voulez faire ? Placer une case Mirage (0) ou Oasis (n'importe quel autre chiffre) ? ");
                    scanf("%d", &choice_case);
                    if(choice_case==0)
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=1;
                       *position=newposition;
                    }
                    else
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=2;
                       *position=newposition;
                    }
                }
                else
                {
                    printf("Votre saisie est invalide, il y a une tuile desert sur la case numero 2. \nVous allez devoir ressaisir une autre case.");
                    place_desert(position, piste);
                }
                break;


            case 15:
                if(piste[14].desert==0)
                {
                    printf("Que voulez faire ? Placer une case Mirage (0) ou Oasis (n'importe quel autre chiffre) ? ");
                    scanf("%d", &choice_case);
                    if(choice_case==0)
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=1;
                       *position=newposition;
                    }
                    else
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=2;
                       *position=newposition;
                    }

                }
                else
                {
                    printf("Votre saisie est invalide, il y a une tuile desert sur la case numero 14. \nVous allez devoir ressaisir une autre case.");
                    place_desert(position, piste);
                }
                break;
            default:
                if(piste[newposition-1].desert==0&&piste[newposition+1].desert==0)
                {
                    printf("Que voulez faire ? Placer une case Mirage (0) ou Oasis (n'importe quel autre chiffre) ?");
                    scanf("%d", &choice_case);
                    if(choice_case==0)
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=1;
                       *position=newposition;
                    }
                    else
                    {
                       piste[*position].desert=0;
                       piste[newposition].desert=2;
                       *position=newposition;
                    }

                }
                else
                {
                    printf("Votre saisie est invalide, il y a une tuile desert sur la case d'avant ou d'apres. \nVous allez devoir ressaisir une autre case");
                    place_desert(position, piste);
                }
                break;
        }
    }
    else
    {
        printf("Votre saisie est invalide, il y a un chameau sur cette case. \nVous allez devoir ressaisir une autre case.");
        place_desert(position, piste);
    }

    return 1;
}
