#include <data_structures.hpp>

void DataStructures::removeMinHeap(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));
    
    while(value--) minheap->pop();
}


