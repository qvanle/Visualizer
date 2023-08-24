#include <data_structures.hpp>
#include <services.hpp>


AVL::Node* AVL::insert(Node* node, Node* newNode)
{
    if(node == nullptr) 
    {
        node = newNode;
        if(isAnimate)
        {
            highlight({1, 2, 3});
            animate_mutex.lock();
            node->sprite->highlight();
            animate_mutex.unlock();

            waitForStep();

            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
            unhighlight({1, 2, 3});
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
        highlight({4, 5});
        if(isAnimate) waitForStep();
        unhighlight({4, 5});

        node->lson = insert(node->lson, newNode);
    }
    else if(compare(newNode, node) == 1)
    {
        highlight({6, 7});
        if(isAnimate) waitForStep();
        unhighlight({6, 7});
        node->rson = insert(node->rson, newNode);
    }

    highlight({9});
    node = balancing(node);
    unhighlight({9});

    return node;
}

bool AVL::insert(int key)
{
    if(sizeOfTree == capacity)
    {
        return false;
    }
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    cache = nullptr;

    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");

    sprite->setFontColor(fontColor);
    sprite->Object::coloring(nodeColor);

    sprite->setText(NUMBER::intToString(key));

    cache = new Node(key, sprite);

    isPause = false;
    isQueue = false;
    isAnimate = true;
    
    highlight({0});
    waitForStep();
    unhighlight({0});

    root = insert(root, cache);

    maxHigh = maxDepth(root);


    cache = nullptr;

    return true;
}
