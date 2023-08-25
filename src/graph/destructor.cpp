#include <data_structures/graph.hpp>

Graph::Node::~Node()
{
    for (auto &i : edges)
        i = nullptr;
    edges.clear();

    if(sprite != nullptr) delete sprite;
}

Graph::Edge::~Edge()
{
    u = nullptr;
    v = nullptr;
    if(sprite != nullptr) delete sprite;
}

Graph::~Graph()
{
    for(auto &i : nodes)
        delete i;
    nodes.clear();

    for(auto &i : edges)
        delete i;
    edges.clear();

    TTF_CloseFont(scriptFont);
    for(auto i : script)
        delete i.second;
    script.clear();
}
