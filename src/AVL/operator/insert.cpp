#include <data_structures.hpp>
#include <services.hpp>


AVL::Node* AVL::insert(Node* node, Node* newNode)
{
    if(node == nullptr) 
    {
        node = newNode;
        if(isAnimate)
        {
            node->sprite->highlight();
            waitForStep();
            node->sprite->unhighlight();
        }
        sizeOfTree++;
        return newNode;
    }
    if(isAnimate)
    {
        node->sprite->highlight();
        waitForStep();
        node->sprite->unhighlight();
    }
    if(compare(newNode, node) == -1)
    {
        node->lson = insert(node->lson, newNode);
        if(node->lson != nullptr && isAnimate)
        {
            waitForStep();
        }
    }
    else if(compare(newNode, node) == 1)
    {
        node->rson = insert(node->rson, newNode);
        if(node->rson != nullptr && isAnimate)
        {
            waitForStep();
        }
    }
    node = balancing(node);
    return node;
}

bool AVL::insert(int key)
{
    if(sizeOfTree == capacity)
    {
        return false;
    }
    cache = nullptr;

    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");
    sprite->setText(NUMBER::intToString(key));

    cache = new Node(key, sprite);

    isPause = false;
    isQueue = false;
    isAnimate = true;

    root = insert(root, cache);

    maxHigh = maxDepth(root);


    cache = nullptr;

    return true;
}
