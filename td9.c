/*!
 * file td8.c
 * author Gadzina Guillaume
 * version 1.0
 * date 27 nov 2023
 * brief main du td8, affiche un menu, lance l'exercice voulu et initialise un tab si besoin
 */

#include "fct_td9.h"


int main(int argc, char **argv){
    // Déclaration des variables
	tabJeu tab; // tab de jeu
	time_t t_debut, t_fin; // temps de début et de fin du jeu
	int int_diff; // différence de temps entre le début et la fin

	// initialisation de la seed pour pouvoir faire de l'aléatoire
	srand(time(NULL));

	printf("Choisir la taille du tableau de jeu pour le démineur\n");
	tab.taille=saisieEntier();

    do {
	    printf("Choisir le nombre de mines, doit être inférieur à %d\n", tab.taille*tab.taille);
    	tab.nbMines=saisieEntier();
    }
    while (tab.nbMines>tab.taille*tab.taille);

	tab.mat = malloc(tab.taille * sizeof(caze *));
	for (int i = 0; i < tab.taille; ++i) {
		tab.mat[i] = malloc(tab.taille * sizeof(caze));
	}
	
	// création et remplissage du tableau
	initTab(tab);
	placeMine(tab);
	compteMinesvsn(tab);

	//début de la partie
	t_debut = time(NULL);
	
	do {
		t2jeu(tab);


		if (f2jeu(tab) == pow(tab.taille, 2)-tab.nbMines){
			t_fin = time(NULL);
			int_diff=difftime(t_fin, t_debut);

			victoire(tab, int_diff);
		}
	} while(f2jeu(tab) != pow(tab.taille, 2)-tab.nbMines);


    for (int i = 0; i < tab.taille; ++i) {
	    free(tab.mat[i]);
    }
	free(tab.mat);

    printf("finito");

    return (0);
}