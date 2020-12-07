#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

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

Noeud **creer_tab_occur(FILE* f,int *taille);
L_Noeud * Tab_to_L_Noeud(Noeud ** tab , int nbre_chara_diff );
Noeud* fusionner_deux_noeuds(Noeud*n1,Noeud*n2);
Noeud ** creer_2_premiers_noeud (Noeud** tab,int* taille,FILE* f);
void quick_sort(Noeud*** tab, int debut, int fin);
void Afficher_tab(int taille, Noeud**tab);
Noeud* Arb_Huff_queue(Noeud **tab,int taille);
void free_tree(Noeud** tree);

void add_noeud_avl (Noeud**avl,Noeud*noeud);
int depth(Noeud* tree);
int bf(Noeud* tree);
void right_rotation(Noeud** tree);
void left_rotation(Noeud** tree);
void balance(Noeud** tree);
Noeud* creer_avl(Noeud**tab, int taille);

#endif // ARBRE_H_INCLUDED
