#include <data_structures/graph.hpp>
#include <algorithm>

struct DSU 
{
    std::vector<int> parent;
    DSU(int n)
    {
        parent.resize(n + 1);
        for(int i = 0; i < n; i++)
            parent[i] = -1;
    }
    ~DSU()
    {
        parent.clear();
    }

    void unionEdge(Graph::Edge* e)
    {
        unionEdge(e->u, e->v);
    }
    void unionEdge(Graph::Node* u, Graph::Node* v)
    {
        unionEdge(u->value, v->value);
    }
    void unionEdge(int u, int v)
    {
        int a = find(u);
        int b = find(v);
        if(a == b) return ;

        parent[a] += parent[b];
        parent[b] = a;
    }

    int find(Graph::Node* v)
    {
        return find(v->value);
    }
    int find(int v)
    {
        if(parent[v] < 0)
            return v;
        return parent[v] = find(parent[v]);
    }
    
    bool isUnionized(Graph::Node* u, Graph::Node* v)
    {
        return isUnionized(u->value, v->value);
    }
    bool isUnionized(Graph::Edge* e)
    {
        return isUnionized(e->u, e->v);
    }
    bool isUnionized(int u, int v)
    {
        return find(u) == find(v);
    }

};

void Graph::MST()
{
    sortedEdges.clear();
    
    for(auto i : edges)
        sortedEdges.push_back(i);
    
    std::sort(
            sortedEdges.begin(), 
            sortedEdges.end(),
            [&](Edge* u, Edge* v){
                if(u == nullptr) return false;
                if(v == nullptr) return true;
                return u->weight < v->weight;
            }
    );

    unionEdges();
}

void Graph::unionEdges()
{
    repair();
    currentScript = script[DATA_STRUCTURES_OPERATOR::MST];
    DSU dsu(nodes.size());
    nodirect = true;

    highlight({0});
    waitForStep();
    unhighlight({0});

    highlight({1});
    waitForStep();
    unhighlight({1});

    highlight({2, 3, 4, 5, 6});
    waitForStep();
    for(auto i : sortedEdges)
    {
        if(nodirect && i->u->value > i->v->value)
            continue;
        i->mark = 3;
        waitForStep();
        if(!dsu.isUnionized(i))
        {
            i->mark = 1;
            waitForStep();
            dsu.unionEdge(i);
        }else 
        {
            i->mark = 2;
            waitForStep();
        }
    }
    unhighlight({2, 3, 4, 5, 6});
}
