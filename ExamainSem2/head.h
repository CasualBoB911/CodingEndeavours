#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct Plaque Plaque;
struct Plaque
{
    int id;
    int etat;
};

typedef struct Plaques Plaques;
struct Plaques
{
    int id;
    int etat;
    Plaques *next;
};

typedef struct liste_plaque liste_plaque;
struct liste_plaque
{
    Plaques *first;
};
liste_plaque *initialiser();
int saisi(Plaque *plaque);
int sauvgarde_plaque(Plaque *plaque);
int sauvgarde_plaquebonne(Plaque *plaque);
int sauvgarde_plaquebonne2(Plaques *plaque);
void ajoutliste(liste_plaque *listeplaque, Plaque plaque);
int lire_fichier(Plaque *plaque,liste_plaque *listeplaque);
Plaque plaquedelete(liste_plaque *listeplaque);
void traitement(liste_plaque *listeplaque , liste_plaque *liste_fifo ,  liste_plaque *liste_lifo);
void afficherfifo(liste_plaque *liste_fifo);

#endif // HEAD_H_INCLUDED
