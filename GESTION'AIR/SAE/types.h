#include <stdio.h>
#include <stdlib.h>
#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25

// Structure pour repr�senter la date de naissance
typedef struct {
    int jour, mois, annee;
} DATE_N;

// Structure pour repr�senter un passager
typedef struct {
    char nom[MAX_CARACT];
    char prenom[MAX_CARACT];
    DATE_N date_naissance;
    int numeroSiege;
    float prixBillet;
} PASSAGER;


// Structure pour repr�senter un vol
typedef struct {
    int numeroVol;
    char compagnie[MAX_CARACT];
    char destination[MAX_CARACT];
    int comptoirEnregistrement;
    int heureDebutEnregistrement;
    int heureFinEnregistrement;
    int salleEmbarquement;
    int heureDebutEmbarquement;
    int heureFinEmbarquement;
    int heureDecollage;
    char etatVol[MAX_CARACT]; // � l'heure, Retard� (dur�e retard), Annul�

} VOL;


#endif // TYPES_H_INCLUDED
