#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"


void creer_code_v2(Noeud *Arbre, char* code,Noeud**tab) // Création du dictionnaire à partir d'un arbre donné
{
    char copie[30]="";

    if (Arbre!=NULL)
    {
        if ((Arbre->droite==NULL)&&(Arbre->gauche==NULL))  //feuille
        {
            strcpy(Arbre->code,code);// ecrire le code binaire dans la struture noeud

        }
        else
        {
            strcpy(copie,code);          // copie = code
            strcat(code, "0");           //concaténer les contenus de deux chaînes de caractères
            creer_code_v2(Arbre->gauche,code,(tab));   //On va à gauche = 0
            strcat(copie, "1");                          // On va à droite = 1
            creer_code_v2(Arbre->droite,copie,(tab));
        }
    }
}



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