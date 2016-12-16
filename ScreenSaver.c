#include "launcher.c"
#include "launcher.h"
#include "statistic.c"
#include "statistic.h"


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

        if (argc ==2) // par défaut 1 seul argument, si on en a un deuxème c'est que l'on a rentré un argument (ici -stats), on entre dans la boucle
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
                                readHistTri(nb_static, nb_dynamic, nb_interactive, nb_total); // lance la fonction qui lit le fichier où les nombres sont stockés TRIÉ
                                statistic=readHistTri(nb_static, nb_dynamic, nb_interactive, nb_total); // renvoie le tableau contenant tous les nombres
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
        }
        free(statistic);

//CHOIX ECRAN RANDOM
        int nb_random; // nombre aléatoire (pour choix écran)
        nb_random = screenChoice(nb_random); // nombre aléatoire renvoyé
        writeFile(nb_random); // nombre aléatoire écrit dans le fichier histori$

//CHOIX PBM (explications variables voir launcher.c)
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
//                printf("\n\n il y a %d  fichiers", xMax);
                fileNumber = randomPbm(fileList, fileNumber, xMax);
//                printf("\n\n le fichier choisi est %d", fileNumber);
                stockPbmName(fileList, fileNumber, fileName);
        }
        else
        {
                printf("end");
        }
	return 0;
}
