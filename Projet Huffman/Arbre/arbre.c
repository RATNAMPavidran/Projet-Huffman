#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"



Noeud** creer_tab_occur(FILE* f,int *taille)
{

    Noeud **tab = malloc(sizeof(Noeud*)*(*taille));
    char lettre;
    if (f != NULL)
    {
        tab=creer_2_premiers_noeud(tab,taille,f);
        do
        {
            lettre = fgetc(f);

            if (lettre!=-1)// Evitez le dernier carac vide du fichier
            {
                int pos=(*taille)/2; // regarde la moitie du tableau
                if (lettre >= tab[pos]->lettre)
                {
                    while ((lettre>tab[pos]->lettre)&&(pos<(*taille)-1)) // Tant que la lettre est plus grande que le carac du tab et tant que l'on ne dépasse pas le tab
                    {
                        pos++;
                    }
                    if (tab[pos]->lettre==lettre)// Si la lettre existe deja dans le tableau
                    {
                        tab[pos]->poids++;
                    }
                    else
                    {
                        (*taille)++;
                        tab= realloc( tab, (*taille) * sizeof(Noeud*) ); // Ajoute une place dans le tab afin d'ajouter un nouveau noeud
                        if (lettre>tab[pos]->lettre)
                        {
                            pos++;
                        }
                        else
                        {
                            tab=tab_swipe(tab,pos,*taille);// déplacer le tab afin d'insérer au milieu un nouveua noeud
                        }
                        tab[pos]=creer_noeud(tab[pos],lettre);// creer le noeud
                    }
                }
                else
                {
                    while ((lettre<tab[pos]->lettre)&&(pos>0))// même conditions que la premiere boucle while mais inverse vu qu'on s'interresse ici à la gauche du tab
                    {
                        pos--;
                    }
                    if (tab[pos]->lettre==lettre)
                    {
                        tab[pos]->poids++;
                    }
                    else
                    {
                        (*taille)++;
                        tab= realloc( tab, (*taille) * sizeof(Noeud*) );
                        if (lettre>tab[pos]->lettre)
                        {
                            pos++;
                        }
                        tab=tab_swipe(tab,pos,*taille);// déplacer le tab afin d'insérer au milieu un nouveua noeud
                        tab[pos]=creer_noeud(tab[pos],lettre);
                    }
                }
            }
        } while (lettre != EOF);

    }
    return(tab);

}


L_Noeud * Tab_to_L_Noeud(Noeud ** tab , int nbre_chara_diff )
{
    L_Noeud* list =NULL;
    L_Noeud * temp=NULL;
    int i=0;



    if(tab[i]!=NULL)
    {
        list= malloc(sizeof(L_Noeud));
        temp=list;
        while(i<nbre_chara_diff-1)
        {
            temp->n = tab[i];
            temp->suivant = malloc(sizeof(L_Noeud));
            temp=temp->suivant;
            i++;
        }
        temp->n=tab[i];



  }
  temp->suivant=NULL;
    return (list);
}


Noeud* fusionner_deux_noeuds(Noeud*n1,Noeud*n2)
{
    Noeud* nouv_noeud=malloc(sizeof(Noeud));
    nouv_noeud->poids = n1->poids+ n2->poids;
    nouv_noeud->lettre='\0';
    nouv_noeud->code[0]='\0';
    nouv_noeud->gauche=n2;
    nouv_noeud->droite=n1;

    return (nouv_noeud);
}


Noeud ** creer_2_premiers_noeud (Noeud** tab,int* taille,FILE* f) 
{

    char lettre;
    lettre=fgetc(f);

    if(lettre != EOF)
    {

(*taille)=1;
tab= realloc( tab, (*taille) * sizeof(Noeud*) );

    tab[0]=creer_noeud(tab[0],lettre);
    while ((*taille)!=2)
    {
        lettre=fgetc(f);

        if (lettre==tab[0]->lettre)
        {
            tab[0]->poids++;
        }
        else
        {
            (*taille)++;

            tab= realloc( tab, (*taille) * sizeof(Noeud*) );
            if (lettre<tab[0]->lettre)
            {
                tab_swipe(tab,0,*taille);
                tab[0]=creer_noeud(tab[0],lettre);
            }
            else
            {

                tab[1]=creer_noeud(tab[1],lettre);

            }
        }


    }
    }


    return (tab);
}

void quick_sort(Noeud*** tab, int debut, int fin)
{
   int i;
   int j;
   int pivot;
   Noeud* temp = NULL;

    if (debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;

        //on va faire en sorte que tous les éléments sous le pivot soit < et le reste >
        //la plus grande valeur deviendra le pivot
        while (i < j)
        {
            while ((*tab)[i]->poids <= (*tab)[pivot]->poids && (i < fin)){
                i++;
            }
            while ((*tab)[j]->poids > (*tab)[pivot]->poids)
            {
                j--;
            }
            if (i < j){
                temp = (*tab)[i];
                (*tab)[i] = (*tab)[j];
                (*tab)[j] = temp;
            }
        }
        temp = (*tab)[pivot];
        (*tab)[pivot] = (*tab)[j];
        (*tab)[j] = temp; //le pivot a été déplacé


        quick_sort(tab, debut,j-1);
        quick_sort(tab,j+1, fin);
    }
}



