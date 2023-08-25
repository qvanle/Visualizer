#include <data_structures/graph.hpp>

void Graph::repair()
{
    for(auto i : edges)
    {
        i->mark = 0;
    }
    setting(bgColor, nodeColor, fontColor, edgesColor);
    nodirect = false;
}
