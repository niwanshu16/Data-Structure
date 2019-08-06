 #include<stdio.h>
 struct student
{
 char name[10];
 char address[20];
 int roll,id;
}e;
int main()
{
 printf("Name : ");
 scanf("%[^\n]s",e.name);
 printf("\nAddress : ");
 scanf("\n");
 scanf("%[^\n]s",e.address);
 printf("\nID : ");
 scanf("%d",&e.id);
 printf("\n Roll :");
 scanf("%d",&e.roll);
 printf("Name : %s",e.name);
 printf("\nAddress : %s",e.address);
 printf("\nID : %d",e.id);
 printf("\n Roll :%d",e.roll);
 return 0;
}
