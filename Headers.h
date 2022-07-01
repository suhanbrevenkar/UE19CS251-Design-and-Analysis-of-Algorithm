#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Node struct
typedef struct Node
{
    // Required:vertex ID,Weight,pointer,path dist,previous vertex ID
    int id,weight,d,pre;
    struct Node* next;
}Node;

// Node header
typedef struct Head
{
    Node* head;
    int pre,d; // ID of previous vertex in graph & length of shortest path
}Head;


typedef struct Graph
{
    int n;
    Head* graph;
}Graph;

typedef struct Heap
{
    int n;
    Node*heap;
}Heap;

typedef struct Path
{
    Node* head;
    int d; 
} Path;

typedef struct Paths
{
    int n; // Number of vertices
    Path* paths;
}Paths;

Graph* initialise(int size);
Graph* file(void);
Graph* Dijkstra(Graph* g, Heap* h);

// Inserting graphs to adj list
Head insert(Head head, int id, int weight);

Heap* create(int size);
Heap* delete(Heap* h, int* del);
Heap* update(Heap* h);
Heap* distance_update(Heap* h, int id, int d);

Node* outgoing(Graph* g, int* visited, int id);
Node* insert_path(Node* head, int id);

void disp(Graph* g);
int* reset(int* arr, int size);