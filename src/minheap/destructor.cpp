#include <data_structures/minheap.hpp>

minHeap::Node::~Node()
{
}

minHeap::~minHeap()
{
    for(auto &i : value)
    {
        delete i;
    }
    if(scriptFont != nullptr) TTF_CloseFont(scriptFont);
    for(auto & i : scripts)
        delete i.second;
    scripts.clear();
}
