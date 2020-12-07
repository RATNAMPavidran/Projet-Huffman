#include <stdio.h>
#include <stdlib.h>

#include "encodage.h"
#include "dictionnaire.h"
#include "arbre.h"

void decodage_avl(Noeud*avl)
{
    FILE* trad = fopen("Decodage.txt","w+");
    FILE* f = fopen("Traduction_dico.txt","r");
    if (trad != NULL)
    {
        char caractereActuel;
        char* traduction=malloc(sizeof(char)*30);
        traduction[0]='\0';
        int i=0;
        char lettre='\0';
        do
        {

            caractereActuel= fgetc(f) ;

            if (caractereActuel!=EOF)
            {

                traduction[i] = caractereActuel;
                i++;
                traduction[i]='\0';
                if (chercher_lettre_avl(avl,traduction,&lettre)==1)
                {
                    fputc(lettre,trad);
                    i=0;
                    free(traduction);

                }
            }




        }while (caractereActuel!=EOF);


    }

    fclose(f);
    fclose(trad);
}
void encodage_avl(FILE* f, Noeud*avl)
{
    FILE* trad = fopen("Traduction_dico.txt","w+");
    char caractereActuel;
   // printf("ENCODAGE");
    if (f != NULL)
    {
        do
        {
            char traduction[30]="\0";
            caractereActuel = fgetc(f);
           // printf("%c est caracatere\n",caractereActuel);
           // printf("ENCODAGE");
            if (caractereActuel!=EOF)
            {
                strcpy(traduction,code_dans_avl(caractereActuel,avl));
                fputs(traduction,trad);
                free(trad);

            }

        } while (caractereActuel != EOF);

    fclose(trad);
    }

}