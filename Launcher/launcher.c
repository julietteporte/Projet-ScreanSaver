#include "statistic.h"
#include "statistic.c"
#include "launcher.h"
#include "conio.h"
#include "TimeRead.h"
#include "TimeRead.c"

int screenChoice(int nb_random)             //CHOISI UN NB AU HASARD, 1:STATIC 2:DYNAMIC 3:INTERACTIVE
{
        srand(time(NULL));              //initialise le générateur de nombre à 0
        nb_random = (rand() %3) + 1;    //choisi un nombre aleatoire entre 1 et 3
        return nb_random;
}


void writeExecScreen(int nb_random)       //SAUVEGARDE DANS LE FICHIER hist.txt DES CHOIX DU RANDOM ECRAN + EXECUTION ECRAN
{
        FILE* file = NULL;              //initialise le pointeur de type file à NULL "initialise à zéro"
        file = fopen("hist.txt", "a");  //définir quel fichier ouvrir avec comme paramètre : a=écrire
        if(file != NULL)                //si le pointeur a trouvé le fichier
  {
                switch (nb_random) // la variable du switch est nb_random
                {
                        case 1: // si nb_random = 1
                  	fputs("\n1", file); // écrire 1 dans le fichier historique
			printf("JE VAIS OUVRIR L'ECRAN STATIQUE");
		        system("sort -o histTrie.txt  hist.txt"); // fonction qui trie les caractère de hist.txt et les copient (triés) dans histTrie.txt avec paramètre "-o" pour écrire à la ligne dans le fichier
                        break;

                        case 2: // si nb_random = 2
                        fputs("\n2", file);
	                system("sort -o histTrie.txt  hist.txt"); // fonction qui trie les caractère de hist.txt et les copient (triés) dans histTrie.txt avec paramètre "-o" pour écrire à la ligne dans le fichier

			// EXECUTION DE L'ECRAN DYNAMIQUE
			char sentence[] = "Time will be refresh in few seconds"; // permet de récupérer la chaine de caractère dans un tableau
               		system("clear"); //vide la console
                	printf_center(sentence);// fonction qui affiche le programme, centrage, heure, et phrase			}
                        break;

                        case 3: // si nb_random = 3
                        fputs("\n3", file);
			printf("JE VAIS OUVRIR L'ECRAN INTERACTIF");
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



int main(int argc, char *argv[])
{

//MENU STATS
        int nb_static=0; // nombre de fois où l'écran statique a été choisi
        int nb_dynamic=0; // nombre de fois où l'écran dynamique a été choisi
        int nb_interactive=0; // nombre de fois où l'écran interactive a été choisi
        int nb_total=0; // nombre de fois où le processus a choisi un écran
        int *statistic = malloc(4*sizeof(int)); // tableau de 4 cases permettant de stocker les 4 nombres précédents
        int choiceMenu=0; // choix du menu (1 ou 2) choisi dans le menu des statistiques
        char key; // key = touche du clavier

        if (argc ==2) // par défaut 1 seul argument, si on en a un deuxème c'est que l'on a rentré un argument (ici -stats), on entre dans la $
        {
                if(strcmp(argv[1],"-stats")) // si argv est différent de -stats on lui dit erreur
                {
                        system("clear"); //efface l'écran
                        printf("ERREUR");
                }
                else // si l'argument rentré est bien -stats
                {
                        statsMenu(choiceMenu, key); // on affiche le menu des statistiques
                        choiceMenu=statsMenu(choiceMenu, key); // on retourne le choix fait pas la personne (ici seulement 1)
                        if(choiceMenu ==1)
                        {
                                readHistTri(nb_static, nb_dynamic, nb_interactive, nb_total); // lance la fonction qui lit le fichier où les n$
                                statistic=readHistTri(nb_static, nb_dynamic, nb_interactive, nb_total); // renvoie le tableau contenant tous l$
                                displayStats(statistic); // affiche les statistiques
                                key = getch(); // fonctionne comme un scanf sans besoin d'appuyer sur entrée pour éxecuter la fonction
                                system("setterm -cursor off"); //cache le curseur blanc qui clignote
                                while(1) // boucle infinie
                                {
                                        if (key == 32) // sur la table ASCII, Espace correspond à 32, alors i on presse Espace : KILL
                                        {
                                                system("clear");
                                                system("setterm -cursor on");
                                                exit(0); // arrêt du processus
                                        }
                                        else
                                        {
                                                key = getch();
                                        }
                                }
                        }
        }
        free(statistic);
}

//CHOIX ECRAN RANDOM
        int nb_random; // nombre aléatoire (pour choix écran)
        nb_random = screenChoice(nb_random); // nombre aléatoire renvoyé
        writeExecScreen(nb_random); // nombre aléatoire écrit dans le fichier historique + execution écran


//CHOIX PBM
        int xMax = 0;
        int fileNumber = 0;
        char fileName[25];
        int actualCharacter = 0;
        int actualFile = 0;
        int fileQuantity = 0;
        int i =0;

        system("clear");
        if(nb_random == 1)
        {
                FILE* fileList = NULL; // initialisation du pointeur à NULL ("à zéro")
                fileList = fopen("fileList.txt", "r"); // le pointeur ouvre le fichier fileList.txt avec paramètre r:lecture
                xMax = comptFiles(fileList, actualCharacter, actualFile, fileNumber, xMax);
                printf("\n\n il y a %d  fichiers", xMax);
                fileNumber = randomPbm(fileList, fileNumber, xMax);
                printf("\n\n le fichier choisi est %d", fileNumber);
                stockPbmName(fileList, fileNumber, fileName);
        }
        return 0;
}

