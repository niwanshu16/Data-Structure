//Addition of all elements of an array using array
#include<stdio.h>
#include<stdlib.h>
int sum_array(int *,int);
int * create_array(int *p,int n)
{
  p=(int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
   scanf("%d",(p+i));
  return p;
}
int main()
{
 int *p,n,i,sum=0;
 scanf("%d",&n);
 p=create_array(p,n);
 sum=sum_array(p,n);
 printf("%d",sum);
 return 0;
}
 int sum_array(int *p,int n)
{
 int i,sum=0;
 for(i=0;i<n;i++)
  sum+=*(p+i);
 return sum;
}
 
 
 
