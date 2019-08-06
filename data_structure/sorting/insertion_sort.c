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
 void insertion_sort(int a[],int n)
{
 int i,j,temp;
 for(i=1;i<n;i++)
 {
   j=i-1;
   temp=a[i];
   while(a[j]>temp && j>=0)
   {
    a[j+1]=a[j];
    j--;
   }
   a[j+1]=temp;
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
 insertion_sort(a,n);
 printf("\nArray elements after sorting : ");
 display_array(a,n);
 return 0;
}
 
 
