#include<stdlib.h>
#include<stdio.h>
struct BST
{
 int data;
 struct BST *left,*right;
};
struct ArrayQueue
{
 int front,rear;
 int capacity;
 struct BST **array;
};
struct ArrayQueue* CreateQueue(int size)
{
 struct ArrayQueue* Q =malloc(sizeof(struct ArrayQueue));
 Q->front=Q->rear=-1;
 Q->capacity=size;
 Q->array=malloc(sizeof(struct BST *)*Q->capacity);
 if(!Q->array)
 {
  printf("MemoryError\n");
  return 0;
 }
 int i;
 for(i=0;i<size;i++)
 Q->array[i]=NULL;
 return Q;
}
 int IsFullQueue(struct ArrayQueue *Q)
 {
  return (Q->rear+1)%Q->capacity==Q->front;
 }
 int IsEmptyQueue(struct ArrayQueue *Q)
{
 return Q->front==-1;
}
  int EnQueue(struct ArrayQueue *Q,struct BST *data)
 {
  if(IsFullQueue(Q))
  {
   printf("Overflow\n");
   return 0;
  }
  else
  {
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->array[Q->rear]=data;
    if(Q->front==-1)
     Q->front=Q->rear;
  }
 }
 struct BST* DeQueue(struct ArrayQueue *Q)
 {
   struct BST* data;
   if(IsFullQueue(Q))
   {
    printf("Queue is Empty\n");
    return 0;
   }
   else
   {
    data=Q->array[Q->front];
    if(Q->front==Q->rear)
     Q->rear=Q->front=-1;
    else
     Q->front=(Q->front+1)%Q->capacity;
   }
  return data;
 }
 void DeleteQueue(struct ArrayQueue *Q)
 {
  if(Q)
  {
    if(Q->array)
     free(Q->array);
    free(Q);
  }
 }
 struct BST* CreateNode(int data)
{
 struct BST* newnode=malloc(sizeof(struct BST));
 newnode->left=newnode->right=NULL;
 newnode->data=data;
 return newnode;
}
int PreOrder(struct BST *root)
{
 if(!root)
  return 0;
 printf("%d ",root->data);
 PreOrder(root->left);
 PreOrder(root->right);
}
int CreateTree(struct BST **root,int data)
{
 struct BST *newNode,*temp;
 struct ArrayQueue *Q;
 newNode=CreateNode(data);
 if(!*root){
  *root=newNode;
  return 0;
 }
 else
 {
  Q=CreateQueue(10);
  EnQueue(Q,*root);
  while(!IsEmptyQueue(Q))
  {
   temp=DeQueue(Q);
   if(temp->left)
    EnQueue(Q,(temp->left));
   else
   {
    temp->left=newNode;
    DeleteQueue(Q);
    return 0;
   }
   if(temp->right)
    EnQueue(Q,(temp->right));
   else
   {
    temp->right=newNode;
    DeleteQueue(Q);
    return 0;
   }
  }
 }   
}
int main(void)
{
 struct BST *root=NULL;
 int data;
 char ch;
 do
 {
  printf("Enter Data\n");
  scanf("%d",&data);
  CreateTree(&root,data);
  printf("Press y/n\n ");
  scanf("%s",&ch);
 }while(ch=='y');
 PreOrder(root);
 return 0;
}
  
  
  
 

     
 
