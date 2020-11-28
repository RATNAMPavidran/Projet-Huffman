/*****************************************************************//**
 * \file   dictionnaire.H
 * \brief  Header of the library allowing the management of dictionnaire.
 *
 * \author  Mélina, Arnaud, Pavidran, Olivier, Tommy
 * \date   November 2020
 *********************************************************************/


#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include "arbre.h"

void creer_code(Noeud* Arbre, char* code, FILE* dico);

void dico_binaire(FILE* dico, char caractere, char* trad);
