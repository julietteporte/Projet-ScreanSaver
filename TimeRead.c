#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FRANCE +1

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
		timeRead();
		printSentenceRefresh();
		system("clear");
	}

	return 0;
}
