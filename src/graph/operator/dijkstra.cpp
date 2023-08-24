#include <data_structures/graph.hpp>

struct distanceHeap
{
    Graph* g;
    std::vector<int> value;

    distanceHeap(Graph* g)
    {
        this->g = g;
    }
    ~distanceHeap()
    {
        value.clear();
        g = nullptr;
    }

    bool swapable(int i, int j)
    {
        if(g->distance[value[i]] == -1) return true;
        if(g->distance[value[j]] == -1) return false;
        return g->distance[value[i]] > g->distance[value[j]];
    }
    void swap(int i, int j)
    {
        std::swap(value[i], value[j]);
    }
    void insert(int v)
    {
        value.push_back(v);
        int index = value.size() - 1;
        do 
        {
            int parent = (index - 1) / 2;
            if(swapable(parent, index))
            {
                swap(parent, index);
            }
            index = parent;
        }while(index != 0);
    }
    int pop()
    {
        if(value.size() == 0) return 2e9;
        int result = value[0];
    
        value[0] = value[value.size() - 1];
        value.pop_back();

        int index = 0;

        while(index < value.size())
        {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int next = index;

            if(left < value.size() && swapable(next, left))
                next = left;
            if(right < value.size() && swapable(next, right))
                next = right;

            if(next == index) break;

            swap(index, next);
            index = next;
        }

        return result;
    }
    bool empty() { return value.empty(); }
};

void Graph::Dijkstra(int start, int end)
{
    distance.clear();
    distance.resize(nodes.size(), -1);
    distanceHeap heap(this);

    distance[start] = 0;
    heap.insert(start);

    while(!heap.empty())
    {
        int u = heap.pop();

        for(auto e : nodes[u]->edges)
        {
            int v = e->v->value;
            if(distance[v] == -1 || distance[v] > distance[u] + e->weight)
            {
                distance[v] = distance[u] + e->weight;
                heap.insert(v);
            }
        }
    }
}