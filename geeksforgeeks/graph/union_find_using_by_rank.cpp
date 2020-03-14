#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int src, dest;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

class subset
{
public:
    int parent;
    int rank;
};

Graph *create_graph(int V, int E)
{
    Graph *graph = new Graph();
    graph->E = E;
    graph->V = V;
    graph->edge = new Edge[E * sizeof(Edge)];
    return graph;
}

int find(subset subs[], int i)
{
    if (subs[i].parent != i)
        subs[i].parent = find(subs, subs[i].parent);
    return subs[i].parent;
}

void _union(subset subs[], int x, int y)
{
    int xroot = find(subs, x);
    int yroot = find(subs, y);

    if (subs[xroot].rank > subs[yroot].rank)
        subs[yroot].parent = xroot;
    else if (subs[xroot].rank < subs[yroot].rank)
        subs[xroot].parent = yroot;
    else
    {
        subs[xroot].parent = yroot;
        subs[yroot].rank++;
    }
}

int iscycle(Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    subset *subs = new subset[V * sizeof(subset)];
    for (int i = 0; i < V; i++)
    {
        subs[i].parent = i;
        subs[i].rank = 0;
    }
    for (int e = 0; e < E; ++e)
    {
        int x = find(subs, graph->edge[e].src);
        int y = find(subs, graph->edge[e].dest);

        if (x == y)
            return 1;

        _union(subs, x, y);
    }
    return 0;
}

int main(){
    int V = 3, E = 3;
    Graph *graph = create_graph(V, E);
    // add edge 0-1 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
  
    // add edge 1-2 
    graph->edge[1].src = 1; 
    graph->edge[1].dest = 2; 
  
    // add edge 0-2 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 2;

    if (iscycle(graph)) 
        printf( "Graph contains cycle" ); 
    else
        printf( "Graph doesn't contain cycle" ); 
  
    return 0; 
}