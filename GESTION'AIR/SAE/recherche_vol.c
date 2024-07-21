
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25


void casse(char *chaine) {
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            chaine[i] = chaine[i] + 32;
        }
        i++;
    }
}

void recherche_compagnie(VOL *tab_vol,int nb_vols, char *nom_compagnie, int *tab_indice,int *tab_indice_recherche, int choixrecherche){
   char copie_compagnie[MAX_CARACT];
   int compteur = 0,i = 0, j = 0;
   casse(nom_compagnie);
    printf("|%-12s |%-12s |%-15s |%-12s |%-12s |%-18s |%-12s|%-14s |%-14s |%-14s |%-14s\n",
           "H-VOL", "NUMERO-VOL", "NOM-COMPAGNIE", "DESTINATION", "COMPTOIR","ETAT-VOL", "SALLE-EMB", "H-DEBUT-ENR", "H-FIN-ENR", "H-DEBUT-EMB", "H-FIN-EMB");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    do {
        strcpy(copie_compagnie, tab_vol[tab_indice[i]].compagnie);
        casse(copie_compagnie);

        if ((choixrecherche == 1 && strcmp(copie_compagnie, nom_compagnie) == 0) ||
            (choixrecherche == 2 && strstr(copie_compagnie, nom_compagnie) != NULL)) {
            printf("|%-12d |%-12d |%-15s |%-12s |%-12d |%-18s |%-11d |%-14d |%-14d |%-14d |%-14d| \n",
                   tab_vol[tab_indice[i]].heureDecollage, tab_vol[tab_indice[i]].numeroVol,
                   tab_vol[tab_indice[i]].compagnie, tab_vol[tab_indice[i]].destination,
                   tab_vol[tab_indice[i]].comptoirEnregistrement, tab_vol[tab_indice[i]].etatVol,
                   tab_vol[tab_indice[i]].salleEmbarquement, tab_vol[tab_indice[i]].heureDebutEnregistrement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement, tab_vol[tab_indice[i]].heureDebutEmbarquement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement);

            *(tab_indice_recherche + j) = tab_indice[i];
            compteur++;
            j++;
        }
        i++;
    } while ((tab_indice[i] != -1) && (i < nb_vols));

    if (compteur == 0) {
        printf("La recherche a menee a aucun resultat.\n");
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void recherche_destination(VOL *tab_vol,int nb_vols, char *nom_destination, int *tab_indice,int *tab_indice_recherche, int choixrecherche){
    char copie_destination[MAX_CARACT];
    int compteur = 0, i = 0, j = 0;
    printf("|%-12s |%-12s |%-15s |%-12s |%-12s |%-18s |%-12s|%-14s |%-14s |%-14s |%-14s\n",
           "H-VOL", "NUMERO-VOL", "NOM-COMPAGNIE", "DESTINATION", "COMPTOIR","ETAT-VOL", "SALLE-EMB", "H-DEBUT-ENR", "H-FIN-ENR", "H-DEBUT-EMB", "H-FIN-EMB");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    do {

        strcpy(copie_destination, tab_vol[tab_indice[i]].destination);
        casse(copie_destination);

        if ((choixrecherche == 1 && strcmp(copie_destination, nom_destination) == 0) ||
            (choixrecherche == 2 && strstr(copie_destination, nom_destination) != NULL)) {
            printf("|%-12d |%-12d |%-15s |%-12s |%-12d |%-18s |%-11d |%-14d |%-14d |%-14d |%-14d|\n",
                   tab_vol[tab_indice[i]].heureDecollage, tab_vol[tab_indice[i]].numeroVol,
                   tab_vol[tab_indice[i]].compagnie, tab_vol[tab_indice[i]].destination,
                   tab_vol[tab_indice[i]].comptoirEnregistrement, tab_vol[tab_indice[i]].etatVol,
                   tab_vol[tab_indice[i]].salleEmbarquement, tab_vol[tab_indice[i]].heureDebutEnregistrement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement, tab_vol[tab_indice[i]].heureDebutEmbarquement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement);

            *(tab_indice_recherche + j) = tab_indice[i];
            compteur++;
            j++;
        }
        i++;
    } while ((tab_indice[i] != -1) && (i < nb_vols));

    if (compteur == 0) {
        printf("La recherche n'a donné aucun resultat.\n");
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void recherche_heure_decollage(VOL *tab_vol,int nb_vols, int heure_decollage, int *tab_indice,int *tab_indice_recherche){
    int compteur = 0,i =0,j=0;
    printf("|%-12s |%-12s |%-15s |%-12s |%-12s |%-18s |%-12s|%-14s |%-14s |%-14s |%-14s\n",
           "H-VOL", "NUMERO-VOL", "NOM-COMPAGNIE", "DESTINATION", "COMPTOIR","ETAT-VOL", "SALLE-EMB", "H-DEBUT-ENR", "H-FIN-ENR", "H-DEBUT-EMB", "H-FIN-EMB");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    do{
        if(tab_vol[tab_indice[i]].heureDecollage == heure_decollage){
            printf("|%-12d |%-12d |%-15s |%-12s |%-12d |%-18s |%-11d |%-14d |%-14d |%-14d |%-14d|\n",
                   tab_vol[tab_indice[i]].heureDecollage, tab_vol[tab_indice[i]].numeroVol,
                   tab_vol[tab_indice[i]].compagnie, tab_vol[tab_indice[i]].destination,
                   tab_vol[tab_indice[i]].comptoirEnregistrement, tab_vol[tab_indice[i]].etatVol,
                   tab_vol[tab_indice[i]].salleEmbarquement, tab_vol[tab_indice[i]].heureDebutEnregistrement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement, tab_vol[tab_indice[i]].heureDebutEmbarquement,
                   tab_vol[tab_indice[i]].heureFinEmbarquement);

            tab_indice_recherche[i]= tab_indice[i]; //nous servira si l'utilisateur voudra ajouter des criteres
            compteur++;
            j++;
        }
        i++;

        }   while((tab_indice[i]!=-1)&&(i<nb_vols));
        if(compteur==0)
            printf("La recherche a menee a aucun resultat\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}



