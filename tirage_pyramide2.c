#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines2.h"
#include "tirage_pyramide2.h"
#include "display2.h"

void shuffle(int liste[], int taille);

void tirage_pyramide(S_pyr pyramide[])
{
    int pyra[5]={1,2,3,4,5};    //tableau des couleurs

    /*for(int a=0; a<5; a++)
        printf("%d", pyra[a]);*/

    shuffle(pyra,5);    //m�lange le tab des couleurs

    for(int i=0; i<5; i++)
    {
        pyramide[i].valeur=1+(rand() % 3);  //nombre de cases � avancer (on pourrait presque se passer de la faire ici)
        pyramide[i].couleur=pyra[i];        //couleur du d�
    }
}

void shuffle(int liste[], int taille) // m�lange un tableau 'liste' de taille 'taille' al�atoirement
{
    int tmp, b;

    for(int a=taille-1; a>0; a--)
    {
        b=rand() % (a+1);
        tmp=liste[a];
        liste[a]=liste[b];
        liste[b]=tmp;

        /*printf("\n");
        for(int c=0; c<5; c++)
            printf("%d", liste[c]);*/
    }//algo de tri bas� sur le m�lange de Fischer-Yates (si je l'ai bien compris)
}
