
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25




void moins_trois_h(VOL *tab_vol, int *tab_indice, int nb_vols, int heure_actuelle) {
    int minutes_vol, minutes_heure_actuelle, minutes_debut_enr, minutes_fin_enr,minutes_debut_emb, minutes_fin_emb;
    minutes_heure_actuelle = (heure_actuelle / 100) * 60 + (heure_actuelle % 100);


    printf("|%-8s |%-10s |%-15s |%-12s |%-18s |%-8s |%-14s |%-14s |%-11s |%-14s |%-14s\n",
       "H-VOL", "NUMERO-VOL", "NOM-COMPAGNIE", "DESTINATION", "ETAT-VOL",
       "COMPTOIR", "H-DEBUT-ENR", "H-FIN-ENR", "SALLE-EMB", "H-DEBUT-EMB", "H-FIN-EMB");

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < nb_vols; i++) {
        // Conversion des horaires en minutes
        minutes_vol = (tab_vol[tab_indice[i]].heureDecollage / 100) * 60 + (tab_vol[tab_indice[i]].heureDecollage % 100);
        minutes_debut_enr = (tab_vol[tab_indice[i]].heureDebutEnregistrement / 100) * 60 + (tab_vol[tab_indice[i]].heureDebutEnregistrement % 100);
        minutes_fin_enr = (tab_vol[tab_indice[i]].heureFinEnregistrement / 100) * 60 + (tab_vol[tab_indice[i]].heureFinEnregistrement % 100);
        minutes_debut_emb = (tab_vol[tab_indice[i]].heureDebutEmbarquement / 100) * 60 + (tab_vol[tab_indice[i]].heureDebutEmbarquement % 100);
        minutes_fin_emb = (tab_vol[tab_indice[i]].heureFinEmbarquement / 100) * 60 + (tab_vol[tab_indice[i]].heureFinEmbarquement % 100);

        if ((minutes_vol - minutes_heure_actuelle > 0) && (minutes_vol - minutes_heure_actuelle <= 180)) {
            // Affichage en colonnes
            printf("|%-8d |%-10d |%-15s |%-12s |%-18s",
            tab_vol[tab_indice[i]].heureDecollage, tab_vol[tab_indice[i]].numeroVol,
            tab_vol[tab_indice[i]].compagnie, tab_vol[tab_indice[i]].destination,
            tab_vol[tab_indice[i]].etatVol);

            if ((minutes_heure_actuelle - 30 <= minutes_debut_enr) && (minutes_heure_actuelle + 10 >= minutes_fin_enr)) {
                printf("|%-8d |%-14d |%-14d", tab_vol[tab_indice[i]].comptoirEnregistrement, tab_vol[tab_indice[i]].heureDebutEnregistrement, tab_vol[tab_indice[i]].heureFinEnregistrement);
            } else {
            printf("|%-8s |%-14s |%-14s", "", "", "");
            }

        if ((minutes_heure_actuelle - 30 <= minutes_debut_emb) && (minutes_heure_actuelle + 10 >= minutes_fin_emb)) {
            printf("|%-11d |%-14d |%-14d", tab_vol[tab_indice[i]].salleEmbarquement, tab_vol[tab_indice[i]].heureDebutEmbarquement, tab_vol[tab_indice[i]].heureFinEmbarquement);
        } else {
            printf("|%-11s |%-14s |%-14s|", "", "", "");
        }

        printf("\n");
    }
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------");

}
