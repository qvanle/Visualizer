#include <climits>
#include <data_structures/minheap.hpp>

int minHeap::top()
{
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::TOP];
    isAnimate = true;
    highlight({0, 1, 2, 3, 4, 5});
    waitForStep();
    unhighlight({0, 1, 2, 3, 4, 5});

    if(value.size() == 0)
        return INT_MAX;
    return value[0]->value;
}
