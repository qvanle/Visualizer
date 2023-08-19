#include <data_structures/minheap.hpp>

void minHeap::pop()
{
    if(value.size() == 0)
    {
        return;
    }
    
    swap(0, value.size() - 1);
    value.pop_back();

    heapify(0);
}
