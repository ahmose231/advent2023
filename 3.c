#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 140

int is_sign(int c)
{
	if(c<'0'||c>'9')
		if(c!='.')
			return 1;
	return 0;
}

int main()
{
	char table[LEN][LEN];
	int c;
	int x=0;
	int y=0;
	c=getchar();
	while(c!=EOF)
	{
		if(c=='\n')
		{
			y++;
			x=0;
		}
		else
		{
			table[y][x++]=c;
		}
		c=getchar();
	}
		
	int sum=0;

	for(int s=0;s<LEN;s++)
	{
		int i=0;
		for(;i<LEN;i++)
		{
			if(table[s][i]>='0' && table[s][i]<='9')
			{
				int n;
				char token[4];
				int k=0;
				for(;i<LEN;i++)
				{
					if(table[s][i]<'0'||table[s][i]>'9')
						break;
					token[k++]=table[s][i];
				}
				token[k]=0;
				n=atoi(token);
				
				int flag=0;
				if(s>0)
				{
					if(i-k>0)
						if(is_sign(table[s-1][i-k-1]))
							flag=1;
					for(int t=0;t<k;t++)
						if(is_sign(table[s-1][i-k+t]))
							flag=1;
					if(i<LEN-1)
						if(is_sign(table[s-1][i]))
							flag=1;
				}
				
				if(i-k>0)
					if(is_sign(table[s][i-k-1]))
						flag=1;
				if(i<LEN-1)
					if(is_sign(table[s][i]))
						flag=1;
				
				if(s<LEN-1)
				{
					if(i-k>0)
						if(is_sign(table[s+1][i-k-1]))
							flag=1;
					for(int t=0;t<k;t++)
						if(is_sign(table[s+1][i-k+t]))
							flag=1;
					if(i<LEN-1)
						if(is_sign(table[s+1][i]))
							flag=1;
				}			
				
				if(flag)
				{	
					
					sum+=n;
				}
			}
		}
	}
	
	printf("%d\n",sum);

		
	
	return 0;
}
