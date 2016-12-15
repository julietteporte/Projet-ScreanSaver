#include "TimeRead.h"


void printf_center (char sentence[]) // fonction de centrage
{
        unsigned int n;
        unsigned int i;
        for (i = 0; i < (HEIGHT_TERMINAL-1)/2 ; i++) // i qui parcour la moitié de la hauteur du terminal
        {
                putchar('\n'); // fait les saut de ligne
        }

        for (n = 0 ; n  < (LENGHT_TERMINAL-8)/2 ; n++) // n qui parcour la moitié de la longueur du terminal
        {
                putchar(' '); // fait les espaces
        }
	timeRead(); //Affiche l'heur
	for (n= 0; n< (LENGHT_TERMINAL-(strlen(sentence)))/2 ; n++) //n qui parcour la moitié de la longureur du terminal - la taille de la chaine de caractères 
	{
		putchar(' '); //ajoute les espaces
	}
	printSentenceRefresh(sentence); // fonction contenant la phrase
        for (i = 0; i < (HEIGHT_TERMINAL)/2 ; i++) // i qui parcours l'autre moitié du terminal
        {
                putchar('\n'); // ajout des retours à la ligne
        }
}

void timeRead() // fonction qui lit l'heur
{
	time_t hour; //time_t: est un type de variable qui sert à indiquer un nombre de secondes 
	struct tm date; //structure contenant les variables de temps

	time(&hour);//récupère le temps
	date = *gmtime(&hour);// obtient l'heure GMT
	printf(" %d:%d:%d\n ",(date.tm_hour+FRANCE+24)%24, date.tm_min, date.tm_sec);//écrit le l'heure, minutes et secondes
	/*tm_wday, le jour de la semaine est exprimé en 3 lettres dans son nom anglais (ex : Lundi -> Mon);
	tm_mon, le nom du mois exprimé en 3 lettres dans son anglais (ex : Juin -> Jun) ;
	tm_mday, le jour du mois;
	tm_hour, l'heure;
	tm_min, les minutes;
	tm_sec, les secondes;
	tm_year, l'année.
	*/
}

void printSentenceRefresh(char sentence[]) //fonction qui affiche la phrase et les points
{
	int j = 0; 
	printf("%s", sentence);
	fflush(stdout);// Avant d'être afficher, les caractères sont mis en mémoire (tampon) vide cette mémoire et force l'affichage des caractères qui y étaient.
	while (j<5) //Boucle pour afficher 5 points
	{
		printf(".");
		fflush(stdout);//conserve en mémoire tampon puis affiche
		sleep(1);// attend 1 sec
		j++; // incrémente j de 1
	}

system("clear"); // vide la console 
printf_center(sentence); // affiche la phrase qui est récupéré avec le printf qui est envyé dans la fonction de centrage.

}




