#include <data_structures/AVL.hpp>
#include <services.hpp>

void AVL::init(std::vector<int> values)
{
    if(root != nullptr)
        delete root;
    root = nullptr;
    cache = nullptr;
    sizeOfTree = 0;
    shiftX = 20;
    shiftY = 20;
    isAnimate = false;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INIT];
    for(int i = 0; i < values.size() && sizeOfTree < capacity; i++)
    {
        Sprite* sprite = new Sprite(render);
        sprite->setFont(font);
        sprite->linking("AVL/node");
        sprite->setText(NUMBER::intToString(values[i]));

        root = insert(root, new Node(values[i], sprite));
    }
    maxHigh = maxDepth(root);
}

