#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------Fonction Général-------------------------------------------------------//
void extr_vol_passagers(const char *chemin, VOL *tableau_vol, PASSAGER tableau_passagers[][MAX_PASSAGER], int nb_vols,char ligne[MAX_LIGNE]);
/**
 * entrées fichier: Chemin du fichier CSV contenant les informations des vols / tableau_vol : tableau type VOL / tab_passager : Tableau de passager organisé par vol / nb_vols : int
 * pré-cond: Le fichier CSV est accessible en lecture
 * post-cond: affecte toute les informations des vols dans tableau_vol
 */

int nombre_vol(char *fichier);
/**
 * entrées fichier: Chemin du fichier CSV contenant les informations des vols
 * pré-cond: Le fichier CSV est accessible en lecture
 * sortie result: int
 * post-cond: result est le nombre de vol que possède le fichier
 */

int nombre_passagers(char *fichier, int num_vol);
/**
 * entrées fichier : Chemin du fichier CSV contenant les informations des vols / num_vol : int
 * pré-cond: Le fichier CSV est accessible en lecture
 * sortie passager : int
 * post-cond: passager est le nombre de passager que possède le vol numéro num_vol
*/


void trie_insertion_heure_decollage(int nb_vols,VOL *tab_vol,int *tab_indice);
/**
 * entrées nb_vols : int / tab_vol : tableau type VOL / tab_indice : Tableau
 * pré-cond: tab_indice doit être initialisé avec les indices 0,1,...,nb_vols-1
 * post-cond: le tableau tab_indice est trié en fonction de l'heure de decollage croissante en utilisant un tri par insertion
*/


void remplissage_moins_un(int nb_vols,int *tab);
/**
 * entrées nb_vols: int / tab : Tableau de int
 * pré-cond: tab doit avoir une taille d'au moins N
 * post-cond: Le tableau tab est rempli avec des -1
*/


void enleve_retour_chariot(char *texte);
/**
 * entrées texte : chaîne de caractère char
 * post-cond: Si la chaîne contient un caractère de retour à la ligne, il est remplacé par un caractère nul.
*/

void viderTamponEntree();
/**
 * post-cond: Le tampon d'entrée est vidé de tous les caractères jusqu'à la prochaine fin de ligne ou la fin de ficher
*/

