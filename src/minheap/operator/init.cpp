#include <data_structures/minheap.hpp>


void minHeap::init(std::vector<int> value)
{
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INIT];
    this->value.clear();
    for(auto &i : value)
    {
        realInsert(i);
    }
}
