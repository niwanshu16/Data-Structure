#include<stdio.h>
#include<stdlib.h>

// HeapSort
int Left(int i)
{
  return(2*i+1);
}
int Right(int i)
{
 return (2*i+2);
}

void Heapify(int A[],int n,int i)
{
 int l,r,max=i;
 l = Left(i);
 r = Right(i);
 if( l < n && A[l]>A[i])
  max = l;
 else
  max = i;
 if( r < n && A[r]>A[max])
  max = r;
 if(max!=i)
 {
  int temp;
  temp = A[max];
  A[max] = A[i];
  A[i] = temp;
  Heapify(A,n,max);
 }
}

void HeapSort(int A[] , int n)
{
 int i;
 for(i=n/2-1;i>=0;i--)
  Heapify(A,n,i);
 for(i=n-1 ; i>=0 ; i--)
 {
  int temp = A[i];
  A[i] = A[0];
  A[0] = temp;
  Heapify(A,i,0);
 }
} 
 
void Display(int A[],int n)
{
 HeapSort(A,size);
 Display(A,size);
 return 0;
}

