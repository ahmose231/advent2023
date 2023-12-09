#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 512

int main()
{
	char line[LEN];
	int sum=0;
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		char *token;
		token=strtok(line," ");
		token=strtok(NULL," ");
		
		int winning[10];
		for(int i=0;i<10;i++)
		{
			token=strtok(NULL," ");
			winning[i]=atoi(token);
		}
		
		token=strtok(NULL," ");
		
		int card[25];
		for(int i=0;i<25;i++)
		{
			token=strtok(NULL," ");
			card[i]=atoi(token);
		}
		
		int point=0;
		for(int i=0;i<10;i++)
			for(int j=0;j<25;j++)
				if(winning[i]==card[j])
				{
					if(point)
						point*=2;
					else
						point=1;
				}
		sum+=point;
	}
	printf("%d\n",sum);
	return 0;
}
	
