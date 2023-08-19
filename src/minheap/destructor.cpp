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
}
