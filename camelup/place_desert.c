#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "place_desert.h"

int place_desert(int *position, S_case piste[])
{
    //rappeler les regles de placement dans le printf

    int newposition;
    int choice_case;

    printf("Sur quelle case souhaitez vous placer votre tuile desert (entre 1 et 15) : ");
    scanf("%d", &newposition);

    //verification que la case choisie ne sors pas du plateau (case 0 exclue)
    while (newposition <1 || newposition >15)
    {
        printf("\nVotre saisie est invalide, la case ne fait pas partie du plateau. \nVotre nombre doit etre entre 1 et 15 : ");
        scanf("%d", &newposition);
    }
    printf("Que voulez faire ? Placer une case Mirage (0) ou Oasis (n'importe quel autre chiffre) : ");
    scanf("%d", &choice_case);

    //on vérifie que la case choisie ne contient pas de chameau
    if (piste[newposition].cham[0]==0)
    {

        switch(newposition)
        {
        /*verification s'il y a une case desert déjà placée avant ou après dans default
        + Cas particuliers pour case 1 et 15 où on doit vérifier seulement la case d'après (case 1) ou la case d'avant (case 15)*/
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
                printf("Que voulez faire ? Placer une case Mirage /0 ou Oasis (n'importe quel autre chiffre) ? ");
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
            if(piste[newposition].desert==0&&piste[newposition-1].desert==0&&piste[newposition+1].desert==0)
            {
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
                printf("Votre saisie est invalide, il y a une tuile desert sur la case choisie, la case d'avant ou d'apres. \nVous allez devoir ressaisir une autre case\n");
                place_desert(position, piste);
            }
            break;
        }
    }

    else
    {
        printf("Votre saisie est invalide, il y a un chameau sur cette case. \nVous allez devoir ressaisir une autre case.\n");
        place_desert(position, piste);
    }

    return 1;
}
