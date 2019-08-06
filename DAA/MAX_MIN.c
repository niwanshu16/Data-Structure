#include<stdio.h>
#include<stdlib.h>
void Display(int A[],int size)
{
 for(int i=0;i<size;i++)
  printf("%d ",A[i]);
 printf("\n\n\n\v");
}
// Random Array Generator
int * RandomNumbers(int A[],int size)
{
 for(int i=0;i<size;i++)
 {
   int r=rand()%size;
   A[i]=r;
 }
return A;
}
// Iterative Approach
void max_min(int A[],int size)
{
 int count1=0;
 int max,min;
 max=min=A[0];
 for(int i=1;i<size;i++)
 {
   if(A[i]>max)
   {
    count1++;
    max=A[i];
   }
   if(A[i]<min)
   {
    count1++;
    min=A[i];
   }
  }
  printf("Max : %d , Min : %d Comparisons : %d ",max,min,count1);
}
void max_min_dnc(int A[],int size)
{
 int mid = size/2;
 int mid=size/2,max,min;
 if(size==1)
  max=min=A[size];
 else if(size==2)
 {
  if(A[mid]>A[size])
  {
   max=A[mid];
   min=A[size];
  }
  else
  {
   max=A[size];
   min=A[mid];
  }
 }
 else
 {
   min1=max_min_dnc(A  
  
 
  
int main()
{
 int size;
 printf("Enter the size of Array \n");
 scanf("%d",&size);
 int *A;
 A=malloc(sizeof(int)*size);
 A= RandomNumbers(A,size);
 Display(A,size);
 max_min(A,size);
 return 0;
}
