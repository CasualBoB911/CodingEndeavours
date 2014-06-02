#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int c,c2;
    Plaque plaque;
    liste_plaque *listeplaque = initialiser();
    liste_plaque *liste_fifo = initialiser();
    liste_plaque *liste_lifo = initialiser();

    do{
        printf("1-remplir le fichier plaque.txt\n");
        printf("2-remplir la liste des plaques\n");
        printf("3-afficher la liste FIFO");
        scanf("%d",&c);
    }while(c<1 || c>3);

    if(c == 1){
      do{
        saisi(&plaque);
        sauvegarde_plaque(&plaque);
        printf("voulez vous encore ajouter?\n1-oui\n2-non");
        scanf("%d",&c2);
      }while(c2=1);
        }
    if(c==2){
        lirefichier(plaque,listeplaque);
    }
    if(c==3){
        traitement(listeplaque,liste_fifo,liste_lifo);
        afficherfifo(liste_fifo);
    }



    return 0;
}
