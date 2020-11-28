 /*****************************************************************//**
  * \file   arbre.h
  * \brief  Header of the library allowing the management of arbre.
  *
  * \author Mélina, Arnaud, Pavidran, Olivier, Tommy
  * \date   November 2020
  *********************************************************************/
#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

 

/**
 *  \typedef struct Element
 *   \brief structure of the liste of element.
 */
typedef struct Element
{
    char lettre;
    int nombre;
    Element* suivant;
}Element;

/**
 *  \typedef struct Noeud
 *   \brief structure of the liste of noeud.
 */
typedef struct Noeud{
    int poids;
    char lettre;
    Noeud* droite;
    Noeud* gauche;
} Noeud;

/**
 *  \typedef struct Noeud
 *   \brief structure list of noeud.
 */
typedef struct L_Noeud{
    Noeud* n;
    L_Noeud* suivant;
} L_Noeud;



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
void print_tree(Noeud* tree);





#endif // ARBRE_H_INCLUDED