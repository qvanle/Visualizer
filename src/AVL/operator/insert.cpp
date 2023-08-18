#include <data_structures.hpp>
#include <services.hpp>


AVL::Node* AVL::insert(Node* node, Node* newNode)
{
    if(node == nullptr) 
    {
        node = newNode;
        if(isAnimate)
        {
            animate_mutex.lock();
            node->sprite->highlight();
            animate_mutex.unlock();

            waitForStep();

            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
        }
        sizeOfTree++;
        return newNode;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();

        waitForStep();

        animate_mutex.lock();
        node->sprite->unhighlight();
        animate_mutex.unlock();
    }
    if(compare(newNode, node) == -1)
    {
        node->lson = insert(node->lson, newNode);
    }
    else if(compare(newNode, node) == 1)
    {
        node->rson = insert(node->rson, newNode);
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
