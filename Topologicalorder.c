#include<stdio.h>
#define MAX 10
void dfs(int adj[][MAX],int visited[],int start,int stack[],int*top){
    visited[start]=1;
    for(int i=0;i<MAX;i++){
        if(adj[start][i]&&visited[i]==0){
            dfs(adj,visited,i,stack,top);
        }
    }
    (*top)++;
    stack[*top]=start;
}
void topologicalsort(int adj[][MAX],int numVertices){
    int visited[MAX]={0};
    int stack[MAX];
    int top=-1;

    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            dfs(adj,visited,i,stack,&top);
        }
    }
    printf("Topological sort:\n");
    for(int i=top;i>=0;i--){
        printf("\n%d",stack[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    int adj[MAX][MAX]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter value of %d,%d:",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    topologicalsort(adj,n);

}
