#include <stdio.h>
#include <stdlib.h>
#include "Pbm.h"



picture* pbmReader(char fileName[])
{
	int readCharacter = 0;
	int lineCounter = 1;
	picture *actualPicture = malloc(sizeof(picture));
	actualPicture->Columns = 0;
	actualPicture->Rows = 0;
	int cursorPosition = 0;
	FILE *fileRead = NULL;
	fileRead = fopen(fileName, "r");
	int i = 0;
	int condition = 0;
	while(condition == 0)
	{

		while(lineCounter < 3)//Permet de savoir si on a bien récupérer les deux lignes d'informations sur la pbm
		{
			readCharacter = getc(fileRead);
			if (readCharacter == '#')//permet d'éliminer les commentaires du fichier de l'image
			{
				while(readCharacter != '\n')
				{
					readCharacter = getc(fileRead);
				}
			}
			else if(lineCounter == 1)//récupere la donnée correspondant au type de l'image (couleur)
			{
				while(readCharacter != '\n')
				{
					if (readCharacter != ' ')
					{
						actualPicture->feature[cursorPosition] = readCharacter;//lit tous les caractères de la premiere ligne d'infos
						cursorPosition ++;
					}
					readCharacter = getc(fileRead);
				}
				lineCounter ++;
			}
			else if(lineCounter == 2)//récupére les données sur les dimensions de l'image
			{



				while(readCharacter != ' ' )
				{

					if(readCharacter >= 48 && readCharacter <= 57)
					{
						actualPicture->Columns = (10*actualPicture->Columns + readCharacter - 48);//permet de récuperer le  nombres de colonnes
						readCharacter = getc(fileRead);
						
					}
					else
					{
						return NULL;
					}
				}
				if(readCharacter == '\n')//detecte un erreur dans le fichier
				{
					return NULL;
				}
				readCharacter = getc(fileRead);
				while(readCharacter != '\n' && readCharacter != ' ')
				{
					if(readCharacter >= 48 && readCharacter <= 57)
					{
						actualPicture->Rows = 10*actualPicture->Rows + readCharacter - 48;//récupère le nombres de lignes de l'image
					}
					else
					{
						printf("Le fichier contient une erreur dans ses dimensions2\n");
						return NULL;
					}
					readCharacter = getc(fileRead);
					condition ++;
				}
				lineCounter ++;
			}

		}

		


	}

	if(condition != 0)
	{
		actualPicture->pictureArray = malloc(actualPicture->Rows * sizeof(int*));//allocation mémoire pour le tableaux contenat l'image
        	for(i = 0; i < actualPicture->Rows; i++)
        	{
			actualPicture->pictureArray[i] = malloc((actualPicture->Columns+1) * sizeof(int));
        	}

        	actualPicture = convertPictureIntoArray(fileRead, actualPicture);
	}
	return actualPicture;

}



picture* convertPictureIntoArray(FILE *fileRead, picture *Picture)
{
	int i, j;
	i = 0;
	j = 0;
	int actualCharacter;
	for(i = 0; i < Picture->Rows; i++)
	{
		for(j = 0; j < Picture->Columns+1; j++)
		{
			while(actualCharacter == ' ')//ce while permet d'enlever les espaces present dans le pbm
			{
				actualCharacter = getc(fileRead);
			}
        	if(actualCharacter == '1')	          //ce if permettent de transformer les 1 et 0 du pbm en caractères
       	        {
            	       Picture->pictureArray[i][j] = 'X';
          	}
                else if(actualCharacter == '0')
                {
 	    	       Picture->pictureArray[i][j] = ' ';
                }
                else if(actualCharacter == '\n')
                {
                       Picture->pictureArray[i][j] = '\n';
                }

                actualCharacter = getc(fileRead);
		}
	}
	return Picture;
}


void printPicture(picture *Picture)
{
	
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	for(i = 0; i < Picture->Rows; i++)//ce double for permet de parcourir tout le tableaux de  caractères en lisant un par un tous les caractères de la ligne puis passe à la suivante
	{		
		for(j = 0; j < Picture->Columns+1; j++)
		{	
			putchar(Picture->pictureArray[i][j]);
		}
			
	}
}
/*

void HeightPbm(int pictureHeight)
{
	unsigned int i;

	for(i = 0; i < (HEIGHT_TERMINAL - pictureHeight) / 2; i++)
	{
		putchar('\n');
	}
}

void LenghtPbm(int pictureLenght)
{
	unsigned int i = 0;
	
	for(i = 0; i < (LENGHT_TERMINAL - pictureLenght) / 2; i++)
	{
		
		putchar(' ');
	}
	
	
}*/


int** Centering(picture *Picture)
{
	int i, j;
	int offsetX = 0;
	int offsetY = 0;
	int CenteredPicture[80][24] = 0;

	offsetX = (LENGHT_TERMINAL - Picture->Columns)/2;
	offsetY = (HEIGHT_TERMINAL - Picture->Rows)/2;

	for(i = 0; i < 	offsetY; i++)
	{
		for(j = 0;j < offsetX; j++)
		{
			CenteredPicture[i][j] = ' ';
		}



	}
	




}







