#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------Fonction G�n�ral-------------------------------------------------------//
void extr_vol_passagers(const char *chemin, VOL *tableau_vol, PASSAGER tableau_passagers[][MAX_PASSAGER], int nb_vols,char ligne[MAX_LIGNE]);
/**
 * entr�es fichier: Chemin du fichier CSV contenant les informations des vols / tableau_vol : tableau type VOL / tab_passager : Tableau de passager organis� par vol / nb_vols : int
 * pr�-cond: Le fichier CSV est accessible en lecture
 * post-cond: affecte toute les informations des vols dans tableau_vol
 */

int nombre_vol(char *fichier);
/**
 * entr�es fichier: Chemin du fichier CSV contenant les informations des vols
 * pr�-cond: Le fichier CSV est accessible en lecture
 * sortie result: int
 * post-cond: result est le nombre de vol que poss�de le fichier
 */

int nombre_passagers(char *fichier, int num_vol);
/**
 * entr�es fichier : Chemin du fichier CSV contenant les informations des vols / num_vol : int
 * pr�-cond: Le fichier CSV est accessible en lecture
 * sortie passager : int
 * post-cond: passager est le nombre de passager que poss�de le vol num�ro num_vol
*/


void trie_insertion_heure_decollage(int nb_vols,VOL *tab_vol,int *tab_indice);
/**
 * entr�es nb_vols : int / tab_vol : tableau type VOL / tab_indice : Tableau
 * pr�-cond: tab_indice doit �tre initialis� avec les indices 0,1,...,nb_vols-1
 * post-cond: le tableau tab_indice est tri� en fonction de l'heure de decollage croissante en utilisant un tri par insertion
*/


void remplissage_moins_un(int nb_vols,int *tab);
/**
 * entr�es nb_vols: int / tab : Tableau de int
 * pr�-cond: tab doit avoir une taille d'au moins N
 * post-cond: Le tableau tab est rempli avec des -1
*/


void enleve_retour_chariot(char *texte);
/**
 * entr�es texte : cha�ne de caract�re char
 * post-cond: Si la cha�ne contient un caract�re de retour � la ligne, il est remplac� par un caract�re nul.
*/

void viderTamponEntree();
/**
 * post-cond: Le tampon d'entr�e est vid� de tous les caract�res jusqu'� la prochaine fin de ligne ou la fin de ficher
*/

