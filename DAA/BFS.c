#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visited[50];
void Display(int G[50][50],int v)
{
 printf("\n Adjacency Matrix \n");
 for(int i=0;i<v;i++)
 {
  for(int j=0;j<v;j++)
   printf("  %d    ",G[i][j]);
  printf("\n");
 }
 printf("\n");
}
// This code creates a graph with adjacency matrix
void adjMatrixOfGraph(int G[50][50],int v,int e)
{
 int i,x,y,j,distance;
 for(i=0;i<v;i++)
  for(j=0;j<v;j++)
   G[i][j]=0;
 for(i=0;i<e;i++)
 {
  // Read an Edge
  printf("\n Reading Edge :");
  scanf("%d%d",&x,&y);
  printf("\n Enter Distance(Kms) between the cities you mentioned above : ");
  scanf("%d",&distance);
  //For directed graphs set 1 bit to 1
  G[x][y]=distance;
  G[y][x]=distance;
 }
 Display(G,v);
}
//Depth First Search Traversal
int DFS(int G[50][50],int k,int v,int e)
{
  visited[k]=1;
  printf("%d ",k);
  for(int j=0;j<v;j++)
   if(G[k][j] && !visited[j])
    DFS(G,j,v,e);
}
 void DFStraversal(int G[50][50],int v,int e)
{
 int i;
 for(i=0;i<v;i++)
  visited[i]=0;
 for(i=0;i<v;i++)
  if(!visited[i])
   DFS(G,i,v,e);
 printf("\n");
}
int Prims(int mat[50][50],int n)
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
//Minimum Spanning Tree Djikstra
int print_solution(int distance[50],int v)
{
 printf("\n\n\nVertex\t Distance from Source\n");
 for(int i=0;i<v;i++)
  printf("%d \t\t %d \n",i,distance[i]);
 return 0;
}
int minDistance(int distance[50],int boolean[50],int v)
{
   int min=10000,min_index;
   for(int i=0;i<v;i++)
    if(!boolean[i] && distance[i]<=min)
    {
     min=distance[i];
     min_index=i;
    }
    return min_index;
}
void Djikstra(int G[50][50],int src,int v)
{
 int distance[v],boolean[v];
 for(int i=0;i<v;i++)
 {
   distance[i]=10000;
   boolean[i]=0;
 }
  //Distance from src to same vertex is 0
  distance[src]=0;
  for(int count=0;count<v-1;count++)
  {
    int u = minDistance(distance,boolean,v);
    boolean[u]=1;
    for(int j=0;j<v;j++)
     if(!boolean[j]&& G[u][j] && distance[u]!=10000 && ((distance[u] + G[u][j])<distance[j]))
      distance[j]=G[u][j]+distance[u];
  }
 print_solution(distance,v);
}
int main(void)
{
 int G[50][50],i,j,v,e;
 printf("Codes for following City \n");
 printf("Mumbai : 0 \n Shimla : 1 \n Jaipur : 2 \n Kolkata : 3 \n Chennai : 4 \n Bhubhaneswar : 5 \n");
 printf("\n Number of Vertices and Edges : ");
 scanf("%d%d",&v,&e);
 adjMatrixOfGraph(G,v,e);
 DFStraversal(G,v,e);
 printf("\n");
 Prims(G,v);
 Djikstra(G,0,v);
 printf("\n");
 return 0;
}
