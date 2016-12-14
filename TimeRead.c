#include "TimeRead.h"


void printf_center (char sentence[])
{
        unsigned int n;
        unsigned int i;
        for (i = 0; i < (HEIGHT_TERMINAL-1)/2 ; i++)
        {
                putchar('\n');
        }

        for (n = 0 ; n  < (LENGHT_TERMINAL-8)/2 ; n++)
        {
                putchar(' ');
        }
	timeRead();
	for (n= 0; n< (LENGHT_TERMINAL-(strlen(sentence)))/2 ; n++)
	{
		putchar(' ');
	}
	printSentenceRefresh(sentence);
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

void printSentenceRefresh(char sentence[])
{
	int j = 0;
	printf("%s", sentence);
	fflush(stdout);
	while (j<5)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
		j++;
	}

system("clear");
printf_center(sentence);

}




