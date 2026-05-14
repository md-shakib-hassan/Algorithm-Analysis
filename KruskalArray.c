#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for edge
struct Edge
{
    int src;
    int dest;
    int weight;
};

// Union-Find parent array
int parent[MAX];

// Find function
int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

// Union function
void Union(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

// Sort edges by weight
void sortEdges(struct Edge edges[], int E)
{
    for(int i = 0; i < E - 1; i++)
    {
        for(int j = 0; j < E - i - 1; j++)
        {
            if(edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskal(struct Edge edges[], int V, int E)
{
    // Initialize parent
    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // Sort edges
    sortEdges(edges, E);

    int count = 0;
    int totalCost = 0;

    printf("\nEdges in MST:\n");

    for(int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        int setU = find(u);
        int setV = find(v);

        // Avoid cycle
        if(setU != setV)
        {
            printf("%d - %d : %d\n", u, v, w);

            totalCost += w;

            Union(setU, setV);

            count++;
        }
    }

    printf("\nTotal Cost = %d\n", totalCost);
}

int main()
{
    int V, E;

    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (src dest weight):\n");

    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}