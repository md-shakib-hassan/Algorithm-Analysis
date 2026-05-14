#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    int vertices;
    struct Node* adjList[MAX];
};

struct Node* createNode(int v, int w)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;

    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add edge src -> dest
    struct Node* newNode =
        createNode(dest, weight);

    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge dest -> src
    newNode = createNode(src, weight);

    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Find minimum key vertex
int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX;
    int minIndex;

    for(int v = 0; v < V; v++)
    {
        if(mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print MST
void printMST(int parent[], int key[], int V)
{
    int total = 0;

    printf("\nEdge \tWeight\n");

    for(int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i],  i, key[i]);

        total += key[i];
    }

    printf("\nTotal Cost = %d\n", total);
}

// Prim's Algorithm
void primMST(struct Graph* graph)
{
    int V = graph->vertices;

    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    // Initialize
    for(int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // MST
    for(int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);

        mstSet[u] = 1;

        struct Node* temp =
            graph->adjList[u];

        while(temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if(mstSet[v] == 0 &&
               weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }

            temp = temp->next;
        }
    }

    printMST(parent, key, V);
}

int main()
{
    struct Graph graph;

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    graph.vertices = V;

    // Initialize adjacency list
    for(int i = 0; i < V; i++)
    {
        graph.adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (src dest weight):\n");

    for(int i = 0; i < E; i++)
    {
        int src, dest, weight;

        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src,  dest,  weight);
    }
    primMST(&graph);

    return 0;
}