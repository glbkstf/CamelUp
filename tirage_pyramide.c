#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "tirage_pyramide.h"

/*void shuffle(int liste[], int taille);

void tirage_pyramide(S_pyr pyramide[])
{
    int pyra[5]={1,2,3,4,5};    //tableau temporaire

    shuffle(pyra,5);

    for(int i=0; i<5; i++)
    {
        pyramide[i].valeur=i + (rand() % 3) //nombre de cases à avancer (on pourrait presque se passer de la faire ici
        pyramide[i].couleur=pyra[i];        //couleur du dé
    }
}

void shuffle(int liste[], int taille) // mélange un tableau 'liste' de manière aléatoire
{
    int list[taille];
    for(int k=0; k<taille; k++) // remplit 'list' de nombres de 0 à 'taille-1'
        list[k]=k;

    for (int i = 0; i < NB_CARTES; i++) // mélange 'list' et l'affecte à 'liste'
    {
        int j = i + rand() % (taille - i);
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;

        liste[i] = list[i];

    }// shuffle algorythm by 'mob' on stack overflow: https://stackoverflow.com/a/1608254
}
*/
