#include "Headers.h"

int main(void)
{
    Graph*g=file(); 
    Heap*h=create(g->n); 

    g=Dijkstra(g,h);
    disp(g);
}