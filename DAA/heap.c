#include<stdio.h>
int Left(int n,int i)
{
 if(n>2*i+1)
 return 2*i+1;
 return -1;
}
int Right(int n,int i)
{
 if(n>2*i+2)
  return 2*i+2;
 return -1;
}
void Heapify(int a[20],int i,int n)
{
 int l,r,largest = i,temp;
 l= Left(n,i);
 r = Right(n,i);
 if(a[i]<a[l] && l!=-1)
  largest = l;
 if(a[largest]<a[r] && r!=-1)
  largest = r;
 if(largest!=i && i>=0)
 {
  temp = a[largest];
  a[largest]=a[i];
  a[i]=temp;
  Heapify(a,largest,n);
 }
}
int main(void)
{
  int a[20],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  for(i=n/2;i>=0;i--)
   Heapify(a,i,n);
  for(i=0;i<n;i++)
   printf("%d ",a[i]);
  printf("\n");
  //Deletion
  for(i=n-1;i>=0;i--)
  {
    int temp;
    temp=a[0];
    a[0]=a[i];
    a[i]=temp;
    Heapify(a,0,i);
  }
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
 return 0;
}
 
