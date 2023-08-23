#include <data_structures/minheap.hpp>

bool valuesReachedZero = false;

void minHeap::pop()
{
    if(!value.empty()) valuesReachedZero = false;
    if(valuesReachedZero) return ;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::DELETE];
    isAnimate = true;
    highlight({0});
    waitForStep();
    unhighlight({0});

    if(value.size() == 0)
    {
        valuesReachedZero = true;
        highlight({1, 2, 3});
        waitForStep();
        unhighlight({1, 2, 3});
        return;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        value[0]->sprite->highlight();
        value.back()->sprite->highlight();
        animate_mutex.unlock();
        waitForStep();
    }
    swap(0, value.size() - 1);

    if(isAnimate)
    {
        animate_mutex.lock();
        value[0]->sprite->unhighlight();
        value.back()->sprite->unhighlight();
        animate_mutex.unlock();
    }
    
    highlight({5});
    waitForStep();
    unhighlight({5});

    value.pop_back();

    highlight({6});
    waitForStep();

    heapify(0);

    unhighlight({6});
    waitForStep();
}
