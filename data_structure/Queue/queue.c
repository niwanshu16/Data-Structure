#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
struct Queue
{
 int front,rear;
 int capacity;
 int *array;
};
struct Queue * CreateQueue(int size)
{
 struct Queue *Q=malloc(sizeof(struct Queue));
 Q->front=Q->rear=-1;
 Q->capacity=size;
 Q->array=malloc(sizeof(int)*size);
 if(!Q->array)
  return NULL;
 return Q;
}
int IsEmptyQueue(struct Queue *Q)
{
 return (Q->front==-1);
}
int IsFullQueue(struct Queue *Q)
{
 return ((Q->rear+1)%Q->capacity==Q->front);
}
void EnQueue(struct Queue *Q,int data)
{
 if(IsFullQueue(Q))
    printf("Queue Overflow\n");
 else
 {
  Q->rear=(Q->rear+1)%Q->capacity;
 	Q->array[Q->rear]=data;
  if(Q->front==-1)
		Q->front=Q->rear;
 }
}
int DeQueue(struct Queue *Q)
 { 
 	int data;
	if(IsEmptyQueue(Q))
		printf("Queue Is Empty\n");
  else
	{
		data=Q->array[Q->front];
		if(Q->front==Q->rear)
			Q->front=Q->rear=-1;
		else
			Q->front=(Q->front+1)%Q->capacity;
	}
	return data;
 }
 void DeleteQueue(struct Queue *Q)
 {
  if(Q)
  {
   if(Q->array)
		free(Q->array);
	 free(Q);
	}
 }
int main(void)
{
 struct Queue *Q;
 Q=CreateQueue(10);
 for(int i=1;i<6;i++)
 	EnQueue(Q,i);
 for(int i=0;i<5;i++)
 {
  int x;
  x=DeQueue(Q);
  printf("%d ",x);
 }
 DeleteQueue(Q);
 return 0;
}
   
