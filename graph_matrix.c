#include <stdio.h>
#include<stdlib.h>
#define max 10


void printgraph(int graph[max][max], int vertices)
{
    printf("weighted adjacency matrix\n");
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("%-5d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int graph[max][max]={0};
    printf("enter number of vertices\n");
    int vertices, edges;    
    scanf("%d", &vertices);
    printf("enter the number of edges\n");
    scanf("%d", &edges);
    for(int i=0;i<edges;i++)
    {
        int u, v,w;
        scanf("%d %d %d", &u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;


    }
    printgraph(graph,vertices);

}