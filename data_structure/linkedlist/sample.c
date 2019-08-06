#include<stdio.h>
#include<stdlib.h>
int *stack,top;
int main()
{
 int t,n,k,i,num;
 scanf("%d",&t);
  while(t>0)
  {
   scanf("%d%d",&n,&k);
   stack=(int*)calloc(n,sizeof(int));
   top=-1;
   scanf("%d",&num);
   top++;
   stack[top]=num;
   for(i=1;i<n;i++)
   {
     scanf("%d",&num);
     while(k>=1&&num>stack[top]&&top!=-1)
     {
       top--;
       k--;
     }
     top++;
     stack[top]=num;
   }
   while(k>=1)
   {
    top--;
    k--;
   }
   for(i=0;i<=top;i++)
   printf("%d ",stack[i]);
   t--;
   free (stack);
 }
   printf("\n");
   return 0;
}
     
     
     
     
     
     
     
     
     
     
