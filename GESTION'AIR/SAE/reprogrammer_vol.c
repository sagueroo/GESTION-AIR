
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25


void reprogrammervol(VOL *tableau_vol, int nb_vols,int *tab_indice) {
    int i,dureeRetard,heures,minutes,nouvelleHeureDecollage;
    for (i = 0; i < nb_vols; i++) {
        if ((strcmp(tableau_vol[tab_indice[i]].etatVol, "A l'heure") != 0)&&(strcmp(tableau_vol[tab_indice[i]].etatVol,"Annule")!=0)) {
            sscanf(tableau_vol[tab_indice[i]].etatVol, "Retarde (%d min)", &dureeRetard);
            heures = (tableau_vol[tab_indice[i]].heureDecollage + dureeRetard)/100;
            minutes = (tableau_vol[tab_indice[i]].heureDecollage + dureeRetard)%100;
            heures = heures + minutes/60;
            minutes = minutes%60;
            heures = heures%24;
            nouvelleHeureDecollage = heures*100+minutes;
            tableau_vol[tab_indice[i]].heureDecollage = nouvelleHeureDecollage;
            strcpy(tableau_vol[tab_indice[i]].etatVol, "A l'heure");



        }
    }
}

void gestionvols(int nb_vols,VOL *tableau_vol,int *tab_indice) {
    int heures,minutes;
    for (int i = 0; i < nb_vols - 1; i++) {
        while (tableau_vol[tab_indice[i + 1]].heureDecollage - tableau_vol[tab_indice[i]].heureDecollage < 5) {
            // Ajuster l'heure de départ du vol en retard
            tableau_vol[tab_indice[i]].heureDecollage = tableau_vol[tab_indice[i + 1]].heureDecollage + 5;
            // Conversion des minutes dépassant 60
            heures = tableau_vol[tab_indice[i]].heureDecollage / 100;
            minutes = tableau_vol[tab_indice[i]].heureDecollage % 100;
            heures = heures + minutes / 60;
            minutes = minutes % 60;
            heures = heures % 24;
            tableau_vol[tab_indice[i]].heureDecollage = heures * 100 + minutes;
            trie_insertion_heure_decollage(nb_vols,tableau_vol,tab_indice);
            i++;
        }
    }
}


void contrainte_securite(VOL *tableau_vol, int nb_vols, int *tab_indice) {
    int heures_actuel,minutes_actuel,heures_suivant,minutes_suivant,ecart_minutes;
    for (int i = 0; i < nb_vols - 1; i++) {
        if (strcmp(tableau_vol[tab_indice[i]].etatVol, "Annule") == 0) {
            continue;
        }
        heures_actuel = tableau_vol[tab_indice[i]].heureDecollage / 100;
        minutes_actuel = tableau_vol[tab_indice[i]].heureDecollage % 100;

        for (int j = i+1; j < nb_vols; j++) {
            if (strcmp(tableau_vol[tab_indice[j]].etatVol, "Annule") == 0) {
                continue;
            }
            heures_suivant = tableau_vol[tab_indice[j]].heureDecollage / 100;
            minutes_suivant = tableau_vol[tab_indice[j]].heureDecollage % 100;
            ecart_minutes = (heures_suivant - heures_actuel) * 60 + (minutes_suivant - minutes_actuel);
            if (ecart_minutes < 5) {
                strcpy(tableau_vol[tab_indice[i]].etatVol, "Annule");


            }
        }
    }
}

void couvre_feu(VOL *tableau_vol, int nb_vols,int *tab_indice){
    for (int i = 0; i < nb_vols - 1; i++) {
          if (tableau_vol[tab_indice[i]].heureDecollage < 600 || tableau_vol[tab_indice[i]].heureDecollage > 2200) {
            printf("Vol %d annulé en raison du couvre-feu.\n", tableau_vol[tab_indice[i]].numeroVol);
            strcpy(tableau_vol[tab_indice[i]].etatVol, "Annule");
    }
}
}




