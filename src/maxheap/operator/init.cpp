#include <data_structures/maxheap.hpp>


void maxHeap::init(std::vector<int>& value)
{
    for(auto &i : value)
    {
        insert(i);
    }
}
