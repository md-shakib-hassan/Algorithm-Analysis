#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge node
struct Edge
{
    int src;
    int dest;
    int weight;
    struct Edge* next;
};

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

// Create edge node
struct Edge* createEdge(int s, int d, int w)
{
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->src = s;
    newEdge->dest = d;
    newEdge->weight = w;
    newEdge->next = NULL;

    return newEdge;
}

// Insert edge sorted by weight
void insertSorted(struct Edge** head, int s, int d, int w)
{
    struct Edge* newEdge =
        createEdge(s, d, w);

    // Insert at beginning
    if(*head == NULL ||
       w < (*head)->weight)
    {
        newEdge->next = *head;
        *head = newEdge;
        return;
    }

    struct Edge* temp = *head;

    while(temp->next != NULL &&
          temp->next->weight < w)
    {
        temp = temp->next;
    }

    newEdge->next = temp->next;
    temp->next = newEdge;
}

// Kruskal Algorithm
void kruskal(struct Edge* head, int V)
{
    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int count = 0;
    int totalCost = 0;

    printf("\nEdges in MST:\n");

    struct Edge* temp = head;

    while(temp != NULL &&
          count < V - 1)
    {
        int u = temp->src;
        int v = temp->dest;
        int w = temp->weight;

        int setU = find(u);
        int setV = find(v);

        if(setU != setV)
        {
            printf("%d - %d : %d\n", u, v, w);
            totalCost += w;
            Union(setU, setV);
            count++;
        }

        temp = temp->next;
    }

    printf("\nTotal Cost = %d\n",
           totalCost);
}

int main()
{
    int V, E;

    struct Edge* head = NULL;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (src dest weight):\n");

    for(int i = 0; i < E; i++)
    {
        int s, d, w;

        scanf("%d %d %d", &s, &d, &w);
        insertSorted(&head, s, d, w);
    }

    kruskal(head, V);

    return 0;
}