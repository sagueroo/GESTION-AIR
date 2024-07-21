
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25



int indice_vol(VOL *tab_vol,int *tab_indice,int nb_vols, int num_vol){
    int i =0;
    while(tab_vol[tab_indice[i]].numeroVol!= num_vol){
        i++;
    }
    return i;
}


int date_vers_nombre(int nb_passager, PASSAGER tab_passager[][MAX_PASSAGER], int num_passager, int ind_vol) {
    int result;
    int annee = tab_passager[ind_vol][num_passager].date_naissance.annee;
    int mois = tab_passager[ind_vol][num_passager].date_naissance.mois;
    int jour = tab_passager[ind_vol][num_passager].date_naissance.jour;
    result = annee * 1000 + mois * 100 + jour;
    return result;
}



void trie_indirect_age(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol) {
    int i = 1, petit, j;
    while (i < nb_passager) {
        petit = tab_indice[i];
        j = i - 1;
        while ((j >= 0) && (date_vers_nombre(nb_passager,tab_passager,j,ind_vol) < date_vers_nombre(nb_passager,tab_passager,petit,ind_vol))) {
            tab_indice[j + 1] = tab_indice[j];
            j--;
        }

        tab_indice[j + 1] = petit;
        i++;
    }
}



int indice_plus_douze(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,DATE_N date_actuelle){
    int i =0;
    int date_actuelle_convert = date_actuelle.annee*1000 + date_actuelle.mois*100 + date_actuelle.jour;
    int age = date_vers_nombre(nb_passager,tab_passager,tab_indice[i],ind_vol);
    while(((date_actuelle_convert-age)/1000.0<=12)&&((date_actuelle_convert-age)/1000.0>=0)){
        i++;
        age = date_vers_nombre(nb_passager,tab_passager,tab_indice[i],ind_vol);
        }
    return i;
}



void trie_billet(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,int ind_plus_douze){
    int petit,j;
    int debut_trier = ind_plus_douze;
    while(ind_plus_douze<nb_passager){
        petit = tab_indice[ind_plus_douze];
        j = ind_plus_douze -1;
        while((j>=debut_trier)&&(tab_passager[ind_vol][tab_indice[j]].prixBillet<tab_passager[ind_vol][petit].prixBillet)){
            tab_indice[j+1]=tab_indice[j];
            j--;
        }
        tab_indice[j+1] = petit;
        ind_plus_douze++;
    }
}

void prix_identique(int nb_passager, PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice, int ind_vol, int ind_plus_douze) {
    int temp;
    for (ind_plus_douze; ind_plus_douze < nb_passager - 1; ind_plus_douze++) {
        if ((tab_passager[ind_vol][tab_indice[ind_plus_douze]].prixBillet - tab_passager[ind_vol][tab_indice[ind_plus_douze + 1]].prixBillet) <= 0.01) {
            if (strcmp(tab_passager[ind_vol][tab_indice[ind_plus_douze]].nom, tab_passager[ind_vol][tab_indice[ind_plus_douze + 1]].nom) > 0) {
                temp = tab_indice[ind_plus_douze];
                tab_indice[ind_plus_douze] = tab_indice[ind_plus_douze + 1];
                tab_indice[ind_plus_douze + 1] = temp;
            }
        }
    }
}

void affichage_passager(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol){
   printf("%-25s %-25s %-20s %-15s %-20s\n", "NOM", "PRENOM", "DATE DE NAISSANCE", "NUMERO DU SIEGE", "PRIX DU BILLET");
   printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < nb_passager; i++) {
        printf("| %-25s %-25s %02d/%02d/%d %18d %20.2f e |\n",
               tab_passager[ind_vol][tab_indice[i]].nom,
               tab_passager[ind_vol][tab_indice[i]].prenom,
               tab_passager[ind_vol][tab_indice[i]].date_naissance.jour,
               tab_passager[ind_vol][tab_indice[i]].date_naissance.mois,
               tab_passager[ind_vol][tab_indice[i]].date_naissance.annee,
               tab_passager[ind_vol][tab_indice[i]].numeroSiege,
               tab_passager[ind_vol][tab_indice[i]].prixBillet);
    }
    printf("--------------------------------------------------------------------------------------------------------");

}


