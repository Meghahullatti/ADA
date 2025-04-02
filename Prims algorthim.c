#include<stdio.h>
void main()
{
   int i;
   int cost[10][10],vt[10],et[10][10],vis[10],j,n;
   int e=0,sum=0;
   printf("enter the number of vertices\n");
   scanf("%d",&n);
   printf("enter the cost adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
 scanf("%d",&cost[i][j]);
       }
       vis[i]=0;
    }
    prims(vt, vis, cost,et, n , &sum, &e);
    printf("edges of spanning tree\n");
    for(i=1;i<=e;i++)
    {
printf("%d,%d\n",et[i][0],et[i][1]);
    }
    printf("weight=%d\n",sum);
}

void prims(int vt[10],int vis[10], int cost[10][10],int et[10][10], int n, int *sum, int *e)
{
   int s,min,m,k,u,v,x=1,j;
   vt[x]=1;
   vis[x]=1;
   for(s=1;s<n;s++)
   {
       j=x;
       min=999;
       while(j>0)
       {
  k=vt[j];
  for(m=2;m<=n;m++)
  {
    if(vis[m]==0)
    {
if(cost[k][m]<min)
{
  min=cost[k][m];
  u=k;
  v=m;
}
        }
}
j--;
    }
    vt[++x]=v;
    et[s][0]=u;
    et[s][1]=v;
    (*e)++;
    vis[v]=1;
    *sum=(*sum)+min;
 }
}

