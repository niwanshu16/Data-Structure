//Sum of Matrix by passing array
#include<stdio.h>
#include<stdlib.h>
int** matrix_sum(int **,int **,int,int,int**);
int main()
{
 int **p,r,c,i,**q,**h;
 scanf("%d%d",&r,&c);
 p=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++)
  *(p+i)=(int *)malloc(c*sizeof(int));
 for(i=0;i<r;i++)
  for(int j=0;j<c;j++)
   scanf("%d",(*(p+i)+j));
 q=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++)
  *(q+i)=(int *)malloc(c*sizeof(int));
 for(i=0;i<r;i++)
  for(int j=0;j<c;j++)
   scanf("%d",(*(q+i)+j));
 h=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++)
  *(h+i)=(int *)malloc(c*sizeof(int));
 h=matrix_sum(p,q,r,c,h);
 for(i=0;i<r;i++){
  for(int j=0;j<c;j++)
   printf("%d ",*(*(h+i)+j));
    printf("\n");}
 for(i=0;i<r;i++)
 {
  free(*(p+i));
  free(*(q+i));
  free(*(h+i));
 }
  free(p);
  free(q);
  free(h);
 return 0;
}
 int** matrix_sum(int **p,int **q,int r,int c,int **h)
{
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
   *(*(h+i)+j)=*(*(p+i)+j)+(*(*(q+i)+j));
  return h;
}
 
  
 
