#include<stdio.h>
#include<stdlib.h>
int main(void)
{
 int *a,n,i,j;
 scanf("%d",&n);
 a=malloc(sizeof(int)*n);
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 int lcs[n+1][n+1];
 for(i=0;i<=n;i++)
  {
   for(j=0;j<=n;j++)
    {
     if(i==0||j==0)
      lcs[i][j]=0;
     else
      lcs[i][j]=a[j-1]*a[i-1];
    }
  }
 
