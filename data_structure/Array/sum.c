#include<stdio.h>
int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  int c=printf("%*c%*c",a,'\r',b,'\r');
  printf("%d",c);
}
