#include<stdio.h>
void swap1(int,int);
void swap2(int *,int *);
void swap3(int &,int &);
int main()
{
 int a,b;
 scanf("%d%d",&a,&b);
 printf("Before Swapping\n");
 printf("%d %d",a,b);
 printf("\nAfter Swapping\n Call by value\n");
 swap1(a,b);
 printf("%d %d",a,b);
 printf("\nCall by address");
 swap2(&a,&b);
 printf("%d %d",a,b);
 printf("\nCall by reference\n");
 swap3(a,b);
 printf("%d %d\n",a,b);
 return 0;
}
void swap1(int a,int b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
 void swap2(int*a,int*b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}
void swap3(int&a,int&b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}

