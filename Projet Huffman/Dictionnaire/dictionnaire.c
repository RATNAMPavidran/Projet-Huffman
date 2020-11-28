#include <stdio.h>
#include <stdlib.h>
#include "dictionnaire.h"


/**
 * \brief Function to creat  dictionary.
 * \n Example
 * \code{.c}
 *void creer_code(Noeud* Arbre, char* code, FILE* dico);
 * \endcode
 * \return
 *  \return
 *
 */
extern void creer_code(Noeud* Arbre, char* code, FILE* dico);
void creer_code(Noeud* Arbre, char* code, FILE* dico) // Création du dictionnaire ŕ partir d'un arbre donné
{
    char copie[50];

    if (Arbre != NULL)
    {
        if ((Arbre->droite == NULL) && (Arbre->gauche == NULL))  //feuille
        {
            //printf("%s est le code\n",code); 
            fprintf(dico, "%c : %s\n", Arbre->lettre, code); // écrire dans le fichier dico le chemin
        }

        else
        {
            strcpy(copie, code);          // copie = code
            strcat(code, "0");           //concaténer les contenus de deux chaînes de caractčres
            creer_code(Arbre->gauche, code, dico);         //On va ŕ gauche = 0
            strcat(copie, "1");                          // On va ŕ droite = 1
            creer_code(Arbre->droite, copie, dico);
        }
    }
}

/**
 * \brief Function to translate a chractere with the dictionary.
 * \n Example
 * \code{.c}
 *void dico_binaire(FILE* dico, char caractere, char* trad);
 * \endcode
 * \return
 *  \return
 *
 */
extern void dico_binaire(FILE* dico, char caractere, char* trad);
void dico_binaire(FILE* dico, char caractere, char* trad)// traduire un caractere en binaire ŕ partir du dico
{
    char caractereActuel;
    int i = 0;
    if (dico != NULL)
    {
        rewind(dico);  //replace le curseur au début du fichier

        //printf("%c est caractere\n", caractere);
        while (caractere != caractereActuel)      // on recherche le caractčre dans le dico
        {
            caractereActuel = fgetc(dico);
        }

        while ((caractereActuel != '0') && (caractereActuel != '1'))
        {
            caractereActuel = fgetc(dico);
        }

        do
        {

            //  printf("%c est caractere %d \n", caractereActuel, i);
             // if (caractereActuel!='\n')
             // {
            trad[i] = caractereActuel;     // on place le chiffre dans le tableau
            caractereActuel = fgetc(dico);
            //}
            i++;

        } while (caractereActuel != '\n');

        trad[i] = '\0';

        // printf("%s est le code bin", trad);
    }
}