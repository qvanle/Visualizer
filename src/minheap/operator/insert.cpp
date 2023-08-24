#include <data_structures/minheap.hpp>
#include <services.hpp>

void minHeap::realInsert(int value)
{
    if(inverse) value *= -1;
    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");
    sprite->setFontColor(fontColor);
    sprite->coloring(nodeColor);
    sprite->setText(NUMBER::intToString(value));
    Node* node = new Node(value, sprite);

    this->value.push_back(node);

    int index = this->value.size() - 1;
    highlight({1, 2, 3});
    waitForStep();
    unhighlight({1, 2, 3});

    if(index == 0)
    {
        highlight({5, 6, 7});
        waitForStep();
        unhighlight({5, 6, 7});
        return ;
    }
    highlight({9});
    do
    {
        int parent = (index - 1) / 2;

        if(isAnimate)
        {
            animate_mutex.lock();
            this->value[index]->sprite->highlight();
            this->value[parent]->sprite->highlight();
            animate_mutex.unlock();
            waitForStep();
        }
        if(swapable(parent, index))
        {
            highlight({11, 12, 13});
            waitForStep();
            swap(parent, index);
            unhighlight({11, 12, 13});
        }
        if(isAnimate)
        {
            animate_mutex.lock();
            this->value[index]->sprite->unhighlight();
            this->value[parent]->sprite->unhighlight();
            animate_mutex.unlock();
        }
        index = parent;
    }while(index !=0);
    unhighlight({9});
}

void minHeap::insert(int value)
{
    shiftX = 20;
    shiftY = 20;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    isAnimate = true;

    highlight({0});
    waitForStep();
    unhighlight({0});

    realInsert(value);
}
