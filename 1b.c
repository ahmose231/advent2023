#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 64

int main()
{
	int sum=0;
	int n1,n2;
	char line[LEN];
	char digits[9][6]={"one", "two", "three", "four",
						"five", "six", "seven", "eight", "nine"};

	
	while(fgets(line,LEN,stdin)!=NULL)
	{
		int len=strlen(line);
		int i=0;
		n1=n2=0;	
		int out=0;
		for(;i<len;i++)
		{
			if(line[i]>='0'&&line[i]<='9')
			{
				n1=n2=line[i]-'0';
				break;
			}
			
			else
			{
				for(int j=0;j<9;j++)
				{
					int len2=strlen(digits[j]);
					int flag=1;
					for(int k=0;k<len2;k++)
					{
						if(digits[j][k] != line[i+k])
						{
							flag=0;
							break;
						}
					}
					
					if(flag)
					{
						n1=n2=j+1;
						out=1;
						break;
					}

				}
				if(out) break;
			}		
		}
		
		for(i++;i<len;i++)
		{
			if(line[i]>='0'&&line[i]<='9')
				n2=line[i]-'0';
				
			else
			{
				for(int j=0;j<9;j++)
				{
					int len2=strlen(digits[j]);
					int flag=1;
					for(int k=0;k<len2;k++)
					{
						if(digits[j][k] != line[i+k])
						{
							flag=0;
							break;
						}
					}
					
					if(flag)
						n2=j+1;

				}
			}		
		}

		sum+=n1*10;
		sum+=n2;
	}
	
	printf("\n\n %d\n",sum);
	return 0;
}
