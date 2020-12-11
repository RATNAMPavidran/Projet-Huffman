/*****************************************************************//**
 * \file   encodage.h
 * \brief  Header of the library allowing the management of encodage.
 *
 * \author  Mélina, Arnaud, Pavidran, Olivier, Tommy
 * \date   November 2020
 *********************************************************************/
ifndef ENCODAGE_H_INCLUDED
#define ENCODAGE_H_INCLUDED

#include "dictionnaire.h"
#include "arbre.h"

void decodage_avl(Noeud*avl);
void encodage_avl(FILE* f, Noeud*avl);

#endif // ENCODAGE_H_INCLUDED