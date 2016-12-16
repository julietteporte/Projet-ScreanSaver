#include "launcher.h"
//#include "TimeRead.h"
//#include "TimeRead.c"
//#include "mainTimeRead.c"

int screenChoice(int nb_random)             //CHOISI UN NB AU HASARD, 1:STATIC 2:DYNAMIC 3:INTERACTIVE
{
        srand(time(NULL));              //initialise le générateur de nombre à 0
        nb_random = (rand() %3) + 1;    //choisi un nombre aleatoire entre 1 et 3
        return nb_random;
}


void writeFile(int nb_random)               //SAUVEGARDE DANS LE FICHIER hist.txt DES CHOIX DU RANDOM ECRAN
{
        FILE* file = NULL;              //initialise le pointeur de type file à NULL "initialise à zéro"
        file = fopen("hist.txt", "a");  //définir quel fichier ouvrir avec comme paramètre : a=écrire
        if(file != NULL)                //si le pointeur a trouvé le fichier
  {
                switch (nb_random) // la variable du switch est nb_random
                {
                        case 1: // si nb_random = 1
                  	fputs("\n1", file); // écrire 1 dans le fichier historique
	                system("sort -o histTrie.txt  hist.txt"); // fonction qui trie les caractère de hist.txt et les copient (triés) dans histTrie.txt avec paramètre "-o" pour écrire à la ligne dans le fichier
                        break;

                        case 2: // si nb_random = 2
//	main();
                        fputs("\n2", file);
	                system("sort -o histTrie.txt  hist.txt"); // fonction qui trie les caractère de hist.txt et les copient (triés) dans histTrie.txt avec paramètre "-o" pour écrire à la ligne dans le fichier
                        break;

                        case 3: // si nb_random = 3
                        fputs("\n3", file);
	                system("sort -o histTrie.txt  hist.txt"); // fonction qui trie les caractère de hist.txt et les copient (triés) dans histTrie.txt avec paramètre "-o" pour écrire à la ligne dans le fichier
                        break;

                        default: // sinon écrire erreur
                        printf("ERREUR");
                        break;
                }
                fclose(file); // ferme le fichier
        }
        else    // écrit un message d'erreur si fichier non trouvé
        {
                printf("Impossible d'ouvrir le fichier demandé");
        }

}


int comptFiles(FILE *fileList,char  actualCharacter,int actualFile,int fileNumber,int xMax) // compte le nombre de fichier dans le fichier fileList.txt
{
        if(fileList == NULL) // le pointeur pointe NULL, c'est à dire rien
        {
                printf("Impossible d'ouvrir le fichier demandé");
        }
        while(actualCharacter != EOF) // boucle pour compter le nombre de nom dans le fichier jusqu'à la fin : EOF
        {
                if(actualCharacter == '\n') //à chaque retour à la ligne
                {
                        actualFile ++; // on descend à la ligne suivante
                }
                actualCharacter = getc(fileList);
        }
        xMax = actualFile;
        return xMax;
}

int randomPbm(FILE *fileList,int fileNumber,int xMax) // choix PBM random
{
        srand(time(NULL)); // initialise le random à 0
        fileNumber = rand()%(xMax); // calcul du random de 0 à xMax
        fclose(fileList); // fermeture du fichier
        return fileNumber; // retourne le numéro du fichier choisi dans la liste
}

void stockPbmName(FILE *fileList,int fileNumber,char* fileName) //cherche et stocke le nom du PBM choisi, en effet il connait son numéro mais pas son nom
{
        int  actualFile = 0;
        char actualCharacter = 0;
        fileList = fopen("fileList.txt", "r"); // ouverture du fichier grâce au poiteur
        while(actualFile < fileNumber) // boucle qui sert à se déplacer au nive$
        {
                if(actualCharacter == '\n') // si le caractère actuel est = à un saut de ligne
                {
                        actualFile ++; // on passe à la ligne suivante
                }
                actualCharacter = getc(fileList); // le PBM choisi en random a enfin un nom !
        }
        fclose(fileList); // ferme le fichier
}

void readHist() // lit le fichier historique non trié
{
        FILE* fileHist = NULL; //initialise le pointeur à NULL
        int current_charact = 0;
        fileHist = fopen("histTrie.txt", "r"); //ouvre le fichier "histTrie.txt" grâce au pointeur fileHist
        if(fileHist != NULL);                           // Boucle qui lit les caractères un à un
        {
                while(current_charact != EOF) // Faire ... tant que fgetc n'est pas arrivé à la fin du fichier (EOF)
                {
                        current_charact = fgetc(fileHist); // ON lit le caractère
                        printf("%c", current_charact); // On l'affiche
                }
        }
        fclose(fileHist); //ferme de fichier
}

