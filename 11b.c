#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 140
#define EXPFACTOR 1000000-1

int m[LEN][LEN];

int main()
{
	char line[LEN+2];
	int linecount=0;
	
	while(fgets(line,LEN+2,stdin)!=NULL)
	{
		if(strlen(line)<2) continue;
		for(int i=0;i<LEN;i++)
			m[linecount][i] = line[i];
		linecount++;
	}
	
	int gcount=0;
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
			if(m[i][j]=='#')
				gcount++;
	
	int g[gcount][2];
	int k=0;
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
			if(m[i][j]=='#')
			{
				g[k][0]=i;
				g[k][1]=j;
				k++;
			}
	
	int rowblank[LEN+LEN];
	int rbcount=0;
	
	
	for(int i=0;i<LEN;i++)
	{
		int flag=1;
		for(int j=0;j<LEN;j++)
			if(m[i][j]=='#')
				flag=0;
		if(flag)
			rowblank[rbcount++]=i;
		
	}
	
	int colblank[LEN+LEN];
	int cbcount=0;
	
	for(int i=0;i<LEN;i++)
	{
		int flag=1;
		for(int j=0;j<LEN;j++)
			if(m[j][i]=='#')
				flag=0;
		if(flag)
			colblank[cbcount++]=i;
	
	}
	
	long int sum=0;
	
	for(int i=0;i<gcount-1;i++)
		for(int j=i+1;j<gcount;j++)
		{
			sum += abs(g[j][0] - g[i][0]);
			sum += abs(g[j][1] - g[i][1]);
			

			int min, max;
			if(g[i][0]<g[j][0])
			{
				min=g[i][0];
				max=g[j][0];
			}
			else
			{
				max=g[i][0];
				min=g[j][0];
			}				
			for(int a=0;a<rbcount;a++)
				if(rowblank[a]>min && rowblank[a]<max)
					sum+=EXPFACTOR;	

			
			if(g[i][1]<g[j][1])
			{
				min=g[i][1];
				max=g[j][1];
			}
			else
			{
				max=g[i][1];
				min=g[j][1];
			}	

			for(int a=0;a<cbcount;a++)
				if(colblank[a]>min && colblank[a]<max)
					sum+=EXPFACTOR;
	
		}
	
	printf("%ld\n",sum);
	return 0;
}
