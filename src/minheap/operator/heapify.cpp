#include <data_structures/minheap.hpp>

void minHeap::swap(int index1, int index2)
{
    std::swap(value[index1], value[index2]);
}

bool minHeap::swapable(int index1, int index2)
{
    return value[index1]->value > value[index2]->value;
}

void minHeap::heapify(int index)
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
        if(isAnimate)
        {
            animate_mutex.lock();
            value[index]->sprite->highlight();
            value[largest]->sprite->highlight();
            animate_mutex.unlock();
            waitForStep();
        }
        swap(index, largest);
        if(isAnimate)
        {
            animate_mutex.lock();
            value[index]->sprite->unhighlight();
            value[largest]->sprite->unhighlight();
            animate_mutex.unlock();
        }
        heapify(largest);
    }
}
