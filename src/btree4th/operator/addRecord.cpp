#include<data_structures/btree4th.hpp>

BTree4th::Node* BTree4th::addRecordToLeaf(Node* node, int k)
{
    if(node == nullptr) return nullptr;
    if(!node->isLeaf()) return node;

    int index = 0;
    for(int i = 0; i < 3; i++)
    {
        if(node->key[i] == nullptr)
        {
            node->key[i] = new int(k);
            index = i;
            return node;
        }
    }
    if(index == 1) 
    {
        if(k < *(node->key[0]))
            std::swap(node->key[0], node->key[1]);
    }

    if(index == 2)
    {
        if(*(node->key[0]) < *(node->key[1]))
            std::swap(node->key[0], node->key[1]);
        if(*(node->key[1]) < *(node->key[2]))
            std::swap(node->key[1], node->key[2]);
        if(*(node->key[0]) < *(node->key[2]))
            std::swap(node->key[0], node->key[2]);
    }

    return node;
}

BTree4th::Node* BTree4th::mergeChild(Node* node, Node* child)
{
    if(node == nullptr) return nullptr;
    if(child == nullptr) return node;
    if(!child->isBinary()) return node;

    int index = -1;
    for(int i = 0; i < 3; i++)
    {
        if(node->child[i] == child)
        {
            index = i;
            break;
        }
    }
    if(index == -1) return node;

    return mergeChild(node, index);
}

BTree4th::Node* BTree4th::mergeChild(Node* node, int index)
{
    if(node == nullptr) return nullptr;
    if(node->child[index] == nullptr) return node;
    if(!node->child[index]->isBinary()) return node;

    for(int i = 1; i >= 0; i--)
    {
        node->key[i+1] = node->key[i];
    }
    for(int i = 2; i >= index; i--)
    {
        node->child[i+1] = node->child[i];
    }
    Node* tmp = node->child[index];

    node->key[index] = tmp->key[0];
    tmp->key[0] = nullptr;

    node->child[index] = tmp->child[0];
    tmp->child[0] = nullptr;

    node->child[index + 1] = tmp->child[1];
    tmp->child[1] = nullptr;

    delete tmp;
    
    node->repair(false);
    return node;
}