void Afficher_tab(int taille, Noeud**tab)
{
    int i=0;
    int somme=0;
    while (i<taille)
    {
        printf("tab [%d] : %c = ",i,tab[i]->lettre);
        printf("%d\n", tab[i]->poids);
        somme=somme+ tab[i]->poids;
        i++;
    }
    printf("%d est la somme",somme);
}




Noeud* Arb_Huff_queue(Noeud **tab,int taille)
{
    Queue* q1 = malloc(sizeof(Queue));
    q1->liste_noeud = Tab_to_L_Noeud(tab,taille);

    Queue* q2 = malloc(sizeof(Queue));
    q2->liste_noeud=malloc(sizeof(L_Noeud));
    q2->liste_noeud=NULL;
    Noeud* noeud_1 = malloc(sizeof(Noeud));
    Noeud* noeud_2 = malloc(sizeof(Noeud));

    //CREER LE premier Noeud
    noeud_1=dequeue(q1);
    noeud_2=dequeue(q1);


    enqueue(q2,fusionner_deux_noeuds(noeud_2,noeud_1));

    while ((is_empty(q1)!=1)||((q2->liste_noeud->suivant)!=NULL))
    {

        if ((is_empty(q1)!=1)&&(q1->liste_noeud->n->poids) <= (q2->liste_noeud->n->poids)) // On sait ici que le premier noeud de la 2eme file est plus petit
        {
            noeud_1=dequeue(q1);

            if (is_empty(q1)==0)
            {
                if ((is_empty(q1)!=1)&&(q1->liste_noeud->n->poids) <= (q2->liste_noeud->n->poids))
                {
                    noeud_2 = dequeue(q1);
                }
                else
                {
                    noeud_2 = dequeue(q2);
                }
            }
            else
                noeud_2 = dequeue(q2);
        }
        else
        {
            noeud_1=dequeue(q2);
            if (is_empty(q2)==0)
            {
                if ((is_empty(q1)!=1)&&( (q1->liste_noeud->n->poids) <= (q2->liste_noeud->n->poids)))
                {
                    noeud_2 = dequeue(q1);

                }
                else
                {
                    noeud_2 = dequeue(q2);
                }
            }
            else
                noeud_2=dequeue(q1);
        }

        enqueue(q2,fusionner_deux_noeuds(noeud_2,noeud_1));
    }
    //print_tree(q2->liste_noeud->n);

    free(q1);
    return (q2->liste_noeud->n);


}


void free_tree(Noeud** tree){
    if(tree != NULL){
        free_tree((*tree)->gauche);
        free_tree((*tree)->droite);
        free(*tree);
    }
}


void add_noeud_avl(Noeud **avl, Noeud *noeud)
{
    if ((*avl) ==NULL)
    {

        (*avl)=noeud;
    }
    else
    {

        if ((*avl)->lettre > noeud->lettre)
        {
            add_noeud_avl(&((*avl)->gauche) , noeud);
        }
        else if((*avl)->lettre < noeud->lettre)
        {


            add_noeud_avl(&((*avl)->droite), noeud);
        }
    }

}

int depth(Noeud* tree)
{
    if(tree == NULL){
        return 0;//Attention définition. -1 ou 0
    }
    else{
        int depth_left = depth(tree->gauche);
        int depth_right = depth(tree->droite);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}


int bf(Noeud* tree)
{
    if(tree == NULL) {
        return 0;
    }
    else{
        return depth(tree->droite) - depth(tree->gauche);
    }
}


void right_rotation(Noeud** tree){
    if (*tree != NULL){
        Noeud* temp = (*tree)->gauche;
        (*tree)->gauche = temp->droite;
        temp->droite = *tree;
        *tree = temp;
    }
}

void left_rotation(Noeud** tree){
    if (*tree != NULL){
        Noeud* temp = (*tree)->droite;
        (*tree)->droite = temp->gauche;
        temp->gauche = *tree;
        *tree = temp;
    }
}

void balance(Noeud** tree){
    if (*tree != NULL){
        balance(&((*tree)->gauche));// Postfix
        balance(&((*tree)->droite));

        int balance_factor = bf(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf((*tree)->gauche) > 0){// Gauche - Droite
                left_rotation(&((*tree)->gauche));
            }
            right_rotation(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(bf((*tree)->droite) < 0){// Droite - Gauche
                right_rotation(&((*tree)->droite));
            }
            left_rotation(tree);// Droite - Droite
        }
    }
}

Noeud* creer_avl(Noeud**tab, int taille )
{
    Noeud *avl=malloc(sizeof(Noeud));
    avl=NULL;
    for(int i=0;i<taille;i++)
    {
        //printf("%c est la carac  %d est i \n",tab[i]->lettre,i);
        add_noeud_avl(&avl,tab[i]);
        balance(&avl);
    }
    return(avl);
}
