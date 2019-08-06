#include<stdio.h>
 int a[4][4]={{0,1,1,0},{0,0,1,0},{0,0,0,0},{0,1,1,0}};
int check(int m,int n)
{
 int j=0;
 if(m==4&&n==4)
  ++j;
 a[m-1][n]=1;
 if(a[m][n]==0)
  check(m+1,n);
 else if(a[m][n]==0)
  check(m,n+1);
 printf("%d",j);
  return 0;
}
int main()
{
  int i=1,j=1;
  if(a[1][1]==1&&a[4][4]==1){
   printf("There is no way ");
  return 0;
  }
  while(i<=4 && j<=4)
  {
   if(a[i][j]==0)
   {
     check(i+1,j);
     //check(i,j+1);
   }
    i++;
    j++;
  }
   return 0;
}
