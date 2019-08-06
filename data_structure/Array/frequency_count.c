#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *p,a[10],n,i,temp,j=0,max=0;
 printf("Enter the size : ");
 scanf("%d",&n);
 printf("\nEnter the elements :  ");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {
   if(max<a[i])
    max=a[i];
  }
 p=(int*)calloc(max+1,sizeof(int));
 for(i=0;i<n;i++)
 {
   ++p[a[i]];
 }
 for(i=1;i<=max;i++)
 if(p[i]!=0)
 printf(" %d--->%d \n",i,p[i]);
 free(p);
 return 0;
}
