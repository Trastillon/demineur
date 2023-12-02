#include "fct_globales.h"

/*!
 * file fct_globale.c
 * author Gadzina Guillaume
 * version 1.0
 * date 13 oct 2023
 * brief contient toutes les fonctions pouvant être utilisées dans tous les programmes
 */

int saisieEntier(){
    // Déclaration des variables
    int int_n, int_verif;
    double double_verifNonFloat;
    char *lecture; // cette variable permet de lire la saisie de l'utilisateur
    lecture=NULL;

    // Initialisation verif
    int_verif = 0;

    // allocation espace lecture
    lecture=malloc(10*sizeof(char));

    do {
        // texte pour l'utilisateur
        printf("Choisir un entier ?\n");
        // lecture données
        fgets(lecture, sizeof lecture, stdin);
        // libération la ligne qu'on vient de traiter pour pas avoir de caractères parasites pour la suite
        fflush(stdout);
        // lecture de la chaine entrée par l'utilisateur
        sscanf(lecture, "%lf", &double_verifNonFloat);

        // vérification pour controler que la valeur que l'on a dans la variable est bien celle qu'on a entré
        if (atof(lecture)!=double_verifNonFloat){
            printf("La saisie n'est pas un nombre, réessayez\n");
        } else{
            int_n=double_verifNonFloat;
            if(int_n!=double_verifNonFloat){
                printf("La sasie n'est pas un nombre entier, réessayez\n");
            } else{
                int_verif=1;
            }
        }

    } while (!int_verif);


    // libération espace pour réinitialiser le pointeur
    free(lecture);
    lecture=NULL;

    return int_n;
}

char* saisieTexte() {
    // Déclaration des variables
    char *lecture; // cette variable permet de lire la saisie de l'utilisateur
    lecture=NULL;

    // allocation espace lecture
    lecture=malloc(360*sizeof(char));

    // texte pour l'utilisateur
    printf("Entrer une chaine de caractères\n");
    // lecture données
    fgets(lecture, sizeof lecture, stdin);
    // libération la ligne qu'on vient de traiter pour pas avoir de caractères parasites pour la suite
    fflush(stdout);

    return lecture;
}

float calc_rayon(float x, float y){
    return sqrt(pow(x, 2) + pow(y, 2));
}

void affTab(int* pint_tab, int int_taille) {
    for (int i = 0; i < int_taille; ++i) {
        printf("| %d ", pint_tab[i]);
    }
    printf("|\n\n");
}

