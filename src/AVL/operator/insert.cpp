#include <data_structures.hpp>
#include <services.hpp>


Node* AVL::insert(Node* node, Node* newNode)
{
    if(node == nullptr) 
    {
        sizeOfTree++;
        return newNode;
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
    cache->sprite->highlight();

    isPause = false;
    isQueue = false;

    root = insert(root, cache);

    maxHigh = maxDepth(root);
    locating(root, 0, 0);

    cache->sprite->unhighlight();

    cache = nullptr;

    return true;
}
