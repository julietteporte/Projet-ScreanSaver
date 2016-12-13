#include <stdio.h>
#include <stdlib.h>

int **convertPictureIntoArray(FILE *fileRead, int Rows, int Columns, int **pictureArray);
void printPicture(int **pictureArray, int Rows, int Columns);


typedef struct picture picture;
struct picture{

	int Columns, Rows;
	char feature[2];
	int **PictureArray;

};

int main(int argc, char* argv[]){

	FILE* fileRead = NULL;
	int readCharacter = 0;
	int lineCounter = 1;
	picture actualPicture;
	actualPicture.Columns = 0;
	actualPicture.Rows = 0;
	int cursorPosition = 0;
	fileRead = fopen("test.pbm", "r");
	int i = 0;
	int condition = 0;
	while(condition == 0)
	{
		while(lineCounter < 3)
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
						actualPicture.feature[cursorPosition] = readCharacter;
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
						actualPicture.Columns = (10*actualPicture.Columns + readCharacter - 48);
						readCharacter = getc(fileRead);
						printf("%c colonnes\n", readCharacter);
					}
					else
					{
						printf("Le fichier contient une erreur dans ses dimensions1\n");
						return 2;
					}
				}
				if(readCharacter == '\n')
				{
					printf("Erreur dans le fichier\n");
					return 3;
				}
				readCharacter = getc(fileRead);
				while(readCharacter != '\n' && readCharacter != ' ')
				{
					if(readCharacter >= 48 && readCharacter <= 57)
					{
						actualPicture.Rows = 10*actualPicture.Rows + readCharacter - 48;
					}
					else
					{
						printf("Le fichier contient une erreur dans ses dimensions2\n");
						return 2;
					}
					readCharacter = getc(fileRead);
					condition ++;
				}
				lineCounter ++;
			}

		}

		//printf("sortie du while");
		actualPicture.PictureArray = malloc(actualPicture.Rows * sizeof(int*));
		for(i = 0; i < actualPicture.Rows; i++)
		{

			actualPicture.PictureArray[i] = malloc((actualPicture.Columns+1) * sizeof(int));
		}

	}

	if(condition != 0)
	{
		printf("Rows %d\nColumns %d\nFeature %s\n", actualPicture.Rows, actualPicture.Columns, actualPicture.feature);
		actualPicture.PictureArray = malloc(actualPicture.Rows * sizeof(int*));
        	for(i = 0; i < actualPicture.Rows; i++)
        	{
			actualPicture.PictureArray[i] = malloc((actualPicture.Columns+1) * sizeof(int));
        	}

        	actualPicture.PictureArray = convertPictureIntoArray(fileRead, actualPicture.Rows, actualPicture.Columns, actualPicture.PictureArray);

		printPicture(actualPicture.PictureArray, actualPicture.Rows, actualPicture.Columns);
		return 0;
	}
}



int **convertPictureIntoArray(FILE *fileRead, int Rows, int Columns, int **pictureArray)
{
	printf("convert\n");
	int i, j;
	i = 0;
	j = 0;
	int actualCharacter;
	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Columns+1; j++)
		{


			while(actualCharacter == ' ')
			{
				actualCharacter = getc(fileRead);
			}
            if(actualCharacter == '1')
            {
                pictureArray[i][j] = 'X';
            }
            else if(actualCharacter == '0')
            {
                pictureArray[i][j] = ' ';
            }
            else if(actualCharacter == '\n')
            {
                pictureArray[i][j] = '\n';
            }

            actualCharacter = getc(fileRead);
		}
	}
	return pictureArray;
}


void printPicture(int **pictureArray, int Rows, int Columns)
{
	printf("picture\n");
	int i, j;
	i = 0;
	j = 0;

	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Columns+1; j++)
		{
			printf("%c", pictureArray[i][j]);
		}
		//printf("\n");
	}
}
