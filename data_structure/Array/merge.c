#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a[10],b[10],n1,n2,i,j,k,*p;
 printf("Enter the number of elemnts of first sorted array : ");
 scanf("%d",&n1);
 printf("\nEnter the number of elemnts of second sorted array : ");
 scanf("%d",&n2);
 printf("\nEnter the elements in sorted order for 1st array "); 
 for(i=0;i<n1;i++)
 scanf("%d",&a[i]);
 printf("\nEnter the elements in sorted order for 2nd array "); 
 for(i=0;i<n2;i++)
 scanf("%d",&b[i]);
 i=0,j=0,k=0;
 int d= n1+n2;
 p=(int*)calloc(d,sizeof(int));
 while(i<n1 && j<n2)
 {
  if(a[i]<=b[j])
  {
   *(p+k)=a[i];
   i++;
   k++;
  }
  else
  {
   *(p+k)=b[j];
   j++;
   k++;
  }
 }
  while(i<n1){
  *(p+k)=a[i++];k++;}
  while(j<n2){
  *(p+k)=b[j++];k++;}
// int d=n1+n2;
 for(i=0;i<k;i++)
 printf("%d\t",*(p+i));
 printf("\n");
 return 0;
}
 
 
