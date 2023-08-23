#include <climits>
#include <data_structures/minheap.hpp>

int minHeap::top()
{
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::TOP];
    if(value.size() == 0)
        return INT_MAX;
    return value[0]->value;
}
