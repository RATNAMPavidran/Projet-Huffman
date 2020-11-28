#include <stdio.h>
#include <stdlib.h>
#include "encodage.h"

/**
 * \brief Function to encode.
 * \n Example
 * \code{.c}
 * void encodage(FILE* dico, FILE* f);
 * \endcode
 * \return
 *  \return
 *
 */
extern void encodage(FILE* dico, FILE* f);
void encodage(FILE* dico, FILE* f)   // Traduire le fichier f(texte) à partir du fichier dico dans le fichier Traduction_dico(binaire)
{
    FILE* trad = fopen("Traduction_dico.txt", "w+");
    char caractereActuel;

    if (f != NULL)
    {
        do
        {
            char traduction[50];
            caractereActuel = fgetc(f);
            if (caractereActuel != EOF)
            {
                // printf("%c est le caractere a chercher\n",caractereActuel );  
                dico_binaire(dico, caractereActuel, &traduction);   // traduction va contenir le binaire compressé
               // printf("%s est le binaire\n", traduction);

                fputs(traduction, trad);   // on écrit dans le fichier Traduction_dico
                free(traduction);
            }

        } while (caractereActuel != EOF);

        fclose(f);
    }
}