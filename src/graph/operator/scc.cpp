#include <data_structures/graph.hpp>

void Graph::Tarjan(Node* u)
{
    order[u->value] = low[u->value] = ++state;
    buffer.push(u);

    for(auto i : u->edges)
    {
        if(order[i->v->value] == 0)
        {
            Tarjan(i->v);
            low[u->value] = std::min(low[u->value], low[i->v->value]);
        }
        else if(order[i->v->value] != 0 && low[i->v->value] != 0)
        {
            low[u->value] = std::min(low[u->value], order[i->v->value]);
        }
    }

    if(low[u->value] == order[u->value])
    {
        std::vector<Node*> component;
        Node* v;
        do
        {
            v = buffer.top();
            buffer.pop();
            component.push_back(v);
            low[v->value] = 0;
        } while(v != u);
        components.push_back(component);
    }
}

void Graph::SCC()
{
    low.clear();
    order.clear();
    components.clear();

    state = 0;

    low.resize(nodes.size() + 1);
    order.resize(nodes.size() + 1);
    
    for(auto i : nodes)
    {
        if(order[i->value] == 0)
            Tarjan(i);
    }
}
