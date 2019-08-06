#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *p,n,i,j;
 printf("Enter the size of array");
 scanf("%d",&n);
 p=(int*)calloc(n,sizeof(int));
 printf("\nEnter the elements of array : ");
 for(i=0;i<n;i++)
 scanf("%d",p+i);
 for(i=0;i<n;i++)
 {
  j=n-i;
  while(j>i)
  {
   if(*(p+i)==*(p+j))
    *(p+j)=0;
    j--;
  }
 }
 for(i=0;i<n;i++)
 printf(" %d ",*(p+i));
 printf("\n");
 return 0;
}
