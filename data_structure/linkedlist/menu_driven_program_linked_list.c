#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
}*start=NULL;
struct node* create()
{
  struct node *ptr,*newnode;
  int data,a;
  do
 {
   newnode=(struct node *)malloc(sizeof(struct node));
   scanf("%d",&data);
   newnode->data=data;
   if (newnode==NULL)
   {
     printf("\n Memory Error");
     exit(EXIT_FAILURE);
   }
   if(start==NULL)
   {
     start=newnode;
     ptr=newnode;
     newnode->next=NULL;
   }
   else
   {
    ptr->next=newnode;
    ptr=newnode;
    newnode->next=NULL;
   }
   printf("\n Press 1 if you want to add node else press 0 ");
   scanf("%d",&a);
  }while(a==1);
 return start;
}
void display()
{
 struct node *ptr=start;
 while(ptr)
 {
   printf("%d ",ptr->data);
   ptr=ptr->next;
 }
 printf("\n\v\v\v");
}

void add_node_first()
{
 //struct node *ptr=start;
 struct node *newnode;
 int data;
 scanf("%d",&data);
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=start;
 start=newnode;
}
void add_node_last()
{
 struct node *ptr=start;
 struct node *newnode;
 int data;
 scanf("%d",&data);
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=data;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->next=newnode;
 newnode->next=NULL;
}
 void add_node_before()
{
  struct node *ptr =start;
  struct node *newnode;
  int data;
  scanf("%d",&data);
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->data=data;
  int k;
  printf("\nEnter Position : ");
  scanf("%d",&k);
  while(k>3 && ptr!=NULL )
  {
    ptr=ptr->next;
    k--;
  }
  newnode->next=ptr->next;
  ptr->next=newnode;
}
void add_node_after()
{
  struct node *ptr =start;
  struct node *newnode;
  int data;
  scanf("%d",&data);
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->data=data;
  int k;
  printf("\nEnter Position : ");
  scanf("%d",&k);
  while(k>1 && ptr!=NULL)
  {
    ptr=ptr->next;
    k--;
  }
  newnode->next=ptr->next;
  ptr->next=newnode;
}
 void delete_node_first()
{
  struct node *ptr=start;
  start=start->next;
  ptr->next=NULL;
  free(ptr);
}
 void delete_node_last()
{
 struct node *ptr=start,*prev=start;
 while(ptr->next!=NULL)
 {
  prev=ptr;
  ptr=ptr->next;
 }
  prev->next=NULL;
  ptr->next=NULL;
  free(ptr);
}
void delete_node_before()
{
 struct node *ptr=start,*prev=start;
 int k,pos;
 printf("\n Enter position : ");
 scanf("%d",&k);
 while(ptr!=NULL && pos<k-1)
 {
  prev=ptr;
  pos+=1;
  ptr=ptr->next;
 }
  prev->next=ptr->next;
  ptr->next=NULL;
  free(ptr);
}
void delete_node_after()
{
 struct node *ptr=start,*prev=start;
 int k,pos;
 printf("\n Enter position : ");
 scanf("%d",&k);
 while(ptr!=NULL && pos<k)
 {
  prev=ptr;
  pos+=1;
  ptr=ptr->next;
 }
  prev->next=ptr->next;
  ptr->next=NULL;
  free(ptr);
}
 void reverse_linked_list()
{
  struct node *ptr=NULL,*prev=NULL;
  while(start)
  {
   ptr=start->next;
   start->next=prev;
   prev=start;
   start=ptr;
  }
  start=prev;
}
 void Nth_node()
{
 struct node *ptr=start;
 struct node *prev=start;
 int n,k=0;
 printf("\nEnter Position ");
 scanf("%d",&n);
 while(k<n)
 {
  ptr=ptr->next;
  k+=1;
 }
 while(ptr!=NULL)
 {
  prev=prev->next;
  ptr=ptr->next;
 }
 printf("\n%d\n\v",prev->data);
}
int Loop_Detection()
{
 struct node *fast,*slow;
 fast=start->next;
 slow=start;
 while(slow && fast && fast->next)
 {
  if(slow==fast)
  return 1;
  slow=slow->next;
  fast=fast->next->next;
 }
 return 0;
}
int print_reverse(struct node *p)
{
 if(p==NULL)
  return 0;
 print_reverse(p->next);
 printf("%d ",p->data);
}
int check_pallindrome()
{
 int s[10];
 int top=-1;
 struct node* ptr=start;
 while(ptr)
 {
  top++;
  s[top]=ptr->data;
  ptr=ptr->next;
 }
 ptr=start;
 while(ptr)
 {
  if(s[top]!=ptr->data)
    return 0;
  else
  {
    top--;
    ptr=ptr->next;
  }
 }
 return 1;
}
 int swap_nodes(int x,int y)
{
 if(x==y)
 return 0;
 struct node *currx,*curry,*prevx=NULL,*prevy=NULL;
 currx=start;
 curry=start;
 while(currx && currx->data!=x)
 {
   prevx=currx;
   currx=currx->next;
 }
 while(curry && curry->data!=y)
 {
   prevy=curry;
   curry=curry->next;
 }
 if(prevx!=NULL)
  prevx->next=curry;
 else
  start=curry;
 if(prevy!=NULL)
  prevy->next=currx;
 else
  start=currx;
 struct node*temp=curry->next;
 curry->next=currx->next;
 currx->next=temp;
 return 0;
}

int main(void)
{
 int choice,x,y;
 while(1)
{
 printf(" 1.Create_Linked_List\n 2.Add_Node_First\n 3.Add_Node_Last\n 4.Add_Node_Before\n 5.Add_Node_After\n 6.Delete_Node_First\n 7.Delete_Node_Last\n 8.Delete_Node_Before\n 9.Delete_Node_After\n 10.Reverse_List\n 11.Display_Nth_Node\n 12.Loop Detection\n 13.Print_Reverse\n 14. Check Pallindrome\n 15.Swap_nodes\n 16.Exit\n");
 printf("\n Enter choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
       create();
       display();
       break;
 case 2:
       add_node_first();
       display();
       break;
 case 3:
       add_node_last();
       display();
       break;
 case 4:
       add_node_before();
       display();
       break;
 case 5:
       add_node_after();
       display();
       break;
 case 6:
        delete_node_first();
        display();
        break;
 case 7:
	delete_node_last();
	display();
	break;
 case 8:
	delete_node_before();
	display();
	break;
 case 9:
    	delete_node_after();
	display();
	break;
 case 10:
	reverse_linked_list();
  	display();
        break;
 case 11:
 	Nth_node();
	break;
 case 12:
	if(Loop_Detection())
	   printf("Loop Exists\n");
	else
	   printf("Loop does'nt Exists\n");
  	break;
 case 13:
	print_reverse(start);
	printf("\n");
	break;
 case 14:
         if(check_pallindrome())
	    printf("Linked List is Pallindrome\n");
	 else
	    printf("Linked List is not pallindrome\n");
	 break;
 case 15:
	 printf("Enter the numbers you want to swap\n");
	 scanf("%d%d",&x,&y);
 	 swap_nodes(x,y);
	 display();
	 break;
 case 16:
       exit(EXIT_FAILURE);
 default:
        printf("\nTry Again ");
        break;
 }
}
}

