#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 32
#define TOTALHANDS 1000
#define HANDLEN 5

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int string_cmp (const void * a, const void * b ) {
    const char * pa = (const char *) a;
    const char * pb = (const char *) b;

    return strcmp(pb,pa);
}
struct proto_hand {
	char cards[HANDLEN+1];
	int bid;
};

struct proto_group {
	struct proto_hand hands[TOTALHANDS];
	int groupcount;
} group[7];

int check_hand(char *hand)
{
	/*
	 *	0: five of a kind
	 *	1: four of a kind
	 *	2: full house
	 *	3: three of a kind
	 *	4: two pair
	 *	5: one pair
	 *	6: high card
	 */

	int ascii[128]={0};
	for(int i=0;i<5;i++)
		ascii[hand[i]]++;

	for(int i=0;i<128;i++)
	{
		if(ascii[i]==5)
			return 0;
		if(ascii[i]==4)
			return 1;
		if(ascii[i]==3) 
		{
			for(int j=0;j<128;j++)
				if(ascii[j]==2)
					return 2;
			return 3;
		}
	}
	for(int i=0;i<128;i++)
		if(ascii[i]==2)
		{
			for(int j=0;j<128;j++)
				if(ascii[j]==2)
					return 4;
			return 5;
		}
	return 6;
}

int main()
{

	char inputhand[TOTALHANDS][HANDLEN+1];
	int inputbid[TOTALHANDS];
	int inputcount=0;
	char line[LEN];
	for(int i=0;i<TOTALHANDS;i++)
	{
		fgets(line,LEN,stdin);
		
		char *token;
		
		token=strtok(line," ");
		strcpy(inputhand[inputcount], token);
		
		for(int j=0;j<5;j++)
			switch(inputhand[inputcount][j])
			{
				case 'A':inputhand[inputcount][j]='E';break;
				case 'K':inputhand[inputcount][j]='D';break;
				case 'Q':inputhand[inputcount][j]='C';break;
				case 'J':inputhand[inputcount][j]='B';break;	
				case 'T':inputhand[inputcount][j]='A';break;
			}
		
		token=strtok(NULL," ");
		inputbid[inputcount] = atoi(token);
		
		inputcount++;
	}
	
	qsort(inputhand, inputcount, HANDLEN+1, string_cmp);

	for(int i=0;i<TOTALHANDS;i++)
	{
		int whatgroup;
		whatgroup = check_hand(inputhand[i]);
		
		strcpy(group[whatgroup].hands[group[whatgroup].groupcount].cards, inputhand[i]);
		group[whatgroup].hands[group[whatgroup].groupcount].bid = inputbid[i];
		
		group[whatgroup].groupcount++;
	}
	

	int sum=0;
	int countdown=TOTALHANDS;
	
	for(int j=0;j<7;j++)
	{
		for(int i=0;i<group[j].groupcount;i++)
			sum += group[j].hands[i].bid * countdown--;
	}
	
	printf("%d\n",sum);
	return 0;
}
