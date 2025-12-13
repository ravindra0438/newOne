#include<stdio.h>
#include<stdlib.h>
struct adjListNode{
    int dest;
    struct adjListNode *next;
};
struct adjList{
    struct adjListNode *head;
};
struct  Graph
{
    int V;
    struct adjList *arr;
};

struct adjListNode * createAdjListNode(int dest)
{
    struct adjListNode *newNode = (struct adjListNode *)malloc(sizeof(struct adjListNode ));
    if(newNode==NULL)
    {
        printf("memory allocation is fails for the adjacency list node\n");
        return newNode;
    }
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

struct Graph * createGraph(int v)
{
    struct Graph *g= (struct Graph *)malloc(sizeof(struct Graph));
    if(g==NULL)
    {
        printf("memory allocation fails for the graph\n");
        return g;
    }
    g->V=v;
    g->arr= (struct adjList *) malloc(sizeof (struct adjList) * v);
    for (int i=0;i<v;i++)
    {
        g->arr[i].head= NULL;
    }
    return g;
}

void printGraph(struct Graph * g)
{
    int v;
    for (v =0;v<g->V;v++)
    {
        printf("printing adjacency list nodes for the vertex head %d=>", v);
        struct adjListNode *ptr= g->arr[v].head;
        while(ptr != NULL)
        {
            printf ("%d =>", ptr->dest);
            ptr= ptr->next;
        }

        printf("\n");
    }
}


void addEdge(struct Graph *g, int src, int dest)
{
    if(g == NULL || g->arr == NULL)
    {
        printf("graph is null / or graph arraylist is null\n);
        return;
    }
    struct adjListNode *newNode = createAdjListNode(dest);

    newNode->next= g->arr[src].head;
     g->arr[src].head = newNode;


     newNode= createAdjListNode(src);
     newNode->next= g->arr[dest].head;
     g->arr[dest].head=newNode;
    
}
int main()
{
    struct Graph *g= createGraph(5);
    addEdge(g,0,1);
    addEdge(g,0,4);
    addEdge(g,1,2);
    addEdge(g,1,3);
    addEdge(g,1,4);
    addEdge(g,2,3);
    addEdge(g,3,4);
   printGraph(g);
   return 0;


}

