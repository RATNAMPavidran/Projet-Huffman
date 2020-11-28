#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"


/**
 * \brief Function to translate ascci files.
 * \n Example
 * \code{.c}
 * void trad_fichier_ascii(FILE* f);
 * \endcode
 * \return 
 *  \return 
 *
 */
extern void trad_fichier_ascii(FILE* f);
void trad_fichier_ascii(FILE* f)
{
    FILE* trad = fopen("Traduction.txt", "w+");
    char caractereActuel;
    char* traduction = malloc(9);
    if (f != NULL)
    {
        do
        {
            caractereActuel = fgetc(f); // on récupère un caractère du fichier

            traduction = binaire(caractereActuel);  // on traduit en binaire
            if (caractereActuel != -1)              //c'est EOF mais correspond sur certaines machines a -1
                fputs(traduction, trad);          // ecrit dans le fichier
            free(traduction);
        } while (caractereActuel != EOF);

        fclose(f);
    }

}
/**
 * \brief Function to convert number to binary.
 * \n Example
 * \code{.c}
 * char* binaire(char a);
 * \endcode
 * \return if the character is not none, we generate the  binary convesion of the charactere.
 *  \return \c NULL, if the charactere is none.
 *
 */
extern char* binaire(char a);
char* binaire(char a)            //Convertie les lettres en binaire
{
    int i = 0;
    char* octet = malloc(9);
    for (i = 0; i < 8; i++)
    {
        int puissance = 1;
        for (int p = 7 - i; p > 0; p--)     //On commence par 2^7 jusqu'a 2^1
        {
            puissance = 2 * puissance;    // puissance de 2
        }

        if (a - puissance >= 0)          //Si la valeur ASCII - la puissance est positif ou = 0 (ex : cas du 2^0-1) on a 1
        {
            a = a - puissance;
            octet[i] = '1';
        }
        else
            octet[i] = '0';
    }
    octet[8] = '\0';

    return octet;
}
/**
 * \brief Function to convert number to binary.
 * \n Example
 * \code{.c}
 * char* binaire(char a);
 * \endcode
 * \return if the character is not none, we generate the  binary convesion of the charactere.
 *  \return \c NULL, if the charactere is none.
 *
 */
extern char* binaire(char a);
int nombre_caractere_fich_txt(FILE* f)
{
    int nombre = -1; // on enleve le NULL à la fin du texte 
    char caractereActuel;
    do
    {
        caractereActuel = fgetc(f);
        nombre++;

    } while (caractereActuel != EOF);

    return nombre;
}
/**
 * \brief Function to count occurence of a charactere.
 * \n Example
 * \code{.c}
 * Element* compter_occurrence(FILE* f);
 * \endcode
 * \return we retrun a list of all the charactere with their occurnece.
 *  \return \c NULL, if the file is none.
 *
 */
extern Element* compter_occurrence(FILE* f);
Element* compter_occurrence(FILE* f)
{
    Element* lsc;
    lsc = malloc(sizeof(Element));
    char lettre;


    if (f != NULL)
    {
        lettre = fgetc(f);          //On stock la 1 ere lettre dans la structure
        lsc->lettre = lettre;
        lsc->nombre = 1;
        lsc->suivant = NULL;
        do
        {

            lettre = fgetc(f);           // on stock le caractère suiv
            Element* temp = lsc;           // on recommence pour la boucle
            int trouve = 0;
            if (lettre != -1)             // Différent de la fin, c'est EOF mais correspond sur certaines machines a -1
            {
                while ((temp != NULL) && trouve != 1)
                {
                    if (lettre == temp->lettre)  // CAS ou on a déja rencontré le caractère
                    {
                        temp->nombre++;
                        trouve = 1;
                    }
                    temp = temp->suivant;
                }

                if (trouve == 0)              // CAS ou on a jamais encore rencontrer le caractere
                {
                    temp = lsc;
                    Element* nouveau = malloc(sizeof(Element));

                    while (temp->suivant != NULL)    // arrive jusqu'à la fin pour ajouter le nv caractère à la liste
                    {
                        temp = temp->suivant;
                    }
                    nouveau->lettre = lettre;
                    nouveau->nombre = 1;
                    nouveau->suivant = NULL;

                    temp->suivant = nouveau;
                }
            }

        } while (lettre != EOF);
    }
    //afficherListe(lsc);
    return lsc;
}
/**
 * \brief Function to print a list of element.
 * \n Example
 * \code{.c}
 * void afficherListe(Element* liste);
 * \endcode
 * \return 
 *  \return 
 *
 */
