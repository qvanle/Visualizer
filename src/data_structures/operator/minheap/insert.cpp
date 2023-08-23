#include <data_structures.hpp>

void DataStructures::insertMinHeap(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));
    minheap->insert(value);
}

