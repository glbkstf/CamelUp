#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

//choix de l'action à effectuer
int choix();

//actions :
/*int place_desert();*/ //dans place_desert.h

int use_pyramid(S_case piste[], int pos[], int couleur, int valeur);

int pari_manche(int cartes_manche[][3],int num_joueur);

int pari_course(S_joueur joueurs[], int pari[][2],int num_joueur, int nb_jr);

#endif // ACTIONS_H_INCLUDED
