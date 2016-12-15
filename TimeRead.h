#include <stdio.h>
#include <stdlib.h>
#include <time.h> // bibliothèque pour récupérer le temps qui passe
#include "conio.h" // conio.h est la bibliothèque pour récupérer les touche de notre clavier
#define FRANCE +1 // fuseau  horaire
#define LENGHT_TERMINAL 80 //longueur de la console 
#define HEIGHT_TERMINAL 24 // hauteur de la console 


void printf_center(char sentence[]); //fonction de centrage
void timeRead(); //fonction qui lit l'heure
void printSentenceRefresh(char sentence[]); //fonction qui écrit la phrase et affiche les points un à un.


