#include<stdio.h>
int Prims(int mat[6][6],int n)
{
 int cost[n][n],u,v,min_distance,distance[n],from[n],visited[n],no_of_edges,i,min_cost,j;
 int spanning[n][n];
 //create cost[][]matrix , spanning[][]
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
    if(mat[i][j]==0)
      cost[i][j]=9999;
    else
      cost[i][j]=mat[i][j];
    spanning[i][j]=0;
  }
 
//Initialize visited , distance and from

 distance[0]=0;
 visited[0]=1;
 
 for(i=0;i<n;i++)
 {
   distance[i]=cost[0][i];
   from[i]=0;
   visited[i]=0;
 }
 min_cost=0;
 //cost of spanning trees
 no_of_edges =n-1;
 
 while(no_of_edges>0)
 {
  min_distance = 9999;
  for(i=1;i<n;i++)
   if(visited[i]==0 && distance[i]<min_distance)
   {
    v=i;
    min_distance = distance[i];
   }
   u=from[v];
  spanning [u][v] = distance[v];
  spanning[v][u]=distance[v];
  no_of_edges--;
  visited[v]=1;
 
  for(i=1;i<n;i++)
  {
    if(visited[i]==0 && cost[i][v]<distance[i])
    {
     distance[i] =  cost[i][v];
     from[i] =v;
    }
  }
  min_cost +=cost[u][v];
 }
 for(i=0;i<n;i++)
 {
  printf("\n");
  for(j=0;j<n;j++)
   printf("%d\t ",spanning[i][j]);
  }
  return(min_cost);
}   
int main(void)
{
 int G[6][6]={{0,3,1,6,0,0},
	      {3,0,5,0,3,0},
	       {1,5,0,5,6,4},{6,0,5,0,0,2},{0,3,6,0,0,6},{0,0,4,2,6,0}};
 Prims(G,6);
 return 0;
}
 
