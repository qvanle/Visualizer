#include <data_structures/graph.hpp>
#include <algorithm>

void Graph::FindMiniMumSpanningTree()
{
    auto l = edges; 
    MST(l);
}

int getPresent(std::vector<int> &p, int u)
{
    if (p[u] < 0)
        return u;
    return p[u] = getPresent(p, p[u]);
}

bool merge(std::vector<int> &p, int u, int v)
{
    u = getPresent(p, u);
    v = getPresent(p, v);
    if(u == v) return false;

    p[u] += p[v];
    p[v] = u;

    return true;
}

void Graph::MST(EdgesList &list)
{
    std::sort(list.begin(), list.end(), [](Edges &a, Edges &b) { return a.weight < b.weight; });
    present.clear();
    present.resize(numberOfVertices + 1, -1);

    for(Edges &edge : list)
    {
        if(merge(present, edge.u, edge.v))
        {
            edge.flag = 1;
        }
    }
}
