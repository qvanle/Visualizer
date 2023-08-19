#include <data_structures/maxheap.hpp>

void maxHeap::pop()
{
    if(value.size() == 0)
    {
        return;
    }
    
    swap(0, value.size() - 1);
    value.pop_back();

    heapify(0);
}
