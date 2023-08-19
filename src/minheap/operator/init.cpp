#include <data_structures/minheap.hpp>


void minHeap::init(std::vector<int>& value)
{
    for(auto &i : value)
    {
        insert(i);
    }
}
