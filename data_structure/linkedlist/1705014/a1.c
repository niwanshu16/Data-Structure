#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next=(struct node*)malloc(sizeof(struct node));
}*start=NULL;

void create(int n)
{
struct nodee *new=(struct node*)malloc(sizeof(struct node));
new->data=n;
new->next=NULL;
if (start==NULL)
{
start=new;
}
else
{

while(temp->next!=NULL)
{temp=temp->next;}
temp->next=new;
}
}

void check_p()
{
	
}




















