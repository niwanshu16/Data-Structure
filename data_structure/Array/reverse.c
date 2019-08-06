#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,*p,i,t,pos,k;
 printf("Enter the size :");
 scanf("%d",&n);
 p=(int*)calloc(n+1,sizeof(int));
 printf("Enter the position on which you want to insert a number : ");
 scanf("%d",&pos);
 printf("\nEnter the number you want to insert");
 scanf("%d",&k); 
 printf("\nEnter the elements");
 for(i=0;i<n;i++)
 scanf("%d",p+i);
 for(i=n-1;i>=pos-1;i--)
  *(p+i+1)=*(p+i);
 *(p+pos-1)=k;
 for(i=0;i<=n;i++)
 printf("%d ",*(p+i));
 return 0;
}
