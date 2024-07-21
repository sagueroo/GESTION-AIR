
#include "fonction.h"
#include <windows.h>
#include <string.h>
#include "types.h"
#define chemin "../data_vols.csv"
#define MAX_PASSAGER 200
#define MAX_LIGNE 1000
#define MAX_CARACT 25


void fullscreen()       // permet de mettre le terminal en plein �cran pour pouvoir bien afficher les vols
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}



int main()
{

    //Variable g�n�ral
    int i = 0,nb_vols;
    char ligne[MAX_LIGNE];
    nb_vols = nombre_vol(chemin); //on affecte le nombre de vols � la variable nb_vols
    VOL tableau_vol[nb_vols]; //cr�ation d'un tableau de VOL de taille nombre vol
    PASSAGER tableau_passagers[nb_vols][MAX_PASSAGER]; // cr�ation d'un tableau � deux dimensions de type PASSAGER, on considerera que le nombre maximum de passagers est de 200 (peut �tre modifiable)


    //Extraction des passager
    extr_vol_passagers(chemin, tableau_vol, tableau_passagers,nb_vols,ligne);


    fullscreen(); //Met le cmd en grand �cran


    menu(nb_vols,tableau_vol,tableau_passagers);


    return 0;
}
