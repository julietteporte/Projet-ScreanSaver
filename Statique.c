#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pbm/Pbm.h"
#include "Pbm/Pbm.c"








void main(int argc, int *argv[])
{
	char *PictureName = "Pbm/heart.pbm";
	FILE* fileRead = NULL;
	picture *Picture;
	Picture = pbmReader(PictureName);
	system("clear");
	printPicture(Picture);
	getchar();
	free(Picture);
	
}
