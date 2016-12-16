#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Pbm.h"
#include "Pbm.c"








void main()
{

	char PictureName[] = "heart.pbm"; 
	FILE* fileRead = NULL;
	picture *Picture;
	Picture = pbmReader(PictureName);
	system("clear");
	printPicture(Picture);
	int key = getch();
	system("setterm-cursor off");
	while(1)
	{
		if(key == 32)
		{
			system("clear");
			system("setterm-cursor on");
			exit (0);
		}
		key = getch();

	}	
	free(Picture);

}
