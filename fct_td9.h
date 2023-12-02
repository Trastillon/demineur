/*!
 * file fct_td9.c
 * author Gadzina Guillaume
 * version 1.0
 * date 27 nov 2023
 * brief contient tous les headers des fonctions du td9 et les commentaires décrivant les fonctions
 */

#ifndef TD9_FCT_TD9_H
#define TD9_FCT_TD9_H

#define DEFAITE 0


#include "fct_globales.h"
#include <time.h>

// structure des cases du tableau
struct caze {
 int mine; // est-ce que la case contient une mine
 int visible; // est-ce qu'on a révélé la case
 int drapeau; // est-ce qu'on a mis un drapeau sur la case
 int nbMinesvoisins; // combien il y a de mines autour de la case
};
typedef struct caze caze;

struct tabJeu {
 int taille; // taille du tableau définie par l'utilisateur
 int nbMines; // nombre de mines dans le tableau
 caze** mat; // tableau de jeu (matrice carrée)
};
typedef struct tabJeu tabJeu;

/*!
 * void initTab(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief rempli le tableau avec tout à 0
 * param tab tableau de jeu du démineur
 * rempli le tableau de 0
 */
void initTab(tabJeu tab);

/*!
 * void interligne(int int_taille)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief affiche un interligne pour le tableau
 * param int_taille taille du tableau de jeu du démineur
*/
void interligne(int int_taille);

/*!
 * void placerMine(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief place une mine dans le tableau
 * param tab tableau de jeu du démineur
*/
void placeMine(tabJeu tab);

/*!
 * void compteMinesvsn(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief compte les mines des cases adjacentes
 * param tab tableau de jeu du démineur
*/
void compteMinesvsn(tabJeu tab);

/*!
 * void perdu(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief révèle le tableau entier et écris un message pour signaler que le joueur a perdu
 * param tab tableau de jeu du démineur
*/
void perdu(tabJeu tab);

/*!
 * void grille(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief affiche le tableau de jeux avec les symboles des cases
 * param tab tableau de jeu du démineur
*/
void grille(tabJeu tab);

/*!
 * void victoire(tabJeu tab, int int_temps)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief affiche un message de victoire avec le temps de jeu qu'il a fallu pour terminer le démineur
 * param tab tableau de jeu du démineur
 * param int_temps temps passé sur le jeu
*/
void victoire(tabJeu tab, int int_temps);

/*!
 * void placerDrapal(tabJeu tab, int int_lgn, int int_cln)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief place ou enlève un drapeau à la case [int_lgn][int_cln]
 * param tab tableau de jeu du démineur
 * param int_lgn ligne où on souhaite place le drapeau
 * param int_cln colonne où on souhaite place le drapeau
*/
void placerDrapal(tabJeu tab, int int_lgn, int int_cln);

/*!
 * void decouverteRec(tabJeu tab, int int_lgn, int int_cln)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief découvre récursivement les cases selon s'il y a des mines dans les cases voisines
 * param tab tableau de jeu du démineur
 * param int_lgn ligne de la case que l'on souhaite révéler
 * param int_cln colonne de la case que l'on souhaite révéler
*/
tabJeu decouverteRec(tabJeu tab, int int_lgn, int int_cln);

/*!
 * void decouverteRec(tabJeu tab, int int_lgn, int int_cln)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief découvre la case [int_lgn][int_cln] et vérifie si le joueur a perdu sinon on découvre les cases autour récursivement.
 * param tab tableau de jeu du démineur
 * param int_lgn ligne de la case que l'on souhaite révéler
 * param int_cln colonne de la case que l'on souhaite révéler
*/
tabJeu decouverteCase (tabJeu tab, int int_lgn, int int_cln);

/*!
 * void t2jeu(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief laisse le joueur choisir son action pour le tour
 * param tab tableau de jeu du démineur
*/
void t2jeu(tabJeu tab);

/*!
 * int f2jeu(tabJeu tab)
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief compte le nombre de cases révélées
 * param tab tableau de jeu du démineur
 * Retourne le nombre de cases révélées
*/
int f2jeu(tabJeu tab);

#endif //TD9_FCT_TD9_H
