#include<stdio.h>
int main()
{
 int a[10][10],i,j,round,p,t,k=0,r,c;
 printf("Enter Row and column\n");
 scanf("%d%d",&r,&c);
//Enter the array elements
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   scanf("%d",&a[i][j]);
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   for(round=1;round<c-j+1;round++)
   {
   for(k=0;k<c-1;k++)
    {
     if(a[j][k]>a[j][k+1])
      {
	t=a[j][k];
	a[j][k]=a[j][k+1];
	a[j][k+1]=t;
      }
      if(a[k][j]>a[k+1][j])
      {
     	t=a[k][j];
	a[k][j]=a[k+1][j];
	a[k+1][j]=t;
      }
    }
   } 
  }
 }
  for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   printf("%d ",a[i][j]);
   printf("\n");
  }
return 0;
}   
