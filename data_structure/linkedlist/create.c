//To create a linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
}*start=NULL;
int create()
{
 struct node *current=NULL,*newnode=NULL;
 int ch;
 do
 {
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter the data part : ");
   scanf("%d",&newnode->data);
   if(newnode==NULL)
   {
    printf("out of memory\n");
    exit(EXIT_FAILURE);
   }
   newnode->next=NULL;
   if(start==NULL)// it runs during the formation of first node
   {
    start=newnode;//start changes its state from null to the address of newnode
    current=newnode;//and the other pointer stores the address of newnode
   }
   else
   {
    current->next=newnode;//other pointer's next part assigns the newnode address
    current=newnode;
   }
   printf("If you want to add another node than press 1 else press 0 : ");
   scanf("%d",&ch);
 }while(ch==1);
 return 0;
}
int display()
{
 //Display function starts
  struct node *ptr=start;
  if(ptr==NULL)
  {
   printf(" Linked list is empty ");
    return 0;
  }
  while(ptr!=NULL)
    {
     printf("%d ",ptr->data);
     ptr=ptr->next;//increement in ptr to next address
    }
 return 0;
}
int deallocation()
{
 //MEMORY DEALLOCATION
 struct node *ptr=start;
 while(ptr!=NULL)
 {
  start=ptr->next;
  ptr->next=NULL;
  free(ptr);
  ptr=ptr->next;
 }
 return 0;
}
int reverse_list()
{
 struct node *prev=NULL,*ptr=start;
   while(start)
   {
 	 ptr=start->next;
 	 start->next=prev;
	 prev=start;
	 start=ptr;
   }
   
   return 0;  
 }

   
 
int main()
{  
  int choice;
 while(1)
  {
  printf(" 1. Create_Linked_List \n 2 . Display_List \n 3. Deallocation \n 4. Reverse_list \n 5. Exit \n");
  printf("Enter the choice\n");
  scanf("%d",&choice);
     switch(choice)
    {
     case 1:
   		    create();
   		    break;
     case 2:
   			display();
   			break;
     case 3:
            deallocation();
            break;
     case 4:
      	 	reverse_list();
      	 	break;
     case 5:
   			exit(EXIT_FAILURE);
   			break;
     default:
   			printf("Try Again\n");
  }
 }
   return 0;
}

