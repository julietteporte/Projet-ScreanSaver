#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include "conio.h"
//conio.h =  bibliothèque fonctionnement semblable à la fonction getch() sous windows permettant de récupérer le caractère ASCII d'une touche du clavier lorsqu'on appuie dessus

int statsMenu(int choiceMenu, char key);
// AFFICHAGE MENU DES STATISTIQUES

int* readHistTri(int nb_static,int nb_dynamic,int nb_interactive,int nb_total);
// LECTURE DU FICHIER OÙ LES NOMBRES STOCKÉS DES CHOIX ÉCRANS SONT TRIÉ

void displayStats(int *statistic);
// AFFICHER LES STATS

