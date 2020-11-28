void creer_code(Noeud* Arbre, char* code, FILE* dico) // Cr�ation du dictionnaire � partir d'un arbre donn�
{
    char copie[50];

    if (Arbre != NULL)
    {
        if ((Arbre->droite == NULL) && (Arbre->gauche == NULL))  //feuille
        {
            //printf("%s est le code\n",code); 
            fprintf(dico, "%c : %s\n", Arbre->lettre, code); // �crire dans le fichier dico le chemin
        }

        else
        {
            strcpy(copie, code);          // copie = code
            strcat(code, "0");           //concat�ner les contenus de deux cha�nes de caract�res
            creer_code(Arbre->gauche, code, dico);         //On va � gauche = 0
            strcat(copie, "1");                          // On va � droite = 1
            creer_code(Arbre->droite, copie, dico);
        }
    }
}


void dico_binaire(FILE* dico, char caractere, char* trad)// traduire un caractere en binaire � partir du dico
{
    char caractereActuel;
    int i = 0;
    if (dico != NULL)
    {
        rewind(dico);  //replace le curseur au d�but du fichier

        //printf("%c est caractere\n", caractere);
        while (caractere != caractereActuel)      // on recherche le caract�re dans le dico
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
