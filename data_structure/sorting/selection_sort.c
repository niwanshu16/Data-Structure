//SELECTION SORT
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
 void selection_sort(int a[],int n)
{
 int i,j,t,min;
 for(i=0;i<n;i++)
 {
  min=i;
  for(j=i+1;j<n;j++)
  {
   if(a[min]>a[j])
   min=j;
  }
    t=a[min];
    a[min]=a[i];
    a[i]=t;
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
 selection_sort(a,n);
 printf("\nArray elements after sorting : ");
 display_array(a,n);
 return 0;
}
 
 
