#include <data_structures/maxheap.hpp>

void maxHeap::swap(int index1, int index2)
{
    std::swap(value[index1], value[index2]);
}

bool maxHeap::swapable(int index1, int index2)
{
    return value[index1]->value < value[index2]->value;
}

void maxHeap::heapify(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if(left < value.size() && swapable(index, left))
    {
        largest = left;
    }

    if(right < value.size() && swapable(largest, right))
    {
        largest = right;
    }

    if(largest != index)
    {
        swap(index, largest);
        heapify(largest);
    }
}
