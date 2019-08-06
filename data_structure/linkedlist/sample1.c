#include<stdio.h>
int main()
{
int a=3,b=4;
//for(j=0;j<0;j++)
int carry=a&b;
a=a^b;
b=carry<<1;
printf("%d",a);
return 0;
}
