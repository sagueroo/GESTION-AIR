
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25



void menu(int nb_vols,VOL tableau_vol[],PASSAGER tableau_passagers[][MAX_PASSAGER]){
    //Variable général
    int choix, tab_indice[nb_vols]; //on crée un tableau d'entiers de la taille du nombre de vol
    tableau_indice(nb_vols,tab_indice);

    //Variable 1
    int heure_actuelle;

    //Variable 2
    int choix_recherche;

    //Variable 3
    int numero_vol,ind_vol,nb_passager_vol,ind_plus_douze;
    DATE_N date_actuelle;
    int *tab_indice_passager;

    trie_insertion_heure_decollage(nb_vols,tableau_vol,tab_indice);

    do {
            printf("Bienvenue dans le projet GESTION'AIR, comment peut-on vous aider a trouver un vol\n");
            printf("0 : Mettre a jour les vols\n1 : Afficher tous les vols a un intervalle de maximales 3 heures par rapport a l'heure actuelle\n2 : Trouver des vols en fonction de la compagnie, la destination ou l'heure de decollage\n3 : Afficher les details sur une salle d'embarquement\n4 : Quitter l'application");
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix);
            viderTamponEntree();
        switch(choix){
        case 0:
            reprogrammervol(tableau_vol,nb_vols,tab_indice);
            trie_insertion_heure_decollage(nb_vols,tableau_vol,tab_indice);
            gestionvols(nb_vols,tableau_vol,tab_indice);
            contrainte_securite(tableau_vol,nb_vols,tab_indice);
            couvre_feu(tableau_vol,nb_vols,tab_indice);
            printf("|%-8s |%-10s |%-15s |%-12s |%-9s |%-11s\n","H-VOL", "NUMERO-VOL", "NOM-COMPAGNIE", "DESTINATION", "COMPTOIR","ETAT-VOL");
            printf("--------------------------------------------------------------------------\n");
            for(int i= 0;i<nb_vols;i++){
                printf("|%-8d |%-10d |%-15s |%-12s |%-9d |%-11s |\n",tableau_vol[tab_indice[i]].heureDecollage,tableau_vol[tab_indice[i]].numeroVol,tableau_vol[tab_indice[i]].compagnie,tableau_vol[tab_indice[i]].destination,tableau_vol[tab_indice[i]].comptoirEnregistrement,
                tableau_vol[tab_indice[i]].etatVol,tableau_vol[tab_indice[i]].etatVol);
            }
            printf("-----------------------------------------------------------------------");
            break;

        case 1:
                printf("Quelle heure est-il ? (format HHMM): ");
                scanf("%d",&heure_actuelle);
                viderTamponEntree();
                printf("Voici les vols a moins de 3 heures de l'heure actuelle : \n\n");
                moins_trois_h(tableau_vol,tab_indice,nb_vols,heure_actuelle);
                break;
        case 2:
            printf("Par quel critere voulez-vous faire la recherche du vol ? \n1 : Par le nom de la compagnie \n2 : Par le nom de la destination \n3 : Par l'heure de decollage\n");
            scanf("%d",&choix_recherche);
            viderTamponEntree();
            menu_choix(choix_recherche,nb_vols,tableau_vol,tab_indice);
            break;

        case 3:
                printf("Quelle est la date d'aujourd'hui (format XX XX XXXX): "  );
                scanf("%d %d %d",&(date_actuelle.jour),&(date_actuelle.mois),&(date_actuelle.annee));
                viderTamponEntree();
                printf("Pour quel vol voulez-vous afficher la salle d'embarquement : ");
                scanf("%d",&numero_vol);
                viderTamponEntree();
                ind_vol = indice_vol(tableau_vol,tab_indice,nb_vols,numero_vol);
                nb_passager_vol = nombre_passagers(chemin,numero_vol);
                tab_indice_passager = malloc(nb_passager_vol * sizeof(int));
                tableau_indice(nb_passager_vol,tab_indice_passager);
                trie_indirect_age(nb_passager_vol,tableau_passagers,tab_indice_passager,ind_vol);
                ind_plus_douze = indice_plus_douze(nb_passager_vol,tableau_passagers,tab_indice_passager,tab_indice[ind_vol],date_actuelle);
                trie_billet(nb_passager_vol,tableau_passagers,tab_indice_passager,tab_indice[ind_vol],ind_plus_douze);
                prix_identique(nb_passager_vol,tableau_passagers,tab_indice_passager,tab_indice[ind_vol],ind_plus_douze);
                printf("Salle embarquement %d pour le vol numero %d : \n", tableau_vol[tab_indice[ind_vol]].salleEmbarquement, tableau_vol[tab_indice[ind_vol]].numeroVol);
                printf("\n");
                affichage_passager(nb_passager_vol,tableau_passagers,tab_indice_passager,ind_vol);

                break;

        case 4:
            break;

        default:
            printf("Choix non valide\n");
            break;
    }
    free(tab_indice_passager);
    printf("\n");
    } while(choix != 4);
}


