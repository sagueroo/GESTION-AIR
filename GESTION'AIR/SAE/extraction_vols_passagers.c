
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25



void extr_vol_passagers(const char *chemin, VOL *tableau_vol, PASSAGER tableau_passagers[][MAX_PASSAGER], int nb_vols,char ligne[MAX_LIGNE]) {
    int nb_passager;
    FILE *fic = fopen(chemin, "r");
    if (fic == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
    }

    else {
    fseek(fic, 0, SEEK_SET);
    while (fgetc(fic) != '\n'); // Saut de l'en-tête du fichier

    int i = 0;
    do {
        fscanf(fic, "%d,%25[^,],%25[^,],%d,%d,%d,%d,%d,%d,%d,%25[^,],\"",
            &(tableau_vol[i].numeroVol), tableau_vol[i].compagnie, tableau_vol[i].destination,
            &(tableau_vol[i].comptoirEnregistrement), &(tableau_vol[i].heureDebutEnregistrement),
            &(tableau_vol[i].heureFinEnregistrement), &(tableau_vol[i].salleEmbarquement),
            &(tableau_vol[i].heureDebutEmbarquement), &(tableau_vol[i].heureFinEmbarquement),
            &(tableau_vol[i].heureDecollage), tableau_vol[i].etatVol);

        nb_passager = nombre_passagers(chemin, tableau_vol[i].numeroVol);

        for (int j = 0; j < nb_passager; j++) {
            if (j == nb_passager - 1) {
                fscanf(fic, "%25[^,],%25[^,],%d/%d/%d,%d,%f", tableau_passagers[i][j].nom,
                    tableau_passagers[i][j].prenom, &(tableau_passagers[i][j].date_naissance.jour),
                    &(tableau_passagers[i][j].date_naissance.mois), &(tableau_passagers[i][j].date_naissance.annee),
                    &(tableau_passagers[i][j].numeroSiege), &(tableau_passagers[i][j].prixBillet));
            } else {
                fscanf(fic, "%25[^,],%25[^,],%d/%d/%d,%d,%f;", tableau_passagers[i][j].nom,
                    tableau_passagers[i][j].prenom, &(tableau_passagers[i][j].date_naissance.jour),
                    &(tableau_passagers[i][j].date_naissance.mois), &(tableau_passagers[i][j].date_naissance.annee),
                    &(tableau_passagers[i][j].numeroSiege), &(tableau_passagers[i][j].prixBillet));
            }
        }
        fgets(ligne, MAX_LIGNE, fic);
        i++;
    } while (i != nb_vols);
    }

    fclose(fic);
}
