#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

// met à 0 les variables ci-dessous
void setup(S_case piste[], S_joueur joueurs[], int nb_plyr);

// met à 0 le pari-course donné
void setup_pari_course(int cartes[][2], int nb_plyr);

// met à 0 les cartes pari-manche
void setup_pari_manche(int cartes[][3]);

#endif // SETUP_H_INCLUDED
