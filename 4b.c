#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 512
#define WIN 10
#define MYNUMBERS 25
#define TOTALCARDS 196

int main()
{
	char line[LEN];
	int cards[TOTALCARDS];
	for(int i=0;i<TOTALCARDS;i++)
		cards[i]=1;
		
	int cardcount=0;
	while(fgets(line,LEN,stdin)!=NULL)
	{
		char *token;
		token=strtok(line," ");
		token=strtok(NULL," ");
		
		int winning[WIN];
		for(int i=0;i<WIN;i++)
		{
			token=strtok(NULL," ");
			winning[i]=atoi(token);
		}
		
		token=strtok(NULL," ");
		
		int card[MYNUMBERS];
		for(int i=0;i<MYNUMBERS;i++)
		{
			token=strtok(NULL," ");
			card[i]=atoi(token);
		}
		
		int wincount=0;
		for(int i=0;i<WIN;i++)
			for(int j=0;j<MYNUMBERS;j++)
				if(winning[i]==card[j])
					wincount++;
		
		for(int i=0;i<wincount;i++)
			cards[cardcount+i+1] += cards[cardcount];
		
		cardcount++;
	}
	
	int sum=0;
	for(int i=0;i<TOTALCARDS;i++)
		sum+=cards[i];
	printf("%d\n",sum);
	return 0;
}
	
