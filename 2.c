#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024

#define RED 12
#define GREEN 13
#define BLUE 14

int main()
{
	char line[LEN];
	int sum=0;
	int linecount=0;
	while(fgets(line,LEN,stdin)!=NULL)
	{
		linecount++;
		int len=strlen(line);
		int i=0;
		int n;
		int red, green, blue;
		char *token;
		token=strtok(line," ");
		token=strtok(NULL," ");

		red=green=blue=0;
		int flag=1;
		while(1)
		{ 	
			token=strtok(NULL," ");
			n=atoi(token);
			
			token=strtok(NULL," ");
			
			switch(token[0])
			{
				case 'r':red=n;break;
				case 'b':blue=n;break;
				case 'g':green=n;break;
			}
			if(token[strlen(token)-1] == ',')
				continue;
			
			if(red>RED || green>GREEN || blue>BLUE)
				flag=0;
				
			red=green=blue=0;	

			if(token[strlen(token)-1] != ';')
			{
				if(flag)
					sum+=linecount;
				
				flag=1;
				break;
			}
		}
	}
	
	printf("%d\n",sum);
	return 0;
}
		
			
