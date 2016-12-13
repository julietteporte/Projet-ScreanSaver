#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGHT_TERMINAL 80
#define HEIGHT_TERMINAL 24

void printf_center (const char* str)
{
	system("clear");
	unsigned int n;
	unsigned int i;
	for (i = 0; i < (HEIGHT_TERMINAL-1)/2 ; i++)
	{
		putchar('\n');
	}

	for (n = 0 ; n  < (LENGHT_TERMINAL-strlen(str)) / 2; n++)
	{
		putchar(' ');
	}
	printf("%s", str);
	for (i = 0; i < (HEIGHT_TERMINAL-1)/2 ; i++)
        {
                putchar('\n');
        }


}

int main (void)
{
	printf_center("test");
	return 0;
}
