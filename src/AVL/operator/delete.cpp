#include <data_structures/AVL.hpp>
#include <services.hpp>

AVL::Node* AVL::unplugSmallest(Node* node, struct Node*& n2)
{
    if(node == nullptr) return nullptr;
    if(node->lson == nullptr)
    {
        n2 = node;
        return node->rson;
    }
    node->lson = unplugSmallest(node->lson, n2);
    return node;
}
AVL::Node* AVL::remove(Node* node, int key)
{
    if(node == nullptr) return node;
    if(node->key < key)
    {

        node->rson = remove(node->rson, key);
        node = balancing(node);
        return node;
    }
    else if(node->key > key)
    {
        node->lson = remove(node->lson, key);
        node = balancing(node);
        return node;
    }
    else
    {
        if(node->rson == nullptr)
        {
            Node* temp = node->lson;
            delete node;
            temp = balancing(temp);
            return temp;
        }else 
        {
            Node* temp = unplugSmallest(node->rson, cache);

            cache->lson = node->lson;
            node->lson = nullptr;

            cache->rson = temp;
            node->rson = nullptr;

            delete node;
            node = cache;

            node = balancing(node);
            return node;
        }
    }
}

bool AVL::remove(int key)
{
    if(sizeOfTree == 0)
    {
        return false;
    }
    
    isAnimate = true;

    root = remove(root, key);
    locating(root, 0, 0);
    
    cache = nullptr;
    return true;
}

