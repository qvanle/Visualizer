#include <data_structures/maxheap.hpp>

maxHeap::Node::~Node()
{
}

maxHeap::~maxHeap()
{
    for(auto &i : value)
    {
        delete i;
    }
}
