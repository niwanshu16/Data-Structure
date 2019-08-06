//BUBBLE SORT
#include<stdio.h>
int get_array(int *p,int n)
{
 int i;
 for(i=0;i<n;i++)
 scanf("%d",(p+i));
 return 0;
}
void display_array(int p[],int n)
{
 int i;
 for(i=0;i<n;i++)
 printf("%d\t",*(p+i));
}
 void bubble_sort(int p[],int n)
{
 int i,round,temp,f;
 for(round=1;round<n;round++)
 {
  //f=0;
  for(i=0;i<n-round;i++)
   {
   if(p[i]>p[i+1])
    {
     temp=p[i];
     p[i]=p[i+1];
     p[i+1]=temp;
    // f++;
    }
  }
//  if(f==1)
  // break;
 } 
} 
 int main()
{
 int i,j,a[20],n;
 printf("enter the number of array elements : ");
 scanf("%d",&n);
 printf("Enter the array elements :");
 get_array(a,n);
 display_array(a,n);
 bubble_sort(a,n);
 printf("\nArray in sorted order\n");
 /*for(i=0;i<n;i++)
  printf("%d  ",a[i]);
 printf("\n");*/
 display_array(a,n);
 return 0;
}
