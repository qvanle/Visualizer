#include <data_structures/minheap.hpp>
#include <services.hpp>

void minHeap::realInsert(int value)
{
    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");
    sprite->setText(NUMBER::intToString(value));
    Node* node = new Node(value, sprite);

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

void minHeap::insert(int value)
{
    shiftX = 20;
    shiftY = 20;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    realInsert(value);
}
