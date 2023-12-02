/*!
 * file fct_globale.h
 * author Gadzina Guillaume
 * version 1.0
 * date 13 oct 2023
 * brief contient tous les headers des fonctions pouvant être utilisées dans tous les programmes et les commentaires décrivant les fonctions
 */

#ifndef TD7_FCT_GLOBALES_H
#define TD7_FCT_GLOBALES_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/*!
 * fn int saisieEntier(void)
 * author Gadzina Guillaume
 * version 2.0
 * date 09 nov 2023
 * brief Demande de saisir un entier et vérifie qu'il rentre une donnée valide (non char et non float)
 * retourne le nombre choisi ou exit le programme si la saisie n'est pas un entier
 */
int saisieEntier();

/*!
 * fn char* saisieTexte(void)
 * author Gadzina Guillaume
 * version 1.0
 * date 27 nov 2023
 * brief Demande de saisir une chaine de caractères
 * retourne la chaine rentrée par l'utilisateur
 */
char* saisieTexte();

/*!
 * float calc_rayon(int x, int y);
 * author Gadzina Guillaume
 * version 1.0
 * date 18 oct 2023
 * brief Calcule le rayon par rapport au point (0,0) d'un point de coordonnés (x,y)
 * param x abscisse du point
 * param y ordonnée du point
 * retourne une valeur approximative de pi
 */
float calc_rayon(float x, float y);

/*!
 * void affTab(int* pint_tab);
 * author Gadzina Guillaume
 * version 1.0
 * date 16 nov 2023
 * brief affiche un tableau dynamique
 * param pint_tab tableau dynamique à afficher
 */
void affTab(int* pint_tab, int int_taille);



#endif
