#include "fct_td9.h"

/*!
 * file fct_td9.c
 * author Gadzina Guillaume
 * version 1.0
 * date 02 dec 2023
 * brief contient toutes les fonctions du td9
 */

void initTab(tabJeu tab) {
	for (int i = 0; i < tab.taille; i++) {
		for (int j = 0; j < tab.taille; j++) {
			tab.mat[i][j].mine = 0;
			tab.mat[i][j].visible = 0;
			tab.mat[i][j].drapeau = 0;
			tab.mat[i][j].nbMinesvoisins = 0;
		}
	}
}

void interligne(int int_taille) {
	for (int i = 0; i < int_taille; i++) {
		printf("+---");
	}
	printf("+\n");
}

void grille(tabJeu tab) {
	// variables de boucle
	int i, j;

	printf("    ");
	// nombres en haut des colonnes
	for (i = 0; i < tab.taille; i++) {
		printf("%d   ", i);
		if (i == tab.taille-1) {
			printf("\n");
		}
	}

	// affichage du tableau
	for (i = 0; i < tab.taille; i++) {
		printf("  ");
		interligne(tab.taille);
		printf("%d ", i); // nombre au début des lignes
		for (j = 0; j < tab.taille; j++) {
			printf("| ");
			// affiche si il y a un drapeau sur la case
			switch (tab.mat[i][j].drapeau) {
				case 1:
					printf("\u25BA ");
					if (j == tab.taille - 1) {
						printf("|\n");
					}
					break;
				default:

					break;
			}

			// si il n'y a pas de drapeau on vérifie le reste
			if (!tab.mat[i][j].drapeau) {
				// si là case n'est pas encore révéler
				if (!tab.mat[i][j].visible) {
					printf("\u2580 ");
				}
				else {
					// on affiche une mine si la case est révélée et en contient une
					if (tab.mat[i][j].mine) {
						printf("\u2660 ");
					}
					// sinon si il n'y a pas de mines mais qu'une case voisine en contient on affiche le nombre de mines dans les cases voisines
					else if ((!tab.mat[i][j].mine) && (tab.mat[i][j].nbMinesvoisins)) {
						printf("%d ", tab.mat[i][j].nbMinesvoisins);
					}
					// sinon on affiche un espace vide
					else {
						printf("  ");
					}
				}
			}
			if (j == tab.taille - 1) {
				printf("|\n");
			}
		}
	}
	printf("  ");
	interligne(tab.taille);
}

void placeMine(tabJeu tab){
	// déclaration des variables
	int int_lgn, int_cln, int_verif;
	// on place autant de mines que demandé par le joueur
	for (int i = 0; i < tab.nbMines; i++) {
		// on réinitialise la valeur de vérification du placement
		int_verif = 0;
		do {
			// on donne une valeur aléatoire à la ligne et à la colonne
			int_lgn = rand()%tab.taille;
			int_cln = rand()%tab.taille;
			// si il n'y a pas de mines déjà dans la case on en place une et on modifie la valeur de la vérification
			if (!tab.mat[int_lgn][int_cln].mine) {
				tab.mat[int_lgn][int_cln].mine = 1;
				int_verif = 1;
			}
		} while(!int_verif);
	}
}

void compteMinesvsn(tabJeu tab){
	// trouver les positions des mines
	for (int lgn = 0; lgn < tab.taille; lgn++) {
		for (int cln = 0; cln < tab.taille; cln++) {
			if (tab.mat[lgn][cln].mine){
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if ((lgn+i>=0) && (lgn+i<tab.taille) && (cln+j>=0) && (cln+j<tab.taille)){
							tab.mat[lgn+i][cln+j].nbMinesvoisins++;
						}
					}
				}
			}
		}
	}
}

void perdu(tabJeu tab){
	for (int i = 0; i < tab.taille; i++) {
		for (int j = 0; j < tab.taille; j++) {
			tab.mat[i][j].visible = 1;
		}
	}
	grille(tab);
	printf("Vous avez perdu :(\n");
	exit(DEFAITE);
}

void victoire(tabJeu tab, int temps) {
	printf("**********************************************************************\n***                        C'EST GAGNE                             ***\n**********************************************************************\n");
	printf("Vous avez gagné en %d secondes\n", temps);
}

void placerDrapal(tabJeu tab, int int_lgn, int int_cln) {
	if (!tab.mat[int_lgn][int_cln].drapeau){
		tab.mat[int_lgn][int_cln].drapeau=1;
	}
	else{
		tab.mat[int_lgn][int_cln].drapeau=0;
	}
}

tabJeu decouverteRec(tabJeu tab, int int_lgn, int int_cln){
	// si il y a des mines dans les cases voisines on s'arrète là
	if (tab.mat[int_lgn][int_cln].nbMinesvoisins){
		tab.mat[int_lgn][int_cln].visible++;
		return tab;
	}else {
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				// sinon si on reste dans le tableau sans être sur la même case en ajoutant +/- 1 on relance la fonction
				tab.mat[int_lgn][int_cln].visible++;
				if (int_lgn+i>=0 && int_lgn+i<tab.taille && int_cln+j>=0 && int_cln+j<tab.taille && (int_lgn+i != int_lgn && int_cln+j != int_cln) && !tab.mat[int_lgn+i][int_cln+j].visible){
					return decouverteRec(tab, int_lgn+i, int_cln+j);
				}
			}
		}
	}
}

tabJeu decouverteCase (tabJeu tab, int int_lgn, int int_cln){
	if (tab.mat[int_lgn][int_cln].mine){
		perdu(tab);
		return tab;
	}else {
		return decouverteRec(tab, int_lgn, int_cln);
	}
}

void t2jeu(tabJeu tab){
	// déclaration des variables
	int int_lgn, int_cln, int_choix;

	// choix de la case par le joueur
	do{
		grille(tab);
		printf("Choisir une case\nLigne:\n");
		int_lgn=saisieEntier();
		printf("Colonne:\n");
		int_cln=saisieEntier();
	} while (int_lgn<0 || int_lgn>tab.taille || int_cln<0 || int_cln>tab.taille);

	// choix de l'action par le joueur
	do{
		printf("Que faire à la case %d/%d :\n(1) Révéler\n(2) Placer/enlever un drapeau\n", int_lgn, int_cln);
		int_choix=saisieEntier();
	} while (int_choix<1 || int_choix>2);

	// on fait l'action choisie par le joueur
	if (int_choix == 1){
		decouverteCase(tab, int_lgn, int_cln);
	}
	else{
		placerDrapal(tab, int_lgn, int_cln);
	}
}

int f2jeu(tabJeu tab){
	int int_total=0;
	for (int i = 0; i < tab.taille; i++) {
		for (int j = 0; j < tab.taille; j++) {
			if (tab.mat[i][j].visible){
				int_total++;
			}
		}
	}
	return int_total;
}