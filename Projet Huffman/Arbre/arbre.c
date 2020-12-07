#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

typedef struct Element Element;
struct Element
{
    char lettre;
    int nombre;
    Element *suivant;
};


typedef struct Noeud Noeud;
struct Noeud
{
    int poids;
    char lettre;

    char code[30];
    Noeud *droite;
    Noeud *gauche;
};


typedef struct L_Noeud L_Noeud;
struct L_Noeud
{
    Noeud* n;
    L_Noeud *suivant;
};

typedef struct Queue Queue;
struct Queue
{
    L_Noeud* liste_noeud;
};


Noeud **creer_tab_occur(FILE* f,int *taille){
             return(tab);
}

L_Noeud * Tab_to_L_Noeud(Noeud ** tab , int nbre_chara_diff ){
             return (list);
}

Noeud* fusionner_deux_noeuds(Noeud*n1,Noeud*n2){
            return (nouv_noeud);
} 


Noeud ** creer_2_premiers_noeud (Noeud** tab,int* taille,FILE* f){
            return (tab);
}
void quick_sort(Noeud*** tab, int debut, int fin){
            quick_sort(tab, debut,j-1);
            quick_sort(tab,j+1, fin);
}

void Afficher_tab(int taille, Noeud**tab){
            
}

Noeud* Arb_Huff_queue(Noeud **tab,int taille){
    return (q2->liste_noeud->n);
}

void free_tree(Noeud* tree){
}




