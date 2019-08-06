//Tuesday 29 January 2019 07:38:31 PM IST 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Merge(int*,int*,int,int,int,int);
void MergeSort(int A[],int temp[],int left , int right,int order)
{
  int mid;
  if(left<right)
  {
    mid=(left+right)/2;
    MergeSort(A,temp,left,mid,order);
    MergeSort(A,temp,mid+1,right,order);
    Merge(A,temp,left,mid+1,right,order);
  }
}
void Merge(int A[],int temp[],int left,int mid,int right,int order)
{
 int size=right-left+1;
 int left_end=mid-1;
 int temp_pos=left;
 if(order)
 {
  while(left<=left_end && mid<=right)
  {
   if(A[left]<A[mid])
   {
     temp[temp_pos]=A[left];
     left+=1;
     temp_pos+=1;
   }
   else
   {
     temp[temp_pos]=A[mid];
     mid+=1;
     temp_pos+=1;
   }
  }
 }
 else
 {
   while(left<=left_end && mid<=right)
  {
   if(A[left]>A[mid])
   {
     temp[temp_pos]=A[left];
     left+=1;
     temp_pos+=1;
   }
   else
   {
     temp[temp_pos]=A[mid];
     mid+=1;
     temp_pos+=1;
   }
  }
 }
 while(left<=left_end)
 {
   temp[temp_pos]=A[left];
   left+=1;
   temp_pos+=1;
 }
 while(mid<=right)
 {
   temp[temp_pos]=A[mid];
   mid+=1;
   temp_pos+=1;
 }
 for(int i=0;i<=size;i++)
 {
   A[right]=temp[right];
   right-=1;
 }
}
void Display(int A[],int size)
{
  for(int i=0;i<size;i++)
     printf("%d ",A[i]);
  printf("\n\n\n\v");
}  
int * RandomNumbers(int A[],int size)
{
 for(int i=0;i<size;i++)
 {
  int r=rand()%size;
  A[i]=r;
 }
 return A;
}
void BestCase(int A[],int temp[],int size)
{
 Display(A,size);
 int start=clock();
 //printf("%d \n",&start);
 MergeSort(A,temp,0,size,1);
 int end=clock();
 printf("BestCase : %d \n",(end-start));
}
void WorstCase(int A[],int temp[],int size)
{
 Display(A,size);
 int start=clock();
 //printf("%d \n",&start);
 MergeSort(A,temp,0,size,0);
 int end=clock();
 printf("WorstCase : %d \n",(end-start));
}
void AverageCase(int A[],int temp[],int size)
{
 Display(A,size);
 int start=clock();
 //printf("%d \n",&start);
 MergeSort(A,temp,0,size,1);
 int end=clock();
 printf("AverageCase : %d \n",(end-start));
}
int main()
{
 int size,choice;
  int *A,*temp;
 while(1)
 {
 printf("0. Exit\n 1. GeneratingArray \n 2.Display\n 3.Ascending_Sort\n 4. Descending_Sort \n 5.BestCase 6.    WorstCase \n 7.AverageCase \n ");
 printf("Enter Choice \n");
 scanf("%d",&choice);
 switch(choice)
 {
   case 0:
	  exit(EXIT_FAILURE);
	  break;
   case 1:
     	  printf("Enter the size of array\n");
 	  scanf("%d",&size);
          A= malloc(sizeof(int)*size);
	  temp=malloc(sizeof(int)*size);
          A=RandomNumbers(A,size);
          break;
   case 2:
          Display(A,size);
          break;
   case 3:
          MergeSort(A,temp,0,size,1);
          Display(A,size);
	  break;
   case 4:
 	  MergeSort(A,temp,0,size,0);
 	  Display(A,size);
	  break;
   case 5:
	  MergeSort(A,temp,0,size,1);
          BestCase(A,temp,size);
	  break;
   case 6:
	  MergeSort(A,temp,0,size,0);
          WorstCase(A,temp,size);
	  break;
   case 7:
   	  A=RandomNumbers(A,size);
	  AverageCase(A,temp,size);
	  break;
  }
 }
 return 0;
}
