#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 64

struct proto_item {
	char name[4];
	char left[4];
	char right[4];
} item[1000];

char instructions[1024];
int inst_count;
int total_inst_count;

int itemcount;
int steps;

void delve(char currentname[])
{

	if(strcmp(currentname, "ZZZ")==0)
	{
		printf("%d\n",steps);
		exit(0);
	}
	for(int i=0;i<itemcount;i++)
		if(strcmp(item[i].name, currentname)==0)
		{
			int c = instructions[inst_count++];
			if(inst_count==total_inst_count)
				inst_count=0;
			steps++;
			
			switch(c)
			{
				case 'R':delve(item[i].right);break;
				case 'L':delve(item[i].left);break;
			}
			break;
		}
	return;
}

int main()
{
	fgets(instructions,1024,stdin);
	if(instructions[strlen(instructions)-1]=='\n')
		instructions[strlen(instructions)-1]=0;
	total_inst_count = strlen(instructions);
	
	char line[LEN];
	fgets(line,LEN,stdin);
	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		if(strlen(line)<2) continue;
		
		char*token;
		token=strtok(line," ");
		strcpy(item[itemcount].name, token);
		
		token=strtok(NULL," ");
		token=strtok(NULL," ");
		for(int i=0;i<3;i++)
			token[i]=token[i+1];
		token[3]=0;
		strcpy(item[itemcount].left, token);
		
		token=strtok(NULL," ");
		token[3]=0;
		strcpy(item[itemcount].right, token);
		
		itemcount++;
	}
	
	for(int i=0;i<itemcount;i++)
		delve("AAA");

	
	return 0;
}
