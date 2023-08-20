#include <data_structures/graph.hpp>

Graph::Edges::Edges(int s, int d)
{
    u = s;
    v = d;
    isWeighted = false;
    flag = 0;
    weight = 0;
}

Graph::Edges::Edges(int s, int d, int w)
{
    u = s;
    v = d;
    isWeighted = true;
    flag = 0;
    weight = w;
}

Graph::Graph()
{
}
