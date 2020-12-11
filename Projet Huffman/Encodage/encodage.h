ifndef ENCODAGE_H_INCLUDED
#define ENCODAGE_H_INCLUDED

#include "encodage.h"
#include "dictionnaire.h"
#include "arbre.h"

void decodage_avl(Noeud*avl);
void encodage_avl(FILE* f, Noeud*avl);

#endif // ENCODAGE_H_INCLUDED