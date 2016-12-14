#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#define LENGHT_TERMINAL 80
#define HEIGHT_TERMINAL 24
int kdb()
{
	char ch;
	char kill = ' ';
	while(1)
	{
		ch= getch();
		if (ch == '\033')
		{
			getch();
			switch(ch = getch())
			{
				case 'A':
				return 1;
				break;
				case 'B':
				return 2;
				break;
				case 'C':
				return 3;
				break;
				case 'D':
				return 4;
				break;
			}
			if(ch == kill)
			{
				return 5;
			}
		}
	}
}

void main()
{
int x = 0;
int y = 0;
int stop = 0;
int ordre = 0;
while(stop != 1)
{
	ordre = kdb();
	switch(ordre)
	{
	case 1 :
	y--;
	break ;
	case 2 :
	y++;
	break;
	case 3 :
	x--;
	break;
	case 4 :
	x++;
	break;
	case 5:
	stop = 1;
	break;
	}
        if( x == -1)
        {
                x = 23;
        }
        if( y == -1)
        {
                y = 79;
        }

	system("clear");
	unsigned int n;
	unsigned int i;

	for( i = 0; i <(HEIGHT_TERMINAL-1)-(y%24); i++)
	{
		putchar('\n');
	}

	for ( n = 0 ; n < (LENGHT_TERMINAL)-(x%80); n++)
	{
		putchar(' ');
	}
	printf("X");
	for (i = 0; i <(HEIGHT_TERMINAL-1)-(y%24); i++)
	{
		putchar('\n');
	}
 
}
}

