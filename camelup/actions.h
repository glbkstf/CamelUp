#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

//choix de l'action à effectuer
int choix();

//actions :
int place_desert();

int use_pyramid(S_case piste[], int pos[], int couleur, int valeur);

int pari_manche();

int pari_course();

#endif // ACTIONS_H_INCLUDED
