#ifndef __include_Pbm_h__
#define __include_Pbm_h__ 
#include <stdio.h>
#include <stdlib.h>
#define HEIGHT_TERMINAL 24
#define LENGHT_TERMINAL 80

typedef struct picture picture;
struct picture{

	int Columns, Rows;
	char feature[2];
	char **pictureArray;

};



picture* convertPictureIntoArray(FILE *fileRead, picture *Picture);
void printPicture(picture *Picture);
picture* pbmReader(char fileName[]);

void Height(picture* Picture);


#endif