void menu_choix(int choix_recherche,int nb_vols, VOL tableau_vol[],int *tab_indice){
    int heure_decollage,choixrecherche,choix_recherche_plus;
    char choix_compagnie[MAX_CARACT],choix_destination[MAX_CARACT];
    int tab_indice_critere_un[nb_vols],tab_indice_critere_deux[nb_vols];
    remplissage_moins_un(nb_vols,tab_indice_critere_un); //affecte au tableau des -1 au nombres de vols

    switch(choix_recherche){
        case 1:
                    printf("Votre recherche est une :\n1- Recherche exacte\n2- Recherche approximative\n");
                    scanf("%d",&choixrecherche);
                    viderTamponEntree();
                    printf("Quelle est le nom de la compagnie :");
                    fgets(choix_compagnie,MAX_CARACT,stdin);
                    enleve_retour_chariot(choix_compagnie);
                    recherche_compagnie(tableau_vol,nb_vols,choix_compagnie,tab_indice,tab_indice_critere_un,choixrecherche);
                    printf("Voulez-vous ajoutez d'autres critere ?\n1 : Pour ajouter la destination\n2 : Pour ajouter l'heure de decollage\n0 : Pour quitter\n");
                    scanf("%d",&choix_recherche_plus);
                    viderTamponEntree();
                    if(choix_recherche_plus == 1){
                            printf("Votre recherche est une :\n1- Recherche exacte\n2- Recherche approximative\n");
                            scanf("%d",&choixrecherche);
                            viderTamponEntree();
                            printf("Quelle est le nom de la destination :");
                            fgets(choix_destination,MAX_CARACT,stdin);
                            enleve_retour_chariot(choix_destination);
                            recherche_destination(tableau_vol,nb_vols,choix_destination,tab_indice_critere_un,tab_indice_critere_deux,choixrecherche);
                    }
                    else if(choix_recherche_plus == 2){
                        printf("Quelle est l'heure de decollage (format HHMM) ? : ");
                            scanf("%d",&heure_decollage);
                            viderTamponEntree();
                            recherche_heure_decollage(tableau_vol,nb_vols,heure_decollage,tab_indice_critere_un,tab_indice_critere_deux);
                    }
                    else if(choix_recherche_plus == 0){
                        break;
                    }
                    else {
                         printf("Choix non valide");
                    }
                    break;


                case 2:
                    printf("Votre recherche est une :\n1- Recherche exacte\n2- Recherche approximative\n");
                    scanf("%d",&choixrecherche);
                    viderTamponEntree();
                    printf("Quelle est le nom de la destination :");
                    fgets(choix_destination,MAX_CARACT,stdin);
                    enleve_retour_chariot(choix_destination);
                    recherche_destination(tableau_vol,nb_vols,choix_destination,tab_indice,tab_indice_critere_un,choixrecherche);
                    printf("Voulez-vous ajoutez d'autres critere ?\n1 : Pour ajouter la compagnie\n2 : Pour ajouter l'heure de decollage\n0 : Pour quitter\n");
                    scanf("%d",&choix_recherche_plus);
                    viderTamponEntree();
                    if(choix_recherche_plus == 1){
                            printf("Votre recherche est une :\n1- Recherche exacte\n2- Recherche approximative\n");
                            scanf("%d",&choixrecherche);
                            viderTamponEntree();
                            printf("Quelle est le nom de la compagnie :");
                            fgets(choix_compagnie,MAX_CARACT,stdin);
                            enleve_retour_chariot(choix_compagnie);
                            recherche_compagnie(tableau_vol,nb_vols,choix_compagnie,tab_indice_critere_un,tab_indice_critere_deux,choixrecherche);
                            break;
                    }
                    else if(choix_recherche_plus == 2){
                            printf("Quelle est l'heure de decollage (format HHMM) ? : ");
                            scanf("%d",&heure_decollage);
                            viderTamponEntree();
                            recherche_heure_decollage(tableau_vol,nb_vols,heure_decollage,tab_indice_critere_un,tab_indice_critere_deux);
                            break;
                    }
                    else {
                        printf("Choix non valide");
                    }
                   break;

                case 3:
                    printf("Quelle est l'heure de decollage (format HHMM) ? : ");
                    scanf("%d",&heure_decollage);
                    viderTamponEntree();
                    recherche_heure_decollage(tableau_vol,nb_vols,heure_decollage,tab_indice,tab_indice_critere_un);
                    break;
                } // pas besoin de mettre d'autres criteres car il n'y aura qu'un seul resultat

}




