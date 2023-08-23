#include<data_structures.hpp>

void DataStructures::initMinHeap(InputBox* inp)
{
    std::vector<int> v = NUMBER::stringToArray(inp->getText(1));
    minheap->init(v);
}
