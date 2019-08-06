#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition1(int A[],int,int);
int partition2(int A[],int,int);
void QuickSort(int A[],int start,int end,int key)
{
 int q,Q;
  if(key==1)
  {
   if(start<end)
   {
    q=partition1(A,start,end);
    QuickSort(A,start,q-1,1);
    QuickSort(A,q+1,end,1);
   }
  }
  else
  {
    if(start<end)
   {
    Q=partition2(A,start,end);
    QuickSort(A,start,Q-1,0);
    QuickSort(A,Q+1,end,0);
   }
  }
}
int partition1(int A[],int low,int high)
{
 int left,right,pivot;
 left=low;
 right = high;
 pivot = A[low];
 while(left < right)
 {
  while(A[left] <= pivot)
   left+=1;
  while(A[right] > pivot)
   right-=1;
  if(left < right)
  {
   int temp;
   temp = A[left];
   A[left] = A[right];
   A[right] = temp;
  }
 }
 A[low]=A[right];
 A[right]=pivot;
 return right;
}
int partition2(int A[],int low,int high)
{
 int left,right,pivot;
 left=low;
 right = high;
 pivot = A[low];
 while(left < right)
 {
  while(A[left] >= pivot)
   left+=1;
  while(A[right] < pivot)
   right-=1;
  if(left < right)
  {
   int temp;
   temp = A[left];
   A[left] = A[right];
   A[right] = temp;
  }
 }
 A[low]=A[right];
 A[right]=pivot;
 return right;
}
int Display(int A[],int size)
{
 for(int i=0;i<size;i++)
  printf("%d ",A[i]);
 printf("\n\n\n");
}
void BestCase(int A[],int size)
{
 int start,end;
 start=clock();
 end = clock();
 printf("\nBestCase : %d\n",(end-start));
}

void WorstCase(int A[],int size)
{
 int start,end;
 QuickSort(A,0,size,1);
 start = clock();
 QuickSort(A,0,size,1);
 end = clock();
 printf("\n WorstCase : %d \n",(end-start));
}
void AverageCase(int A[] , int size)
{
 int start,end;
 start=clock();
 QuickSort(A,0,size,1);
 end = clock();
 printf("\n AverageCase : %d\n",(end-start));
}
int main()
{
 int *A,size,choice;
 while(1)
 {
 printf(" 1. Generating Array \n 2. Sorting(Ascending) \n 3.Sorting(Descending) \n 4.BestCase \n 5. AverageCase \n 6. WorstCase \n 7.Exit\n");
 printf("\n Enter Choice ");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
	 printf("Enter Size\n");
 	 scanf("%d",&size);
	 A = malloc(sizeof(int)*size);
 	 for(int i=0;i<size;i++)
	 {
  	  int r= rand()%size;
          A[i] = r;
 	 }
	 Display(A,size);
	 break;
 case 2:
	 QuickSort(A,0,size,1);
 	 Display(A,size);
	 break;
 case 3:
	 QuickSort(A,0,size,0);
 	 Display(A,size);
	 break;
 case 4:
 	 BestCase(A,size);
	 break;
 case 5:
	 AverageCase(A,size);
	 break;
 case 6:
	 WorstCase(A,size);
	 break;
 case 7:
         exit(EXIT_FAILURE);
  }
 }
 return 0;
}
 
