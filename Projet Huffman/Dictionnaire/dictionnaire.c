#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"

/**
 * \brief Function to creat  dictionary.
 * \n Example
 * \code{.c}
 * void creer_code_v2(Noeud *Arbre, char* code,Noeud**tab)
 * \endcode
 * \return
 *  \return
 *
 */
void creer_code_v2(Noeud *Arbre, char* code,Noeud**tab) 
{
    char copie[30]="";

    if (Arbre!=NULL)
    {
        if ((Arbre->droite==NULL)&&(Arbre->gauche==NULL))  
        {
            strcpy(Arbre->code,code);

        }
        else
        {
            strcpy(copie,code);          
            strcat(code, "0");           
            creer_code_v2(Arbre->gauche,code,(tab));   
            strcat(copie, "1");                          
            creer_code_v2(Arbre->droite,copie,(tab));
        }
    }
}


/**
 * \brief Function to translate a chractere with the AVL.
 * \n Example
 * \code{.c}
 * int chercher_lettre_avl(Noeud *avl,char* code, char* lettre);
 * \endcode
 * \return
 *  \return
 *
 */
int chercher_lettre_avl(Noeud *avl,char* code, char* lettre)
{

    if (avl!=NULL)
    {
        if (strcmp(code,avl->code)==0)
        {
            (*lettre)=avl->lettre;
            return 1;
        }
        else
        {
                return (chercher_lettre_avl(avl->gauche,code,lettre)||chercher_lettre_avl(avl->droite,code,lettre));


        }
    }
    else
        return 0;
}