extern afficherListe(Element* liste);
void afficherListe(Element* liste)
{
    Element* temp = liste;

    while (temp != NULL)
    {
        printf("'%c' = ", temp->lettre);
        printf("%d -> ", temp->nombre);
        temp = temp->suivant;
    }
    printf("NULL\n");
}
/**
 * \brief Function  to creat  a list of noeud.
 * \n Example
 * \code{.c}
 * void creer_liste(L_Noeud** l_nd, Element* l);
 * \endcode
 * \return
 *  \return 
 *
 */
extern creer_liste(L_Noeud** l_nd, Element* l);
void creer_liste(L_Noeud** l_nd, Element* l) // CREER une liste de noeuds
{
    Element* lect = l; //lect pour lecture
    L_Noeud* temp = *l_nd; // l_nd liste de noeud  pour parcourir la liste de noeud

    Noeud* n = malloc(sizeof(Noeud));

    n->poids = lect->nombre;     // convertir les informations de la liste en noeud
    n->lettre = lect->lettre;
    n->gauche = NULL;
    n->droite = NULL;
    //printf("%c est tara\n",n->lettre);

    temp->n = n;                // premier noeud de la liste de noeud
    lect = lect->suivant;
    //printf("%c est la lettre lue\n",lect->lettre);

    while (lect != NULL)       //tant que liste != NULL
    {
        L_Noeud* nouv_el = malloc(sizeof(L_Noeud));        //création de liste de noeud
        Noeud* n = malloc(sizeof(Noeud));                //création du noeud

        n->poids = lect->nombre;
        n->lettre = lect->lettre;
        n->gauche = NULL;
        n->droite = NULL;
        //printf("%c",n->lettre);

        nouv_el->n = n;
        //printf("%c est le cara\n",temp->n->lettre);
        temp->suivant = nouv_el;

        lect = lect->suivant;

        temp = temp->suivant;
    }

    temp->suivant = NULL;
}
/**
 * \brief Function  to print  a list of noeud.
 * \n Example
 * \code{.c}
 * void afficherListe_Noeud(L_Noeud* liste);
 * \endcode
 * \return
 *  \return
 *
 */
extern void afficherListe_Noeud(L_Noeud* liste);
void afficherListe_Noeud(L_Noeud* liste)
{
    L_Noeud* temp = liste;
    printf("VOICI la liste des noeuds : \n");
    while (temp != NULL)
    {
        printf("'%c' = ", temp->n->lettre);
        printf("%d -> ", temp->n->poids);
        temp = temp->suivant;
        //printf("FAIT\n");
    }
    printf("NULL\n");
}
/**
 * \brief Function  to add  a node to a  list of node.
 * \n Example
 * \code{.c}
 * void Add_Liste_Noeud(L_Noeud** l, Noeud* n);
 * \endcode
 * \return
 *  \return
 *
 */
