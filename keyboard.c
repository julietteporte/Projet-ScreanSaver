#include <stdio.h>

int main(void)
{
	FILE* flux = stdin;
	char caractere;

	caractere = getc(flux);
	if (caractere == EOF)
	{
		return(0);
	}
}
