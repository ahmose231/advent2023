#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 140

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

int table[LEN][LEN];
int steps;

int move(int x, int y, int going)
{
	steps++;
	
	int nextblock;
	switch(going)
	{
		case UP:
			nextblock=table[y-1][x];
			break;
		case DOWN:
			nextblock=table[y+1][x];
			break;
		case RIGHT:
			nextblock=table[y][x+1];
			break;
		case LEFT:
			nextblock=table[y][x-1];
			break;
	}
	
	int nextgoing;
	switch(nextblock)
	{
		case 'S':
			printf("%d\n",(steps+1)/2);
			exit(0);
		case 'F':
			if(going==UP) nextgoing=RIGHT;
			else nextgoing=DOWN;
			break;
		case '7':
			if(going==UP) nextgoing=LEFT;
			else nextgoing=DOWN;
			break;
		case '|':
			if(going==UP) nextgoing=UP;
			else nextgoing=DOWN;
			break;
		case 'J':
			if(going==DOWN) nextgoing=LEFT;
			else nextgoing=UP;
			break;
		case '-':
			if(going==RIGHT) nextgoing=RIGHT;
			else nextgoing=LEFT;
			break;
		case 'L':
			if(going==DOWN) nextgoing=RIGHT;
			else nextgoing=UP;
			break;
	}
	
	switch(going)
	{
		case UP:
			move(x, y-1, nextgoing);
			break;
		case DOWN:
			move(x, y+1, nextgoing);
			break;
		case RIGHT:
			move(x+1, y, nextgoing);
			break;
		case LEFT:
			move(x-1, y, nextgoing);
			break;
	}
	
	return 0;
}	
	
			

int main()
{

	char line[LEN+2];
	int linecount=0;

	while(fgets(line,LEN+2,stdin)!=NULL)
	{
		if(strlen(line)<2) continue;
		
		for(int i=0;i<LEN;i++)
			table[linecount][i] = line[i];
		
		linecount++;
	}

	int x,y;
	
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
			if(table[i][j]=='S')
			{
				y=i;
				x=j;
			}

	if(y>0)
		switch(table[y-1][x])
		{
			case 'F':
				move(x, y-1, RIGHT);
				break;
			case '|':
				move(x, y-1, UP);
				break;
			case '7':
				move(x, y-1, LEFT);
				break;
		}
	if(y<LEN-1)
		switch(table[y+1][x])
		{
			case 'L':
				move(x, y+1, RIGHT);
				break;
			case '|':
				move(x, y+1, DOWN);
				break;
			case 'J':
				move(x, y+1, LEFT);
				break;
		}
	if(x>0)
		switch(table[y][x-1])
		{
			case '-':
				move(x-1, y, LEFT);
				break;
			case 'F':
				move(x-1, y, DOWN);
				break;
			case 'L':
				move(x-1, y, UP);
				break;
		}		
	if(x<LEN-1)
		switch(table[y][x+1])
		{
			case '-':
				move(x+1, y, RIGHT);
				break;
			case '7':
				move(x+1, y, DOWN);
				break;
			case 'J':
				move(x+1, y, UP);
				break;
		}		
		

	return 0;
}			
