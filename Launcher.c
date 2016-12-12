#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(int argc, char* argv[])
{





}






char RandomFile()
{
	FILE* FileList = NULL;
	int xMin = 1;
	int xMax = 0;
	int FileNumber = 0;
	char FileName[25];

	FileList = fopen("fileList.txt", "r");
	if(FileList == NULL)
	{
		return -1;
	}

	








	srand(time(NULL));
	FileNumber rand_a_b(xMin, xMax);


}
