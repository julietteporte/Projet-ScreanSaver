#include <stdio.h>
#include <stdlib.h>
#include <time.h>










void main()
{
	FILE* FileList = NULL;
	int xMin = 0;
	int xMax = 0;
	int FileNumber = 0;
	char FileName[25];
	int actualCharacter = 0;
	int ActualFile = 0;
	int FileQuantity = 0;
	int i = 0;

	FileList = fopen("fileList.txt", "r");
	if(FileList == NULL)
	{
		printf("Erreur");
	}

	printf("avant 1er while\n");
	while(actualCharacter != EOF)//boucle pour compter le nombre de fichier
	{
		if(actualCharacter == '\n')
		{
			ActualFile ++;
		}
		actualCharacter = getc(FileList);
	}

	printf("Il y a %d fichiers\n", ActualFile);
	xMax = ActualFile;

	srand(time(NULL)); //tirage random pour choisir quelle pbm ouvrir
	FileNumber = rand()%(xMax);
	fclose(FileList);

	FileList = NULL;
	ActualFile = 0;
	actualCharacter = 0;
	FileList = fopen("fileList.txt", "r");
	while(ActualFile < FileNumber) // boucle qui sert a se déplacer au niveau de la ligne contenat le nom du pbm à ouvrir.
	{
		if(actualCharacter == '\n')
		{
			ActualFile ++;
		}
		actualCharacter = getc(FileList);
	}

	while(actualCharacter != '\n')//sert a stocker le nom de la pbm a ouvrir
        
	{
		FileName[i] = actualCharacter;
		i ++;
		actualCharacter = getc(FileList);
	}

	fclose(FileList);
	for(i = 0; i <25; i++)
	{
	printf("%c", FileName[i]);
	}
	printf("\n");
}
