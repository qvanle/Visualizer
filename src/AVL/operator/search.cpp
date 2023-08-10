#include <data_structures/AVL.hpp>
#include <services.hpp>


void AVL::search(Node* node, int key)
{
    if(node == nullptr)
    {
        return ;
    }
    if(node->key == key)
    {
        node->sprite->highlight();
        return ;
    }
    if(node->key < key)
    {
        search(node->rson, key);
    }
    else
    {
        search(node->lson, key);
    }
}

bool AVL::search(int key)
{
    if(sizeOfTree == 0)
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
    
    search(root, key);
    cache->sprite->unhighlight();
    
    delete cache;
    cache = nullptr;
    return true;
}

