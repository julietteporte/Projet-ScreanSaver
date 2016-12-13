
#include "conio.h"

#define UP 72
pid_t sonPid;
char ch;
char kill = ' ' ;
int main()
{
	while(1)
	{
		ch = getch();
		printf("%c", ch);
		if (ch == '\033')
		{
			getch();
			switch(getch())
			{
				case 'A':
				printf("up");
				break;
				case 'B' :
				printf("down");
				break;
				case 'C' :
				printf("right");
				break;
				case 'D' :
				printf("left");
				break;
			}
		}
		if (ch == kill)
		{
			printf("kill");
		}
	}
}
