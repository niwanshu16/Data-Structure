#include<stdio.h>
#include<stdlib.h>
int * insertion(int*,int,int,int);
int main()
{
 int *p,n,pos,k,i;
scanf("%d",&n);
 p=(int *)malloc((n+1)*sizeof(int));
 for(i=0;i<n;i++)
  scanf("%d",(p+i));
 printf("\nPosition of insertion : ");
 scanf("%d",&pos);
 printf("\n Number which you want to insert : ");
 scanf("%d",&k);
 p=insertion(p,n,pos,k);
for(i=0;i<n+1;i++)
 printf("%d\t",*(p+i));
printf("\n");
 return 0;
}
int*insertion(int *p,int n,int pos,int k)
{
 for(int i=n;i>=pos-1;i--)
   *(p+i)=*(p+i-1);
  *(p+pos-1)=k;
 return p;
}
 
 
 
