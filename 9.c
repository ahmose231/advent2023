#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1024
#define MAXN 32

struct node {
	int content;
	struct node* next;
};

int lastnumbers[MAXN];
int lastindex;

int sum=0;

void go_up()
{
	for(int i=1;i<lastindex;i++)
		lastnumbers[i] += lastnumbers[i-1];

	sum += lastnumbers[lastindex-1];
	return;
}

void go_down(struct node *head)
{
	struct node *downhead = malloc(sizeof(struct node));
	downhead->next = NULL;

	struct node *downcurrent;
	downcurrent = downhead;
	
	struct node *current;
	current = head;
	
	downcurrent->content = current->next->content - current->content;
	current = current->next;
	while(current->next!=NULL)
	{
		struct node *newnode = malloc(sizeof(struct node));
		downcurrent->next = newnode;
		downcurrent = newnode;
		downcurrent->next = NULL;
		downcurrent->content = current->next->content - current->content;
	
		current = current->next;
	}
	
	lastnumbers[lastindex++] = current->content;
	
	int flag=1;
	downcurrent = downhead;
	
	while(downcurrent!=NULL)
	{
		if(downcurrent->content!=0)
		{
			flag=0;
			break;
		}
		
		downcurrent = downcurrent->next;
	}
	
	if(flag)
		go_up();
	else
		go_down(downhead);
		
	return;
}
		



void process_array(int input[], int inputcount)
{
	struct node *head = malloc(sizeof(struct node));
	head->content = input[0];
	head->next = NULL;
	struct node *current;
	current=head;
	for(int i=1; i<inputcount; i++)
	{
		struct node *newnode = malloc(sizeof(struct node));
		current->next = newnode;
		current = newnode;
		current->content = input[i];
		current->next = NULL;
	}
	lastindex=0;
	go_down(head);
	return;
}
		
		
int main()
{
	char line[LEN];
	while(fgets(line,LEN,stdin)!=NULL)
	{
		if(strlen(line)<2) continue;
		
		char*token;
		token=strtok(line," ");
		
		int input[MAXN];
		int inputcount=0;
	
		while(token!=NULL)
		{
			input[inputcount++]=atoi(token);
			token=strtok(NULL," ");
		}
		
		process_array(input, inputcount);
	}		
	
	printf("%d\n",sum);
	return 0;

}
