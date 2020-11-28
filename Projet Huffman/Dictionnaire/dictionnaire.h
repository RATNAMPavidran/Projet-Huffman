#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include "arbre.h"

void creer_code(Noeud* Arbre, char* code, FILE* dico);

void dico_binaire(FILE* dico, char caractere, char* trad);