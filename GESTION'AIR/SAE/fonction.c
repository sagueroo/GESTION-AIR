
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25


int nombre_vol(char *fichier)
{
    int result = 0;
    char ligne[MAX_LIGNE];
    FILE * fic = fopen(fichier, "r");
    if( fic == NULL)
    {
        printf("Echec ouverture fichier \n") ;
        exit(EXIT_FAILURE);
    }

    fseek(fic, 0, SEEK_SET);
    while (fgetc(fic) != '\n');


    while (fgets(ligne,MAX_LIGNE, fic) != NULL)
    {
        result++;
    }

    fclose(fic);

    return result;
}



int nombre_passagers(char *fichier, int num_vol) {
    char ligne[MAX_LIGNE];
    int passagers = 0;
    FILE * fic = fopen(fichier, "r");
    if( fic == NULL)
    {
        printf("Echec ouverture fichier \n") ;
        exit(EXIT_FAILURE);
    }

    fseek(fic, 0, SEEK_SET);
    while (fgetc(fic) != '\n');

    while (fgets(ligne,MAX_LIGNE, fic) != NULL) {

        int numeroVol;
        if (sscanf(ligne, "%d,", &numeroVol) == 1) {
            if (numeroVol == num_vol) {

                for (int i = 0; ligne[i] != '\0'; i++) {
                    if (ligne[i] == ';') {
                        passagers++;
                    }
                }
                break;
            }
        }
    }

    return passagers+1;
}




void enleve_retour_chariot(char *texte){
    int i=0;
    while((texte[i]!='\n')&&(texte[i]!='\0'))
        i++;
    if(texte[i]=='\n')
        texte[i]='\0';
}


void viderTamponEntree() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void tableau_indice(int nombrevols, int *tab_indice)
{
    for(int i =0; i<=nombrevols; i++)
        tab_indice[i]=i;
}


void trie_insertion_heure_decollage(int nb_vols,VOL *tab_vol, int *tab_indice)
{
    int i = 1;
    int petit,j;
    while(i<nb_vols)
    {
        petit = tab_indice[i];
        j = i-1;
        while((j>=0)&&(tab_vol[tab_indice[j]].heureDecollage>tab_vol[petit].heureDecollage))
        {
            tab_indice[j+1]=tab_indice[j];
            j--;
        }
        tab_indice[j+1] = petit;
        i++;
    }
}

void remplissage_moins_un(int nb_vols,int *tab){
    for(int i=0;i<nb_vols;i++)
        tab[i]=-1;

}
