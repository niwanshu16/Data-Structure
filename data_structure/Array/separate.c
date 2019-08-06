#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *p,n,i,j,f,k;
 printf("Enter the size of an array");
 scanf("%d",&n);
 p=(int*)calloc(n,sizeof(int));
 printf("\nEnter the elements ");
 for(i=0;i<n;i++)
  scanf("%d",p+i);
 for(i=0;i<n;i++)
 {
 //  f=0;
   if(*(p+i)==0)
  {
   // f=1;
   for(j=i+1;j<n;j++)
    {
     if(*(p+j)!=0)
      {
       *(p+i+k)=*(p+j);
       *(p+j)=0;
	k++;
      }
    }
   }
  //if(f==0)
  //break;
 }
 printf("\n After separation ");
 for(i=0;i<n;i++)
 printf("%d  ",*(p+i));
 return 0;
}