//------------------------------------------------Fonction 0-------------------------------------------------------//
void reprogrammervol(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entrées tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de vol.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tableau_vol.
 * post-cond: Actualise les vols en retard en ajoutant la durée du retard à l'heure de décollage initiale, puis les places en état à l'heure
*/
void gestionvols(int nb_vols,VOL *tableau_vol,int *tab_indice);
/**
 * entrées  : nb_vols : int / tableau_vol : Tableau de vols / tab_indice : Tableau d'indices
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de vol.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tableau_vol.
 * post-cond: Gère l'heure de decollage d'un vol qui ne respecte pas la contrainte de sécurité
*/


void contrainte_securite(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entrées  : tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de vol.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tableau_vol.
 * post-cond: Annule les vols qui ne respectent pas la contrainte de sécurité
*/

void couvre_feu(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entrées  : tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de vol.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tableau_vol.
 * post-cond: Annule les vols qui ne respectent pas le couvre feu
*/


//------------------------------------------------Fonction 1-------------------------------------------------------//
void moins_trois_h(VOL *tab_vol,int *tab_indice,int nb_vols, int heure_actuelle);
/**
 * entrées : tab_vol : Tableau de vols / tab_indice : Tableau d'indices / nb_vols : int / heure_actuelle : int
 * post-cond : Affiche les vols dont l'heure de décollage est dans les 3 prochaines heures à partir de l'heure actuelle.
 *             Les vols sont affichés en colonnes avec des détails supplémentaires sur les horaires d'enregistrement et d'embarquement si ils sont 30mn avant et 10mn après.
 */


//------------------------------------------------Fonction 2-------------------------------------------------------//
void casse(char *chaine);
/**
 * entrées : chaine : char
 * post-cond : Modifie la chaîne de départ pour qu'elle soit tout en minuscule
 */

void recherche_compagnie(VOL *tab_vol,int nb_vols, char *nom_compagnie, int *tab_indice,int *tab_indice_recherche, int choixrecherche);
/**
 * entrées : tab_vol : Tableau de vols / nom_compagnie : char / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices / choixrecherche : int
 * post-cond : Affiche les vols de la compagnie spécifiée en colonnes avec des détails sur les horaires,
 *             les destinations, les comptoirs, les états, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stockés dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouvé, affiche un message indiquant qu'aucun résultat n'a été trouvé.
*/

void recherche_destination(VOL *tab_vol,int nb_vols, char *nom_destination, int *tab_indice,int *tab_indice_recherche, int choixrecherche);
/**
 * entrées : tab_vol : Tableau de vols / nom_destination : char / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices / choixrecherche : int
 * post-cond : Affiche les vols de la destination spécifiée en colonnes avec des détails sur les horaires,
 *             les destinations, les comptoirs, les états, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stockés dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouvé, affiche un message indiquant qu'aucun résultat n'a été trouvé.
*/

void recherche_heure_decollage(VOL *tab_vol,int nb_vols, int heure_decollage, int *tab_indice,int *tab_indice_recherche);
/**
 * entrées : tab_vol : Tableau de vols / heure_decollage : int / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices
 * post-cond : Affiche les vols de l'heure spécifiée en colonnes avec des détails sur les horaires,
 *             les destinations, les comptoirs, les états, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stockés dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouvé, affiche un message indiquant qu'aucun résultat n'a été trouvé.
*/


//------------------------------------------------Fonction 3-------------------------------------------------------//
int date_vers_nombre(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int num_passager,int ind_vol);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / num_passager : int / ind_vol : int
 * pré-cond: Les paramètres num_passager et ind_vol sont valides et représentent un passager existant dans le tableau.
 * sortie result : int
 * post-cond: Retourne un nombre entier représentant la date de naissance du passager sous la forme AAAAMMJJ.
*/

int indice_vol(VOL *tab_vol,int *tab_indice,int nb_vols, int num_vol);
/**
 * entrées tab_vol : Tableau des vols / tab_indice : Tableau d'indices / nb_vols : int / num_vol : int
 * pré-cond: Le tableau des indices (tab_indice) est trié et les numéros de vol sont uniques.
 * sortie i : int
 * post-cond: Retourne l'indice du vol dans le tableau trié d'indices
*/
void trie_indirect_age(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / tab_indice : Tableau d'indices / ind_vol : int
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de passagers.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tab_passager.
 * pré-cond: La fonction date_vers_nombre retourne une valeur numérique correcte pour la date de naissance.
 * post-cond: Les indices dans tab_indice sont réorganisés pour trier les passagers en fonction de leur âge décroissant.
*/

int indice_plus_douze(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,DATE_N date_actuelle);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / tab_indice : Tableau d'indices / ind_vol : int / date_actuelle : DATE_N
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de passagers.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tab_passager.
 * pré-cond: La fonction date_vers_nombre retourne une valeur numérique correcte pour la date de naissance.
 * sortie : i : int
 * post-cond: L'indice retourné est celui du premier passager ayant plus de 12 ans à la date actuelle.
*/
void trie_billet(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,int ind_plus_douze);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / tab_indice : Tableau d'indices / ind_vol : int / ind_plus_douze : int
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de passagers.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tab_passager.
 * pré-cond: La fonction date_vers_nombre retourne une valeur numérique correcte pour la date de naissance.
 * pré-cond: Les indices ind_vol et ind_plus_douze sont valides pour accéder aux données de tab_passager.
 * post-cond: Les indices dans tab_indice sont triés par ordre décroissant de prix du billet à partir de l'indice ind_plus_douze.
*/

void prix_identique(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,int ind_plus_douze);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / tab_indice : Tableau d'indices / ind_vol : int / ind_plus_douze : int
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de passagers.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tab_passager.
 * pré-cond: Les indices ind_vol et ind_plus_douze sont valides pour accéder aux données de tab_passager.
 * post-cond: A partir de l'indice ind_plus_douze les indices dans tab_indice sont triés par ordre décroissant de prix du billet.
*/
void affichage_passager(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol);
/**
 * entrées nb_passager : int / tab_passager : Tableau de passager organisé par vol / tab_indice : Tableau d'indices / ind_vol : int
 * pré-cond: Le tableau des indices (tab_indice) est initialisé et de même taille que le nombre total de passagers.
 * pré-cond: Les indices dans tab_indice sont valides pour accéder à tab_passager.
 * pré-cond: Les indices ind_vol et ind_plus_douze sont valides pour accéder aux données de tab_passager.
 * post-cond: Les informations des passagers sont affichées en fonction de tab_indice
*/




#endif // FONCTION_H_INCLUDED
