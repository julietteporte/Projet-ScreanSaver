
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"

int screenChoice(int nb_random);
//CHOISI UN NB AU HASARD, 1:STATIC 2:DYNAMIC 3:INTERACTIVE

void writeExecuteScreen(int nb_random);
//SAUVEGARDE DANS LE FICHIER hist.txt DES CHOIX DU RANDOM ECRAN

int comptFiles(FILE *fileList,char  actualCharacter,int actualFile,int fileNumber,int xMax); 
//compte le nombre de fichier dans le fichier fileList.txt

int randomPbm(FILE *fileList,int fileNumber,int xMax); 
// choix PBM random

void stockPbmName(FILE *fileList,int fileNumber,char* fileName); 
//cherche et stocke le nom du PBM choisi, en effet il connait son numéro mais pas son nom

void readHist();
// lit le fichier l'historique non trié

