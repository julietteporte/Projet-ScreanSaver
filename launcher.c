#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int screenChoice(nb_random) { // CHOISI UN NB AU HASARD, 1:STATIC 2:DYNAMIC 3:INTERACTIVE

        srand(time(NULL)); // initialise le générateur de nombre aléatoire
        nb_random = (rand() %3) + 1; // choisi un nombre aleatoire entre 1 et 3
        return nb_random;
}

void writeFile(nb_random) { // SAUVEGARDE DANS LE FICHIER hist.txt LE TYPE CHOISI
	FILE* file = NULL; //  initialise le pointeur de type file à NULL ("à zéro") 
        file = fopen("hist.txt", "a"); // définir quel fichier ouvrir:a=écrire à la fin du fichier
        if(file != NULL) { // si le pointeur a trouvé le fichier
                switch (nb_random) {
                        case 1:
                        printf("stat");
                        fputs("\n1", file);
                        break;
                        case 2:
                        printf("dynamic");
                        fputs("\n2", file);
                        break;
                        case 3:
                        printf("interact");
                        fputs("\n3", file);
                        break;
                        default:
                        printf("ERREUR");
	        printf("ERREUR");
                }
                fclose(file); // ferme le fichier
        }
        else { // écrit un message d'erreur si fichier non trouvé
        	printf("Impossible d'ouvrir le fichier demandé");
        }

}

int  main(int argc, char *argv[]) {

        int nb_random;
        system("clear");
        nb_random = screenChoice(nb_random); // nombre aléatoire renvoyé
	writeFile(nb_random); // nombre aléatoire écrit dans le fichier historique
	return 0;
}

