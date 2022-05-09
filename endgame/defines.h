#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

struct case_piste  {            // type structuré d'une case de la piste
                int desert;
                int cham[5];
                };
typedef struct case_piste S_case;

struct lancer_pyramide {               // type structuré pour la pyramide
                int couleur;
                int valeur;
                };
typedef struct lancer_pyramide S_pyr;

//le type S_manche gère les cartes pari-manche :
/*struct cartem {
		int R[3];	//stocke le numéro du joueur (0 si libre) qui à pris la carte du chameau rouge qui vaut 5 en carte.R[0], qui vaut 3 en carte.R[1] et qui vaut 2 en carte.R[2].
		int Y[3];
		int G[3];
		int B[3];
		int W[3];
		};
typedef struct cartem S_manche;*/

struct joueur {                 // type structuré pour le joueur
                int desert;     // positions de la tuile desert du joueur
                int argent;     // self-explanatory
                int pyra;       // nb de tuiles pyramides possédées
                int paricourse[5];  // état de chacune des cartes pari-course du joueur (ordre univ.)
                };
typedef struct joueur S_joueur;

/* couleurs définies comme tel :
    Red     1
    Yellow  2
    Green   3
    Blue    4
    White   5
*/

#endif // DEFINES_H_INCLUDED