//------------------------------------------------Fonction 0-------------------------------------------------------//
void reprogrammervol(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entr�es tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de vol.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tableau_vol.
 * post-cond: Actualise les vols en retard en ajoutant la dur�e du retard � l'heure de d�collage initiale, puis les places en �tat � l'heure
*/
void gestionvols(int nb_vols,VOL *tableau_vol,int *tab_indice);
/**
 * entr�es  : nb_vols : int / tableau_vol : Tableau de vols / tab_indice : Tableau d'indices
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de vol.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tableau_vol.
 * post-cond: G�re l'heure de decollage d'un vol qui ne respecte pas la contrainte de s�curit�
*/


void contrainte_securite(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entr�es  : tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de vol.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tableau_vol.
 * post-cond: Annule les vols qui ne respectent pas la contrainte de s�curit�
*/

void couvre_feu(VOL *tableau_vol, int nb_vols,int *tab_indice);
/**
 * entr�es  : tableau_vol : Tableau de vols / nb_vols : int / tab_indice : Tableau d'indices
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de vol.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tableau_vol.
 * post-cond: Annule les vols qui ne respectent pas le couvre feu
*/


//------------------------------------------------Fonction 1-------------------------------------------------------//
void moins_trois_h(VOL *tab_vol,int *tab_indice,int nb_vols, int heure_actuelle);
/**
 * entr�es : tab_vol : Tableau de vols / tab_indice : Tableau d'indices / nb_vols : int / heure_actuelle : int
 * post-cond : Affiche les vols dont l'heure de d�collage est dans les 3 prochaines heures � partir de l'heure actuelle.
 *             Les vols sont affich�s en colonnes avec des d�tails suppl�mentaires sur les horaires d'enregistrement et d'embarquement si ils sont 30mn avant et 10mn apr�s.
 */


//------------------------------------------------Fonction 2-------------------------------------------------------//
void casse(char *chaine);
/**
 * entr�es : chaine : char
 * post-cond : Modifie la cha�ne de d�part pour qu'elle soit tout en minuscule
 */

void recherche_compagnie(VOL *tab_vol,int nb_vols, char *nom_compagnie, int *tab_indice,int *tab_indice_recherche, int choixrecherche);
/**
 * entr�es : tab_vol : Tableau de vols / nom_compagnie : char / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices / choixrecherche : int
 * post-cond : Affiche les vols de la compagnie sp�cifi�e en colonnes avec des d�tails sur les horaires,
 *             les destinations, les comptoirs, les �tats, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stock�s dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouv�, affiche un message indiquant qu'aucun r�sultat n'a �t� trouv�.
*/

void recherche_destination(VOL *tab_vol,int nb_vols, char *nom_destination, int *tab_indice,int *tab_indice_recherche, int choixrecherche);
/**
 * entr�es : tab_vol : Tableau de vols / nom_destination : char / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices / choixrecherche : int
 * post-cond : Affiche les vols de la destination sp�cifi�e en colonnes avec des d�tails sur les horaires,
 *             les destinations, les comptoirs, les �tats, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stock�s dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouv�, affiche un message indiquant qu'aucun r�sultat n'a �t� trouv�.
*/

void recherche_heure_decollage(VOL *tab_vol,int nb_vols, int heure_decollage, int *tab_indice,int *tab_indice_recherche);
/**
 * entr�es : tab_vol : Tableau de vols / heure_decollage : int / tab_indice : Tableau d'indices / tab_indice_recherche : Tableau d'indices
 * post-cond : Affiche les vols de l'heure sp�cifi�e en colonnes avec des d�tails sur les horaires,
 *             les destinations, les comptoirs, les �tats, les salles d'embarquement, et les plages horaires
 *             d'enregistrement et d'embarquement. Les indices des vols correspondants sont stock�s dans le tableau tab_indice_recherche.
 *             Si aucun vol n'est trouv�, affiche un message indiquant qu'aucun r�sultat n'a �t� trouv�.
*/


//------------------------------------------------Fonction 3-------------------------------------------------------//
int date_vers_nombre(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int num_passager,int ind_vol);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / num_passager : int / ind_vol : int
 * pr�-cond: Les param�tres num_passager et ind_vol sont valides et repr�sentent un passager existant dans le tableau.
 * sortie result : int
 * post-cond: Retourne un nombre entier repr�sentant la date de naissance du passager sous la forme AAAAMMJJ.
*/

int indice_vol(VOL *tab_vol,int *tab_indice,int nb_vols, int num_vol);
/**
 * entr�es tab_vol : Tableau des vols / tab_indice : Tableau d'indices / nb_vols : int / num_vol : int
 * pr�-cond: Le tableau des indices (tab_indice) est tri� et les num�ros de vol sont uniques.
 * sortie i : int
 * post-cond: Retourne l'indice du vol dans le tableau tri� d'indices
*/
void trie_indirect_age(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / tab_indice : Tableau d'indices / ind_vol : int
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de passagers.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tab_passager.
 * pr�-cond: La fonction date_vers_nombre retourne une valeur num�rique correcte pour la date de naissance.
 * post-cond: Les indices dans tab_indice sont r�organis�s pour trier les passagers en fonction de leur �ge d�croissant.
*/

int indice_plus_douze(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,DATE_N date_actuelle);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / tab_indice : Tableau d'indices / ind_vol : int / date_actuelle : DATE_N
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de passagers.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tab_passager.
 * pr�-cond: La fonction date_vers_nombre retourne une valeur num�rique correcte pour la date de naissance.
 * sortie : i : int
 * post-cond: L'indice retourn� est celui du premier passager ayant plus de 12 ans � la date actuelle.
*/
void trie_billet(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,int ind_plus_douze);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / tab_indice : Tableau d'indices / ind_vol : int / ind_plus_douze : int
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de passagers.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tab_passager.
 * pr�-cond: La fonction date_vers_nombre retourne une valeur num�rique correcte pour la date de naissance.
 * pr�-cond: Les indices ind_vol et ind_plus_douze sont valides pour acc�der aux donn�es de tab_passager.
 * post-cond: Les indices dans tab_indice sont tri�s par ordre d�croissant de prix du billet � partir de l'indice ind_plus_douze.
*/

void prix_identique(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol,int ind_plus_douze);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / tab_indice : Tableau d'indices / ind_vol : int / ind_plus_douze : int
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de passagers.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tab_passager.
 * pr�-cond: Les indices ind_vol et ind_plus_douze sont valides pour acc�der aux donn�es de tab_passager.
 * post-cond: A partir de l'indice ind_plus_douze les indices dans tab_indice sont tri�s par ordre d�croissant de prix du billet.
*/
void affichage_passager(int nb_passager,PASSAGER tab_passager[][MAX_PASSAGER], int *tab_indice,int ind_vol);
/**
 * entr�es nb_passager : int / tab_passager : Tableau de passager organis� par vol / tab_indice : Tableau d'indices / ind_vol : int
 * pr�-cond: Le tableau des indices (tab_indice) est initialis� et de m�me taille que le nombre total de passagers.
 * pr�-cond: Les indices dans tab_indice sont valides pour acc�der � tab_passager.
 * pr�-cond: Les indices ind_vol et ind_plus_douze sont valides pour acc�der aux donn�es de tab_passager.
 * post-cond: Les informations des passagers sont affich�es en fonction de tab_indice
*/




#endif // FONCTION_H_INCLUDED
