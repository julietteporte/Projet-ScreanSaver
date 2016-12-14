#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FRANCE +1
#define LENGHT_TERMINAL 80
#define HEIGHT_TERMINAL 24


void printf_center ()
{
        unsigned int n;
        unsigned int i;
        for (i = 0; i < (HEIGHT_TERMINAL-1)/2 ; i++)
        {
                putchar('\n');
        }

        for (n = 0 ; n  < (LENGHT_TERMINAL)/2 ; n++)
        {
                putchar(' ');
        }
	timeRead();
	for (n= 0; n< (LENGHT_TERMINAL-36)/2 ; n++)
	{
		putchar(' ');
	}
	printSentenceRefresh();
        for (i = 0; i < (HEIGHT_TERMINAL)/2 ; i++)
        {
                putchar('\n');
        }
}

void timeRead()
{
	time_t hour;
	struct tm date;

	time(&hour);
	date = *gmtime(&hour);
	printf(" %d:%d:%d\n ",(date.tm_hour+FRANCE+24)%24, date.tm_min, date.tm_sec);
}

void printSentenceRefresh()
{
	int j = 0;

	printf(" time will be refresh in few seconde");

	fflush(stdout);

	while (j<5)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
		j++;
	}
}

int main()
{

	while(1)

	{
		printf_center();
		system("clear");
	}

	return 0;
}
