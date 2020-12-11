#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include "arbre.h"

void creer_code_v2(Noeud *Arbre, char* code,Noeud**tab);
int chercher_lettre_avl(Noeud *avl,char* code, char* lettre);


#endif // DICTIONNAIRE_H_INCLUDE
