#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct Element Element;
struct Element
{
    char lettre;
    int nombre;
    Element* suivant;
};

typedef struct Noeud Noeud;
struct Noeud
{
    int poids;
    char lettre;
    Noeud* droite;
    Noeud* gauche;
};

typedef struct L_Noeud L_Noeud;
struct L_Noeud
{
    Noeud* n;
    L_Noeud* suivant;
};



void trad_fichier_ascii(FILE* f);
int nombre_caractere_fich_txt(FILE* f);
Element* compter_occurrence(FILE* f);
char* binaire(char a);
void creer_liste(L_Noeud** l_nd, Element* l)
void afficherListe_Noeud(L_Noeud* liste);
void Add_Liste_Noeud(L_Noeud** l, Noeud* n);
void trie_liste(Element** liste);
void Arbre_Huff(Element* l);
void print_tree(Noeud* tree);
void creer_code(Noeud* Arbre, char* code, FILE* dico);
void print_tree(Noeud* tree);





#endif // ARBRE_H_INCLUDED