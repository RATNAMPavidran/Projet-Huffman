#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

Noeud **creer_tab_occur(FILE* f,int *taille);
L_Noeud * Tab_to_L_Noeud(Noeud ** tab , int nbre_chara_diff );
Noeud* fusionner_deux_noeuds(Noeud*n1,Noeud*n2);
Noeud ** creer_2_premiers_noeud (Noeud** tab,int* taille,FILE* f);
void quick_sort(Noeud*** tab, int debut, int fin);
void Afficher_tab(int taille, Noeud**tab);
Noeud* Arb_Huff_queue(Noeud **tab,int taille);
void free_tree(Noeud** tree);

#endif // ARBRE_H_INCLUDED
