#include <data_structures/maxheap.hpp>

void maxHeap::insert(int value)
{
    Node* node = new Node(value);
    this->value.push_back(node);

    int index = this->value.size() - 1;
        
    if(index == 0) return ;

    do
    {
        int parent = (index - 1) / 2;
        
        if(swapable(parent, index))
        {
            swap(parent, index);
        }

        index = parent;
    }while(index !=0);

}