extern void Add_Liste_Noeud(L_Noeud** l, Noeud* n);
void Add_Liste_Noeud(L_Noeud** l, Noeud* n)  // Ajouter n dans la liste de noeud (avec n noeud contenant le poid de de noeud + ces noeuds en enfant)
{
    L_Noeud* temp = *l;
    int trie = 0;
    //on compare le poid de n avec la liste de noeud
    if (n->poids < temp->n->poids) //ajoute element au debut de la liste
    {
        L_Noeud* swap = malloc(sizeof(L_Noeud)); // allouer le nouvel element
        swap->n = n;
        swap->suivant = temp;
        *l = swap;
        trie = 1;
    }

    else
    {
        while ((temp->suivant != NULL) && (trie == 0))// milieu de liste
        {
            //  printf("%d est le poids ",n->poids);
            //  printf("%d est le poids a comparer \n",temp->suivant->n->poids);
            if (n->poids < (temp->suivant->n->poids))
            {
                L_Noeud* swap = malloc(sizeof(L_Noeud));
                swap->n = n;

                //     printf("%c est la caractere a ajouter",swap->n->lettre);
                swap->suivant = temp->suivant;
                temp->suivant = swap;
                trie = 1;
            }

            else
                temp = temp->suivant;
        }

        if (temp->suivant == NULL) // Add l'element en fin de liste
        {
            L_Noeud* swap = malloc(sizeof(L_Noeud));
            swap->n = n;

            temp->suivant = swap;
            swap->suivant = NULL;
        }
    }
}
/**
 * \brief Function  to sort a list.
 * \n Example
 * \code{.c}
 * void trie_liste(Element** liste);
 * \endcode
 * \return
 *  \return
 *
 */
extern void trie_liste(Element** liste);
void trie_liste(Element** liste) {
    Element* temp = *liste;
    int boucle;
    int permut_nbr;
    char permut_char;

    if (temp == NULL) {
        return;
    }
    do {
        boucle = 0;
        temp = *liste;

        while (temp->suivant != NULL) {                   //parcours toute la liste
            if (temp->nombre > temp->suivant->nombre) {    // compare avec le suiv

                permut_nbr = temp->nombre;                   // on stock le suiv si il est plus petit
                permut_char = temp->lettre;

                temp->nombre = temp->suivant->nombre;
                temp->lettre = temp->suivant->lettre;

                temp->suivant->nombre = permut_nbr;
                temp->suivant->lettre = permut_char;
                boucle = 1;                             //sera = à 1 jusqu'à qu'il n'y a plus de valeur à changer

            }
            temp = temp->suivant;
        }

    } while (boucle != 0);
}
/**
 * \brief Function  to creat Huffman tree.
 * \n Example
 * \code{.c}
 * void Arbre_Huff(Element* l);
 * \endcode
 * \return
 *  \return
 *
 */
extern void Arbre_Huff(Element* l);
void Arbre_Huff(Element* l)
{
    L_Noeud* l_nd = malloc(sizeof(struct L_Noeud));
    creer_liste(&l_nd, l);    //création liste de noeud

    L_Noeud* temp = l_nd;
    afficherListe_Noeud(l_nd);
    Noeud* prem = malloc(sizeof(struct Noeud));

    while (temp->suivant != NULL)
    {
        Noeud* n = malloc(sizeof(struct Noeud));              // création noeud pour le poid
        n->poids = temp->n->poids + temp->suivant->n->poids;  // addition de deux poids 
        n->lettre = '\0';
        n->gauche = temp->n;
        n->droite = temp->suivant->n;

        Add_Liste_Noeud(&temp, n);       // on ajoute n à la liste de noeud
        afficherListe_Noeud(temp);
        temp = temp->suivant->suivant;
        if (temp->suivant == NULL)
        {
            prem = n;   //arbre huffman
        }
    }
    print_tree(prem);

    char code[] = "\0";
    FILE* dico = fopen("dico.txt", "w+");
    creer_code(prem, code, dico);

    fclose(dico);
}
/**
 * \brief Function  to print tree.
 * \n Example
 * \code{.c}
 * void print_tree(Noeud* tree);
 * \endcode
 * \return
 *  \return
 *
 */
extern void print_tree(Noeud* tree);
void print_tree(Noeud* tree)
{
    if (tree != NULL) {
        printf("[%d][%c]\n", tree->poids, tree->lettre);

        print_tree(tree->gauche);
        print_tree(tree->droite);
    }
}