#include "Headers.h"
#define inf INT_MAX

Graph* initialise(int size)
{
    Graph*g=(Graph*)malloc(sizeof(Graph));  // Create a graph

    g->n=size;
    g->graph=malloc(size * sizeof(Node));

    for (int i=0;i<size;i++)
    {
        g->graph[i].head=NULL;
        g->graph[i].pre=0;
        g->graph[i].d=inf;
    }
    return g;
}

Head insert(Head head, int id, int weight)
{
    // Create node with id and weight
    Node* new = malloc(sizeof(Node));
    new->id = id;
    new->weight = weight;
    new->next = NULL;
    new->d = inf;
    new->pre = 0; //nodes start from 1.0 indicates no preious node in the path

    if (head.head == NULL)
                head.head = new;  //list is empty
    else
    {
        Node*t = head.head;

        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new;
    }
    return head;
}

Graph* file(void)
{
    
    FILE*f;
    f=fopen("adjacencylist.txt","r");

    if (f == NULL)
    {
        return NULL;
    }

    size_t size = 1000;

    char* num = malloc(1000 * sizeof(char));
    int p=getline(&num,&size,f);
    Graph* g = initialise(atoi(num)+1); 

    while(p = getline(&num,&size,f) != -1)
    {
        
        char* token = strtok(num, " ");
        int node = atoi(token);

        int wt,v; //weight and vertex

        while (token != NULL)
        {
            // Get vertex token
            token = strtok(NULL," ");
            if (token == NULL)
                          break;

            v=atoi(token);
            token=strtok(NULL," ");

            if (token == NULL)
                           break;
            wt=atoi(token);
            g->graph[v] = insert(g->graph[v],node,wt);
        }
    }
    return g;
}

Heap* create(int size)
{
    Heap*h=(Heap*)malloc(sizeof(Heap));
    h->n = size - 1;

    h->heap=malloc((h->n + 1) * sizeof(Node));

    for (int i = 0; i < h->n; i++)
    {
        h->heap[i].id = i + 1;
        h->heap[i].d = inf;
        h->heap[i].pre = 0;
    }
    return h;
}

Heap* delete(Heap* h, int* del)
{
    *del = h->heap[0].id;

    for (int i = 0; i < (h->n - 1); i++)
    {
        h->heap[i] = h->heap[i + 1];
    }
    h->n--;
    return h;
}

Heap* update(Heap* h)
{
    Node t;

    for (int i = 0; i < h->n - 1; i++)
    {
        int swaps = 0;
        
        for (int j = 0; j < (h->n - i - 1); j++)
        {
            if (h->heap[j].d > h->heap[j + 1].d)
            {
                t = h->heap[j];
                h->heap[j] = h->heap[j + 1];
                h->heap[j + 1] = t;
                swaps ++;
            }
        }
        if (swaps == 0)
                    break;
    }
    return h;
}

Node* outgoing(Graph* g, int* visited, int id)
{
    Node* t = g->graph[id].head;

    while (t != NULL)
    {
        if (visited[t->id] == 0)
                        return t;
        t = t->next;
    }
    return NULL;
}

Heap* distance_update(Heap* h, int id, int d)
{
    for (int i = 0; i < h->n;i++)
    {
        if (h->heap[i].id == id)
        {
            h->heap[i].d = d;
            break;
        }
    }

    h = update(h);
    return h;
}

Graph* Dijkstra(Graph* g, Heap* h)
{
    int src= g->n - 1;

    h->heap[h->n - 1].d = 0;
    g->graph[h->heap[h->n - 1].id].d = 0;
    h = update(h);

    int v[g->n];
    for (int i = 1; i < g->n;i++)
    {
        v[i] = 0;
    }
    v[g->n - 1] = 1;
    int del;

    Node* n;

    for (int i = 1; i < (g->n - 1);i++)
    {
        h = delete(h,&del);
        v[del] = 1;

        Node*t=g->graph[del].head;

        while (t != NULL)
        {
            if ((g->graph[del].d + t->weight) < (g->graph[t->id].d))
            {
                g->graph[t->id].d = g->graph[del].d + t->weight;
                h = distance_update(h, t->id, g->graph[t->id].d);
                g->graph[t->id].pre = del;
            }
            t=t->next;
        }
    }
    return g;
}

Node* insert_path(Node* head, int id)
{
    Node* new = malloc(sizeof(Node));
    new->id = id;
    new->next = NULL;

    if (head == NULL)
               head=new;
    else
    {
        Node* t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = new;
    }
    return head;
}

int* reset(int* arr,int size)
{
    for (int i = 1; i < size; i ++)
    {
        arr[i] = 0;
    }
    return arr;
}


void disp(Graph* g)
{
    Paths* p = malloc(sizeof(Paths));
    p->paths = malloc((g->n - 1) * sizeof(Node));

    int src=g->n-1;
    int* arr = malloc(src * sizeof(int));

    for (int i = 1; i < src; i ++)
    {
        if (g->graph[i].pre != 0)
        {
            Node* new = malloc(sizeof(Node));
            new->id = i;
            new->next = NULL;
            p->paths[i].head = new; 
        }
        else
            p->paths[i].head = NULL;
    }

    for (int i=1; i < src; i ++)
    {
        int pre = g->graph[i].pre,j=0,k=0;
        arr = reset(arr,src);

        if (pre != 0)
        {
            while (pre != src)
            {
                arr[j] = pre;
                j++;
                pre =g->graph[pre].pre;
            }
            arr[j] = pre;
        }
        while (k <= j && (arr[j]==src))
        {
            p->paths[i].head = insert_path(p->paths[i].head,arr[k]);
            k++;
        }
    }
    Node*t;

    for (int i = 1; i < src; i++)
    {
        t = p->paths[i].head;
        if (t == NULL)
               printf("%d NO PATH\n",i);
        else
        {
            printf("%d ",i);

            while (t != NULL)
            {
                printf("%d ",t->id);
                t = t->next;
            }
            printf("%d\n",g->graph[i].d);
        }
    }
}