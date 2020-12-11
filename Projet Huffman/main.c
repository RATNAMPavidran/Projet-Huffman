#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "encodage.h"
#include "dictionnaire.h"
#include <string.h>

void part1()
{
    FILE* fichier = fopen("Alice.txt", "r");

    trad_fichier_ascii(fichier);
    FILE* fichier2 = fopen("Traduction.txt", "r");
    printf("%d est le nombre binaire\n",nombre_caractere_fich_txt(fichier2));
    fclose(fichier);
    fclose(fichier2);
}

void part2()
{
    FILE* fichier = fopen("Alice.txt", "r");
    Element* lsc=malloc(sizeof(Element));


    lsc=compter_occurrence(fichier);

    if (lsc!=NULL)
    {
        trie_liste(&lsc);
        Arbre_Huff(lsc);
        rewind(fichier);
        FILE *dico = fopen("dico.txt","r");
        encodage(dico,fichier);
        fclose(dico);
    }
    else
    {
        printf("Votre fichier est vide\n");
    }

}

void part3()
{
    FILE* fichier = fopen("Alice.txt", "r");
    Noeud**tab=malloc(sizeof(Noeud*));
    tab=NULL;
    char code[30]="\0"; //CODE BINAIRE
    int taille=0;

    tab=creer_tab_occur(fichier,&taille);// Avoir la taille du tab dans le main




    if (taille!=0)
    {
        quick_sort(&tab,0,taille-1);
        Noeud *Arbre= Arb_Huff_queue(tab,taille);
        creer_code_v2(Arbre,code,tab);
        rewind(fichier);
        Noeud*avl=creer_avl(tab,taille);
        encodage_avl(fichier,avl);

        decodage_avl(avl);
        free(Arbre);
        free(avl);
    }
    else
    {
        printf("Votre fichier est vide !\n");
    }

 fclose(fichier);

}





int main()
{
    //part1();
    //part2();
   part3();

    return 0;
}
