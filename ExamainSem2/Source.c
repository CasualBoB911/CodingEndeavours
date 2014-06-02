#include <stdlib.h>
#include <stdio.h>
#include "head.h"
int saisi(Plaque *plaque)
{
    printf("donner l ID de la plaque");
    scanf("%d",&plaque->id);
    printf("donner l'etat de la plaque\n0-normal\n1-peu critique\n2-critique");
    scanf("%d",&plaque->etat);
}

int sauvgarde_plaque(Plaque *plaque)
{
    FILE*f;
    f=fopen("plaque.txt","a");
    if(f==NULL)
    {
        printf("impossible");
    }
    else
    {
        fprintf(f,"%d\n%d",(*plaque).id,(*plaque).etat);
        fclose(f);
    }
}
int sauvgarde_plaquebonne(Plaque *plaque)
{
    FILE*f;
    f=fopen("plaque_bonne.txt","a");
    if(f==NULL)
    {
        printf("impossible");
    }
    else
    {
        fprintf(f,"%d\n%d",(*plaque).id,(*plaque).etat);
        fclose(f);
    }
}
int sauvgarde_plaquebonne2(Plaques *plaque)
{
    FILE*f;
    f=fopen("plaque_bonne2.txt","a");
    if(f==NULL)
    {
        printf("impossible");
    }
    else
    {
        fprintf(f,"%d\n%d",(*plaque).id,(*plaque).etat);
        fclose(f);
    }
}

liste_plaque *initialiser()
{
    liste_plaque *listeplaque = malloc(sizeof(*listeplaque));
    listeplaque->first = NULL;
}

void ajoutliste(liste_plaque *listeplaque, Plaque plaque)
{
    Plaques *nouveau = malloc(sizeof(*nouveau));
    if (listeplaque == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->id = plaque->id;
    nouveau->etat = plaque->etat;
    nouveau->next = listeplaque->first;
    listeplaque->first = nouveau;
}

int lire_fichier(Plaque *plaque,liste_plaque *listeplaque)
{
        FILE*f;
    f=fopen("plaque.txt","r");
    if(f==NULL)
    {
        printf("impo");
    }
    else
    {
        while(fscanf(f,"%d\n%d",(*plaque).id,(*plaque).etat!=EOF)
        {
           ajoutliste(listeplaque,plaque);
        }
        fclose(f);
    }
}

Plaque plaquedelete(liste_plaque *listeplaque)
{
    Plaque actu;
    if (listeplaque == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Plaques *actuel = listeplaque->first;

    while (actuel != NULL)
    {

            actu.id = actuel->id;
            actu.etat=actuel->etat;
            return actu;
            listeplaque->first = listeplaque->first->next;
            actuel = actuel->next;

    }

}


void traitement(liste_plaque *listeplaque , liste_plaque *liste_fifo ,  liste_plaque *liste_lifo)
{

    Plaque actuel;
    actuel = plaquedelete(listeplaque);
    if(actuel.etat == 0){
        sauvegarde_plaquebonne(actuel)
        }
    if(actuel.etat== 1){
        ajoutliste(liste_fifo,actuel);
    }
    if(actuel.etat==2){
        ajoutliste(liste_lifo,actuel);
    }
}

void afficherfifo(liste_plaque *liste_fifo)
{
    int c;
    if (liste_fifo == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Plaques *actuel = liste_fifo->first;

    while (actuel != NULL)
    {
        printf("%d\n%d\n", actuel->id,actuel->etat);
        printf("voulez vous la faire passer a l'etat 0\n1-oui\n2-non\n");
        scanf("%d",&c);
        if(c==1){
            actuel->etat= 0;
            sauvegarde_plaquebonne2(actuel);
             liste_fifo->first = liste_fifo->first->next;
            }
            else
             actuel = actuel->next;
    }


}
